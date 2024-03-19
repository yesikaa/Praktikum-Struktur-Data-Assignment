#include <iostream>
#include <conio.h>
using namespace std;

// Fungsi untuk menampilkan menu
void menu() 
{
    cout << "<<<<<< Menu >>>>>>" << endl;
    cout << "1. Input Array" << endl;
    cout << "2. Tampilkan Array" << endl;
    cout << "3. Cari Nilai Minimum" << endl;
    cout << "4. Cari Nilai Maksimum" << endl;
    cout << "5. Hitung Rata-Rata" << endl;
    cout << "Masukkan Pilihan Anda : ";
}

// Fungsi untuk mencari nilai minimum dari array
int minimum(int isi[]) 
{
    int min = isi[0];
    for (int x = 1; x < 10; x++) 
    {
        if (isi[x] < min) 
        {
            min = isi[x];
        }
    }
    return min;
}

// Fungsi untuk mencari nilai maksimum dari array
int maksimum(int isi[]) 
{
    int max = isi[0];
    for (int x = 1; x < 10; x++) 
    {
        if (isi[x] > max) 
        {
            max = isi[x];
        }
    }
    return max;
}

// Fungsi untuk menghitung rata-rata dari array
float rata(int isi[]) 
{
    float total = 0;
    for (int i = 0; i < 10; i++) 
    {
        total += isi[i];
    }
    return total / 10;
}

int main() {
    int pil, bil[10];
    char opsi;
    bool x;
    
    // Loop utama
    do {
        menu();
        cin >> pil;
        cout << endl;
        
        if (pil == 1 || x == true || pil == 0) 
        {
            x = true;
            switch (pil) 
            {
                case 1:
                    cout << "Masukkan Bilangan yang Anda inginkan" << endl;
                    for (int i = 0; i < 10; i++) {
                        cout << "Bilangan ke-" << i + 1 << " : ";
                        cin >> bil[i];
                    }
                    break;
                case 2:
                    cout << "Data Array yang sudah dimasukkan" << endl;
                    for (int b = 0; b < 10; b++) {
                        cout << bil[b] << " ";
                    }
                    break;
                case 3:
                    cout << "Nilai Minimum: " << minimum(bil) << endl;
                    break;
                case 4:
                    cout << "Nilai Maksimum: " << maksimum(bil) << endl;
                    break;
                case 5:
                    cout << "Nilai Rata-rata adalah: " << rata(bil) << endl;
                    break;
            }
        } else if (x == false && pil != 1) {
            cout << "Silahkan input nomor 1 dulu.";
            goto mainloop;
        }
        
        mainloop:
        cout << endl;
        cout << "Apakah Anda ingin memilih menu yang lain? [y/n]";
        opsi = getch();
        cout << endl;
    } while (opsi == 'y');
    
    if (opsi == 'n') {
        cout << "Selesai";
    }
    
    return 0;
}
