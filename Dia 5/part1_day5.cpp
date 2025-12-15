#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    int frescos = 0;
    vector<long long> Rmin;
    vector<long long> Rmax;
    vector<long long> IDs;
    string linea;
    ifstream archivo("input.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo";
        return 1;
    }
    while (getline(archivo, linea) && !linea.empty())
    {
        int ini = linea.find('-');
        string primero = linea.substr(0, ini);
        string segundo = linea.substr(ini + 1);

        long long pequeño = stoll(primero);
        long long grande = stoll(segundo);

        Rmin.push_back(pequeño);
        Rmax.push_back(grande);
    }
    while (getline(archivo, linea))
    {
        if (linea.empty())
        {
            continue;
        }
        long long id = stoll(linea);
        IDs.push_back(id);
    }
    archivo.close();
    for (int i = 0; i < IDs.size(); i++)
    {
        for (int j = 0; j < Rmin.size(); j++)
        {
            if (IDs[i] >= Rmin[j] && IDs[i] <= Rmax[j])
            {
                frescos++;
                break;
            }
        }
    }
    cout << frescos << endl;
    return 0;
}