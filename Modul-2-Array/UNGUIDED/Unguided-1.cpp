#include <iostream>
using namespace std;

//Main Program
int main()
{
    // Deklarasi array untuk menyimpan data yang akan dimasukkan oleh pengguna
    int array[10];

    //Meminta pengguna untuk memasukkan data array
    cout << "Masukkan Data Array" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << "Array ke-" << (i) << " : ";
        cin >> array[i];
    }

    //Menampilkan data array yang dimasukkan pengguna
    cout << "Data Array : ";
    for (int i = 1; i <= 10; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;

    //Menampilkan data array dengan nomor genap
    cout << "Nomor Genap : ";
    for (int i = 1; i <= 10; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << ", ";
        }
    }
    cout << endl;

    //Menampilkan data array dengan nomor ganjil
    cout << "Nomor Ganjil : ";
    for ( int i = 1; i <= 10; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << ", ";
        }
    } 
    cout << endl;
    return 0;
}