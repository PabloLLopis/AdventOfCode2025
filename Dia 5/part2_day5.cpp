#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Node
{
    long long low;     // inicio del intervalo
    long long high;    // fin del intervalo
    long long maxHigh; // máximo 'high' de TODO el subárbol con raíz en este nodo
    Node *left;        // hijo izquierdo
    Node *right;       // hijo derecho
};

Node *insertNode(Node *root, long long low, long long high)
{
    if (root == nullptr)
    {
        Node *node = new Node{low, high, high, nullptr, nullptr};
        return node;
    }

    if (low < root->low)
        root->left = insertNode(root->left, low, high);
    else
        root->right = insertNode(root->right, low, high);

    if (root->maxHigh < high)
        root->maxHigh = high;

    return root;
}

bool overlaps(Node *root, long long x)
{
    if (root == nullptr)
        return false;

    if (root->low <= x && x <= root->high)
        return true;

    if (root->left != nullptr && root->left->maxHigh >= x)
        return overlaps(root->left, x);

    return overlaps(root->right, x);
}
void inorder(Node *root, vector<long long> &L, vector<long long> &R)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, L, R);
    L.push_back(root->low);
    R.push_back(root->high);
    inorder(root->right, L, R);
}
int main()
{
    Node *root = nullptr;
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
        root = insertNode(root, pequeño, grande);
    }
    vector<long long> L; // todos los low
    vector<long long> R; // todos los high
    inorder(root, L, R);
    int k = 0;

    for (int i = 1; i < L.size(); i++)
    {

        long long currLow = L[i];
        long long currHigh = R[i];

        if (currLow > R[k] + 1)
        {
            k++;
            L[k] = currLow;
            R[k] = currHigh;
        }
        else
        {
            if (currHigh > R[k])
                R[k] = currHigh;
        }
    }
    long long total = 0;
    for (int i = 0; i <= k; i++)
    {
        total += (R[i] - L[i] + 1);
    }

    cout << total << endl;

    return 0;
}
