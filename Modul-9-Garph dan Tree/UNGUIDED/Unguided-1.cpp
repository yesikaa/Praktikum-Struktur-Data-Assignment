//Yesika Widiyani
//2311102195

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk menampilkan adjacency matrix
void displayMatrix(vector<vector<int>>& matrix, vector<string>& nodes) 
{
    int yesika_2311102195 = matrix.size(); 

    cout << "\nAdjacency Matrix :" << endl;
    cout << "     "; 

    // Menampilkan nama-nama simpul di baris pertama
    for (int i = 0; i < yesika_2311102195; i++) 
    {
        cout << nodes[i] << "   ";
    }
    cout << endl;

    // Menampilkan isi dari adjacency matrix
    for (int i = 0; i < yesika_2311102195; i++) 
    {
        cout << nodes[i] << "    "; 
        for (int j = 0; j < yesika_2311102195; j++) {
            cout << matrix[i][j] << "   "; 
        }
        cout << endl;
    }
}

int main() 
{
    int numNodes;

    // Meminta user untuk memasukkan jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    
    // Meminta user untuk memasukkan nama-nama simpul
    cout << "Silakan masukkan nama simpul: " << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Membuat adjacency matrix dengan ukuran numNodes x numNodes
    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes));

    // Meminta user untuk memasukkan bobot antar simpul
    cout << "\nSilakan masukkan bobot antar simpul: " << endl;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << nodes[i] << " -> " << nodes[j] << " = ";
            cin >> adjacencyMatrix[i][j];
        }
    }

    // Menampilkan adjacency matrix
    displayMatrix(adjacencyMatrix, nodes);

    return 0;
}
