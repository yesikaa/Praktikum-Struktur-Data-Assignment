# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Mahasiswa dapat memahami konsep Array.
2. Mahasiswa dapat mengetahui jenis dimensi Array dan cara penulisannya.
3. Mahasiswa dapat mengimplementasikan Array pada kode program yang dibuat
```
## Dasar Teori
<p style="text-align: justify; font-size: 12px;"> 
Array adalah suatu struktur data yang terdiri dari sekumpulan data dengan tipe data yang sama. Setiap data disimpan dalam alamat memori yang berbeda-beda dan disebut dengan elemen array. Kita dapat memasukkan nilai dalam sebuah variable array berdasarkan ukuran dari array tersebut. Dengan Catatan jika kita menentukan ukurannya, sementara bila tidak maka array tersebut bersifat dinamis menyesuaikan jumlah nilai yang di inputkan.

Array terdiri dari beberapa jenis, yaitu array 1 dimensi, array 2 dimensi dan array multidimensi. Dalam mengakses array digunakan nomor index array yang dimulai dari 0.<br>

  **Array 1 Dimensi**
Array 1 dimensi merupakan suatu kumpulan elemen yang disusun dalam satu baris atau satu kolom. Setiap elemen memiliki indexs unik yang dimulai dari 0 hingga ukuran array dikurangi 1. Array satu dimensi digunakan untuk menyimpan data yang berurutan.<br>

**Array 2 Dimensi**
Array 2 dimensi merupakan array yang biasa dikenal sebagai matriks memiliki dua indexs, yaitu satu untuk baris, dan satu lainnya untuk kolom. indeks dan kolom tersebut dimulai dari nol hingga ukuran array dikurangi 1. Array 2 dimensi digunakan untuk menyimpan data yang berstruktur secara grid atau tabel.<br>

**Array Multidimensi**
Array multidimensi adalah array yang memiliki elemen lebih dari dua dimensi, dimana array multidimensi dapat memiliki struktur data tiga dimensi, empat dimensi, dan seterusnya. Setiap dimensi akan memiliki satu set indeks yang sesuai dengan dimensi tersebut. Array multidimensi ini biasa digunakan untuk menyimpan data yang lebih kompleks dan terstruktur dalam bentuk ruang multidimensional.<br>
</p>
  
## Guided

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
//PROGRAM INPUR ARRAY 3 DIMENSI 
int main()
{
    //Deklarasi Array
    int arr[2] [3] [3];
    //Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "] [" << y << "] [" << z << "] =";
                cin >> arr[x] [y] [z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array [" << x << "] [" << y << "] [" << z << "] = " << arr[x] [y] [z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilkan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x] [y] [z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

#### Output
![Guided-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/2992ceea-868e-48d1-8379-dcd309451f38)

Program diatas merupakan program yang menginisialisasikan sebuah array tiga dimensi yaitu dengan deklarasi `arr[2][3][3]` masing-masing memiliki tiga baris dan tiga kolom. Program ini akan melakukan tiga kali looping dengan menggunakan tiga variabel for untuk meminta input nilai dari user untuk setiap elemen array. User akan diminta memasukkan nilai array, dan setelah itu program akan melakukan looping kembali mencetak nilai dari setiap elemen array yang telah dimasukkan oleh user. Lalu program mencetak ulang nilai dari elemen array dalam format matriks 2 dimensi dengan looping yang baru.
<br>

### 2. Program Mencari Nilai Maksimal pada Array

```C++
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
```

#### Output
![Guided-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/204df8f9-2251-449e-ae11-3d42d350c89a)

Program diatas merupakan sebuah program sederhana untuk mencari nilai maksimum dari sebuah array yang diisi oleh pengguna. Pertama, program akan meminta pengguna untuk memasukkan panjang array melalui pesan yang ditampilkan di layar. Setelah itu, program membuat sebuah array dengan ukuran yang sesuai dengan panjang yang dimasukkan pengguna. Kemudian, pengguna diminta untuk memasukkan nilai dari elemen tersebut satu per satu. Setelah semua nilai dimasukkan, program akan melakukan loop untuk membandingkan setiap elemen array dengan variabel maks. Jika elemen array lebih besar dari maks, maka nilai maks diperbarui dengan elemen array tersebut dan lokasi array disimpan di variable lokasi. Setelah selesai, program akan mencetak nilai maksimum beserta lokasi dalam array.
<br>

## Unguided

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![Soal-Unguided-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/683732f4-5d32-472f-abea-c74878767beb)

#### Source Code
```C++
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
```

#### Output
![Unguided-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/b053c8ac-1a7d-4d81-8588-94fc2600b372)

#### Deskripsi Program
Program di atas merupakan program untuk menampilkan elemen array yang diinputkan oleh user, kemudian memisahkan antara bilangan genal dan bilangan ganjil. Pertama, program akan mendeklarasikan sebuah array dengan meminta user memasukkan 10 bilangan array, selanjutnya bilangan tersebut di simpan menjadi sebuah data yang selanjutnya ditampilkan secara berurutan. kemudian dari bilangan - bilangan tersebut program melakukan proses pemisahan antara bilangan genap dengan bilangan ganjil. Program ini memanfaatkan penggunaan loop iterasi dan kondisional untuk mencapai fungsionalitasnya dalam memproses data array secara sederhana.

### 2. Buatlah program Input Array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

#### Source Code
```C++
#include <iostream>
using namespace std;

int main()
{
    //Untuk mendeklarasikan variable ukuran array
    int x, y, z;

    //Meminta user memasukkan ukuran array
    cout << "Masukkan Ukuran Array [x][y][z] : ";
    cin >> x >> y >> z;

    int array[x] [y] [z];
    //Mendeklarasikan array tiga dimensi dengan ukuran yang dimasukkan oleh user
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
```

#### Output
![Unguided-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/76d92f68-a7b1-425d-89b3-0b5ac0fed0ce)

#### Deskripsi Program
Program di atas merupakan program yang digunakan untuk mendeklarasikan, dan menginput data pada array tiga dimensi, di mana ukuran atau jumlah elemennya diinputkan oleh user. Setelah itu, program akan meminta user untuk memasukkan nilai-nilai array tersebut. Setelah semua nilai dimasukkan, program akan menampilkan kembali nilai setiap elemen array, program juga menampilkan nilai array dalam bentuk matriks, yaitu dengan menampilkan setiap baris elemen array secara terpisah dengan menggunakan loop iterasi bersarang. Program ini memanfaatkan penggunaan loop iterasi bersarang untuk mengakses setiap elemen array dan melakukan proses input-output dengan pengguna. 

### 3. BUatlah program menu untuk mencari nilai Maksimum, Minimim, dan Nilai rata-rata dari suatu array dengan input yang dimasukkan oleh user!

#### Source Code
```C++
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
```

#### Output
![Unguided-3-a](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/488fe47c-048d-47f9-8b88-f8ff97dcefd7)
t
![Unguided-3-b](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/a115252a-542d-4057-995d-7d1108f6d2d9)

#### Deskripsi Program
Program di atas adalah program sederhana dalam bahasa pemrograman C++ yang menyediakan berbagai pilihan menu untuk memanipulasi data dalam sebuah array. Program dimulai dengan mendefinisikan beberapa fungsi, yaitu menu() untuk menampilkan menu, minimum() untuk mencari nilai minimum dalam array, maksimum() untuk mencari nilai maksimum dalam array, dan rata() untuk menghitung rata-rata dari array. Di dalam fungsi main(), program menggunakan loop utama do-while untuk terus menampilkan menu dan memproses pilihan pengguna sampai pengguna memilih untuk keluar. Setiap pilihan menu dieksekusi dengan menggunakan struktur switch-case, di mana pengguna dapat memasukkan data ke dalam array, menampilkan data array, mencari nilai minimum dan maksimum, serta menghitung rata-rata nilai dalam array. Program juga memberikan validasi agar pengguna tidak dapat memilih opsi lain sebelum memasukkan data ke dalam array. Program ini menunjukkan penggunaan fungsi, struktur kontrol, dan input-output sederhana dalam bahasa pemrograman C++ untuk memanipulasi data array.

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Array adalah sebuah struktur data yang terdiri dari kumpulan elemen dengan tipe data yang sama, data array tersimpan secara berurutan di dalam memori komputer. Terdapat tiga jenis array, yaitu array 1 dimensi, array 2 dimensi, dan array multidimensi, di mana setiap elemen dalam array sendiri diidentifikasi dengan indeks yang dimulai dari 0.
Penggunaan array memiliki kelebihan karena dapat menyimpan banyak nilai dengan satu nama variabel, serta memiliki kemampuan untuk menyimpan data lebih dari satu dimensi. serta memiliki kemampuan untuk menyimpan data dalam lebih dari satu dimensi. Hal ini membuat array menjadi sangat berguna dalam pemrograman untuk mempermudah pengelolaan data dan menghemat penggunaan variabel. Selain itu, array juga dapat digunakan untuk mempermudah proses pengolahan data, seperti mengurutkan, mencari nilai maksimum atau minimum, dan menghitung rata-rata.
Namun, terdapat kelemahan saat menggunakan array ini, dimana alokasi memori yang tepat dan pengelolaan memori yang efisien sangat penting dalam penggunaan array untuk mencegah terjadinya kesalahan atau kebocoran memori. Oleh karena itu, diperlukan pemahaman yang baik tentang penggunaan dan manajemen array untuk menghindari masalah pada program yang dihasilkan.
<div/>
  
## Referensi
[1] Asisten Praktikum, "Modul 2-Array", Praktikum Struktur Data dan Algoritma, Learning ManagementSystem, 2024.<br>
[2] Hanief, Shofwan dan Wayan Jepriana. "Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++", Institut Teknologi Dan Bisnis STIKOM BALI, 2020.<br>
[3] Huda, Asrul dan Noper Ardi. "Pengantar Coding Berbasis C/C++", 2021.<br> 





