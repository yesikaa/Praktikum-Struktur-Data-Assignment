# <h1 align="center">Laporan Praktikum Modul Queue	</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">2311102195</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Mahasiswa mampu menjelaskan definisi dan konsep dari double queue
2. Mahasiswa mampu menerapkan operasi tambah, menghapus pada queue
3. Mahasiswa mampu menerapkan operasi tampil data pada queue
```
## Dasar Teori
<p style="text-align: justify; font-size: 12px;">
Queue atau biasa disebut sebagai antrian merupakan kumpulan elemen dengan penyisipan dan penghapusan elemen yang dilakukan dari sisi yang berbeda [1]. Queue sendiri merupakan sebuah struktud data linear[2]. Konsepnya hampir sama dengan stack namun berbeda dengan stack, queue ini memiliki operasi penambahan dan penghapusan pada awal data[2].</br>

Pada queue ini memiliki konsep LIFO (Last In First Out). Pada saat menempatkan elemen pada ujung (tail) dari queue disebut dengan enqueue . Pada saat memindahkan elemen dari kepala (head) kedalam queue disebut dengan dequeue.. Karakteristik penting dari queue adalah:</br>
a. Element antrian yaitu item-item data yang terdapat di elemen antrian</br>
b. Front (element terdepan di antrian)</br>
c. Rear (element terakhir di antrian)</br>
d. Jumlah elemen pada antrian (Count)</br>
e. Status antrian</br>

Kondisi antrian yang menjadi perhatian adalah :</br>
a. Penuh : Bila elemen pada antrian mencapai kapasitas maksimum antrian.
Pada kondisi ini, tidak mungkin dilakukan penambahan ke antrian.
Penambahan elemen menyebabkan kondisi kesalahan Overflow.</br>
b. Kosong : Bila elemen pada antrian mencapai kapasitas maksimum antrian.
Pada kondisi ini, tidak mungkin dilakukan penambahan ke antrian.
Penambahan elemen menyebabkan kondisi kesalahan Overflow.[3]</br>

Pada queue sendiri memiliki operasi antrian. Beberapa operasi antrian adalah sebagai berikut:</br>
a. initializeQueue — Menginisialisasi antrian ke keadaan kosong.</br>
b. isEmptyQueue — Menentukan apakah antrian kosong. Jika antri kosong, ini mengembalikan nilai true; jika tidak, itu mengembalikan nilai salah.</br>
c. isFullQueue — Menentukan apakah antrian penuh. Jika antriannya full, ini mengembalikan nilai true; jika tidak, itu mengembalikan nilai salah.</br>
d. front — Mengembalikan bagian depan, yaitu elemen pertama antrean. </br>
e. back — Mengembalikan elemen terakhir dari antrian. Sebelum operasi ini, antrian harus ada dan tidak boleh kosong.</br>
f. addQueue — Menambahkan elemen baru ke belakang antrian. Sebelum operasi ini, antrian harus ada dan tidak boleh penuh.</br>
g. deleteQueue — Menghapus elemen depan dari antrian. Sebelum operasi ini, antrian harus ada dan tidak boleh kosong.</br>
[4].</br>

Implementasi queue dapat dilakukan dengan menggunakan array atau linked list. Struktur data queue terdiri dari dua pointer yaitu front dan rear. Front/head adalah pointer ke elemen pertama dalam queue dan rear/tail/back adalah pointer ke elemen terakhir dalam queue.</br>
![DT](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7b8b1cb3-7686-4e54-b0fa-e379ec5d4b17)
[5]</br>

Untuk implementasi queue dengan array kita perlu memutuskan berapa banyak variabel anggota yang dibutuhkan untuk mengimplementasikan antrian.Tentu saja, kita memerlukan array untuk menyimpan elemen antrian, variabel queueFront dan queueRear untuk melacak elemen pertama dan terakhir dari antrian, dan variabel maxQueueSize untuk menentukan ukuran maksimum antrian. Jadi, kita membutuhkan setidaknya empat variabel anggota[4].</br>


## GUIDED

### Contoh Penggunaan Queue

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() 
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) 
    {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() 
{ // Antriannya kosong atau tidak
    if (back == 0) 
    {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) 
{ // Fungsi menambahkan antrian
    if (isFull()) 
    {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) 
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() 
{ // Fungsi mengurangi antrian
    if (isEmpty()) 
    {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
        queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() 
{ // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) 
    {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() 
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] <<

endl;

        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() 
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
#### Output
![g-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/67ebf565-b7fd-4e89-ad03-6e90243dc4bc)

#### Deskripsi
<p style="text-align: justify; font-size: 12px;">
Program ini mengimplementasikan konsep antrian (queue) menggunakan array dengan kapasitas tetap untuk menyimpan data berupa string. Antrian ini memiliki kapasitas maksimal lima elemen, dengan dua variabel penanda, `front` dan `back`, untuk melacak elemen pertama dan terakhir dalam antrian. Fungsi `isFull` memeriksa apakah antrian sudah penuh, sementara `isEmpty` memeriksa apakah antrian kosong. Fungsi `enqueueAntrian` menambahkan elemen baru ke antrian; jika antrian penuh, fungsi ini menampilkan pesan "Antrian penuh". Jika antrian kosong, elemen baru ditempatkan di indeks pertama, dan penanda `front` dan `back` diinkrementasi. Jika tidak, elemen baru ditambahkan ke indeks `back`, yang kemudian diinkrementasi. Fungsi `dequeueAntrian` menghapus elemen dari depan antrian. Jika antrian kosong, fungsi ini menampilkan pesan "Antrian kosong". Jika tidak, elemen depan dihapus dan semua elemen setelahnya digeser ke kiri, mengurangi nilai `back`. Fungsi `countQueue` mengembalikan jumlah elemen dalam antrian dengan mengembalikan nilai `back`. Fungsi `clearQueue` menghapus semua elemen dalam antrian, mengatur nilai `back` dan `front` ke nol, dan mengosongkan semua elemen dalam array. Fungsi `viewQueue` menampilkan isi antrian, menunjukkan elemen yang ada atau "(kosong)" jika tidak ada elemen. Dalam fungsi utama, dua elemen ("Andi" dan "Maya") ditambahkan ke antrian dan isi antrian ditampilkan. Program kemudian menghitung dan menampilkan jumlah elemen dalam antrian, menghapus satu elemen, menampilkan kembali isi dan jumlah elemen antrian, dan akhirnya menghapus semua elemen, menampilkan kondisi antrian yang kosong.</br></p>

## UNGUIDED
### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list
#### Source Code
```C++
// Yesika Widiyani
// 2311102195

#include <iostream>

using namespace std;

//Struktur node untuk linked list
struct Node {
    string data;
    Node* next;
};

//Pointer untuk front dan back dari queue
Node* front = nullptr;
Node* back = nullptr;

//Fungsi mengecek apakah queue penuh
bool isFull()
{
    return false; // Linked list tidak pernah penuh (bergantung pada memori)
}

//Fungsi mengecek apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

//Fungsi menambahkan elemen ke dalam queue
void enqueueAntrian(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if(isEmpty()) 
    {
        front = back = newNode;
    } else
    {
        back->next = newNode;
        back = newNode;
    }
}

//Fungsi menghapus elemen dari queue
void dequeueAntrian()
{
    if(isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    } else{
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            back = nullptr;
        }
    }
}

//Fungsi menghitung jumlah elemen dalam queue
int countQueue() 
{
    int count = 0;
    Node* current = front;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi menghapus semua elemen dalam queue
void clearQueue() 
{
    while (!isEmpty()) 
    {
        dequeueAntrian();
    }
}

// Fungsi melihat elemen-elemen dalam queue
void viewQueue() 
{
    cout << "Data antrian teller:" << endl;
    Node* current = front;
    int index = 1;
    while (current != nullptr) 
    {
        cout << index << ". " << current->data << endl;
        current = current->next;
        index++;
    }
    if (index == 1) 
    {
        cout << "Antrian kosong" << endl;
    }
}

// Fungsi utama untuk menjalankan contoh penggunaan
int main() 
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    cout << "\n" << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    cout << "\n" << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    cout << "\n" << endl;    clearQueue();

    return 0;
}
```

#### Output
![un-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/8e7633ee-1d85-42b3-826f-2e34b5152081)

#### Deskripsi Program
Program tersebut mengimplementasikan konsep queue menggunakan linked list. Struktur node `Node` digunakan untuk menyimpan elemen dalam antrian, dengan setiap node memiliki atribut `data` untuk menyimpan nilai dan pointer `next` untuk menunjuk ke node berikutnya. Program ini menggunakan dua pointer, `front` dan `back`, untuk melacak elemen pertama dan terakhir dalam antrian. Fungsi `isFull` mengembalikan `false` karena linked list tidak memiliki batas kapasitas tetap, bergantung pada memori yang tersedia. Fungsi `isEmpty` mengecek apakah antrian kosong dengan memeriksa apakah `front` bernilai `nullptr`.</br>

Fungsi `enqueueAntrian` menambahkan elemen baru ke antrian dengan membuat node baru dan menambahkannya ke belakang antrian. Jika antrian kosong, node baru menjadi `front` dan `back`. Jika tidak, node baru ditambahkan setelah node terakhir, dan `back` diperbarui untuk menunjuk ke node baru. Fungsi `dequeueAntrian` menghapus elemen dari depan antrian. Jika antrian kosong, ditampilkan pesan "Antrian Kosong". Jika tidak, elemen depan dihapus, dan `front` diperbarui untuk menunjuk ke elemen berikutnya. Jika setelah penghapusan antrian menjadi kosong, `back` diatur ke `nullptr`.</br>

Fungsi `countQueue` menghitung jumlah elemen dalam antrian dengan melakukan iterasi melalui seluruh linked list, menghitung setiap node. Fungsi `clearQueue` menghapus semua elemen dalam antrian dengan memanggil `dequeueAntrian` berulang kali hingga antrian kosong. Fungsi `viewQueue` menampilkan semua elemen dalam antrian. Jika antrian kosong, ditampilkan pesan "Antrian kosong". Fungsi `main` menunjukkan contoh penggunaan antrian dengan menambahkan dua elemen ("Andi" dan "Maya"), menampilkan isi antrian, menghitung dan menampilkan jumlah elemen, menghapus satu elemen, dan akhirnya mengosongkan antrian serta menampilkan kembali isi dan jumlah elemen setelah setiap operasi.</br>

Cara program tersebut bekerja yaitu :
1. **Menambahkan Elemen ke Antrian (enqueue):**
Fungsi `enqueueAntrian` dipanggil untuk menambahkan elemen "Andi" dan "Maya" ke antrian. Jika antrian kosong, elemen pertama menjadi `front` dan `back`. Elemen berikutnya ditambahkan ke belakang dan `back` diperbarui.</br>
2. **Menampilkan Isi Antrian:**
Fungsi `viewQueue` dipanggil untuk menampilkan semua elemen dalam antrian. Elemen ditampilkan bersama dengan indeksnya.</br>
3. **Menghitung Jumlah Elemen dalam Antrian:**
Fungsi `countQueue` dipanggil untuk menghitung jumlah elemen dalam antrian, dilakukan dengan iterasi melalui linked list.</br>
5. **Menghapus Elemen dari Antrian (dequeue):**
Fungsi `dequeueAntrian` dipanggil untuk menghapus elemen dari depan antrian. Elemen depan dihapus dan `front` diperbarui ke elemen berikutnya. Jika antrian menjadi kosong, `back` diatur ke `nullptr`.</br>
6. **Menghapus Semua Elemen dalam Antrian (clear):**
Fungsi `clearQueue` dipanggil untuk menghapus semua elemen dalam antrian, dilakukan dengan memanggil `dequeueAntrian` hingga antrian kosong.</br>
7. **Menampilkan dan Menghitung Ulang Antrian:**
Setelah setiap operasi (enqueue, dequeue, dan clear), fungsi `viewQueue` dan `countQueue` dipanggil untuk menampilkan isi antrian dan jumlah elemen yang tersisa.</br>

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

#### Source Code
```C++
//Yesika Widiyani
// 2311102195

#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan data mahasiswa dalam queue
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Kelas Queue untuk mengelola operasi queue
class Queue {
private:
    Node* front; 
    Node* back;  

public:
    // Konstruktor untuk inisialisasi queue
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    // Fungsi untuk menambahkan data mahasiswa ke dalam queue
    void enqueue(string nama, string nim) {
        Node* newNode = new Node; 
        newNode->nama = nama;     
        newNode->nim = nim;       
        newNode->next = nullptr;  
        
        if (back == nullptr) {   
            front = newNode;
            back = newNode;
        } else {                  
            back->next = newNode;
            back = newNode;
        }
    }

    // Fungsi untuk menghapus data mahasiswa dari depan queue
    pair<string, string> dequeue() {
        if (front == nullptr) { // Jika queue kosong
            return make_pair("", "");
        }
        string nama = front->nama;
        string nim = front->nim;
        Node* temp = front;
        front = front->next;
        
        if (front == nullptr) { // Jika queue menjadi kosong setelah dequeue
            back = nullptr;
        }
        delete temp;           
        return make_pair(nama, nim);
    }

    // Fungsi untuk mengecek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Fungsi untuk menghapus semua elemen dalam queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Fungsi untuk mencetak semua elemen dalam queue
    void print() {
        if (front == nullptr) {
            cout << "Queue kosong" << endl;
        } else {
            int i = 1;
            Node* current = front;
            while (current != nullptr) {
                cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
                i++;
            }
            cout << endl;
        }
    }
};

// Fungsi utama untuk menjalankan program
int main() 
{
    Queue queue; 
    int choice; 

    while (true) {
        // Menampilkan menu
        cout << ">>>>>>>>>>M E N U<<<<<<<<<<\n"
             << "1. Tambah data\n"
             << "2. Hapus satu data\n"
             << "3. Reset data\n"
             << "4. Tampilkan data\n"
             << "5. Keluar\n"
             << "Masukkan Pilihan Anda: ";
        cin >> choice;
        cin.ignore(); // Membersihkan newline(\n) yang masih tersisa di buffer

        // Switch case untuk pilihan menu
        switch (choice) {
        case 1: 
        {
            string nama, nim;
            cout << "Masukkan data baru:\n";
            cout << "Nama: ";
            getline(cin, nama);
            cout << "NIM: ";
            getline(cin, nim);
            queue.enqueue(nama, nim); // Menambahkan data ke queue
            break;
        }
        case 2: 
        {
            pair<string, string> data = queue.dequeue(); // Menghapus data dari queue
            if (data.first != "") {
                cout << "Data yang dihapus: Nama: " << data.first << ", NIM: " << data.second << endl;
            } else {
                cout << "Queue kosong" << endl;
            }
            break;
        }
        case 3: 
        {
            queue.clear(); // Menghapus semua data dari queue
            cout << "Data direset" << endl;
            break;
        }
        case 4: 
        {
            cout << "Isi queue:\n";
            queue.print(); // Mencetak semua data dalam queue
            break;
        }
        case 5: 
        {
            return 0; // Keluar dari program
        }
        default: {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    }
    return 0;
}
```

#### Output
##### Output Program dan tampilan ketika User memilih menu 1
![un-2-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/f93d73dc-db7d-4d93-a029-6ab630c70a8f)

##### Output ketika User memilih menu 2
![un-2-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/0562283c-22b2-4c40-b317-f7b206df011b)

##### Output ketika User memilih menu 3
![un-2-3](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/c831cdbc-c151-4d67-b51f-cb1312c1ed9f)

##### Output ketika User memilih menu 4 sebelum dilakukan riset data (menu 3)
![un-2-4](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/180df9d7-ecb6-4aac-b10f-6e0b1f9c757c)

##### Output ketika User memilih menu 4 setelah dilakukan riset data (menu 3)
![un-2-4-kosong](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/c03514e5-b9f8-4196-9359-39fd55ec05b1)

##### Output ketika User memilih menu 5 (keluar program)
![un-2-5](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/f84d5208-aaba-425b-9c2a-aa79ea519db4)

#### Deskripsi Program
Program tersebut mengimplementasikan konsep queue menggunakan linked list untuk menyimpan data mahasiswa, yaitu nama dan NIM. Program ini mencakup struktur `Node` untuk merepresentasikan setiap elemen dalam queue, dengan atribut `nama`, `nim`, dan pointer `next` yang menunjuk ke node berikutnya. Kelas `Queue` menyediakan fungsi-fungsi untuk mengelola operasi queue, termasuk menambah data ke antrian (enqueue), menghapus data dari antrian (dequeue), mengecek apakah antrian kosong (isEmpty), menghapus semua elemen dalam antrian (clear), dan mencetak semua elemen dalam antrian (print).</br>

Fungsi `enqueue` menambahkan data mahasiswa baru ke belakang antrian. Jika antrian kosong, node baru menjadi elemen pertama (`front`) dan terakhir (`back`). Jika tidak, node baru ditambahkan setelah node terakhir, dan `back` diperbarui untuk menunjuk ke node baru. Fungsi `dequeue` menghapus elemen dari depan antrian. Jika antrian kosong, fungsi ini mengembalikan pasangan string kosong. Jika tidak, fungsi ini menghapus node depan dan mengembalikan data mahasiswa yang dihapus. Jika antrian menjadi kosong setelah penghapusan, `back` diatur ke `nullptr`.</br>

Fungsi `isEmpty` mengembalikan `true` jika antrian kosong dan `false` jika ada elemen dalam antrian. Fungsi `clear` menghapus semua elemen dalam antrian dengan memanggil fungsi `dequeue` berulang kali hingga antrian kosong. Fungsi `print` mencetak semua elemen dalam antrian. Jika antrian kosong, ditampilkan pesan "Queue kosong". Jika tidak, semua elemen dalam antrian ditampilkan beserta indeksnya.</br>

Cara kerja program diatas adalah :</br>
1. **Menambahkan Data Mahasiswa ke Antrian:**
Pengguna memilih opsi "Tambah data" dari menu. Program meminta pengguna memasukkan nama dan NIM mahasiswa. Data ini kemudian ditambahkan ke antrian menggunakan fungsi `enqueue`.</br>
2. **Menghapus Data Mahasiswa dari Antrian:**
Pengguna memilih opsi "Hapus satu data" dari menu. Fungsi `dequeue` dipanggil untuk menghapus data mahasiswa dari depan antrian. Jika antrian tidak kosong, data mahasiswa yang dihapus ditampilkan. Jika antrian kosong, ditampilkan pesan "Queue kosong".</br>
3. **Menghapus Semua Data dalam Antrian:**
Pengguna memilih opsi "Reset data" dari menu. Fungsi `clear` dipanggil untuk menghapus semua elemen dalam antrian, sehingga antrian menjadi kosong.</br>
4. **Menampilkan Data dalam Antrian:**
Pengguna memilih opsi "Tampilkan data" dari menu. Fungsi `print` dipanggil untuk menampilkan semua elemen dalam antrian. Jika antrian kosong, ditampilkan pesan "Queue kosong". Jika tidak, setiap elemen dalam antrian ditampilkan beserta indeksnya.</br>
5. **Keluar dari Program:**
Pengguna memilih opsi "Keluar" dari menu untuk menghentikan program.</br>

Program ini menyediakan antarmuka interaktif bagi pengguna untuk menambah, menghapus, mengosongkan, dan menampilkan data mahasiswa dalam antrian, memanfaatkan linked list untuk mengelola data secara dinamis tanpa batasan kapasitas tetap.</br>

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Dari peraktikum kali ini, kita telah mempelajari dan mengimplementasikan konsep struktur data queue menggunakan dua pendekatan yang berbeda, yaitu array dan linked list. </br>

Queue adalah struktur data linear yang mengikuti prinsip FIFO (First In First Out), di mana elemen pertama yang masuk adalah elemen pertama yang keluar. Queue memiliki dua operasi utama yaitu enqueue (menambahkan elemen ke belakang antrian) dan dequeue (menghapus elemen dari depan antrian). Konsep ini sangat berguna dalam berbagai aplikasi seperti manajemen tugas, antrian pelanggan, dan penjadwalan.</br>

Dalam implementasi dengan array, kapasitas queue harus ditentukan di awal. Hal ini bisa menjadi keterbatasan jika ukuran antrian melebihi kapasitas yang telah ditentukan.Dalam operasi dasarnya pada Implementasi array melibatkan pengecekan penuh atau kosongnya antrian, penambahan elemen ke antrian, penghapusan elemen dari antrian, serta menampilkan dan menghapus semua elemen dalam antrian. Di sisi lain, implementasi dengan linked list lebih fleksibel karena tidak ada batasan kapasitas tetap dan memungkinkan penambahan dan penghapusan elemen secara dinamis. 

Contoh aplikasi queue dalam manajemen data mahasiswa memberikan gambaran praktis tentang bagaimana queue digunakan dalam situasi dunia nyata, sementara antarmuka interaktif memungkinkan pengguna untuk berinteraksi dengan antrian data dengan efisien. Dengan pemahaman dan implementasi yang tepat, seseorang dapat memilih pendekatan yang sesuai tergantung pada kebutuhan dan kompleksitas aplikasi yang sedang dikembangkan, sehingga memperkuat kemampuan dalam pengelolaan data menggunakan struktur data queue.</br>

## Referensi
[1] E Erkamim, Abdurrohim, S Yuliyanti, dkk. "Buku Ajar Algoritma dan Struktur Data". Buku Cetak Informatika. Sonpedia Publishing Indonesia.(2024). </br>
[2] M Melladia, G Efendi, dkk. "Algoritma dan Struktur Data dengan Pemrograman Pascal dan Phyton". Buku Cetak. (2024).</br>
[3] A Zein, ES Erina. "Algoritma dan Struktur Data". Repository Unpam. Informatika. (2022). </br>
[4] Y Kurniawan. "Praktikum Struktur Data". Repository Unpam. Informatika. (2021) </br>
[5] Karumanchi, N. "Data Structures and algorithms made easy: Concepts problem, interview question". CareerMonk Publication. (2016). </br>
