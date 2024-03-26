![Unguided-2-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/46c9b98e-f539-4275-bb0a-4d56e97ebbee)# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">2311102195</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Mahasiswa memahami perbedaan konsep Single dan Double Linked List.
2. Mahasiswa mampu menerapkan Single dan Double Linked List ke dalam
pemrograman
```
## Dasar Teori
<p style="text-align: justify; font-size: 12px;">
Linked List adalah suatu simpul (node) yang dikaitkan dengan node yang lain dalam suatu urutan tertentu. Suatu node dapat berbentuk struktur atau class yang berisi data. Linked list dihubungkan secara linier dengan bantuan pointer[1]. Dengan menggunakan linked list memungkinkan pengguna untuk melakukan insert atau delete data dengan mengatur pointernya[2]. Linked list terdiri dari dua bagian, yaitu linked list biasa yang disebut single linked list, dan dua arah yang disebut sebagai double linked list.

a. Single Linked List
Single linked list merupakan linked list dimana struktur data sebuah node hanya memiliki satu tautan atas node berikutnya, dengan tiap-tiap node yang terdiri atas dua elemen integer dan elemen rujukan ke node selanjutnya[3].

b. Dougle Linked List 
Double linked list merupakan linked list yang menerapkan sebuah pointer baru, yaitu "prev" yang dapat digunakan untuk menggeser mundur selain pointer next. Keberadaan 2 pointer penunjuk (next dan prev) menjadikan Double Linked List menjadi lebih fleksibel dibandingkan Single Linked List, namun dengan mengorbankan adanya memori tambahan dengan adanya pointer tambahan tersebut[3].

  
## GUIDED

### 1. Program Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

#### Output
![Guided-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/d0f02124-d42d-4155-92c6-f4b11a09bd98)

Program diatas merupakan program implementasi dari single linked list non-circular dalam bahasa C++. Program ini memiliki beberapa fungsi untuk operasi dasar pada linked list seperti penambahan di depan, di belakang, di tengah, penghapusan di depan, di belakang, di tengah, serta pengubahan data pada node tertentu.</br>

Berikut adalah deskripsi singkat dari setiap fungsi dan alur program:

1. init(): Fungsi ini menginisialisasi pointer head dan tail linked list menjadi NULL.</br>
2. isEmpty(): Fungsi ini memeriksa apakah linked list kosong atau tidak. Mengembalikan nilai true jika linked list kosong, dan false jika tidak kosong.</br>
3. insertDepan(int nilai): Fungsi ini menambahkan node baru di depan linked list dengan nilai yang diberikan. Jika linked list kosong, maka node baru akan menjadi head dan tail. Jika tidak, node baru akan menjadi head dan next-nya akan menunjuk ke node sebelumnya head.</br>
4. insertBelakang(int nilai): Fungsi ini menambahkan node baru di belakang linked list dengan nilai yang diberikan. Jika linked list kosong, maka node baru akan menjadi head dan tail. Jika tidak, node baru akan menjadi tail dan next dari node sebelumnya tail akan menunjuk ke node baru.</br>
5. hitungList(): Fungsi ini menghitung jumlah node dalam linked list dan mengembalikan nilai jumlahnya.</br>
6. insertTengah(int data, int posisi): Fungsi ini menambahkan node baru di antara dua node pada posisi tertentu dalam linked list.</br>
7. hapusDepan(): Fungsi ini menghapus node pertama (head) dari linked list.</br>
8. hapusBelakang(): Fungsi ini menghapus node terakhir (tail) dari linked list.</br>
9. hapusTengah(int posisi): Fungsi ini menghapus node pada posisi tertentu dalam linked list.</br>
10. ubahDepan(int data), ubahTengah(int data, int posisi), ubahBelakang(int data): Fungsi-fungsi ini mengubah data pada node tertentu dalam linked list.</br>
11. clearList(): Fungsi ini menghapus semua node dalam linked list.</br>
12. tampil(): Fungsi ini menampilkan semua data yang ada dalam linked list.</br>
</br>

### 2. Program Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

#### Output
![Guided-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/3fd76090-de0f-4fb6-b7e8-3f5a011a50cf)

Program diatas merupakan sebuah program 
Program di atas merupakan implementasi dari Doubly Linked List menggunakan bahasa pemrograman C++. Berikut adalah deskripsi singkat dari program tersebut:
1. Kelas Node: Digunakan untuk merepresentasikan simpul (node) dalam Doubly Linked List. Setiap simpul memiliki tiga atribut: data (integer) untuk menyimpan nilai data, prev (pointer ke Node sebelumnya), dan next (pointer ke Node berikutnya).

2. Kelas DoublyLinkedList: Digunakan untuk mengelola Doubly Linked List. Kelas ini memiliki atribut head (pointer ke simpul pertama) dan tail (pointer ke simpul terakhir). Method-method yang dimiliki oleh kelas ini antara lain:

3. push(int data): Menambahkan simpul baru dengan nilai data tertentu di awal linked list.
pop(): Menghapus simpul pertama dari linked list.
update(int oldData, int newData): Mengupdate nilai data tertentu menjadi nilai baru.
deleteAll(): Menghapus seluruh simpul dalam linked list.
display(): Menampilkan seluruh data dalam linked list.
Fungsi main: Digunakan untuk mengatur alur program utama. Pengguna diberikan beberapa opsi menu, antara lain:
a. Menambahkan data ke linked list.
b. Menghapus data dari linked list.
c. Mengupdate data dalam linked list.
d. Menghapus seluruh data dalam linked list.
e. Menampilkan seluruh data dalam linked list.
f. Keluar dari program.
<br>


## UNGUIDED

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk
menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan
dari user. Lakukan operasi berikut:
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,
belakang atau tengah). Data pertama yang dimasukkan adalah
nama dan usia anda.
[Nama_anda] [Usia_anda]
John 		19
Jane 		20
Michael 	18
Yusuke 		19
Akechi 		20
Hoshino 	18
Karin 		18

b. Hapus data Akechi
c. Tambahkan data berikut diantara John dan Jane : Futaba 18
d. Tambahkan data berikut diawal : Igor 20
e. Ubah data Michael menjadi : Reyn 18
f. Tampilkan seluruh data

#### Source Code
```C++
//Nama : Yesika Widiyani
// NIM : 2311102195

#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node
{
    string nama;
    int usia;
    Node *next;
};

Node *head = NULL;

Node *cariNode(Node *head, string nama)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->nama == nama)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void insertAwal(string nama, int usia)
{
    Node *nodeBaru = new Node;
    nodeBaru->nama = nama;
    nodeBaru->usia = usia;
    nodeBaru->next = head;
    head = nodeBaru;
}

void insertSelanjutnya(string nama, int usia)
{
    Node *nodeBaru = new Node;
    nodeBaru->nama = nama;
    nodeBaru->usia = usia;
    nodeBaru->next = NULL;

    if (head == NULL)
    {
        head = nodeBaru;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void insertTengah(string nama, int usia, string namaSebelum)
{
    Node *nodeBaru = new Node;
    nodeBaru->nama = nama;
    nodeBaru->usia = usia;

    Node *temp = head;
    while (temp->nama != namaSebelum)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "Data dengan nama " << namaSebelum << " tidak ditemukan " << endl;
            return;
        }
    }
    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
}

// Fungsi untuk mengupdate data berdasarkan nama
void updateData(string nama, int usia, string newnama)
{
    Node *current = head;
    while (current != nullptr && current->nama != nama)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Node dengan nama " << nama << " tidak ditemukan!" << endl;
        return;
    }

    // current->nama = nama;
    current->usia = usia;
    current->nama = newnama;
}

// Fungsi untuk menghapus node berdasarkan nama
void deleteData(string nama)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong." << endl;
        return;
    }
    if (head->nama == nama)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus." << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->nama != nama)
    {
        temp = temp->next;
    }
    if (temp->next != nullptr)
    {
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Data berhasil dihapus." << endl;
    }
    else
    {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan seluruh data dalam linked list
void display()
{
    Node *temp = head;
    cout << "Data Mahasiswa:" << endl;
    while (temp != nullptr)
    {
        cout << "Nama: " << temp->nama << "\t"
             << "Usia: " << temp->usia << endl;
        temp = temp->next;
    }
};

int main()
{
    int choice, pilihan;
    string nama, namaSebelum, namaBaru, newnama;
    int usia;

    do
    {

        cout << "\nMenu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Update Data\n";
        cout << "3. Hapus Data\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                cout << "1. Insert Data Awal" << endl;
                cout << "2. Insert Data Selanjutnya" << endl;
                cout << "3. Insert Data Tengah" << endl;
                cout << "4. Kembali ke menu sebelumnya" << endl;
                cout << "Masukkan Pilihan : ";
                cin >> pilihan;
                switch (pilihan)
                {
                case 1:

                    cout << "Masukkan nama: ";
                    cin >> nama;
                    cout << "Masukkan usia: ";
                    cin >> usia;
                    insertAwal(nama, usia);
                    break;

                case 2:

                    cout << "Masukkan nama: ";
                    cin >> nama;
                    cout << "Masukkan usia: ";
                    cin >> usia;
                    insertSelanjutnya(nama, usia);
                    break;

                case 3:

                    cout << "Masukkan nama: ";
                    cin >> nama;
                    cout << "Masukkan usia: ";
                    cin >> usia;
                    cout << "Masukkan nama sebelum data baru: ";
                    cin >> namaSebelum;
                    insertTengah(nama, usia, namaSebelum);

                case 4:
                    cout << "Kembali ke menu utama" << endl;
                    break;

                default:
                    cout << "Pilihan tidak valid" << endl;
                    break;
                }
            } while (pilihan != 4);
            break;
        case 2:
            cout << "Masukkan nama yang akan diupdate: ";
            cin >> nama;
            cout << "Masukkan usia baru: ";
            cin >> usia;
            cout << "Masukkan nama baru: ";
            cin >> newnama;
            updateData(nama, usia, newnama);
            break;
        case 3:
            cout << "Masukkan nama yang akan dihapus: ";
            cin >> nama;
            deleteData(nama);
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Terima kasih telah menggunakan program.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (choice != 5);
    return 0;
}
```

#### Output
a. Masukkan data sesuai urutan.
![Unguided-1-a(1)](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/5c6acaab-1385-459a-88f5-97e553c2aae5)
![Unguided-1-a(2)](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/925ac8ac-efd7-42bb-9aca-5cf98f1f0389)

b. Hapus data Akechi
![Unguided-1-b](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/ce90be73-4e82-4295-9822-b4ad15e3d2e1)

c. Tambahkan data berikut diantara John dan Jane : Futaba 18
![Unguided-1-c](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7bc97387-5ebb-46ce-9476-08033e692011)

d. Tambahkan data berikut diawal : Igor 20
![Unguided-1-d](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/fde82efe-596f-498e-9e6e-cb82105203f9)

e. Ubah data Michael menjadi : Reyn 18
![Unguided-1-e](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/eb672c03-e8e3-4fc4-84fb-ac1a532f463a)

f. Tampilkan seluruh data
![Unguided-1-f](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/e8b356c3-5aee-403b-ab1a-19d9b6887762)

#### Deskripsi Program
Program di atas merupakan program untuk mengimplementasikan operasi-operasi dasar linked list. Program mulai mendefinisikan dengan `node` yang merepresentasikan simpul dalam linked list. Setiap simpul memiliki dua data: `nama` (string) dan `usia` (integer), serta pointer `next` yang menunjuk ke simpul berikutnya dalam linked list.erdapat variabel global `head` yang bertipe pointer `Node`, yang digunakan untuk menunjuk ke simpul pertama dalam linked list. Program menyediakan beberapa fungsi untuk mengelola linked list:</br>

`cariNode`: Digunakan untuk mencari simpul dengan nama tertentu dalam linked list.</br>
`insertAwal`: Menyisipkan simpul baru di awal linked list.</br>
`insertSelanjutnya`: Menyisipkan simpul baru di akhir linked list.</br>
`insertTengah`: Menyisipkan simpul baru di antara simpul-simpul tertentu dalam linked list.</br>
`updateData`: Mengupdate data (usia dan nama) dari simpul dengan nama tertentu.</br>
`deleteData`: Menghapus simpul dengan nama tertentu dari linked list.</br>
display: Menampilkan seluruh data (nama dan usia) dalam linked list.</br>


### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan
operasi untuk menambah data, menghapus, dan update di tengah / di
urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya
menampilkan Nama produk dan harga.
![ss-soal-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/052cfb02-1c3f-4b26-8bdc-09821e4b2ba3)
Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific</br>
2. Hapus produk wardah</br>
3. Update produk Hanasui menjadi Cleora dengan harga 55.000</br>
4. Tampilkan menu seperti dibawah ini</br>

Toko Skincare Purwokerto</br>
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
</br>
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
ini :
![ss-soal-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/60792a14-5ec4-4659-b9e2-680902ea8224)

#### Source Code
```C++
//Nama : Yesika Widiyani
//NIM : 2311102195

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

//Kelas untuk Doubly Linked List
class DoubleLinkedList {
private:
    Node* head; //Pointer ke Node Pertama
    Node* tail; //Pointer ke Node Terakhir
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    //Fungsi untuk menambahkan data di awal dan di akhir
    void tambahData(string namaProduk, int harga) {
        Node* newNode = new Node();
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            NewFunction(newNode);
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void NewFunction(Node *newNode)
    {
        tail->next = newNode;
    }

    //Fungsi untuk menghapus data pada node
    void hapusData(string namaProduk) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == namaProduk) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Data berhasil dihapus." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    //Fungsi untuk update data pada node
    void updateData(string namaProduk, int hargaBaru, string namaBaru) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaProduk) {
                current->harga = hargaBaru;
                current->namaProduk = namaBaru;
                cout << "Data berhasil diupdate." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    //Fungsi untuk menambahkan data pada urutan Node tertentu
    void tambahDataUrutanTertentu(string namaProduk, int harga, int urutan) {
        Node* newNode = new Node();
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        Node* current = head;
        int pos = 1;
        while (current != NULL && pos < urutan) {
            current = current->next;
            pos++;
        }

        if (current == NULL) {
            cout << "Urutan tidak valid" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
    }

    // Fungsi untuk menyisipkan node di akhir linked list
    void insertAtEnd(string namaProduk, int harga) {
        Node* newNode = new Node();
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    // Fungsi untuk menyisipkan node di antara dua node tertentu
    void insertAfter(string prevNama, string nama_produk, int harga) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk != prevNama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nama produk " << prevNama << " tidak ditemukan." << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->namaProduk = nama_produk;
        newNode->harga = harga;
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Fungsi untuk menghapus node dengan nama produk tertentu
    void deleteNode(string nama_produk) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        if (head->namaProduk == nama_produk) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk !=nama_produk) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nama produk " << nama_produk << " tidak ditemukan." << endl;
            return;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mengubah harga dari node dengan nama produk tertentu
    void updateHarga(string nama_produk, int newHarga) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk != nama_produk) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nama produk " << nama_produk << " tidak ditemukan." << endl;
            return;
        }
        temp->harga = newHarga;
    }

    //Fungsi untuk menghapus node berdasarkan urutan yang ditentukan
    void hapusDataUrutanTertentu(int urutan) {
        if (head == nullptr){
            cout << "Linked List Kosong." << endl;
            return;
        }

        Node* current = head;
        int pos = 1;
        while (current != nullptr && pos < urutan) {
            current = current->next;
            pos++;
        }

        if (current == nullptr || current == tail) {
            cout << "Urutan tidak valid" << endl;
            return;
        }

       if (current == head) {
            head = current->next;
        if (head != nullptr)
            head->prev = nullptr;
        } else if (current == tail) {
            tail = current->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
    }
    delete current;
    cout << "Data pada urutan " << urutan << " berhasil dihapus." << endl;
    }

    //Fungsi untuk menghapus seluruh data pada node
    void hapusSeluruhData() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    //Fungsi untuk menampilkan keseluruhan data pada node
    void tampilkanData() {
        Node* current = head;
        cout << "Nama Produk\tHarga" << endl;
        while (current != NULL) {
            cout << current->namaProduk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    DoubleLinkedList produkList;
    int pilihan;
    string namaProduk, namaBaru;
    int harga, hargabaru, urutan;

    //Menambahkan data produk yang tertera
    produkList.insertAtEnd("Originote",  60000);
    produkList.insertAtEnd("Somethinc",  150000);
    produkList.insertAtEnd("Skintific",  100000);
    produkList.insertAtEnd("Wardah",        50000);
    produkList.insertAtEnd("Hanasui",       30000);

    //Menampilkan menu
    do {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                produkList.tambahData(namaProduk, harga);
                break;
            case 2:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                produkList.hapusData(namaProduk);
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> namaProduk;
                cout << "Masukkan harga baru: ";
                cin >> hargabaru;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                produkList.updateData(namaProduk, hargabaru, namaBaru);
                break;
            case 4:
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan urutan: ";
                cin >> urutan;
                produkList.tambahDataUrutanTertentu(namaProduk, harga, urutan);
                break;
            case 5:
                cout << "Masukkan urutan data yang ingin dihapus: ";
                cin >> urutan;
                produkList.hapusDataUrutanTertentu(urutan);
                break;
            case 6:
                produkList.hapusSeluruhData();
                cout << "Data berhasil dihapus semua" << endl;
                break;
            case 7:
                produkList.tampilkanData();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }

    } while (pilihan != 8);

    return 0;
}
```

#### Output
Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
![Unguided-2-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/0b6ba24d-52d6-4055-b9d1-da2a389b5993)

2. Hapus produk wardah
![Unguided-2-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/d671a1cb-bc4c-44d4-b8e0-990668a419d0)

3. Update produk Hanasui menjadi Cleora dengan harga 55.000
![Unguided-2-3](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/f508930e-fcc1-44ba-9d5d-670b37564256)
   
4. Tampilkan menu
![Unguided-2-4](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/336185d4-436b-4d66-9ebd-c60b3e65c741)

#### Deskripsi Program
Program di atas merupakan program yang digunakan untuk implementasi dari sebuah aplikasi toko skincare yang menggunakan struktur data Doubly Linked List untuk menyimpan dan mengelola data produk skincare.</br>
Berikut adalah deskripsi singkat dari program tersebut:</br>

1. Program ini terdiri dari sebuah kelas `DoubleLinkedList` yang merepresentasikan Doubly Linked List.</br>
2. Setiap node dalam Doubly Linked List memiliki atribut `namaProduk` (nama produk) dan `harga` (harga produk), serta pointer ke node sebelumnya (prev) dan node selanjutnya (next).</br>
3. Program menyediakan beberapa fungsi operasi dasar, antara lain:</br>
a. `tambahData`: Menambahkan data produk ke akhir linked list.</br>
b. `hapusData`: Menghapus data produk berdasarkan nama produk.</br>
c. `updateData`: Mengupdate data produk berdasarkan nama produk.</br>
d. `tambahDataUrutanTertentu`: Menambahkan data produk pada urutan tertentu dalam linked list.</br>
e. `hapusDataUrutanTertentu`: Menghapus data produk pada urutan tertentu dalam linked list.</br>
f. `hapusSeluruhData`: Menghapus seluruh data produk dari linked list.</br>
g. `tampilkanData`: Menampilkan seluruh data produk yang tersimpan dalam linked list.</br>
Program juga memiliki fungsi main yang berfungsi sebagai antarmuka pengguna. Pengguna dapat memilih operasi yang ingin dilakukan melalui menu yang disediakan.</br>
Setiap kali pengguna memilih operasi, program akan mengeksekusi operasi tersebut sesuai dengan logika yang telah diimplementasikan dalam kelas DoubleLinkedList.</br>

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Dari praktikum materi Single dan Double Linked List dapat di simpulkan bahwa linked list merupakan sebuah struktur data yang digunakan untuk menyimpan sejumlah objek data biasanya secara terurut sehingga memungkinkan penambahan,pengurangan, dan pencarian atas elemen data yang tersimpan dalam senarai dilakukan secara lebih efektif. Linked list memiliki dua jenis
yaitu linked list satu arah double linked list.
<div/>
  
## Referensi
[1] Triase, "Struktur Data : Diktat Edisi Revisi.", online-available on repositiry uinsu. (2020).</br>
[2] Cici . handisha, “Tree”, Online-Available: osf.io/t9hv3.(2019).</br>
[3] A. Arraffi, “PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK”, Online-Available: osf.io/sczvp. (2019).</br>
