#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

using namespace std;

int digitos(const vector<int> &v, int ini, int fin)
{
    if (ini == fin) return v[ini];

    int mid = (ini + fin) / 2;
    int max_Izq = digitos(v, ini, mid);
    int max_Der = digitos(v, mid + 1, fin);
    return max(max_Izq, max_Der);
}

int max_posicion(const vector<int> &v, int valor, int desde)
{
    for (int i = desde; i < (int)v.size(); ++i)
    {
        if (v[i] == valor)
            return i;
    }
    return desde;  // por seguridad
}

long long voltage_memo(const vector<int> &v, unordered_map<string, long long> &memo)
{
    const int K = 12;
    int n = (int)v.size();
    int pos = 0;
    long long res = 0;

    string subsequence_key = "";

    for (int i = 0; i < K; ++i)
    {
       subsequence_key += to_string(v[pos]);

        if (memo.find(subsequence_key) != memo.end()) {
            return memo[subsequence_key];  // Devolvemos el valor memorizado
        }

        int restantes = K - i;
        int fin = n - restantes;

        int mayor = digitos(v, pos, fin);
        pos = max_posicion(v, mayor, pos);

        res = res * 10 + mayor;
        ++pos;  
    }
    memo[subsequence_key] = res;

    return res;
}

int main()
{
    string linea;
    ifstream archivo("baterias.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    long long bateria = 0;
    unordered_map<string, long long> memo;

    while (getline(archivo, linea))
    {
        if (linea.empty())
            continue;

        vector<int> v;
        v.reserve(linea.length());

        for (char c : linea)
        {
            if (isdigit((unsigned char)c))
                v.push_back(c - '0');
        }

        if ((int)v.size() >= 12)
        {
            bateria += voltage_memo(v,memo);
        }
    }

    archivo.close();
    cout << "Bateria total: " << bateria << endl;
    return 0;
}
