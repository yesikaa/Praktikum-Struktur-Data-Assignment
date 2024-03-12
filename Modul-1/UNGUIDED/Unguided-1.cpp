#include <iostream>
using namespace std;

//Fungsi untuk menghitung luas persegi panjang
float MenghitungLuas (float Panjang, float Lebar)
{
    float Luas = Panjang*Lebar;
    return Luas;
}
//Fungsi untuk menghitung keliling persegi panjang
float Menghitungkeliling (float Panjang, float Lebar)
{
    float keliling = 2* (Panjang + Lebar);
    return keliling;
}
//Main Program
int main()
{
    int x, y;

    //Meminta nilai x dan y
    cout << "Masukkan Nilai X : "<<endl;
    cin >> x;
    cout << "Masukkan Nilai Y : "<<endl;
    cin >> y;

    //Memasukkan nilai x dan y sebagai panjang dan lebar
    float Luas = MenghitungLuas(x, y);
    float keliling = Menghitungkeliling (x, y);

    //Menampilkan luas persegi panjang
    cout << "Luas Persegi Panjang : " << x << "*" << y << "=" << Luas << endl;

    //Menampilkan Keliling Persegi panjang
    cout << "Keliling Persegi Panjang : 2*(" << x << "+" << y << ") = " << keliling << endl;
    return 0;
}
