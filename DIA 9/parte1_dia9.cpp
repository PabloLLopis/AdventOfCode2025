#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Coordenadas
{
    long long x, y;
};

long long areamaxima(vector<Coordenadas> baldosas)
{
    long long Maxarea = 0;
    for (int i = 0; i < baldosas.size(); i++)
    {
        for (int j = i + 1; j < baldosas.size(); j++)
        {
            long long base = abs((baldosas[i].x - baldosas[j].x) + 1);
            long long altura = abs((baldosas[i].y - baldosas[j].y) + 1);
            long long area = base * altura;
            Maxarea = max(Maxarea, area);
        }
    }
    return Maxarea;
}

int main()
{
    vector<Coordenadas> baldosas_rojas;
    string linea;
    ifstream archivo("area.txt");
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }
    while (getline(archivo, linea))
    {
        int pos = linea.find(',');
        Coordenadas c;
        c.x = stoll(linea.substr(0, pos));
        c.y = stoll(linea.substr(pos + 1));
        baldosas_rojas.push_back(c);
    }
    archivo.close();
    long long Maxarea = 0;
    Maxarea = areamaxima(baldosas_rojas);
    cout << Maxarea << endl;
    return 0;
}