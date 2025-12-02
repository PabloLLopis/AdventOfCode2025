#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
vector<int> numeros_caja;

char obtener_direccion(string orden)
{
    return orden[0];
}

int obtener_giro(string orden)
{
    int giro = 0;
    if (orden[0] != 'R' && orden[0] != 'L')
    {
        throw runtime_error("Orden invalida");
    }
    string entero = orden.substr(1);
    try
    {
        giro = stoi(entero);
        return giro;
    }
    catch (const invalid_argument &e)
    {
        throw runtime_error("Orden invalida: No se pudo convertir el giro a un número");
    }
}
int girar(int giro, int posicion, char dir)
{
    if (dir == 'R')
    {
        posicion += giro;
    }
    else if (dir == 'L')
    {
        posicion -= giro;
    }
    posicion = (posicion % 100 + 100) % 100;
    return posicion;
}
int contar_pasos_por_0(int giro, int posicion, char dir)
{
    int contador_0 = 0;
    int posicion_inicial = posicion;

    // Realizamos la rotación y verificamos cada paso
    if (dir == 'R')
    {
        for (int i = 0; i < giro; i++) // Rotación a la derecha
        {
            posicion++;
            if (posicion >= 100) {
                posicion = 0; // Vuelta al principio
            }
            if ((posicion_inicial <= 0 && posicion > 0) || (posicion_inicial > 0 && posicion <= 0)) {
                contador_0++; // Paso por el 0
            }
            posicion_inicial = posicion;
        }
    }
    else if (dir == 'L')
    {
        for (int i = 0; i < giro; i++) // Rotación a la izquierda
        {
            posicion--;
            if (posicion < 0) {
                posicion = 99; // Vuelta al final
            }
            if ((posicion_inicial >= 0 && posicion < 0) || (posicion_inicial < 0 && posicion >= 0)) {
                contador_0++; // Paso por el 0
            }
            posicion_inicial = posicion;
        }
    }

    return contador_0;
}

int main()
{
    string orden;
    int posicion = 50;
    int contraseña = 0;
    int contador_0 = 0; // Contador para cada vez que la posición sea 0

    // Abrir archivo de texto
    ifstream archivo("ordenes.txt"); // Asegúrate de poner la ruta correcta del archivo
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Leer línea por línea del archivo
    while (getline(archivo, orden)) // Mientras haya líneas en el archivo
    {
        int posicion_inicial = posicion;  // Guardamos la posición antes de realizar el giro
        char dir = obtener_direccion(orden);
        int giro = obtener_giro(orden);
        // Contamos cuántas veces pasamos por 0 durante el giro
        contador_0 += contar_pasos_por_0(giro, posicion, dir);

        // Ahora realizamos la rotación y verificamos si el final es 0
        posicion = girar(giro, posicion, dir);

        // Incrementar contraseña si la posición final es 0
        if (posicion == 0)
        {
            contraseña++;
        }

        cout << "Contraseña: " << contraseña << "\n";
        cout << "Posición: " << posicion << "\n";
    }

    archivo.close(); // Cerrar el archivo
    cout << "Cantidad total de veces que se pasó por el 0 (incluyendo durante el giro): " << contador_0 << endl;
    return 0;
}
