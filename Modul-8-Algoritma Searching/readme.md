# <h1 align="center">Laporan Praktikum Modul Algoritma Searching	</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">2311102195</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Menunjukkan beberapa algoritma dalam Pencarian.
2. Menunjukkan bahwa pencarian merupakan suatu persoalan yang bisa diselesaika dengan beberapa algoritma yang berbeda.
3. Dapat memilih algoritma yang paling sesuai untuk menyelesaikan suatu permasalahan pemrograman.
```

## Dasar Teori
<p style="text-align: justify; font-size: 12px;">

## GUIDED
### Contoh Program Penggunaan Searching
#### Source Code
```
//Guided Praktikum

#include <iostream>
using namespace std;

int arr[]={1,2,3,4,5,6,7,8,9,10,15,14};
int cari = 15;
bool ketemu = false;
int panjangArray = sizeof(arr)/sizeof(arr[0]);
int i;

int main()
{
    for (i = 0; i < panjangArray; i++){
        if(arr[i] == cari) {
            ketemu = true;
            break;
        } else {
            i++;
        }
    }

    cout << "Panjang Array : " << panjangArray <<endl;
    cout << cari << " Terdapat pada index ke- " << i;
}
```
#### Output

#### Deskripsi Program


### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.
##### Source Code
```C++
//Guided 1 - Modul

#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu)
    {
        cout << "\n angka " << cari << " ditemukan pada indeks ke - " << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." <<
    endl;
    }
    return 0;
}
```
#### Output

#### Deskripsi
<p style="text-align: justify; font-size: 12px;">


### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.
##### Source Code
```C++
//Guided 2 - Modul

#include <iostream>
#include <iomanip>

using namespace std;

// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort(int arr[], int n) 
{
    int temp, min;
    for (int i = 0; i < n - 1; i++) 
    {
        min = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }

        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void binary_search(int arr[], int n, int target) 
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir) 
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target) 
        {
            b_flag = 1;
            break;
        } else if (arr[tengah] < target) 
        {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
    cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
    cout << "\nData tidak ditemukan\n";
}

int main() 
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";

    // Tampilkan data awal
    for (int x = 0; x < 7; x++) 
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;

    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";

    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) 
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```
#### Output

#### Deskripsi
<p style="text-align: justify; font-size: 12px;">


## UNGUIDED
### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!
#### Source Code
```C++
// Yesika Widiyani
// 2311102195

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Fungsi untuk melakukan binary search dan mengembalikan posisi asli huruf jika ditemukan
int binary_search(const vector<pair<char, int>>& sorted_kalimat, char cari) 
{
    int awal = 0, akhir = sorted_kalimat.size() - 1;
    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;
        if (sorted_kalimat[tengah].first == cari) {
            return sorted_kalimat[tengah].second; // Kembalikan posisi asli
        } else if (sorted_kalimat[tengah].first < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    return -1; // Kembalikan -1 jika huruf tidak ditemukan
}

int main() 
{
    string kalimat;
    char cari;
    
    cout << ">>>>> MENCARI HURUF <<<<<\n";
    cout << "Masukkan Kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cari;
    cari = tolower(cari);

    // Membuat vector pasangan karakter dan indeks asli
    vector<pair<char, int>> indexed_kalimat;
    for (int i = 0; i < kalimat.size(); ++i) {
        indexed_kalimat.emplace_back(tolower(kalimat[i]), i);
    }

    // Sort berdasarkan karakter
    sort(indexed_kalimat.begin(), indexed_kalimat.end());

    int posisi = binary_search(indexed_kalimat, cari);
    if (posisi != -1) {
        cout << "Huruf '" << cari << "' ditemukan pada posisi asli: " << posisi << endl;
    } else {
        cout << "Huruf '" << cari << "' tidak ditemukan." << endl;
    }
    
    return 0;
}
```

#### Output

#### Deskripsi Program


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

#### Source Code
```C++
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Fungsi untuk mencari huruf vokal dalam kalimat
int hitungVokal(const string& kalimat, string& hurufVokalDitemukan) {
    int jumlahVokal = 0;
    string vokal = "aeiouAEIOU";
    unordered_set<char> hurufVokalSet; // Set untuk menyimpan huruf vokal yang ditemukan
    
    for (char c : kalimat) {
        // Linear search untuk memeriksa apakah karakter adalah huruf vokal
        for (char v : vokal) {
            if (c == v) {
                jumlahVokal++;
                hurufVokalSet.insert(tolower(c)); // Menyimpan huruf vokal yang ditemukan
                break; // Jika ditemukan, lanjut ke karakter berikutnya dalam kalimat
            }
        }
    }
    
    // Mengkonversi set ke dalam string untuk ditampilkan
    for (char vokalDitemukan : hurufVokalSet) {
        hurufVokalDitemukan += vokalDitemukan;
    }
    
    return jumlahVokal;
}

int main() {
    string kalimat;
    string hurufVokalDitemukan; // String untuk menyimpan huruf vokal yang ditemukan

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung jumlah huruf vokal dan mendapatkan huruf vokal yang ditemukan
    int jumlahVokal = hitungVokal(kalimat, hurufVokalDitemukan);

    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal << endl;
    cout << "Huruf vokal yang ditemukan: " << hurufVokalDitemukan << endl;

    return 0;
}
```

#### Output

#### Deskripsi Program

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

#### Source Code
```C++
#include <iostream>
#include <vector>
#include <utility> // Untuk std::pair

using namespace std;

// Fungsi untuk menghitung berapa banyak angka 4 dalam array menggunakan Sequential Search
int hitungAngkaEmpat(const vector<int>& data, vector<pair<int, int>>& urutanAngkaEmpat) {
    int jumlahEmpat = 0;
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == 4) {
            jumlahEmpat++;
            urutanAngkaEmpat.push_back(make_pair(data[i], i)); // Menyimpan angka 4 beserta posisinya
        }
    }
    
    return jumlahEmpat;
}

int main() {
    // Data yang diberikan
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    vector<pair<int, int>> urutanAngkaEmpat;

    // Menghitung jumlah angka 4 dan mendapatkan urutan serta posisi angka 4
    int jumlahEmpat = hitungAngkaEmpat(data, urutanAngkaEmpat);

    // Menampilkan pesan "Menghitung angka 4" beserta data
    cout << "Menghitung angka 4\nData: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Menampilkan hasil jumlah angka 4
    cout << "Jumlah angka 4 dalam data adalah: " << jumlahEmpat << endl;

    // Menampilkan urutan angka 4 dan posisinya
    cout << "Urutan angka 4 dalam data beserta posisinya: ";
    for (auto p : urutanAngkaEmpat) {
        cout << p.first << " (posisi: " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
```

#### Output

#### Deskripsi Program

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 


## Referensi
[1] E Erkamim, Abdurrohim, S Yuliyanti, dkk. "Buku Ajar Algoritma dan Struktur Data". Buku Cetak Informatika. Sonpedia Publishing Indonesia.(2024). </br>
[2] M Melladia, G Efendi, dkk. "Algoritma dan Struktur Data dengan Pemrograman Pascal dan Phyton". Buku Cetak. (2024).</br>
[3] A Zein, ES Erina. "Algoritma dan Struktur Data". Repository Unpam. Informatika. (2022). </br>
[4] Y Kurniawan. "Praktikum Struktur Data". Repository Unpam. Informatika. (2021) </br>
[5] Karumanchi, N. "Data Structures and algorithms made easy: Concepts problem, interview question". CareerMonk Publication. (2016). </br>
