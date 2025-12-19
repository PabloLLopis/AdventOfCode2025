#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long vgrande;
using MinHeap = priority_queue<tuple<vgrande, int, int>, vector<tuple<vgrande, int, int>>, greater<tuple<vgrande, int, int>>>;


//Cordenadas 3D
struct coord {
    int x, y, z;
};

//Base DSU
class DSU {
private:
    vector<int> padre;
    vector<int> tam;

public:
    // Constructor que inicializará al apdre segun el numero y tamaños 1
    DSU(int n) : padre(n), tam(n, 1) {
        for (int i = 0; i < n; ++i)
        {
            padre[i] = i;
        }
    }

    // Buscará el padre del elemento, hara llamadas recursivas
    int buscar(int a) {
        if (padre[a] != a)
        {
            padre[a] = buscar(padre[a]);
        }
        return padre[a];
    }

    // Une dos conjuntos
    void unir(int a, int b) {
        int raizA = buscar(a);
        int raizB = buscar(b);
        if (raizA != raizB)
        {
            if (tam[raizA] < tam[raizB])
            {
                padre[raizA] = raizB;
                tam[raizB] += tam[raizA];
            }
            else
            {
                padre[raizB] = raizA;
                tam[raizA] += tam[raizB];
            }
        }
    }

    // Obtener tamnyo del conjunto al que pertenece a
    int size(int a) {
        return tam[buscar(a)];
    }
};


// Se calcula la distancia euclidiana (formula matematica)
vgrande calcularDistancia(const coord &a, const coord &b) {
    vgrande dx = (vgrande)(a.x - b.x);
    vgrande dy = (vgrande)(a.y - b.y);
    vgrande dz = (vgrande)(a.z - b.z);
    return ((dx * dx) + (dy * dy) + (dz * dz));
}

int main(void)
{
    // Se genera numeros aleatorios con la hora actual
    srand(time(0));


    MinHeap pcola; // Min-heap 

    //input.txt
    string linea;
    ifstream archivo("input.txt");
    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    vector<coord> puntos; 

    while (getline(archivo, linea))
    {
        stringstream ss(linea); 
        coord punto;
        char coma;
        if (ss >> punto.x >> coma >> punto.y >> coma >> punto.z) //GGuardar solo numeros
        {
            puntos.push_back(punto);
        }
    }
    archivo.close();

    const int uniones = puntos.size(); //Número de puntos

    for (int i = 0; i < uniones; ++i)
    {
        for (int j = i + 1; j < uniones; ++j)
        {
            vgrande distancia = calcularDistancia(puntos[i], puntos[j]);// Calcular la distancia entre puntos
            pcola.push(make_tuple(distancia, i, j));//Se agrega a la cola de prioridad
        }
    }
    DSU dsu(uniones); // Estructura DSU

    for (int i = 0; i < uniones; i++) // Como máximo haremos n-1 uniones
    {
        if (pcola.empty())
        {
            break; // Para evitar que se queden elementos sin procesar
        }
        auto [distancia, u, v] = pcola.top(); // Desempaquetar
        pcola.pop();                          // Sacar el elemento de la cola

        if (dsu.buscar(u) != dsu.buscar(v)) // Si los puntos no están unidos, unirlos
        {
            dsu.unir(u, v); // Unir los puntos
        }
    }

    vector<int> tamanyos; // Vector para guardar los tamaños de los conjuntos.

    for (int i = 0; i < uniones; ++i)
    {
        if (dsu.buscar(i) == i)
        {
            tamanyos.push_back(dsu.size(i)); // Agregar el tamaño del conjunto
        }
    }

    sort(tamanyos.begin(), tamanyos.end(), greater<int>()); // Ordenar los tamaños de mayor a menor

    vgrande resultado = 1;         // Variable para guardar el resultado de la multiplicación

    for (int i = 0; i < 3; ++i)
    {
        resultado *= tamanyos[i]; // Multiplicar los tres tamaños más grandes
    }

    cout << resultado << endl;
    return 0;
}
