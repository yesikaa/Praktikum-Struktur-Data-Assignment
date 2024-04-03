![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/85ace432-13d7-4db0-b579-98741c0fa736)# <h1 align="center">Laporan Praktikum Modul List Circular Dan Non Circular	</h1>
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
a. Single Linked List Single linked list merupakan linked list dimana struktur data sebuah node hanya memiliki satu tautan atas node berikutnya, dengan tiap-tiap node yang terdiri atas dua elemen integer dan elemen rujukan ke node selanjutnya[2].</br>
b. Double Linked List Double linked list merupakan linked list yang menerapkan sebuah pointer baru, yaitu "prev" yang dapat digunakan untuk menggeser mundur selain pointer next. Keberadaan 2 pointer penunjuk (next dan prev) menjadikan Double Linked List menjadi lebih fleksibel dibandingkan Single Linked List, namun dengan mengorbankan adanya memori tambahan dengan adanya pointer tambahan tersebut[2].</br>

Circular Linked List adalah double / single LL yang simpul terakhirnya menunjuk ke simpul awal, dan simpul awalnya menunjuk ke simpul akhir, atau dapat disebut LL yang dibuat seakanakan merupakan sebuah lingkaran dengan  titik awal dan titik akhir saling bersebelahan jika LL tersebut masih kosong[2].</br>

1. Single Linked List Non Circular 
Merupakan node pada linked list yang mempunyai field berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node 
baru, mulanya pointer next dan prev akan menunjuk ke nilai NULL. Selanjutnya pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node selanjutnya pada list[3].</br>

2. Single Linked List Circular
Merupakan single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer next pada node terakhir akan menunjuk ke node terdepannya[3].</br>

3. Double Linked List Non Circular
Double Linked List Non Circular adalah linked list dengan menggunakan pointer, dimana setiap node memiliki 3 field, yaitu 1 field pointer yang menunjuk pointer berikutnya (next), 1 field menunjuk pointer sebelumnya (prev), serta sebuah field yang berisi data untuk node tersebut[3].</br>

4. Double Linked List Circular
Double Linked List Circular adalah linked list dengan menggunakan pointer, dimana setiap node memiliki 3 field, yaitu:</br>
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

a. Tampilan Menu :
![soal-menu](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/1150ffcd-50a4-4142-82b1-0404fe787174)

b. Tampilan Operasi Tambah :
![soal-tmbh depan](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/eab994d4-1071-4bbd-a44c-c81817d0cdda)
![soal-tmbh tngh](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/d70e6f79-905b-4466-b21a-1e82ac365591)

c. Tampilan Operasi Hapus:
![s-hps tngh](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/b0317ce5-96e7-41b4-8fd6-ef55901fa50f)
![s-hps blkgn](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/887f42eb-5e27-4e7a-948d-b172508b72a2)

d. Tampilan Operasi Ubah:
![s-ubh tgnh](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7820bd2d-41bf-4f4f-853e-6a129337a527)
![s-ubh blkg](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/9462fb9a-3a41-4a4b-91a8-d5623a2990fd)

e. Tampilan Operasi Tampil Data:
![datamhssw](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/8774f14a-b18d-47b5-aef8-24f9c6c7e33a)

*Buat tampilan output sebagus dan secantik mungkin sesuai kreatifitas anda
masing-masing, jangan terpaku pada contoh output yang diberikan


#### Source Code
```C++

```

#### Output


#### Deskripsi Program
Program di atas adalah sebuah implementasi dari linked list tunggal non-circular dalam bahasa C++. Linked list adalah struktur data linear yang terdiri dari serangkaian simpul (node), di mana setiap simpul terdiri dari dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya. Berikut adalah deskripsi singkat dari setiap bagian program:</br>

1. **Class Mahasiswa**:</br>
   - Kelas ini merepresentasikan simpul dalam linked list. Setiap simpul memiliki tiga data anggota yaitu `nama`, `nim`, dan `namaBaru`, serta sebuah pointer `next` yang menunjuk ke simpul berikutnya.</br>

2. **Class LinkedList**:</br>
   - Kelas ini merupakan implementasi dari linked list. Setiap objek dari kelas LinkedList memiliki sebuah pointer `head` yang menunjuk ke simpul pertama dalam linked list.</br>
   - Metode-metode yang disediakan oleh kelas ini antara lain:</br>
     - `tambahDepan`: Menambahkan simpul baru di depan linked list.</br>
     - `tambahBelakang`: Menambahkan simpul baru di belakang linked list.</br>
     - `tambahTengah`: Menambahkan simpul baru di tengah linked list berdasarkan posisi yang ditentukan.</br>
     - `ubahDepan`: Mengubah data pada simpul pertama.</br>
     - `ubahBelakang`: Mengubah data pada simpul terakhir.</br>
     - `ubahTengah`: Mengubah data pada simpul di tengah linked list berdasarkan posisi yang ditentukan.</br>
     - `hapusDepan`: Menghapus simpul pertama dari linked list.</br>
     - `hapusBelakang`: Menghapus simpul terakhir dari linked list.</br>
     - `hapusTengah`: Menghapus simpul di tengah linked list berdasarkan posisi yang ditentukan.</br>
     - `hapusList`: Menghapus seluruh simpul dari linked list.</br>
     - `tampilkan`: Menampilkan seluruh data mahasiswa yang tersimpan dalam linked list.</br>

3. **Fungsi `main`**:</br>
   - Fungsi utama yang menjalankan program.</br>
   - Pada bagian ini, pengguna dapat memilih berbagai operasi untuk mengelola linked list, seperti menambahkan, mengubah, atau menghapus data, serta menampilkan seluruh data yang tersimpan.</br>

Program tersebut berjalan dengan menggunakan konsep menu-driven interface di mana pengguna dapat memilih berbagai operasi yang ingin dilakukan terhadap linked list. Berikut adalah cara program tersebut berjalan:</br>
1. Ketika program pertama kali dijalankan, sebuah menu akan ditampilkan kepada pengguna dengan berbagai pilihan operasi yang dapat dilakukan terhadap linked list.</br>
2. Pengguna akan diminta untuk memilih operasi yang ingin dilakukan dengan memasukkan nomor pilihan dari menu tersebut.</br>
3. Setelah pengguna memilih operasi, program akan menjalankan fungsi yang sesuai dengan pilihan pengguna.</br>
4. Jika pengguna memilih untuk menambahkan data ke linked list, program akan meminta input nama, NIM, dan nama baru (jika ada) dari pengguna sesuai dengan jenis operasi yang dipilih (tambah depan, tambah belakang, atau tambah tengah). Kemudian, data tersebut akan ditambahkan ke linked list sesuai dengan posisi yang ditentukan.</br>
5. Jika pengguna memilih untuk mengubah data dalam linked list, program akan meminta input nama, NIM, dan nama baru dari pengguna sesuai dengan jenis operasi yang dipilih (ubah depan, ubah belakang, atau ubah tengah). Kemudian, data yang sesuai akan diubah sesuai dengan input pengguna.</br>
6. Jika pengguna memilih untuk menghapus data dari linked list, program akan meminta input posisi data yang ingin dihapus (jika ada) sesuai dengan jenis operasi yang dipilih (hapus depan, hapus belakang, atau hapus tengah). Kemudian, data yang sesuai akan dihapus dari linked list.</br>
7. Jika pengguna memilih untuk menampilkan seluruh data yang tersimpan dalam linked list, program akan menampilkan nomor, nama baru, dan NIM dari setiap data mahasiswa yang tersimpan.</br>
8. Pengguna dapat terus memilih operasi yang ingin dilakukan, dan program akan terus berjalan hingga pengguna memilih untuk keluar dari program.</br>
Dengan cara ini, pengguna dapat secara interaktif mengelola data dalam linked list menggunakan berbagai operasi yang disediakan. Program akan terus berjalan dan menunggu input dari pengguna hingga pengguna memilih untuk keluar.</br>

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![tabel](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/9f38413b-77dc-4a89-98b9-8a9956ac39c6)


### 3. Lakukan perintah berikut:
a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004

b) Hapus data Denis

c) Tambahkan data berikut di awal: Owi 2330000

d) Tambahkan data berikut di akhir:David 23300100

e) Ubah data Udin menjadi data berikut:Idin 23300045

f) Ubah data terkahir menjadi berikut:Lucy 23300101

g) Hapus data awal

h) Ubah data awal menjadi berikut: Bagas 2330002

i) Hapus data akhir

j) Tampilkan seluruh data

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
[1] Triase, "Struktur Data : Diktat Edisi Revisi.", online-available on repositiry uinsu. (2020). 
[2] A. Arraffi, “PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK”, Online-Available: osf.io/sczvp. (2019). 
[3] A. k . Putra, “List linier(linked list) dan variasinya_struktur data”, Online-Available: osf.io/tjnfa.(2019). 
[4] M. yulianti, “struktur data_double linked list circular”, Online- Available: osf.io/2nhs5.(2019). 
