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
Pencarian   data   dalam   sebuah   list   merupakan aspek  dasar  dalam  dunia  komputasi[1].  Pencarian (Searching) sendiri merupakan sebuah proses menemukan suatu nilai tertentu pada kumpulan data. Kemudian untuk hasil dari pencarian tersebut merupakan salah satu dari tiga keadaan berikut, yaitu data ditemukan, data ditemukan lebih dari satu, atau data tidak ditemukan. Searching juga dapat dianggap sebagai proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau setiap index kolomnya dengan menggunakan teknik perulangan untuk melakukan pencarian data[2].</br>

Searching atau biasa di sebut sebagai mencari elemen tertentu merupakan operasi dasar yang juga memungkinkan manipulasi data dalam linked list, seperti penambahan, penghapusan, dan akses terhadap elemen-elemen didalamnya[3]. 

Umumnya algoritma searching dibagi menjadi 2 yaitu algoritma Sequential Search (Pencarian Beruntun) dan Algoritma binery search. </br>

**1. Algoritma Sequential Search</br>**
Algoritma pencarian yang paling sederhana yaitu   metode   pencarian   beruntun   (Sequential Search)  nama  lain  algoritma pencarian  beruntun adalah  pencarian  lurus  (linear  search).  Algoritma pencarian beruntun adalah proses membandingkan setiap elemen larik satu persatu secara berurutan, mulai  dari  elemen  pertama,  sampai  elemen  yang dicari ditemukan atau seluruh elemen sudah habis diperiksa.  (Munir  dan  Lidya,  2016:444)[4].

Adapun Proses   Algoritma   Sequential   Searching   adalah sebagai   berikut:   (1)   Pertama   data   melakukan perbandingan satu per satu secara berurutan dalam kumpulan  data  dengan  data  yang  dicari  sampai data  tersebut  ditemukan  atau  tidak  ditemukan.  (2) Pada  dasarnya,  pencarian  ini  hanya  melakukan pengulangan  data  dari  1  sampai  dengan  jumlah data  (n).  (3)  Setiap  pengulangan,  dibandingkan data  ke-i  dengan  data  yang  sedang  dicari.  (4) Apabila data sama dengan yang dicari, berarti data telah   berhasil   di   temukan.   Sebaliknya   apabila sampai  akhir  melakukan  pengulangan  tidak  ada data  yang  sama  dengan  yang  dicari,  berarti  data tidak ada yang ditemukan[4].

Metode sequential search dapat diterapkan untuk melakukan pencarian data baik pada array yang sudah terurut maupun yang belum terurut. Proses yang terjadi pada metode pencarian ini seperti tahapan berikut:
a. Menentukan data yang dicari.
b. Pada data yang tidak urut, pencarian akan membandingkan data yang dicari dengan data dalam array satu persatu mulai dari indeks pertama data[0] sampai index terakhir data[n-1],</br>
c. Jika data sudah urut, perbandingan antara data yang dicari dengan data dalam array cocok atau lebih besar dari data yang dicari maka proses pengurutan dihentikan.[5]. </br>

**2. Algoritma Binary Search**

Algoritma ini digunakan untuk kebutuhan pencarian dengan waktu yang cepat. Sebenarnya,  dalam  kehidupan  sehari-hari  kita sering  menerapkan  pencarian  bagi  dua.  Untuk mencari  kata  tertentu  di  dalam  kamus  kita  tidak membuka  kamus  itu  dari  halaman  awal  sampai halaman    akhir    satu    persatu,    namun    kita mencarinya    dengan    cara    membelah    atau membagi dua buku itu jika kata yang dicari tidak terletak di halaman pertemuan itu kita mencari lagi di belahan bagian kiri atau belahan bagian kanan dengan    cara    membagi    dua    belahan yang dimaksud  begitu  seterusnya  sampai  kata  yang dicari ditemukan hal ini hanya bisa dilakukan jika kata-kata  di  dalam  kamus  sudah  terurut.  (Munir dan Lidya, 2016:456)[4].</br>

Metode sequential search dapat diterapkan untuk melakukan pencarian data baik pada array yang sudah terurut maupun yang belum terurut. Proses yang terjadi pada metode pencarian ini seperti tahapan berikut:</br>
a. Menentukan data yang dicari.
b. Pada data yang tidak urut, pencarian akan membandingkan data yang dicari dengan data dalam array satu persatu mulai dari indeks pertama data[0] sampai index terakhir data[n-1], tetapi
c. Jika data sudah urut, perbandingan antara data yang dicari dengan data dalam array cocok atau lebih besar dari data yang dicari maka proses pengurutan dihentikan.[5].</br>

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
![g1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/dd2f165d-5a65-412f-a437-7f7881658348)

#### Deskripsi Program
Program tersebut merupakan program dalam bahasa C++ untuk mencari suatu nilai dalam sebuah array menggunakan algoritma Sequential Search (pencarian berurutan). Program akan mencari nilai tertentu dalam array, dan jika nilai tersebut ditemukan, program akan mengindikasikan bahwa nilai tersebut ada di dalam array serta menunjukkan indeks posisinya. Jika nilai tidak ditemukan, program akan menunjukkan bahwa pencarian tidak berhasil. </br>

Program ini bekerja dengan melakukan inisialisasi  deklarasi variable menggunakan array `arr` yang berisi angka `{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 14}`. Kemudian dengan variabel `cari` diinisialisasi dengan nilai 15, yang merupakan nilai yang ingin kita temukan dalam array. Variabel `ketemu` diinisialisasi dengan `false` untuk menunjukkan bahwa nilai yang dicari belum ditemukan. Panjang array dihitung dengan membagi ukuran total array dengan ukuran satu elemen array, menghasilkan panjang 12. Program kemudian melakukan iterasi melalui array menggunakan loop `for`. Dalam setiap iterasi, program membandingkan elemen saat ini `arr[i]` dengan nilai `cari`. Jika elemen tersebut sama dengan `cari`, variabel `ketemu` diatur ke `true`, dan loop dihentikan menggunakan `break`. Jika elemen tidak sama, loop melanjutkan ke elemen berikutnya. Setelah loop selesai, program mencetak panjang array. Kemudian, program memeriksa nilai `ketemu`. Jika `ketemu` adalah `true`, program mencetak nilai yang dicari beserta indeksnya. Jika `ketemu` adalah `false`, program mencetak bahwa nilai tersebut tidak ditemukan dalam array. Contoh outputnya adalah mencetak "Panjang Array: 12" diikuti dengan "15 Terdapat pada index ke-10" saat ditemukan. </br>

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
![g2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/36a30c3e-ec1f-45c6-bfde-19cd480bbbd4)

#### Deskripsi
Program tersebut merupakan implementasi dari algoritma sequential search dalam bahasa c++. Program bertujuan mencari nilai tertentu dalam sebuah array dan menampilkan hasil pencarian tersebut, menunjukkan apakah nilai yang dicari ditemukan dan pada indeks berapa nilai tersebut berada jika ditemukan.</br>

Cara kerja program tersebut adalah : </br>
1. Melakukan inisialisasi variabel yakni pada Array `data` berisi 10 elemen: `{9, 4, 1, 7, 5, 12, 4, 13, 4, 10}`. Nilai yang akan dicari adalah 10, disimpan dalam variabel `cari`. Variabel `ketemu` diinisialisasi dengan `false` untuk menandakan bahwa nilai belum ditemukan. </br>
2. Pencarian sequential dengan Loop `for` mengiterasi setiap elemen dalam array. Setiap elemen `data[i]` dibandingkan dengan cari. Jika ditemukan, ketemu diatur ke `true` dan loop dihentikan.
3. Kemudian untuk menampilkan hasil dari program ini program akan menampilkan pesan "Program Sequential Search Sederhana". Selanjutnya Array `data` dicetak. Jika nilai ditemukan, program mencetak nilai dan indeksnya. Jika tidak ditemukan, program mencetak pesan bahwa nilai tidak ditemukan.</br>

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
![g3](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/0c64392d-9cb7-451b-9509-e7c884b98dad)

#### Deskripsi
Program ini mengimplementasikan algoritma Binary Search dalam bahasa C++. Program dimulai dengan mendeklarasikan sebuah array berisi 7 elemen. Setelah pengguna memasukkan nilai yang ingin dicari, array akan diurutkan menggunakan algoritma Selection Sort. Kemudian, program menggunakan algoritma Binary Search untuk mencari nilai tersebut dalam array yang sudah diurutkan dan menampilkan hasil pencariannya.</br>

Cara kerja dari program tersebut adalah :
1. Inisialisasi Variabel, yaitu pada Array `arrayData` diinisialisasi dengan nilai `{1, 8, 2, 5, 4, 9, 7}`. Variabel `cari` digunakan untuk menyimpan nilai yang akan dicari, yang dimasukkan oleh pengguna.
2. Kemudian untuk menampilkan data awal program akan mencetak elemen-elemen `array arrayData` sebelum diurutkan.
3. Pengurutan Data (Selection Sort) pada Fungsi `selection_sort` mengurutkan elemen-elemen array `arrayData`. Dalam setiap iterasi, elemen terkecil dari sisa elemen array ditemukan dan ditukar dengan elemen saat ini.
4. Untuk menampilkan data setelah diurutkan program akan mencetak elemen - elemen array `arrayData` setelah diurutkan.
5. Untuk pencarian binary search sendiri pada Fungsi `binary_search` mencari nilai cari dalam array yang sudah diurutkan. Algoritma binary search bekerja dengan membagi array menjadi dua bagian dan mencari nilai tengah. Jika nilai tengah adalah nilai yang dicari, pencarian selesai. Jika tidak, algoritma terus mencari di setengah array yang relevan sampai nilai ditemukan atau array tidak bisa dibagi lagi. Hasil pencarian ditampilkan, menunjukkan apakah nilai ditemukan dan pada indeks ke berapa nilai tersebut berada, atau bahwa nilai tidak ditemukan. </br>

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
![un1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/f4eee539-36b2-49a1-ab4e-fa11494d3ee2)

#### Deskripsi Program
Program ini adalah implementasi pencarian huruf dalam sebuah kalimat menggunakan algoritma Binary Search dalam bahasa C++. Program ini menerima masukan kalimat dari pengguna dan huruf yang akan dicari. Kalimat tersebut diolah menjadi pasangan karakter dan indeks aslinya, kemudian diurutkan berdasarkan karakter. Algoritma Binary Search digunakan untuk mencari huruf dalam kalimat yang sudah diurutkan, dan hasilnya menunjukkan posisi asli huruf tersebut jika ditemukan.</br>

Cara Kerja Program tersbeut adalah :
1. Inisialisasi dan Masukan Pengguna pada program tersebut dibuat menerima input kalimat dari pengguna. Program juga menerima input huruf yang ingin dicari dari pengguna.
2. Program kemudian akan membuat vector pasangan yang berisi karakter dari kalimat dan indeks asli dari setiap karakter.
3. Semua karakter dalam kalimat dan huruf yang dicari diubah menjadi huruf kecil untuk memastikan pencarian tidak peka terhadap kapitalisasi.
4. Program mengurutkan vector pasangan berdasarkan karakter menggunakan sort.
5. Program menggunakan algoritma Binary Search untuk mencari huruf dalam vector yang sudah diurutkan. Jika huruf ditemukan, program mengembalikan dan mencetak posisi asli huruf tersebut. Jika huruf tidak ditemukan, program mencetak pesan bahwa huruf tidak ditemukan.</br>

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
![un2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/3408d067-02ba-4d0d-a7a6-1c76fbdb00b8)

#### Deskripsi Program
Program ini ditulis dalam bahasa C++ untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang diberikan oleh pengguna. Selain menghitung jumlah vokal, program juga mengidentifikasi dan mencetak huruf vokal apa saja yang ditemukan dalam kalimat tersebut. Huruf vokal yang dicari adalah 'a', 'e', 'i', 'o', 'u' baik huruf besar maupun kecil. </br>

Cara Kerja Program tersebut adalah :
1. Inisialisasi Variabel:
a. `string kalimat`: untuk menyimpan kalimat yang dimasukkan oleh pengguna.
b. `string hurufVokalDitemukan`: untuk menyimpan huruf vokal yang ditemukan.
c. `unordered_set<char> hurufVokalSet`: untuk menyimpan huruf vokal yang ditemukan tanpa duplikasi.
2. Program meminta pengguna memasukkan sebuah kalimat dan menyimpannya dalam variabel kalimat.
3. Menghitung Huruf Vokal dengan fungsi untuk mengiterasi setiap karakter dalam kalimat. Memeriksa apakah karakter tersebut merupakan huruf vokal dengan membandingkannya terhadap string vokal. Jika karakter adalah huruf vokal, jumlah vokal (jumlahVokal) ditambah satu dan huruf vokal tersebut ditambahkan ke hurufVokalSet (mengubahnya ke huruf kecil untuk menghindari duplikasi kapitalisasi).
4. Setelah semua huruf dalam kalimat diperiksa, isi hurufVokalSet dikonversi menjadi string hurufVokalDitemukan untuk memudahkan tampilan.
5. Selanjutnya program akan menampilkan hasil dengan mencetak jumlah huruf vokal yang ditemukan. Program juga mencetak huruf vokal apa saja yang ditemukan dalam kalimat.</br>

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
![un3](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/dbf5ab6e-e9d4-425e-b98f-f2f6bb4bc752)

#### Deskripsi Program
Program ini adalah implementasi pencarian angka 4 dalam sebuah array menggunakan algoritma Sequential Search dalam bahasa C++. Program ini menghitung berapa kali angka 4 muncul dalam array dan mencatat posisi setiap kemunculan angka 4. Hasilnya ditampilkan dalam format yang menunjukkan jumlah total angka 4 dan posisi masing-masing angka 4 dalam array.</br>

Cara Kerja Program tersebut adalah sebagai berikut :
1. Inisialisasi Variabel:
a. `vector<int> data`: array yang berisi data angka yang diberikan.
b. `vector<pair<int, int>> urutanAngkaEmpat`: vector untuk menyimpan pasangan angka 4 dan posisinya.
2. Fungsi hitungAngkaEmpat:
a. Input: `const vector<int>& data, vector<pair<int, int>>& urutanAngkaEmpat`.
b. Untuk prosesnya adalah Iterasi melalui setiap elemen dalam `data`. Jika elemen adalah angka 4, jumlah angka 4 (`jumlahEmpat`) ditambah.Pasangan angka 4 dan posisinya ditambahkan ke `urutanAngkaEmpat`.
c. Output: Mengembalikan jumlah total angka 4 yang ditemukan.
Menampilkan Data dan Hasil:
3. Program mencetak pesan "Menghitung angka 4" dan menampilkan isi `data`.
4. Program mencetak jumlah total angka 4 yang ditemukan dalam `data`.
5. Program mencetak urutan angka 4 beserta posisi masing-masing dalam `data`.

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Dari modul 8 ini dapat di tarik kesimpulan sebagai berikut :</br>
**1.Sequential Search:** </br>
a. Algoritma pencarian beruntun adalah metode paling sederhana di antara algoritma pencarian lainnya. Ini melibatkan membandingkan setiap elemen satu per satu dalam kumpulan data hingga nilai yang dicari ditemukan atau semua elemen telah diperiksa.
b. Metode ini efektif digunakan untuk mencari data dalam array baik yang sudah terurut maupun yang belum terurut.
c. Kelemahan utama dari sequential search adalah kompleksitas waktu yang linear, yaitu O(n), di mana n adalah jumlah elemen dalam kumpulan data.
</br>
    
**2. Binary Search:**</br>
a. Algoritma pencarian biner digunakan untuk mencari data dalam kumpulan data yang sudah terurut.
b. Algoritma ini bekerja dengan membagi kumpulan data menjadi dua bagian dan memeriksa elemen tengah. Jika nilai yang dicari kurang dari elemen tengah, pencarian dilanjutkan ke separuh kiri. Jika lebih besar, pencarian dilanjutkan ke separuh kanan.
c. Keuntungan utama dari binary search adalah kompleksitas waktu yang logaritmik, yaitu O(log n), di mana n adalah jumlah elemen dalam kumpulan data.

Praktikum yang telah dilakukan mengimplementasikan kedua algoritma tersebut dalam bahasa pemrograman C++. Sequential search digunakan untuk mencari sebuah nilai dalam sebuah array, sementara binary search digunakan untuk mencari sebuah nilai dalam array yang sudah diurutkan.</br>

Kesimpulannya, pemilihan algoritma pencarian yang tepat sangat tergantung pada sifat data yang diolah dan kebutuhan spesifik dari aplikasi yang sedang dikembangkan. Jika data sudah terurut, maka binary search merupakan pilihan yang lebih efisien. Namun, jika data tidak terurut atau hanya terdiri dari sedikit elemen, sequential search mungkin lebih cocok karena kesederhanaannya.</br>

## Referensi
[1] ErbaLutfina, Nur Inayati, Galuh Wilujeng Saraswati. "Analisis Perbandingan Kinerja Metode Rekursif dan Metode Iteratif dalam Algoritma Linear Search". Komputika: Jurnal Sistem Kompute. Volume 11. (2022). </br>
[2] Karumanchi, N. "Data Structures and algorithms made easy: Concepts problem, interview question". CareerMonk Publication. (2016). </br>
[3] Erkamim dkk. "Buku Ajar Algoritma dan Struktur Data". PT. Sonpedia Publishing Indonesia. (2024).</br>
[4] Nurul Imamah,Moch Ilham Bahari. "PERBANDINGAN ALGORITMA SEQUENTIAL SEARCH DAN ALGORITMA BINARY SEARCH PADA APLIKASI KAMUS BAHASA INDONESIA MENGGUNAKAN PHP DAN JQUERY". Jurnal Informatika –COMPUTING. Volume 08. (2021).</br>
[5] Tim Dosen Struktur Data. "BUKU AJAR STRUKTUR DATA". Prodi Informatika Fakultas Ilmu Komputer. (2015)
