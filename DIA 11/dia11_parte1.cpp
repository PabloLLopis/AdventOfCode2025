#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

// ===================== TABLA HASH (string -> int) =====================
class TablaHashStr
{
private:
    // Cada entrada guarda una clave (string) y un valor (int)
    struct Entrada
    {
        string key;
        int valor;
        Entrada(const string &c, int v) : key(c), valor(v) {}
    };

    // Tabla hash con encadenamiento
    vector<list<Entrada>> tabla;
    size_t maximo;               // tamaño actual de la tabla
    size_t tam;                  // número de elementos almacenados
    double umbralFactorCarga;    // limite para rehash

    // Función hash para strings
    size_t funcionHash(const string &key) const
    {
        size_t hash = 5381;
        for (unsigned char c : key)
            hash = ((hash << 5) + hash) + c;
        return hash;
    }

    // Calcula el índice dentro de la tabla
    size_t h(const string &key) const
    {
        return funcionHash(key) % maximo;
    }

    // Duplica el tamaño de la tabla y redistribuye los elementos
    void rehash()
    {
        size_t nuevoMax = maximo * 2;
        vector<list<Entrada>> nuevaTabla(nuevoMax);

        for (const auto &cubeta : tabla)
            for (const auto &nodo : cubeta)
                nuevaTabla[funcionHash(nodo.key) % nuevoMax].push_back(nodo);

        tabla = move(nuevaTabla);
        maximo = nuevoMax;
    }

    // Comprueba si se supera el factor de carga
    void comprobarCarga()
    {
        if ((double)(tam + 1) / maximo > umbralFactorCarga)
            rehash();
    }

public:
    TablaHashStr(size_t maxInicial = 16)
        : maximo(maxInicial), tam(0), umbralFactorCarga(0.75)
    {
        tabla.resize(maximo);
    }

    // Inserta o actualiza una clave
    void insert(const string &key, int valor)
    {
        comprobarCarga();
        size_t indice = h(key);

        for (auto &nodo : tabla[indice])
        {
            if (nodo.key == key)
            {
                nodo.valor = valor;
                return;
            }
        }
        tabla[indice].push_back(Entrada(key, valor));
        tam++;
    }

    // Busca una clave y devuelve puntero al valor
    const int *search(const string &key) const
    {
        size_t indice = h(key);
        for (const auto &nodo : tabla[indice])
            if (nodo.key == key)
                return &nodo.valor;
        return nullptr;
    }

    // Comprueba si una clave existe
    bool contains(const string &key) const
    {
        return search(key) != nullptr;
    }
};

// Grafo dirigido
class GrafoDir
{
private:
    TablaHashStr texto_a_id;         // Mapea nombres a IDs
    vector<string> id_a_texto;       // Mapea IDs a nombres 
    vector<vector<int>> adyacencia;  // Lista de adyacencia

    // Obtiene el ID de un vértice
    int obtenerID(const string &v) const
    {
        const int *id = texto_a_id.search(v);
        return (id ? *id : -1);
    }

    // Crea un vértice si no existee
    int crearVertice(const string &v)
    {
        int id = obtenerID(v);
        if (id != -1)
            return id;

        int nuevo = id_a_texto.size();
        texto_a_id.insert(v, nuevo);
        id_a_texto.push_back(v);
        adyacencia.resize(nuevo + 1);
        return nuevo;
    }

    // Conteo de caminos usando DP + memoizacion
    long long contarDP(int u, int destino, vector<long long> &memo) const
    {
        if (u == destino)
            return 1;

        if (memo[u] != -1)
            return memo[u];

        long long total = 0;
        for (int v : adyacencia[u])
            total += contarDP(v, destino, memo);

        memo[u] = total;
        return total;
    }

public:
    // Añadee una arista dirigida origen -> destino
    void agregarArista(const string &origen, const string &destino)
    {
        int u = crearVertice(origen);
        int v = crearVertice(destino);
        adyacencia[u].push_back(v);
    }

    // Cuenta todos los caminos desde origen hasta destino
    long long contarCaminos(const string &origen, const string &destino) const
    {
        int u = obtenerID(origen);
        int v = obtenerID(destino);
        if (u == -1 || v == -1)
            return 0;

        vector<long long> memo(id_a_texto.size(), -1);
        return contarDP(u, v, memo);
    }
};

int main()
{
    GrafoDir grafo;
    ifstream archivo("reactor.txt");

    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo\n";
        return 1;
    }

    string linea;
    while (getline(archivo, linea))
    {
        // Separar origen y destinos
        size_t pos = linea.find(':');
        if (pos == string::npos)
            continue;

        string origen = linea.substr(0, pos);
        string resto = linea.substr(pos + 1);

        // Leer todos los destinos
        istringstream ss(resto);
        string destino;
        while (ss >> destino)
        {
            grafo.agregarArista(origen, destino);
        }
    }

    archivo.close();

    // Calcular y mostrar el numero total de caminos
    long long totalCaminos = grafo.contarCaminos("you", "out");
    cout << totalCaminos << endl;   // Nos ha dado 470, perfecto

    return 0;
}
