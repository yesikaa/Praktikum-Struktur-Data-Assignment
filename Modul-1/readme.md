# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Mahasiswa dapat mempelajari tipe data primitif, abstrak, dan kolektif.
2. Mahasiswa dapat memahami pengaplikasian pada tools yang digunakan.
3. Mahasiswa mengaplikasikan berbagai tipe data pada bahasa pemrograman yang telah ditentukan.
```
## Dasar Teori
<div style="text-align: justify; font-size: 12px;"> 
Tipe data adalah sebuah tipe yang menandakan jenis data apa yang ingin disimpan dengan menyesuaikan kegunaan memori atau media penyimpanan. Data terdapat dalam berbagai bentuk seperti angka, huruf, karakter, dll. Oleh karena itu tipe data dibutuhkan untuk membuat variable yang akan mewakili data dari macam-macam jenis tipe data dalam pemrograman bahasa C++.
</div>

Adapun tipe data yang akan dipelajari, sebagai berikut :

**1. Tipe Data Primitif**
   
   Tipe data primitif merupakan tipe data bawaan yang dapat mendeklarsikan satu nilai pada waktu dan nilai tersebut dapat diubah melalui referensi dari jenis data non primitif. Terdapat beberapa contoh data primitif seperti : <br>
   **a. Int** -> tipe data yang digunakan untuk menyimpan bilangan bulat<br>
   **b. Float** -> tipe data yang digunakan untuk menyimpan bilangan desimal<br>
   **c. Char** -> tipe data yang digunakan untuk menyimpan huruf dan karakter<br>
   **d. Boolean** -> tipe data yang digunakan untuk menyimpan nilai boolean yang hanya memiliki nilai true dan false<br>
      
**2. Tipe Data Abstrak**

   Tipe data abstrak merupakan tipe data yang digunakan untuk mendeskripsikan sifat dan perilaku objek atau struktur data. Dalam tipe data ini biasanya dibuat dalam sebuah kelas (class), yang merupakan sebuah pengembangan dari sebuah struct dalam bahasa pemrograman C++.<br>
     
**3. Tipe Data Koleksi**

   Tipe data koleksi adalah tipe data dalam pemrograman yang digunakan untuk menyimpan kumpulan nilai atau objek yang serupa dalam satu variable atau struct data. tipe data ini biasa digunakan untuk menyimpan dan memanipulasi data yang berjumlah banyak dalam satu waktu.<br>
   Tipe data koleksi yang biasa digunakan dalam pemrograman diantaranya : <br>
   **a. Array :** struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama.<br>
   **b. Vector :** umumnya vector mirip seperti array yang digunakan untuk menyimpan data dalam bentuk elemen-elemen yang akan dialokasikan secara otomatis dan bersebelahan. fituk vector pada C++ meliputi elemen access, iterators, capacity, modifiers.<br>
   **c. Map :** truktur data dengan index yang memungkinkan untuk digunakan pada tipe data selain integer, pada map biasanya terdapat index khusus yang diberi nama "key".<br>

## Guided

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
//Main Program
int main ()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e.+,-,*,/
    cin >> op;
    //It allow user to enter the operands
    cin >> num1 >> num2;
    
    //Switch statement begins
    switch(op) 
    {
        //If user enter +
        case '+' :
            cout << num1 + num2;
            break;
        //If user enter -
        case '-' :
            cout << num1 - num2;
            break;
        //If user enter *
        case '*' :
            cout << num1 * num2;
            break;
        //If user enter /
        case '/' :
            cout << num1 / num2;
            break;
        //If the operator is other than +,-,* or /,
        //error message will display
        default:
            cout << "Error operator is not correct";
    } //Switch statement ends
    return 0;

}
```

#### Output
![SS-Guided-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/3f0f1d05-abc4-4dcb-bb23-6b35fdcb1285)

Program tersebut merupakan program kalkulator sederhana yang meminta pengguna untuk memasukkan operator berupa +,-,*, atau / dengan dua angka untk dioperasikan. Program akan memproses sebuah perintah menggunakan sebuah swicth statement untuk memilih operasi yang sesuai berdasarkan operator yang diinputkan oleh user. Program kemudian melakukan operasi dari bilangan dan operator untuk kemudian menampilkan hasil dari operasi tersebut.
<br>

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

//Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //Menggunakan Struct
    struct Mahasiswa mhs1, mhs2;
    //Mengisi nilai ke Struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // Mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```

#### Output
![SS-Guided-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/a67a574e-6476-4160-bcaa-f34d53bb5d82)

Program diatas merupakn sebuah program dalam bahasa C++ yang menggunakan struct untuk menampilkan data mahasiswa. Program ini memiliki dua variable mhs1 dan mhs2. Program tersebut akan mencetak informasi mengenai data mahasiswa menggunakan perintah printf (f) dengan format yang ditentukan. Output dari programtersebut akan menampilkan sebuah informasi mengenai data dua mahasiswa yang telah diinisialisasi sebelumnya.
<br>

### 3. Tipe Data Koleksi
```C++
#include <iostream>
using namespace std;
int main()
{
    //Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //Mencetak Array
    cout << "Isi array pertama :" << nilai[0] <<endl;
    cout << "Isi array kedua :" << nilai[1] <<endl;
    cout << "Isi array ketiga :" << nilai[2] <<endl;
    cout << "Isi array keempat :" << nilai[3] <<endl;
    cout << "Isi array kelima :" << nilai[4] <<endl;
    return 0;
}
```

#### Output
![SS-Guided-3](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/5e5d13ad-b897-48d2-a54b-16931f748ca8)

Program diatas merupakan program yang melakukan pendeklarasian dan inisialisasi array `nilai` dengan panjang 5 elemen dengan indeks pertama 0 dan indeks terakhirnya adalah 4. Elemen-elemen tersebut diisi dengan nilai tertentu dan mencetak nilai dari setiap elemen array yang telah diinisialisasi sebelumnya menggunakan pernyataan `cout`.
<br>

## Unguided

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

#### Source Code
```C++
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
```

#### Output
![SS-Unguided-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/a8f32f45-816f-43e6-965b-7934de1c9d66)

#### Deskripsi Program
Program tersebut merupakan program sederhana untuk menghitung luas dan keliling persegi panjang berdasarkan nilai yang diinputkan yang diinisialisasi dengan x sebagai nilai panjang, dan y sebagai nilai lebar. Pada program tersebut terdapat fungsi `MenghitungLuas` untuk menghitung Luas Persegi panjang berdasarkan statement yang diberikan sebelumnya, mengambil dua parameter `Panjang` dan `Lebar`. Kedua, terdapat fungsi `Menghitungkeliling` yang digunakan untuk menghitung keliling persegi panjang berdasarkan statement yang diberikan sebelumnya dan juga menggunakan parameter `Panjang` dan `Lebar`. Kedua fungsi tersebut akan melakukan proses berdasarkan rumus yang telah dideklarasikan sebelumnya untuk menemukan hasil yang akan ditampilkan. 

#### Kesimpulan Tipe Data Primitif
Berdasarkan contoh program tersebut dapat disimpulkan bawa tipe data primitif berguna untuk menyimpan nilai numerik yang diperlukan dalam perhitungan matematis. Program menggunakan tipe data primitif `float` untuk menyimpan nilai panjang, lebar, luas, dan keliling persegi panjang dan juga `int` untuk menyimpan nilai x dan y yang dimasukkan oleh user. Selain itu, cin dan cout juga merupakan fitur penting dalam bahasa C++ untuk memungkinkan user melakukan input dan mendapatkan hasil output dari program yang dijalankan.
<br>

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

#### Penjelasan fungsi Class dan Struct
Class dan Struct merupakan fitur dalam bahasa pemrograman yang digunakan untuk membuat tipe data baru yang terdiri dari beberapa jenis data atau variable. Terdapat beberapa perbedaan antara class dan struct, yakni :
1) Class<br>
   Class sendiri merupakan tipe data khusus dalam bahasa pemrograman yang dapat menyimpan data dan fungsi didalamnya. Class digunakan untuk mewakili objek yang terdiri dari beberapa properti (data) dan metode (fungsi) yang digunakan untuk memanipulasi data tersebut. Class dapat memiliki spesifikasi akses (public, private, protected) untuk mengatur aksesibilitas dari anggotanya.<br>
   
3) Struct
   Struct adalah sebuah fitur yang digunakan untuk menyimpan data, namun berbeda dengan class dalam hal aksesibilitas dan penggunaanya. Struct hanya dapat menyimpan data tanpa adanya fungsi yang terkait didalamnya. Selain itu, semua properti dalam struct dianggap sebagai public, yang berarti dalapt diakses langsung tanpa harus melalui metode.

#### Source Code
```C++
#include <iostream>
using namespace std;

// Struct untuk menampilkan data Anggota
struct Anggota
{
    string name;
    int angkatan;
};
// Class untuk menampilkan data divisi anggota
class Divisi {
    public : 
    string organisasi;
    int tahun;
    string divisi;
    
    //Menampilkan data Anggota
    void TampilkanData(){
        cout << "Organisasi :" << organisasi << endl;
        cout << "Tahun :" << tahun << endl;
        cout << "Divisi :" << divisi << endl;
    }
};

// Main Program
int main ()
{
    //Menggunakan struct Anggota
    Anggota mhs;
    mhs.name = "Yesika";
    mhs.angkatan = 23;
    cout << "Nama Anggota : " << mhs.name << endl;
    cout << "Angkatan : " << mhs.angkatan << endl;

    // Menggunakan Class Divisi
    Divisi agt;
    agt.organisasi = "Kepanitiaan Teknik Informatika";
    agt.tahun = 2023;
    agt.divisi = "Sekretaris";
    agt.TampilkanData();

return 0;

}
```

#### Output
![SS-Unguided-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/b465b46e-cb06-4bce-9edb-a2dafd2de62a)

#### Deskripsi Program
Progran tersebut merupakan program yang digunakan untuk menyimpan dan menampilkan data terstruktur yang menggunakan ilustrasi dari cara penggunaan class dan struct dalam bahasa C++.
Pada program tersebut struct digunakan untuk menyimpan data `Anggota` dengan atribut sederhana, dimana struct memiliki dua anggota yaitu `name` yang menyimpan nama anggota dengan tipe data string dan `angkatan` untuk menyimpan data tahun angkatan anggota dengan tipe data integer. Struct disini berfungsi untuk mengelompokkan data anggota terkait.
sementara class digunakan untuk menyimpan data `Divisi` untuk menyimpan data divisi anggota organisasi yang memiliki 3 anggota yaitu `organisasi` untuk menyimpan data organisasi dalam tipe data string, `tahun` untuk menyimpan data tahun bergabung dalam tipe data integer, dan `divisi` untuk menyimpan data divisi menggunakan tipe data string. Pada class ini memiliki method `TampilkanData()` bertujuan untuk menampilkan data divisi. 
Program akan menggunakan struct `Anggota` untuk menyimpan data anggota `Yesika`, kemudian menggunakan program class `Divisi` untuk menyimpan anggota divisi. Objek `Divisi` dengan nama `agt` yang diinisialisasi dengan nilai tertentu akan ditampilkan dengan metode `TampilkanData()` untuk hasil output yang akan ditampilkan

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

#### Source Code
```C++
#include <iostream>
#include <map>
using namespace std;

//Main Program
int main()
{
    map<string, string> NoHandphone;

    //Menambahkan informasi nomor handphone ke dalam map
    NoHandphone["Yesika"] = "878-5458-7496";
    NoHandphone["Anggi"] = "813-2580-6705";
    NoHandphone["Haura"] = "821-0427-2004";
    NoHandphone["Syamil"] = "878-1030-8932";
    NoHandphone["Okta"] = "896-4242-6232";
    NoHandphone["Defa"] = "812-9090-3012";
    NoHandphone["Kaza"] = "821-1616-6475";
    NoHandphone["Widiya"] = "821-2604-2509";
    NoHandphone["Mei"] = "896-5555-7675";
    NoHandphone["Amanda"] = "812-1314-5657";
    NoHandphone["Satria"] = "878-7777-4535";

    //Menampilkan informasi Nomor handphone
    cout << "Informasi Nomor Telephone : " << endl;
    for (const auto& entry : NoHandphone){
        cout << entry.first << ": " << entry.second << endl;
    }
    return 0;
}
```

#### Output
![SS-Unguided-3](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/ffb0c0be-6e32-47a2-a324-485cd03b9450)

Program diatas menggunakan fungsi map untuk membuat dan mengelola daftar nomor handphone menggunakan struct data map. Program mendeklarasikan objek map bernama `NoHandphone` yang menyimpan pasangan kunci-nilai dengan tipe data string, dimana kunci pada map adalah nama anggota, sedangkan nilai adalah nomor handphone. Selanjutnya program menambahkan informasi nomor handphone kedalam map dengan menggunakan sintaks `NoHandphone[nama_anggota] = nomor_telepon`. Setelah semua data dimasukkan ke dalam map, program menggunakan loop `for` untuk menampilkan informasi nomor handphone, dalam loop setiap pasangan akan di cetak sebagai hasil output.

#### Perbedaam Array dan Map
1. Array:
   - Array adalah kumpulan elemen-elemen data yang memiliki tipe yang sama dan disimpan secara berurutan di dalam memori.
   - Elemen-elemen dalam array diakses menggunakan indeks numerik, yang dimulai dari 0.
   - Ukuran array biasanya tetap dan harus ditentukan pada saat deklarasi.

2. Map:
   - Map adalah struktur data yang mengaitkan kunci unik dengan nilai tertentu. Map digunakan untuk menyimpan pasangan kunci-nilai, di mana setiap kunci hanya dapat muncul sekali dalam map.
   - Map memungkinkan pencarian dan penyisipan data berdasarkan kunci dengan kompleksitas waktu yang konstan.
   - Ukuran map tidak perlu ditentukan pada saat deklarasi dan bisa berubah seiring berjalannya program.

## Kesimpulan
Dalam praktikum ini, mempelajari tentang tipe data yang terdiri dari tiga jenis, yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi. Tipe data primitif merupakan tipe data yang dapat menyimpan satu nilai pada satu waktu dan nilainya tidak dapat berubah dengan cara tipe data non-primitif. Jika nilainya sama, maka tipe data primitif tersebut akan dianggap sama. Kemudian, tipe data abstrak adalah tipe data yang digunakan untuk menggambarkan karakteristik dan perilaku sebuah objek dan biasanya diimplementasikan dalam sebuah kelas. Kelas merupakan pengembangan dari sebuah struct dalam bahasa pemrograman C++. Sementara itu, tipe data koleksi adalah tipe data yang terdiri dari rangkaian data atau objek dengan indeks.
Praktikan dapat membuat program dengan menggunakan ketiga tipe data tersebut. Proses pembuatan program mengajarkan kepada Praktikan tentang ketelitian, ketekunan, dan active critical thinking dalam memecahkan masalah dan menyelesaikan program. Meskipun praktikan sudah berhasil membuat program yang dimaksudkan, namun masih diperlukan penemuan kode yang lebih ringkas untuk memperbaiki program yang telah dibuat

## Referensi
[1] Asisten Praktikum, "Modul 1-Tipe Data", Praktikum Struktur Data dan Algoritma, Learning ManagementSystem, 2024.<br>
[2] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.<br>
[3] Stroustrup, Bjarne. "The C++ Programming Language." Addison-Wesley Professional, 2013.











  





