#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

//  TABLA HASH (string -> int) 
class TablaHashStr
{
private:
    // Cada entrada almacena una clave y su valor asociado
    struct Entrada
    {
        string key;
        int valor;
        Entrada(const string &c, int v) : key(c), valor(v) {}
    };

    vector<list<Entrada>> tabla;   // Tabla hash con encadenamiento
    long long maximo;              // Número de cubetas
    long long tam;                 // Número de elementos almacenados
    double umbralFactorCarga;      // Umbral para realizar rehash

    // Función hash para strings
    long long funcionHash(const string &key) const
    {
        long long hash = 5381;
        for (unsigned char c : key)
            hash = ((hash << 5) + hash) + c;
        return hash;
    }

    // Obtiene el índice de la tabla
    long long h(const string &key) const
    {
        return funcionHash(key) % maximo;
    }

    // Duplica el tamaño de la tabla cuando se supera el factor de carga
    void rehash()
    {
        long long nuevoMax = maximo * 2;
        vector<list<Entrada>> nuevaTabla((size_t)nuevoMax);

        for (const auto &cubeta : tabla)
            for (const auto &nodo : cubeta)
                nuevaTabla[(size_t)(funcionHash(nodo.key) % nuevoMax)].push_back(nodo);

        tabla = move(nuevaTabla);
        maximo = nuevoMax;
    }

    // Comprueba si es necesario hacer rehash antes de insertar
    void comprobarCarga()
    {
        if ((double)(tam + 1) / (double)maximo > umbralFactorCarga)
            rehash();
    }

public:
    // Constructor de la tabla hash
    TablaHashStr(long long maxInicial = 16)
        : maximo(maxInicial), tam(0), umbralFactorCarga(0.75)
    {
        tabla.resize((size_t)maximo);
    }

    // Inserta una clave o actualiza su valor si ya existe
    void insert(const string &key, int valor)
    {
        comprobarCarga();
        long long indice = h(key);

        for (auto &nodo : tabla[(size_t)indice])
        {
            if (nodo.key == key)
            {
                nodo.valor = valor;
                return;
            }
        }
        tabla[(size_t)indice].push_back(Entrada(key, valor));
        tam++;
    }

    // Busca una clave y devuelve un puntero al valor
    const int *search(const string &key) const
    {
        long long indice = h(key);
        for (const auto &nodo : tabla[(size_t)indice])
            if (nodo.key == key)
                return &nodo.valor;
        return nullptr;
    }

    // Comprueba si una clave existe en la tabla
    bool contains(const string &key) const
    {
        return search(key) != nullptr;
    }
};

// grafo dirigiido
class GrafoDir
{
private:
    TablaHashStr texto_a_id;              // Mapeo string -> ID
    vector<string> id_a_texto;            // Mapeo ID -> string
    vector<vector<int>> adyacencia;       // Lista de adyacencia

    // Devuelve el ID de un vértice
    int obtenerID(const string &v) const
    {
        const int *id = texto_a_id.search(v);
        return (id ? *id : -1);
    }

    // Crea un vértice si no existe y devuelve su ID
    int crearVertice(const string &v)
    {
        int id = obtenerID(v);
        if (id != -1)
            return id;

        int nuevo = (int)id_a_texto.size();
        texto_a_id.insert(v, nuevo);
        id_a_texto.push_back(v);
        adyacencia.resize((size_t)nuevo + 1);
        return nuevo;
    }

    // Conteo de caminos mediante programación dinámica
    long long contarDP(int u, int destino, vector<long long> &memo) const
    {
        // Caso base: se alcanza el destino
        if (u == destino)
            return 1;

        // Si ya se ha calculado , se devuelve el valor almacenado
        if (memo[(size_t)u] != -1)
            return memo[(size_t)u];

        long long total = 0;

        // Se exploran todos los vecinos
        for (int v : adyacencia[(size_t)u])
            total += contarDP(v, destino, memo);

        // Se almacena el resultado
        memo[(size_t)u] = total;
        return total;
    }

public:
    // Añade una arista dirigida origen -> destino
    void agregarArista(const string &origen, const string &destino)
    {
        int u = crearVertice(origen);
        int v = crearVertice(destino);
        adyacencia[(size_t)u].push_back(v);
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
        // Separar el nodo origen del resto de destinos
        size_t pos = linea.find(':');
        if (pos == string::npos)
            continue;

        string origen = linea.substr(0, pos);
        string resto = linea.substr(pos + 1);

        // Leer todos los destinos asociados al origen
        istringstream ss(resto);
        string destino;
        while (ss >> destino)
        {
            grafo.agregarArista(origen, destino);
        }
    }
    archivo.close();

    // Calcular y mostrar el número total de caminos
    long long totalCaminos = grafo.contarCaminos("you", "out");
    cout << totalCaminos << endl;   // Resultado esperado: 470

    return 0;
}
