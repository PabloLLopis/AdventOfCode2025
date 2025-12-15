#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
// Implementación propia de sort, no usar <algorithm>

using namespace std;

// (ordenar se define más abajo tras Baldosa)

// Usar directamente long long para mayor claridad

// Estructura que representa una baldosa
struct Baldosa
{
    long long x, y;

    bool operator<(const Baldosa &otra) const
    {
        if (x != otra.x)
            return x < otra.x;
        return y < otra.y;
    }

    bool operator==(const Baldosa &otra) const
    {
        return x == otra.x && y == otra.y;
    }
};

// Estructura para un rango prohibido
struct Rango
{
    long long fila_inicio, fila_fin, col_inicio, col_fin;
};

// Ordenar vector<Baldosa> con quicksort iterativo (una sola función)
void ordenar(vector<Baldosa> &baldosas)
{
    if (baldosas.empty())
    {
        return;
    }
    vector<pair<long long, long long>> pila;
    long long ultimo = baldosas.size() - 1;
    pila.push_back({0, ultimo});
    while (!pila.empty())
    {
        long long izquierda = pila.back().first;
        long long derecha = pila.back().second;
        pila.pop_back();

        long long i = izquierda, j = derecha;
        Baldosa pivote = baldosas[izquierda + (derecha - izquierda) / 2];
        while (i <= j)
        {
            while (baldosas[i] < pivote)
                i++;
            while (pivote < baldosas[j])
                j--;
            if (i <= j)
            {
                swap(baldosas[i], baldosas[j]);
                i++;
                j--;
            }
        }
        if (izquierda < j)
            pila.push_back({izquierda, j});
        if (i < derecha)
            pila.push_back({i, derecha});
    }
}
// Función hash para las baldosas
struct BaldosaHash
{
    int operator()(const Baldosa &b) const
    {
        size_t h = hash<long long>()(b.x) ^ hash<long long>()(b.y);
        return static_cast<int>(h);
    }
};

// Tabla hash implementada como un vector de listas
class TablaHashBaldosas
{
private:
    vector<list<pair<Baldosa, int>>> tabla;
    int tamaño_tabla;

    int indice_hash(const Baldosa &baldosa) const
    {
        BaldosaHash hash_fn;
        return hash_fn(baldosa) % tamaño_tabla;
    }

public:
    TablaHashBaldosas(int tamaño) : tamaño_tabla(tamaño)
    {
        tabla.resize(tamaño_tabla);
    }

    void insertar(const Baldosa &baldosa, int valor)
    {
        int indice = indice_hash(baldosa);
        for (auto &entrada : tabla[indice])
        {
            if (entrada.first == baldosa)
            {
                entrada.second = valor;
                return;
            }
        }
        tabla[indice].push_back({baldosa, valor});
    }

    int buscar(const Baldosa &baldosa) const
    {
        int indice = indice_hash(baldosa);
        for (const auto &entrada : tabla[indice])
        {
            if (entrada.first == baldosa)
            {
                return entrada.second;
            }
        }
        return 0;
    }
};

long long calcular_area(const Baldosa &baldosa_a, const Baldosa &baldosa_b)
{
    return (abs(baldosa_a.x - baldosa_b.x) + 1) * (abs(baldosa_a.y - baldosa_b.y) + 1);
}

bool es_posible(const Baldosa &baldosa_a, const Baldosa &baldosa_b, const vector<Rango> &rangos)
{
    long long x1 = min(baldosa_a.x, baldosa_b.x);
    long long x2 = max(baldosa_a.x, baldosa_b.x);
    long long y1 = min(baldosa_a.y, baldosa_b.y);
    long long y2 = max(baldosa_a.y, baldosa_b.y);

    for (const Rango &rango : rangos)
    {
        if (x1 >= rango.fila_fin || rango.fila_inicio >= x2 || y1 >= rango.col_fin || rango.col_inicio >= y2)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<Baldosa> rojas;
    TablaHashBaldosas tabla_rojas(20011);

    ifstream archivo("area.txt");
    if (!archivo.is_open())
    {
        cerr << "Error: No se pudo abrir el archivo part1dia9.txt" << endl;
        return 1;
    }

    string linea;
    while (getline(archivo, linea))
    {
        int pos = linea.find(',');
        long long x = stoll(linea.substr(0, pos));
        long long y = stoll(linea.substr(pos + 1));
        rojas.push_back({x, y});

        Baldosa nueva{x, y};

        // Usamos la hash para evitar duplicados y tener presencia O(1)
        if (!tabla_rojas.buscar(nueva))
        {
            rojas.push_back(nueva);
            tabla_rojas.insertar(nueva, 1);
        }
    }
    archivo.close();

    int cantidad_baldosas = rojas.size();
    vector<Rango> rangos_prohibidos;

    // Encontrar rangos prohibidos verticales
    ordenar(rojas);
    for (int i = 0; i < cantidad_baldosas; ++i)
    {
        if (i + 1 < cantidad_baldosas && rojas[i + 1].x == rojas[i].x)
        {
            long long c1 = rojas[i].y;
            long long c2 = rojas[i + 1].y;
            if (c2 - c1 > 1)
            {
                rangos_prohibidos.push_back({rojas[i].x, rojas[i].x, c1 + 1, c2 - 1});
            }
        }
    }

    // Intercambiar x e y
    for (int i = 0; i < cantidad_baldosas; ++i)
    {
        swap(rojas[i].x, rojas[i].y);
    }

    ordenar(rojas);

    // Encontrar rangos prohibidos horizontales
    for (int i = 0; i < cantidad_baldosas; ++i)
    {
        if (i + 1 < cantidad_baldosas && rojas[i + 1].x == rojas[i].x)
        {
            long long r1 = rojas[i].y;
            long long r2 = rojas[i + 1].y;
            if (r2 - r1 > 1)
            {
                rangos_prohibidos.push_back({r1 + 1, r2 - 1, rojas[i].x, rojas[i].x});
            }
        }
    }

    // Restaurar coordenadas
    for (int i = 0; i < cantidad_baldosas; ++i)
    {
        swap(rojas[i].x, rojas[i].y);
    }

    long long area_maxima = 0;

    // Probar todos los pares
    for (int i = 0; i < cantidad_baldosas; ++i)
    {
        for (int j = i + 1; j < cantidad_baldosas; ++j)
        {
            if (es_posible(rojas[i], rojas[j], rangos_prohibidos))
            {
                long long area = calcular_area(rojas[i], rojas[j]);
                if (area > area_maxima)
                {
                    area_maxima = area;
                }
            }
        }
    }

    cout << area_maxima << endl;

    return 0;
}