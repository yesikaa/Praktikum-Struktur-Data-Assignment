#include <iostream>
using namespace std;

int main()
{
    //Untuk mendeklarasikan variable ukuran array
    int x, y, z;

    //Meminta pengguna memasukkan ukuran array
    cout << "Masukkan Ukuran Array [x][y][z] : ";
    cin >> x >> y >> z;

    int array[x] [y] [z];
    //Mendeklarasikan array tiga dimensi dengan ukuran yang dimasukkan oleh pengguna
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Input Array [" << i << "][" << j << "][" << k << "] = ";
                cin >> array[i][j][k];
            }
        }
        cout << endl;
    }
    cout << endl;

    //Menampilkan nilai setiap elemen array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Data Array [" << i << "][" << j << "][" << k << "] = " << array[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    //Menampilkan array dalam bentuk matriks
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}