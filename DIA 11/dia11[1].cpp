#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;





// Función recursiva para contar los posibles caminos 
int contarCaminos(const string& nodo, const unordered_map<string, vector<string>>& grafo, unordered_map<string, bool>& visitado) {
    //ultimo nodo
    if (nodo == "out") {
        return 1;
    }

    visitado[nodo] = true;
    int camino = 0;

    // Recorremos todol
    for (const string& vecino : grafo.at(nodo)) {
        // Si no hemos visitado el dispositivo, seguimos buscando
        if (!visitado[vecino]) {
            camino += contarCaminos(vecino, grafo, visitado);
        }
    }

    visitado[nodo] = false;  // Marcamos el nodo como no visitado para permitir otros caminos
    return camino;
}

int main() {
    
    // contstruir grafo
    unordered_map<string, vector<string>> grafo;
    ifstream inputFile("reactor.txt");  

    string linea;
    while (getline(inputFile, linea)) {
        istringstream iss(linea);
        string device;
        string connection;
        iss >> device;  // Dispositivo (ej. "aaa:")
        device = device.substr(0, device.size() - 1);  // Eliminar el ":" al final

        vector<string> connections;
        while (iss >> connection) {
            connections.push_back(connection);
        }

        // Insertar el dispositivo y sus conexiones en el grafo
        grafo[device] = connections;
    }

    // Mapa para realizar un seguimiento de los dispositivos visitados
    unordered_map<string, bool> visited;

     
    int caminoTotal = contarCaminos("you", grafo, visited);

    
    cout << "Número de caminos diferentes desde 'you' hasta 'out': " << caminoTotal << endl;

    return 0;
}
