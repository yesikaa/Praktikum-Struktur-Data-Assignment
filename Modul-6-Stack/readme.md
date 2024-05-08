# <h1 align="center">Laporan Praktikum Modul Stack	</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">2311102195</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Mahasiswa mampu memahami konsep stack pada struktur data dan algoritma
2. Mahasiswa mampu mengimplementasikan operasi-operasi pada stack
3. Mahasiswa mampu memecahkan permasalahan dengan solusi stack
```
## Dasar Teori
<p style="text-align: justify; font-size: 12px;">
Stack atau biasa disebut sebagai tumpukan adalah sebuah struktur data yang memungmkinkan penyisipan dan pengambilan data yang dilakukan dari satu ujung yang disebut puncak[1]. Stack sendiri dapat diartikan sebagai kumpulan elemen yang dapat ditambah atau dihapus dari gerbang yang sama, sehingga seolah-olah bertumpuk[2]. Stack mempunyai sifat LIFO (Last In First Out) [2]. </br>

Dalam sebuah antrian stack dikenal sebagai 2 operaso dasar yaitu menambah elemen baru yang akan diletakan dibelakang antrian dan menghapus elemen yang terletak dibagian depan antrian[1]. </br>

Operasi dasar terhadap stack tersebut disebut sebagai operasi Insert atau penyisipan (PUSH) dan operasi Delete atau penghapusan elemen (POP)[2].</br>

Tumpukan sama dengan array, tetapi tumpukan bersifat dinamis sedangkan array bersifat statis. Dalam array, pengaksesan data (penambahan/penghapusan data) dapat dilakukan pada sembarang elemen (dari depan, tengah maupun belakang). Tetapi pada tumpukan pengaksesan data hanya dapat dilakukan pada satu ujung saja. “Secara sederhana, tumpukan bisa diartikan sebagai suatu kumpulan data yang seolah-olah ada data yang diletakkan diatas data yang lain”[3]. Sebuah stack tidak melebihi batas maksimum banyaknya elemen array. Pada suatu saat, ukuran stack akan sama denganukuran array. Bila diteruskan menambah data, maka akan terjadi overflow[4].</br>

Operasi - operasi dasar yang dapat dilakukan terhadap stack adalah sebagai berikut[3] :</br>

MAKENULL(S) kosongkan stack S </br>
TOP(S) ambil elemen top stack </br>
POP(S) hapus elemen pada top stack </br>
PUSH(x,S) sisipkan elemen x pada top stack </br>
EMPTY(S) cek kekosongan stack pada S” (Slamet, 1990:30) </br>
Proses dalam stack dapat dilihat pada gambar 2.2. </br>

![stack](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/d4d0c71d-b2c5-45a9-99c1-5ce4acfefe58)

Beberapa fungsi dasar lainnya yang terlibat dalam proses stack secara umum, antara lain sebagai berikut[5],
a. Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling
atas atau ujung. </br>
b. Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.</br>
c. Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa menghapusnya.</br>
d. IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.</br>
e. IsFull (Penuh): Memeriksa apakah tumpukan penuh atau tidak (terutama pada implementasi tumpukan dengan kapasitas terbatas).</br>
f. Size (Ukuran): Mengembalikan jumlah elemen yang ada dalam tumpukan.</br>
g. Peek (Lihat): Melihat nilai atau elemen pada posisi tertentu dalam tumpukan tanpa menghapusnya.</br>
h. Clear (Hapus Semua): Mengosongkan atau menghapus semua elemen dari tumpukan.</br>
i. Search (Cari): Mencari keberadaan elemen tertentu dalam tumpukan.</br>

## GUIDED

### Contoh Penggunaan Stack

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}
bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = ' ';
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang dapat di lihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void chargeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang di cetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {

    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();

    cout << "\n" << endl;
    cout << "apakah data stack penuh? " << isFull() << endl;
    cout << "apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);

    popArrayBuku();

    cout << "banyaknya data = " << countStack() << endl;

    chargeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "Jumlah data setelah di hapus : " << top << endl;

    cetakArrayBuku();

    return 0;
}
```

#### Output
![g-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7777bb98-5134-454e-983f-5ba4f3986792)

#### Deskripsi
Kode program tersebut merupakan implementasi dari struktur data stack menggunakan array dalam bahasa C++. Program ini bertujuan untuk menyimpan data buku dan menyediakan fungsi-fungsi dasar dari stack, seperti push (menambahkan data), pop (menghapus data), peek (melihat data pada posisi tertentu), isEmpty (memeriksa apakah stack kosong), isFull (memeriksa apakah stack penuh), countStack (menghitung jumlah data), charge (mengganti data pada posisi tertentu), destroy (menghapus semua data), dan cetak (mencetak data).</br>

Cara kerja program ini sebagai berikut:</br>
a. Pada awalnya, array arrayBuku digunakan untuk menyimpan data buku, dan variabel top menunjukkan posisi teratas pada stack, yang pada awalnya berada pada indeks pertama (0).</br>
b. Fungsi isFull() digunakan untuk memeriksa apakah stack sudah penuh atau belum, sedangkan fungsi isEmpty() digunakan untuk memeriksa apakah stack kosong atau tidak.
Fungsi pushArrayBuku() digunakan untuk menambahkan buku ke dalam stack. Fungsi ini akan menampilkan pesan "Data telah penuh" jika stack sudah penuh.</br>
c. Fungsi popArrayBuku() digunakan untuk menghapus buku dari stack. Fungsi ini akan menampilkan pesan "Tidak ada data yang dihapus" jika stack kosong.</br>
d. Fungsi peekArrayBuku() digunakan untuk melihat buku pada posisi tertentu dalam stack. Fungsi ini akan menampilkan pesan "Tidak ada data yang dapat dilihat" jika stack kosong.</br>
e. Fungsi countStack() digunakan untuk menghitung jumlah buku dalam stack.
Fungsi chargeArrayBuku() digunakan untuk mengganti buku pada posisi tertentu dalam stack. Fungsi ini akan menampilkan pesan "Posisi melebihi data yang ada" jika posisi yang dimasukkan melebihi jumlah buku dalam stack.</br>
f. Fungsi destroyArrayBuku() digunakan untuk menghapus semua buku dari stack.</br>
g. Fungsi cetakArrayBuku() digunakan untuk mencetak semua buku dalam stack.</br>
h. Pada main(), beberapa buku ditambahkan ke dalam stack menggunakan fungsi pushArrayBuku().</br>
i. Kemudian, buku-buku dalam stack dicetak menggunakan fungsi cetakArrayBuku().
Dilakukan pengecekan apakah stack penuh atau kosong menggunakan fungsi isFull() dan isEmpty().</br>
j. Buku pada posisi tertentu dalam stack ditampilkan menggunakan fungsi peekArrayBuku().</br>
k. Salah satu buku dihapus dari stack menggunakan fungsi popArrayBuku().</br>
l. Jumlah buku dalam stack dihitung menggunakan fungsi countStack().</br>
m. Salah satu buku diganti dengan buku baru menggunakan fungsi chargeArrayBuku().</br>
n. Semua buku dalam stack dihapus menggunakan fungsi destroyArrayBuku().</br>
0. Akhirnya, jumlah buku dalam stack dan isi stack setelah dihapus dicetak lagi menggunakan fungsi countStack() dan cetakArrayBuku().</br>

## UNGUIDED
### 1. Buatlah program dalam bahasa C++ dengan stack, untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom atau tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. jelaskan pula bagaiamana cara kerjanya
</br>
Contoh:</br>
kalimat : ini </br>
kalimat tersebut adalah polindrom.</br>

kalimat : telkom</br>
kalimat tersebut tidak polindrom.</br>

#### Source Code
```C++
//Yesika Widiyani
// 2311102195

#include <iostream>
#include <stack>
#include <string>
#include <locale>

using namespace std;

//Fungsi Untuk mengabaikan spasi dan mengubah huruf agar tetap terbaca lowercase
string preprocess (string str) 
{
    string result = "";
    for (char c : str) 
    {
        if (isalpha(c))
            result += tolower(c);
    }
    return result;
}

bool isPolindrome(string str)
{
    stack<char> s;
    int len = str.length();

    // Menambah setengah karakter pertama ke stack
    for (int i = 0; i < len/2; ++i) 
    {
        s.push(str[i]);
    }

    //Mengecek apakah kalimat tersebut adalah polindrom atau tidak
    for (int i = (len+1)/2; i < len; ++i) 
    {
        if (str[i] != s.top()) 
        {
            return false;
        }
        s.pop();
    }
    return true;
} 

int main()
{
    string kalimat;
    cout << "Masukkan sebuah kalimat : " << endl;
    getline(cin, kalimat);

    string processed = preprocess(kalimat);

    if (isPolindrome(processed))
    {
        cout << "Kalimat tersebut merupakan kalimat polindrom." << endl;
    } 
    else
    {
        cout << "Kalimat tersebut bukan kalimat polindrom." << endl;
    }

    return 0;
}
```

#### Output
##### Contoh Output Kalimat Polindrom
![ug-1-pol](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/d6e8477f-ea73-415f-8c34-cb3e7c6d3498)

##### Contoh Output Kalimat Bukan Polindrom
![ug-1-bpol](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7b705f7f-e797-457c-b45f-9d2faed2f94f)

#### Deskripsi Program
Program tersebut adalah program C++ yang menggunakan stack untuk menentukan apakah sebuah kalimat adalah palindrom atau tidak. Program ini meminta pengguna untuk memasukkan sebuah kalimat. Kalimat tersebut kemudian diproses dengan menghapus spasi dan mengubah semua huruf menjadi lowercase agar program dapat mengabaikan spasi dan memperlakukan huruf besar dan kecil sama. Setelah itu, program menggunakan stack untuk membandingkan setengah bagian pertama dari kalimat dengan setengah bagian kedua. Jika kedua bagian tersebut sama ketika dibalik, maka kalimat tersebut dianggap palindrom dan program akan mencetak "Kalimat tersebut adalah palindrom.". Jika tidak, program akan mencetak "Kalimat tersebut bukan palindrom.".</br>

Cara kerja program ini adalah sebagai berikut:</br>

a. Program menerima input kalimat dari pengguna.</br>
b. Fungsi preprocess digunakan untuk menghapus spasi dan mengubah semua huruf menjadi `lowercase`.</br>
c. Fungsi `isPalindrome` menggunakan stack untuk memeriksa apakah kalimat tersebut adalah palindrom atau tidak.</br>
  - Setengah bagian pertama dari kalimat dimasukkan ke dalam stack.</br>
  - Kemudian, setengah bagian kedua dari kalimat dibandingkan dengan karakter yang di-`pop` dari stack.</br>
  - Jika ada karakter yang tidak cocok, maka kalimat tidak merupakan palindrom.</br>
  - Jika semua karakter cocok, kalimat dianggap palindrom.</br>
d. Output akan memberitahu pengguna apakah kalimat tersebut adalah palindrom atau tidak.</br>

### 2. Buatlah Program bahasa c++ , untuk melakukan pembalikan terhadap kalimat dengan menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat</br>

Contoh:

Kalimat : Telkom Purwokerto </br>
Hasil : otrekowruP mokleT</br>

#### Source Code
```C++
//Yesika Widiyani
// 2311102195

#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseSentence(const string& kalimat) 
    {
        stack <string> stack;
        stringstream r047(kalimat);
        string kata;

        // Memasukkan setiap kata (yang sudah dibalik) ke dalam stack
        while (r047 >> kata) 
        {
            reverse(kata.begin(), kata.end()); // Membalikkan kata
            stack.push(kata);
        }

        string reversedSentence;
        while (!stack.empty()) 
        {
            reversedSentence += stack.top();
            stack.pop();

            // Tambahkan spasi setelah kata kecuali untuk kata terakhir
            if (!stack.empty()) 
            {
                reversedSentence += " ";
            }
        }

        return reversedSentence;
    }

    int main()
    {
        string kalimat;
        cout << "Masukkan kalimat (minimal 3 kata): ";
        getline(cin, kalimat);
        string hasil = reverseSentence(kalimat);
        cout << "Kalimat Asli: " << kalimat << endl;
        cout << "Hasil Pembalikkan Kalimat: " << hasil << endl;
        return 0;
    }
```

#### Output
![ug-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/376f58b1-31c7-45d5-b9f0-961b109856e6)

#### Deskripsi Program
Program C++ di atas adalah program sederhana yang bertujuan untuk membalikkan urutan kata dari sebuah kalimat yang dimasukkan oleh pengguna. </br>
- Program ini menggunakan beberapa library standar C++, yaitu `<iostream>`, `<stack>`, `<sstream>`, dan `<algorithm>`.</br>
- Pengguna diminta untuk memasukkan sebuah kalimat (minimal 3 kata) melalui fungsi `getline(cin, kalimat)`.</br>
- Kalimat yang dimasukkan oleh pengguna kemudian diproses oleh fungsi `reverseSentence()` untuk membalikkan urutan kata-katanya.</br>
- Hasil pembalikan kalimat kemudian dicetak oleh program.</br>

Cara kerja program tersebut : </br>
- Pada fungsi `reverseSentence()`, kalimat yang dimasukkan oleh pengguna dibagi menjadi kata-kata menggunakan objek `stringstream`.</br>
- Setiap kata yang sudah dipisahkan dibalik urutannya menggunakan fungsi `reverse()`.</br>
- Kata-kata yang sudah dibalik urutannya kemudian dimasukkan ke dalam stack.</br>
- Selanjutnya, kata-kata dari stack diambil satu per satu dan digabungkan kembali untuk membentuk kalimat yang sudah dibalik urutannya.</br>
- Program mencetak kalimat asli yang dimasukkan oleh pengguna dan hasil pembalikan kalimat tersebut.</br>

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Dari materi praktikum yang telah dilakukan, kita dapat menyimpulkan beberapa hal sebagai berikut:</br>

**Pemahaman Konsep Stack**</br>
Mahasiswa telah memahami konsep dasar dari struktur data stack, seperti operasi-operasi dasar (PUSH, POP, PEEK), serta sifat Last In First Out (LIFO) yang dimiliki oleh stack. Stack merupakan struktur data yang penting dalam pemrograman karena dapat digunakan untuk menyelesaikan berbagai permasalahan, seperti pembalikan urutan kata, pengecekan palindrom, dan sebagainya.

**Implementasi Operasi Stack**</br>
Mahasiswa mampu mengimplementasikan operasi-operasi dasar pada stack menggunakan bahasa pemrograman C++, seperti PUSH, POP, PEEK, dan sebagainya. Implementasi operasi-operasi dasar pada stack merupakan langkah awal yang penting dalam memahami konsep dan penggunaan stack dalam pemrograman.</br>

**Penerapan Solusi Stack pada Permasalahan**</br>
Mahasiswa mampu menerapkan konsep stack untuk memecahkan permasalahan yang diberikan, seperti pembalikan urutan kata, pengecekan palindrom, dan sebagainya.Stack dapat digunakan sebagai solusi untuk berbagai permasalahan, terutama yang berkaitan dengan urutan atau antrian data.</br>

Dengan demikian, praktikum mengenai struktur data stack ini memberikan pemahaman yang cukup baik kepada mahasiswa tentang konsep dasar stack, implementasi operasi-operasi pada stack, serta penerapan solusi stack pada permasalahan yang diberikan. Hal ini menjadi dasar yang penting dalam memahami struktur data lainnya dan kemampuan pemrograman secara umum.
<div/>
  
## Referensi
[1] Anita Sindar RMS, ST., M.TI, "Struktur Data dan Algoritma dengan C++". Buku Cetak Informatika. CV.AA. Rizky.(2019). </br>
[2] Erkamim dkk. "Algoritma dan Struktur Data". Buku Ajar.(2024). </br>
[3] Wahyu. "Perancangan dan Pembuatan Program yang digunakan untuk konversi notasi prefix, infix, dan postfix serta simulasi stack dalam struktur data". Repository Universitas Dinamika. STIKOM. (2023). </br>
[4] Ema Utami. "Langkah Mudah Belajar Struktur Data Menggunakan C/C++". Buku Cetak Informatika. (2017). </br>
[5] Karumanchi, N. "Data Structures and algorithms made easy: Concepts problem, interview question". CareerMonk Publication. (2016). </br>



