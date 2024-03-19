#include <iostream>
using namespace std;
int main()
{
    int maks, i = 1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka:\n";
    for (int i = 0; i < a; i++)
    {
        cout << "Elemen array ke-" << (i + 1) << " : ";
        cin >> array[i];
    }
    maks = array[0];
    for (int i = 1; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " dan berada di indeks " << lokasi << endl;
    return 0;
}