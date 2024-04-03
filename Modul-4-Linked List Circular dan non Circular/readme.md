# <h1 align="center">Laporan Praktikum Modul List Circular Dan Non Circular	</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">2311102195</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Praktikan dapat mengetahui dan memahami linked list circular dan non circular.
2. Praktikan dapat membuat linked list circular dan non circular.
3. Praktikan dapat mengaplikasikan atau menerapkan linked list circular dan non circular pada program yang dibuat.
```
## Dasar Teori
<p style="text-align: justify; font-size: 12px;">

Linked List adalah suatu simpul (node) yang dikaitkan dengan node yang lain dalam suatu urutan tertentu. Suatu node dapat berbentuk struktur atau class yang berisi data. Linked list dihubungkan secara linier dengan bantuan pointer[1].</br>

a. Single Linked List Single linked list merupakan linked list dimana struktur data sebuah node hanya memiliki satu tautan atas node berikutnya dengan tiap-tiap node yang terdiri atas dua elemen integer dan elemen rujukan ke node selanjutnya[2].</br>
<br>b. Double Linked List Double linked list merupakan linked list yang menerapkan sebuah pointer baru, yaitu "prev" yang dapat digunakan untuk   menggeser mundur selain pointer next. Keberadaan 2 pointer penunjuk (next dan prev) menjadikan Double Linked List menjadi lebih fleksibel dibandingkan Single Linked List, namun dengan mengorbankan adanya memori tambahan dengan adanya pointer tambahan tersebut[2].</br>

Circular Linked List adalah double / single LL yang simpul terakhirnya menunjuk ke simpul awal, dan simpul awalnya menunjuk ke simpul akhir, atau dapat disebut LL yang dibuat seakanakan merupakan sebuah lingkaran dengan  titik awal dan titik akhir saling bersebelahan jika LL tersebut masih kosong[2].</br>

1. Single Linked List Non Circular 
Merupakan node pada linked list yang mempunyai field berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node 
baru, mulanya pointer next dan prev akan menunjuk ke nilai NULL. Selanjutnya pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node selanjutnya pada list[3].</br>

2. Single Linked List Circular
Merupakan single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer next pada node terakhir akan menunjuk ke node terdepannya[3].</br>

3. Double Linked List Non Circular
Double Linked List Non Circular adalah linked list dengan menggunakan pointer, dimana setiap node memiliki 3 field, yaitu 1 field pointer yang menunjuk pointer berikutnya (next), 1 field menunjuk pointer sebelumnya (prev), serta sebuah field yang berisi data untuk node tersebut[3].</br>

4. Double Linked List Circular
Double Linked List Circular adalah linked list dengan menggunakan pointer, dimana setiap node memiliki 3 field, yaitu:
  - 1 field pointer yang menunjuk pointer berikutnya (next),</br>
  - 1 field menunjuk pointer sebelumnya (prev),</br>
  - serta sebuah field yang berisi data untuk node tersebut</br>

Double Linked List Circular pointer next dan prev nya menunjuk ke dirinya sendiri secara circular. Setiap node pada linked list mempunyai field yang berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node baru, mulanya pointer next dan prev akan menunjuk ke dirinya sendiri. Jika sudah lebih dari satu node, maka pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node sesudahnya[4].</br>
  
## GUIDED

### 1. Program Linked List Non Circular

```C++
#include <iostream>
using namespace std;

//PROGRAM SINGLE LINKED LIST NON-CIRCULAR

//Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

//Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
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

//Tambah Belakang
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

//Hitung Jumlah List
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

//Tambah Tengah
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

//Hapus Depan
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

//Hapus Belakang
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

//Hapus Tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
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
        cout << "List masih Kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
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

//Tampilkan List
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
![Guided-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7c611351-e8de-474c-96f6-317a4167afc9)

Program diatas merupakan program implementasi dari single linked list non-circular dalam bahasa C++. Program ini memiliki beberapa fungsi untuk operasi dasar pada linked list seperti penambahan di depan, di belakang, di tengah, penghapusan di depan, di belakang, di tengah, serta pengubahan data pada node tertentu.</br>

Berikut adalah deskripsi singkat dari setiap fungsi dan alur program:</br>
1. `init()`: Fungsi ini menginisialisasi pointer head dan tail linked list menjadi NULL.</br>
2. `isEmpty()`: Fungsi ini memeriksa apakah linked list kosong atau tidak. Mengembalikan nilai true jika linked list kosong, dan false jika tidak kosong.</br>
3. `insertDepan(int nilai)`: Fungsi ini menambahkan node baru di depan linked list dengan nilai yang diberikan. Jika linked list kosong, maka node baru akan menjadi head dan tail. Jika tidak, node baru akan menjadi head dan next-nya akan menunjuk ke node sebelumnya head.</br>
4. `insertBelakang(int nilai)`: Fungsi ini menambahkan node baru di belakang linked list dengan nilai yang diberikan. Jika linked list kosong, maka node baru akan menjadi head dan tail. Jika tidak, node baru akan menjadi tail dan next dari node sebelumnya tail akan menunjuk ke node baru.</br>
5. `hitungList()`: Fungsi ini menghitung jumlah node dalam linked list dan mengembalikan nilai jumlahnya.</br>
6. `insertTengah(int data, int posisi)`: Fungsi ini menambahkan node baru di antara dua node pada posisi tertentu dalam linked list.</br>
7. `hapusDepan()`: Fungsi ini menghapus node pertama (head) dari linked list.</br>
8. `hapusBelakang()`: Fungsi ini menghapus node terakhir (tail) dari linked list.</br>
9. `hapusTengah(int posisi)`: Fungsi ini menghapus node pada posisi tertentu dalam linked list.</br>
10. `ubahDepan(int data)`, `ubahTengah(int data, int posisi)`, `ubahBelakang(int data)`: Fungsi-fungsi ini mengubah data pada node tertentu dalam linked list.</br>
11. `clearList()`: Fungsi ini menghapus semua node dalam linked list.</br>
12. `tampil()`: Fungsi ini menampilkan semua data yang ada dalam linked list.</br>

Program di atas menunjukkan penggunaan linked list untuk menyimpan dan mengelola data dengan operasi-operasi dasar seperti penyisipan, penghapusan, dan pengubahan data pada node. </br>


### 2. Program Linked List Circular

```C++
//Yesika Widiyani
//2311102195

#include <iostream>
using namespace std;

//PROGRAM SINGLE LINKED LIST CIRCULAR

//Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

//Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;

}

//Tambah Depan
void insertDepan(string data)
{
    //Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1)
    {
    head = baru;
    tail = head;
    baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
    baru->next = head;
    head = baru;
    tail->next = head;
    }
}

//Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else{
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

//Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan()
{
   if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
             {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    } 
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```

#### Output
![Guided-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/42e5547a-4cac-4e86-a260-16cf824020d0)

Program di atas merupakan implementasi dari sebuah linked list tunggal (single linked list) yang bersifat circular. Berikut adalah deskripsi dari beberapa bagian utama program tersebut:</br>
a. `Struct Node`: Mendefinisikan struktur node yang memiliki dua bagian, yaitu data (bertipe string) dan pointer ke node selanjutnya.</br>
b. `Variabel global`: Terdapat beberapa variabel global seperti head, tail, baru, bantu, dan hapus yang digunakan dalam operasi-operasi linked list.</br>
c. `init()`: Inisialisasi linked list dengan mengatur head dan tail menjadi NULL.</br>
d. `isEmpty()`: Fungsi untuk memeriksa apakah linked list kosong atau tidak.</br>
e. `buatNode(string data)`: Fungsi untuk membuat node baru dengan data yang ditentukan.</br>
f. `hitungList()`: Fungsi untuk menghitung jumlah node dalam linked list.</br>
g. `insertDepan(string data)`: Menyisipkan node baru di depan linked list.</br>
h. `insertBelakang(string data)`: Menyisipkan node baru di belakang linked list.</br>
i. `insertTengah(string data, int posisi)`: Menyisipkan node baru di tengah-tengah linked list pada posisi yang ditentukan.</br>
j. `hapusDepan()`: Menghapus node pertama dari linked list.</br>
k. `hapusBelakang()`: Menghapus node terakhir dari linked list.</br>
l. `hapusTengah(int posisi)`: Menghapus node di tengah-tengah linked list pada posisi yang ditentukan.</br>
m. `clearList()`: Menghapus seluruh isi linked list.</br>
n. `tampil()`: Menampilkan isi linked list.</br>
o. `main()`: Fungsi utama yang melakukan beberapa operasi pada linked list seperti menyisipkan, menghapus, dan menampilkan node-node pada linked list.</br> 

Program di atas menunjukkan penggunaan linked list untuk menyimpan dan mengelola data dengan operasi-operasi dasar seperti penyisipan dan penghapusan node, serta menampilkan isi linked list.
</br>


## UNGUIDED

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.</br>

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

a. Tampilan Menu :</br>
![soal-menu](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/1150ffcd-50a4-4142-82b1-0404fe787174)

b. Tampilan Operasi Tambah :</br>
![soal-tmbh depan](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/eab994d4-1071-4bbd-a44c-c81817d0cdda)

![soal-tmbh tngh](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/d70e6f79-905b-4466-b21a-1e82ac365591)

c. Tampilan Operasi Hapus:</br>
![s-hps tngh](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/b0317ce5-96e7-41b4-8fd6-ef55901fa50f)

![s-hps blkgn](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/887f42eb-5e27-4e7a-948d-b172508b72a2)

d. Tampilan Operasi Ubah:</br>
![s-ubh tgnh](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7820bd2d-41bf-4f4f-853e-6a129337a527)

![s-ubh blkg](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/9462fb9a-3a41-4a4b-91a8-d5623a2990fd)

e. Tampilan Operasi Tampil Data:</br>
![datamhssw](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/8774f14a-b18d-47b5-aef8-24f9c6c7e33a)

*Buat tampilan output sebagus dan secantik mungkin sesuai kreatifitas anda
masing-masing, jangan terpaku pada contoh output yang diberikan


#### Source Code
```C++
//Yesika Widiyani
//2311102195

#include <iostream>
#include <string>
using namespace std;

class Mahasiswa
{
public:
    string nama;
    string nim;
    string namaBaru;
    Mahasiswa *next;

    Mahasiswa(string nama, string nim, string namaBaru)
    {
        this->nama = nama;
        this->nim = nim;
        this->namaBaru = namaBaru;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Mahasiswa *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Fungsi untuk menambahkan data di depan
    void tambahDepan(string nama, string nim, string namaBaru)
    {
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        if (head == nullptr)
        {
            newNode->next = newNode; // Mengubah pointer next menjadi dirinya sendiri jika linked list masih kosong
            head = newNode;
        }
        else
        {
            Mahasiswa *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Fungsi untuk menambahkan data di belakang
    void tambahBelakang(string nama, string nim, string namaBaru)
    {
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        if (head == nullptr)
        {
            newNode->next = newNode; // Mengubah pointer next menjadi dirinya sendiri jika linked list masih kosong
            head = newNode;
        }
        else
        {
            Mahasiswa *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Fungsi untuk menambahkan data di Tengah
    void tambahTengah(string nama, string nim, string namaBaru, int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak tepat." << endl;
            return;
        }
        if (posisi == 1)
        {
            tambahDepan(nama, nim, namaBaru);
            return;
        }
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        Mahasiswa *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            if (temp == nullptr || temp->next == head)
            {
                cout << "Posisi tidak tepat." << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk mengubah data dengan posisi di depan
    void ubahDepan(string nama, string nim, string namaBaru)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }

        string namaLama = head->nama; // Menyimpan nama sebelumnya
        cout << "Data " << head->namaBaru << " berhasil diubah dengan data " << namaBaru << "!" << endl;
        head->nama = nama;
        head->nim = nim;
        head->namaBaru = namaBaru;
    }

    // Fungsi untuk mengubah data dengan posisi di Belakang
    void ubahBelakang(string nama, string nim, string namaBaru)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
        Mahasiswa *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        cout << "Data " << temp->namaBaru << " berhasil diubah dengan data " << namaBaru << "!" << endl;
        temp->nama = nama;
        temp->nim = nim;
        temp->namaBaru = namaBaru;
    }

    // Fungsi untuk mengubah data dengan posisi di Tengah
    void ubahTengah(string nama, string nim, string namaBaru, int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak tepat." << endl;
            return;
        }
        if (posisi == 1)
        {
            ubahDepan(nama, nim, namaBaru);
            return;
        }
        Mahasiswa *temp = head;
        for (int i = 1; i < posisi; i++)
        {
            if (temp == nullptr)
            {
                cout << "Posisi tidak tepat." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Data " << temp->namaBaru << " pada posisi " << posisi << " berhasil diubah dengan data " << namaBaru << "!" << endl;
        temp->nama = nama;
        temp->nim = nim;
        temp->namaBaru = namaBaru;
    }

    // Fungsi untuk menghapus data di bagian depan
    void hapusDepan()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        Mahasiswa *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        cout << "Data " << head->namaBaru << " telah berhasil dihapus!" << endl;
        delete head;
        head = temp->next;
    }

    // Fungsi untuk menghapus data di bagian belakang
    void hapusBelakang()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            cout << "Data terakhir berhasil dihapus!" << endl;
            return;
        }
        Mahasiswa *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        cout << "Data " << temp->next->namaBaru << " pada posisi terakhir telah berhasil dihapus!" << endl;
        delete temp->next;
        temp->next = head;
    }

    // Fungsi untuk menghapus data di bagian tengah
    void hapusTengah(int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak tepat." << endl;
            return;
        }
        if (posisi == 1)
        {
            hapusDepan();
            return;
        }
        Mahasiswa *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            if (temp == nullptr || temp->next == head)
            {
                cout << "Posisi tidak tepat." << endl;
                return;
            }
            temp = temp->next;
        }
        Mahasiswa *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Data " << nodeToDelete->namaBaru << " pada posisi " << posisi << " telah berhasil dihapus!" << endl;
        delete nodeToDelete;
    }

    // Fungsi untuk menghapus semua data
    void hapusList()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }

        Mahasiswa *temp = head;
        while (temp->next != head)
        {
            Mahasiswa *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        cout << "Seluruh data telah berhasil dihapus!" << endl;
    }

    // Fungsi untuk menampilkan data
    void tampilkan()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        Mahasiswa *temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "No\tNAMA\t\tNIM" << endl;
        int nomor = 1;
        do
        {
            cout << nomor << "\t" << temp->namaBaru << "\t\t" << temp->nim << endl;
            temp = temp->next;
            nomor++;
        } while (temp != head);
    }
};

int main()
{
    cout << "\n=========================================" << endl;
    cout << "=== Nama : Yesika Widiyani ===" << endl;
    cout << "=== NIM  :     2311102195  ===" << endl;
    cout << "=========================================" << endl;
   
    LinkedList linkedList;

    while (true)
    {
        cout << "\nPROGRAM SINGLE LINKED LIST CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan Seluruh Data" << endl;
        cout << "0. Keluar" << endl;
        int pilih;
        cout << endl;
        cout << "Pilih Operasi: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1) // Untuk memanggil fungsi menambahkan data di depan (Tambah Depan)
        {
            string nama, nim, namaBaru;
            cout << "--Tambah Depan--\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama :\t";
            getline(cin, namaBaru);
            cout << "Masukkan NIM  :\t";
            cin >> nim;
            linkedList.tambahDepan(nama, nim, namaBaru);
            cout << "Data telah berhasil ditambahkan!" << endl;
        }
        else if (pilih == 2) // Untuk memanggil fungsi menambahkan data di belakang (Tambah Belakang)
        {
            string nama, nim, namaBaru;
            cout << "--Tambah Belakang--\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama :\t";
            getline(cin, namaBaru);
            cout << "Masukkan NIM  :\t";
            cin >> nim;
            linkedList.tambahBelakang(nama, nim, namaBaru);
            cout << "Data telah berhasil ditambahkan!" << endl;
        }
        else if (pilih == 3) // Untuk memanggil fungsi menambahkan data di Tengah (Tambah Tengah)
        {
            string nama, nim, namaBaru;
            int posisi;
            cout << "--Tambah Tengah Sesuai Posisi--\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama :\t";
            getline(cin, namaBaru);
            cout << "Masukkan NIM  :\t";
            cin >> nim;
            cout << "Masukkan Posisi Data : ";
            cin >> posisi;
            linkedList.tambahTengah(nama, nim, namaBaru, posisi);
            cout << "Data telah berhasil ditambahkan!" << endl;
        }
        else if (pilih == 4) // Untuk memanggil fungsi mengubah data di depan (Ubah Depan)
        {
            string nama, nim, namaBaru;

            cout << "--Ubah Depan--\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru :\t";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru  :\t";
            cin >> nim;
            linkedList.ubahDepan(nama, nim, namaBaru);
        }
        else if (pilih == 5) // Untuk memanggil fungsi mengubah data di belakang (Ubah Belakang)
        {
            string nama, nim, namaBaru;
            cout << "--Ubah Belakang--\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru :\t";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru  :\t";
            cin >> nim;
            linkedList.ubahBelakang(nama, nim, namaBaru);
        }
        else if (pilih == 6) // Untuk memanggil fungsi mengubah data di tengah (Ubah Tengah)
        {
            string nama, nim, namaBaru;
            int posisi;
            cout << "--Ubah Tengah--\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru :\t";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru  :\t";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            linkedList.ubahTengah(nama, nim, namaBaru, posisi);
        }
        else if (pilih == 7)
        {
            linkedList.hapusDepan();
        }
        else if (pilih == 8)
        {
            linkedList.hapusBelakang();
        }
        else if (pilih == 9)
        {
            int posisi;
            cout << "Masukkan Posisi Data :";
            cin >> posisi;
            linkedList.hapusTengah(posisi);
        }
        else if (pilih == 10)
        {
            linkedList.hapusList();
        }
        else if (pilih == 11)
        {
            linkedList.tampilkan();
        }
        else if (pilih == 0)
        {
            cout << "Program selesai." << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak tepat. Silakan masukan pilihan yang tepat!" << endl;
        }
    }
    return 0;
}
```

#### Output
**MENU**
![menu](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/ba0e2309-ef7d-4641-9aeb-082f69ecd235)

#### Deskripsi Program
Program di atas adalah implementasi dari sebuah linked list circular dengan menggunakan C++. Berikut adalah deskripsi dari program tersebut:</br>
1. Class Mahasiswa: Ini adalah kelas yang merepresentasikan objek mahasiswa. Setiap objek Mahasiswa memiliki tiga atribut: nama, nim, dan namaBaru (yang digunakan dalam program ini untuk menyimpan nama baru setelah diubah), serta pointer next yang menunjukkan ke simpul berikutnya dalam linked list.</br>
2. LinkedList Class: Ini adalah kelas yang merepresentasikan linked list. Ini memiliki satu atribut pribadi, yaitu head, yang menunjukkan ke simpul pertama dalam linked list. Kelas ini memiliki beberapa metode untuk operasi-operasi seperti menambah, mengubah, dan menghapus data, serta menampilkan seluruh data.</br>
3. Konstruktor: Konstruktor LinkedList digunakan untuk menginisialisasi head menjadi nullptr saat linked list pertama kali dibuat.</br>
4. Metode Tambah Data:</br>
a. `tambahDepan()`: Menambahkan data di depan linked list dengan menggeser head ke simpul baru.</br>
b. `tambahBelakang()`: Menambahkan data di belakang linked list dengan menggeser pointer next simpul terakhir ke simpul baru.</br>
c. `tambahTengah()`: Menambahkan data di tengah linked list pada posisi yang ditentukan dengan mengubah pointer next simpul sebelumnya.</br>
5. Metode Ubah Data:</br>
a. `ubahDepan()`, `ubahBelakang()`, dan `ubahTengah()`: Metode-metode ini digunakan untuk mengubah data di depan, belakang, atau tengah linked list sesuai dengan posisi yang ditentukan.</br>
6. Metode Hapus Data:</br>
a. `hapusDepan()`, `hapusBelakang()`, dan `hpausTengah()`: Metode-metode ini digunakan untuk menghapus data di depan, belakang, atau tengah linked list sesuai dengan posisi yang ditentukan.</br>
b. `hapusList()`: Menghapus seluruh data dari linked list.</br>
7. Metode Tampilkan: Metode ini digunakan untuk menampilkan semua data dalam linked list.</br>
8. Main Function: Fungsi utama program. Di dalamnya terdapat loop yang memungkinkan pengguna untuk memilih operasi yang ingin dilakukan, seperti menambah, mengubah, menghapus, atau menampilkan data. Program akan berjalan terus hingga pengguna memilih untuk keluar. Setiap operasi memanggil metode yang sesuai dari objek LinkedList yang telah dibuat sebelumnya.</br>

Program tersebut bekerja dengan menggunakan konsep linked list circular. Ketika program pertama kali dijalankan, objek LinkedList dibuat dengan head yang menunjuk ke nullptr, menandakan bahwa linked list kosong. Pengguna kemudian diberikan opsi untuk melakukan berbagai operasi, seperti menambah, mengubah, menghapus, atau menampilkan data.</br>

Ketika pengguna memilih untuk menambah data, program meminta input nama, NIM, dan namaBaru dari pengguna. Kemudian, sesuai dengan pilihan pengguna, program akan memanggil salah satu dari tiga metode tambah data yang tersedia: `tambahDepan`, `tambahBelakang`, atau `tambahTengah`. Setiap metode ini akan membuat simpul baru dengan data yang dimasukkan pengguna, dan mengatur pointer next dari simpul-simpul yang tepat agar linked list tetap terhubung dengan benar. Pada linked list circular, jika linked list masih kosong, pointer next dari simpul baru akan menunjuk kembali ke simpul itu sendiri.</br>

Saat pengguna memilih untuk mengubah data, program akan meminta input nama, NIM, dan namaBaru yang ingin diubah, serta posisi data yang ingin diubah. Kemudian, program akan memanggil salah satu dari tiga metode ubah data yang tersedia: `ubahDepan`, `ubahBelakang`, atau `ubahTengah`. Metode ini akan mencari simpul dengan posisi yang sesuai dan mengubah data di dalamnya sesuai dengan input yang diberikan oleh pengguna.</br>

Ketika pengguna memilih untuk menghapus data, program akan meminta input posisi data yang ingin dihapus. Program kemudian akan memanggil salah satu dari tiga metode hapus data yang tersedia: `hapusDepan`, `hapusBelakang`, atau `hapusTengah`. Metode ini akan mencari simpul dengan posisi yang sesuai dan menghapusnya dari linked list, serta memperbarui pointer next dari simpul sebelumnya dan sesudahnya agar linked list tetap terhubung dengan benar.</br>

Setiap kali pengguna memilih untuk menampilkan data, program akan memanggil metode tampilkan yang akan menampilkan semua data yang ada dalam linked list, dari simpul pertama hingga terakhir.</br>

Program akan terus berjalan dan mengulang proses ini hingga pengguna memilih untuk keluar dengan memasukkan pilihan 0.</br>


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![tabel](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/9f38413b-77dc-4a89-98b9-8a9956ac39c6)

#### Untuk menambahkan data pada tabel digunakan fungsi `tambahDepan` dan `tambahBelakang`
##### Source Code
```C++
 // Fungsi untuk menambahkan data di depan
    void tambahDepan(string nama, string nim, string namaBaru)
    {
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        if (head == nullptr)
        {
            newNode->next = newNode; // Mengubah pointer next menjadi dirinya sendiri jika linked list masih kosong
            head = newNode;
        }
        else
        {
            Mahasiswa *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
```
##### Contoh Output
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/ae824cb2-bc69-4eb6-94b6-f1ef4fced40b)

```C++
 // Fungsi untuk menambahkan data di belakang
    void tambahBelakang(string nama, string nim, string namaBaru)
    {
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        if (head == nullptr)
        {
            newNode->next = newNode; // Mengubah pointer next menjadi dirinya sendiri jika linked list masih kosong
            head = newNode;
        }
        else
        {
            Mahasiswa *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
```
##### Contoh Output
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/6d7eb193-db79-4d36-96c3-682356b37b7c)

#### Hasil Output Keseluruhan Data dalam tabel
![tabel](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/56c7481e-73c6-4242-98b9-0d062c52c562)


### 3. Lakukan perintah berikut:
#### a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004</br>
##### Menggunakan Fungsi `tambahTengah`
##### Source Code
```C++
 // Fungsi untuk menambahkan data di Tengah
    void tambahTengah(string nama, string nim, string namaBaru, int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak tepat." << endl;
            return;
        }
        if (posisi == 1)
        {
            tambahDepan(nama, nim, namaBaru);
            return;
        }
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        Mahasiswa *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            if (temp == nullptr || temp->next == head)
            {
                cout << "Posisi tidak tepat." << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
```
##### Output
![a](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/05870d0d-b9eb-4ce0-b8fa-fa3b7e3e2345)

## b) Hapus data Denis</br>
##### Menggunakan Fungsi `hapusTengah`
##### Source Code
```C++
    // Fungsi untuk menghapus data di bagian tengah
    void hapusTengah(int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak tepat." << endl;
            return;
        }
        if (posisi == 1)
        {
            hapusDepan();
            return;
        }
        Mahasiswa *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            if (temp == nullptr || temp->next == head)
            {
                cout << "Posisi tidak tepat." << endl;
                return;
            }
            temp = temp->next;
        }
        Mahasiswa *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Data " << nodeToDelete->namaBaru << " pada posisi " << posisi << " telah berhasil dihapus!" << endl;
        delete nodeToDelete;
    }
```
##### Output
![b](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/619ab264-960c-4302-b6d4-ae211fbffed8)


#### c) Tambahkan data berikut di awal: Owi 2330000</br>
##### Menggunakan Fungsi `tambahDepan`
##### Source Code
```C++
    // Fungsi untuk menambahkan data di depan
    void tambahDepan(string nama, string nim, string namaBaru)
    {
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        if (head == nullptr)
        {
            newNode->next = newNode; // Mengubah pointer next menjadi dirinya sendiri jika linked list masih kosong
            head = newNode;
        }
        else
        {
            Mahasiswa *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
```
##### Output
![c](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/00ff5de0-11d4-454d-89ca-9fb5bcab38fc)

#### d) Tambahkan data berikut di akhir:David 23300100</br>
##### Menggunakan Fungsi `tambahBelakang`
##### Source Code
```C++
    // Fungsi untuk menambahkan data di belakang
    void tambahBelakang(string nama, string nim, string namaBaru)
    {
        Mahasiswa *newNode = new Mahasiswa(nama, nim, namaBaru);
        if (head == nullptr)
        {
            newNode->next = newNode; // Mengubah pointer next menjadi dirinya sendiri jika linked list masih kosong
            head = newNode;
        }
        else
        {
            Mahasiswa *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
```
##### Output
![d](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/a7507e9a-1854-4585-b8c2-ef91e209ff80)

#### e) Ubah data Udin menjadi data berikut:Idin 23300045</br>
##### Menggunakan Fungsi `ubahTengah`
##### Source Code
```C++
    // Fungsi untuk mengubah data dengan posisi di Tengah
    void ubahTengah(string nama, string nim, string namaBaru, int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak tepat." << endl;
            return;
        }
        if (posisi == 1)
        {
            ubahDepan(nama, nim, namaBaru);
            return;
        }
        Mahasiswa *temp = head;
        for (int i = 1; i < posisi; i++)
        {
            if (temp == nullptr)
            {
                cout << "Posisi tidak tepat." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Data " << temp->namaBaru << " pada posisi " << posisi << " berhasil diubah dengan data " << namaBaru << "!" << endl;
        temp->nama = nama;
        temp->nim = nim;
        temp->namaBaru = namaBaru;
    }
```
##### Output
![e](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/c8f013fb-c981-48da-9337-34bd60c5c1f9)

#### f) Ubah data terkahir menjadi berikut:Lucy 23300101</br>
##### Menggunakan Fungsi `ubahBelakang`
##### Source Code
```C++
   // Fungsi untuk mengubah data dengan posisi di Belakang
    void ubahBelakang(string nama, string nim, string namaBaru)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
        Mahasiswa *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        cout << "Data " << temp->namaBaru << " berhasil diubah dengan data " << namaBaru << "!" << endl;
        temp->nama = nama;
        temp->nim = nim;
        temp->namaBaru = namaBaru;
    }
```
##### Output
![f](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/e07372f9-2f4d-4765-a5c4-39c18365e0d5)

#### g) Hapus data awal</br>
##### Menggunakan Fungsi `hapusDepan`
##### Source Code
```C++
    // Fungsi untuk menghapus data di bagian depan
    void hapusDepan()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        Mahasiswa *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        cout << "Data " << head->namaBaru << " telah berhasil dihapus!" << endl;
        delete head;
        head = temp->next;
    }
```
##### Output
![g](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/1f7744e5-485c-41ea-af03-6e7268a5fbdb)

#### h) Ubah data awal menjadi berikut: Bagas 2330002</br>
##### Menggunakan Fungsi `ubahDepan`
##### Source Code
```C++
    // Fungsi untuk mengubah data dengan posisi di depan
    void ubahDepan(string nama, string nim, string namaBaru)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }

        string namaLama = head->nama; // Menyimpan nama sebelumnya
        cout << "Data " << head->namaBaru << " berhasil diubah dengan data " << namaBaru << "!" << endl;
        head->nama = nama;
        head->nim = nim;
        head->namaBaru = namaBaru;
    }
```
##### Output
![h](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/cc61d66a-1608-4376-a6af-dcc6534edce3)

#### i) Hapus data akhir</br>
##### Menggunakan Fungsi `hapusBelakang`
##### Source code
```C++
    // Fungsi untuk menghapus data di bagian belakang
    void hapusBelakang()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            cout << "Data terakhir berhasil dihapus!" << endl;
            return;
        }
        Mahasiswa *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        cout << "Data " << temp->next->namaBaru << " pada posisi terakhir telah berhasil dihapus!" << endl;
        delete temp->next;
        temp->next = head;
    }
```
##### Output
![i](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/2074f29d-2629-43c8-9513-ccf9b9d09a25)

#### j) Tampilkan seluruh data</br>
##### Menggunakan Fungsi `tampilkan`
##### Source code
```C++
    // Fungsi untuk menampilkan data
    void tampilkan()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        Mahasiswa *temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "No\tNAMA\t\tNIM" << endl;
        int nomor = 1;
        do
        {
            cout << nomor << "\t" << temp->namaBaru << "\t\t" << temp->nim << endl;
            temp = temp->next;
            nomor++;
        } while (temp != head);
    }
};
```
##### Output
![j](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/b6f09ef0-3928-4108-ba37-5cdb9d7bfbdd)


## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Kesimpulan dari praktikum linked list circular dan non-circular:</br>

1. Linked List Non-Circular:</br>
a. Linked list non-circular adalah struktur data linear di mana setiap elemen (node) terhubung satu sama lain menggunakan pointer.</br>
b. Linked list non-circular memiliki simpul (node) terakhir yang menunjuk ke nullptr, menandakan akhir dari linked list.</br>
c. Operasi umum pada linked list non-circular termasuk penambahan, penghapusan, dan pencarian elemen.</br>
d. Linked list non-circular memiliki keterbatasan dalam mengakses elemen terakhir dengan efisiensi, karena perlu melintasi semua simpul sebelumnya.</br>

2.Linked List Circular:</br>
a. Linked list circular adalah variasi dari linked list non-circular di mana simpul terakhir mengarah kembali ke simpul pertama, membentuk lingkaran.</br>
b. Keuntungan dari linked list circular adalah bahwa tidak ada simpul yang mengarah ke nullptr, sehingga memudahkan navigasi dari elemen terakhir kembali ke elemen pertama.</br>
c. Operasi pada linked list circular hampir sama dengan linked list non-circular, namun perlu memperhatikan pengolahan titik akhir lingkaran.</br>

Dengan Praktikum linked list circular dan non-circular memberikan pemahaman mendalam tentang dua varian penting dari struktur data linked list dalam konteks pemrograman. Linked list non-circular terdiri dari serangkaian elemen yang terhubung satu sama lain melalui pointer, dengan simpul terakhir menunjuk ke nullptr, sementara linked list circular membentuk lingkaran dengan simpul terakhir mengarah kembali ke simpul pertama. Selama praktikum, mahasiswa belajar tentang operasi dasar seperti penambahan, penghapusan, dan pencarian dalam kedua jenis linked list ini. Lebih dari sekadar mengimplementasikan algoritma, praktikum ini memperkuat keterampilan analisis masalah dan pengembangan algoritma, serta menunjukkan penerapan praktis dari konsep struktur data dalam pengembangan perangkat lunak. Dengan memahami dan menguasai linked list circular dan non-circular, mahasiswa dapat memperluas pemahaman mereka tentang struktur data dan meningkatkan kemampuan mereka dalam pemecahan masalah dan pengembangan perangkat lunak.</br>
<div/>
  
## Referensi
[1] Triase, "Struktur Data : Diktat Edisi Revisi.", online-available on repositiry uinsu. (2020). </br>
[2] A. Arraffi, “PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK”, Online-Available: osf.io/sczvp. (2019). </br>
[3] A. k . Putra, “List linier(linked list) dan variasinya_struktur data”, Online-Available: osf.io/tjnfa.(2019). </br>
[4] M. yulianti, “struktur data_double linked list circular”, Online- Available: osf.io/2nhs5.(2019). </br>
