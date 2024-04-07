# <h1 align="center">Laporan Praktikum Modul Hash Table	</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">2311102195</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Mahasiswa mampu menjelaskan definisi dan konsep dari Hash Code
2. Mahasiswa mampu menerapkan Hash Code kedalam pemrograman
```
## Dasar Teori
<p style="text-align: justify; font-size: 12px;">
Hash memiliki arti memenggal lalu menggabungkan[1]. Dalam ilmu kriptografi fungsi hash merupakan bagian yang cukup penting, yang biasanya dipakai pada algoritma pendataan digital[2]. Hash Table dianggap dapat digunakan untuk menyimpan dan mencari data algoritma dengan lebih cepat dan efisien pada sebuah algoritma pencarian data[3].</br>

Dalam penggunaannya, metode hashing dapat digunakan sebagai metode penyimapanan data dalam sebuah larik (array) agar penyimpanan, pencarian, penambahan, dan penghapusan data dapat dilakukan dengan cepat[4]. Dasar proses dalam metode hashing adalah dengan menghitung posisi record yang dicari di dalam array dan bukan membandingkan record denga nisi pada array. Hal ini yang membuat proses hashing dapat mempercepat dalam proses pencarian data. Fungsi yang mengembalikan nilai atau kunci disebuah fungsi hash (hash function) dan array yang digunakan disebut tabel hash (hash table)[3]. </br>

Hash table adalah struktur data yang digunakan untuk menyimpan pasangan kunci-nilai dengan menggunakan fungsi hash untuk mengonversi kunci menjadi indeks di dalam tabel. Penggunaan hash table dalam bahasa C++ memberikan keuntungan dalam penyimpanan dan pencarian data dengan waktu operasi rata-rata konstan. </br>

**1. Struktur Data Hash Table** </br>
Hash table terdiri dari sebuah array atau vektor yang disebut tabel hash. Setiap elemen dalam tabel hash adalah node yang berisi pasangan kunci-nilai. Kunci digunakan untuk mengakses nilai yang terkait dalam tabel[5]. </br>

**2. Fungsi Hash** </br>
Fungsi hash adalah fungsi matematis yang mengonversi kunci menjadi indeks dalam tabel hash. Tujuan fungsi hash adalah untuk mendistribusikan kunci secara merata di seluruh rentang indeks hash. Implementasi yang baik dari fungsi hash dapat mengurangi kemungkinan terjadinya tabrakan (collision)[6].

**3. Operasi Dasar**</br>
Hash table mendukung beberapa operasi dasar, termasuk penambahan (insertion), pencarian (searching), penghapusan (deletion), dan penelusuran (traversal) elemen. Penambahan dan penghapusan biasanya dilakukan dalam waktu konstan, sementara pencarian memiliki kompleksitas waktu rata-rata O(1) untuk kasus terbaik[7].</br>

**4. Penanganan Tabrakan**</br>
Tabrakan terjadi ketika dua kunci menghasilkan indeks hash yang sama. Untuk menangani tabrakan, beberapa teknik dapat digunakan, seperti chaining (menggunakan linked list untuk menangani tabrakan) atau open addressing (menggunakan lokasi lain di dalam tabel hash untuk menempatkan elemen yang bertabrakan)[6].

**5. Kompleksitas Waktu dan Ruang**</br>
Penggunaan hash table memiliki kompleksitas waktu dan ruang yang penting untuk dipertimbangkan. Meskipun operasi pada hash table dapat memiliki kompleksitas waktu rata-rata konstan, tetapi kompleksitas ruangnya bisa menjadi besar tergantung pada faktor seperti faktor beban (load factor) dan strategi penanganan tabrakan yang digunakan[6].</br> 

## GUIDED

### 1. Program Hash Table

```C++
#include<iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) 
{
    return key % MAX_SIZE;
}

//Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};

//Class hash Table
class HashTable 
{
    private:
        Node** table;
    public:
        HashTable() 
        {
            table = new Node*[MAX_SIZE]();
        }
        ~HashTable() 
        {
            for (int i = 0; i < MAX_SIZE; i++) 
            {
                Node* current = table[i];
                while (current != nullptr) 
                {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] table;
        }

        //Insertion
        void insert(int key, int value) 
        {
            int index = hash_func(key);
            Node* current = table[index];
            while (current != nullptr) 
            {
                if (current->key == key) 
                {
                    current->value = value;
                    return;
                }
                current = current->next;
            }
            Node* node = new Node(key, value);
            node->next = table[index];
            table[index] = node;
        }

        //Searching
        int get(int key) 
        {
            int index = hash_func(key);
            Node* current = table[index];
            while (current != nullptr) 
            {
                if (current->key == key) 
                {
                    return current->value;
                }
                current = current->next;
            }
                return -1;
        }

        //Deletion
        void remove(int key) 
        {
            int index = hash_func(key);
            Node* current = table[index];
            Node* prev = nullptr;
            while (current != nullptr) 
            {
                if (current->key == key) 
                {
                    if (prev == nullptr) 
                    {
                        table[index] = current->next;
                    } else 
                    {
                        prev->next = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        //Traversal
        void traverse() 
        {
            for (int i = 0; i < MAX_SIZE; i++) 
            {
                Node* current = table[i];
                while (current != nullptr) 
                {
                    cout << current->key << ": " << current->value << endl;
                    current = current->next;
                }
            }
        }
};

int main()
{
    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    
    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    return 0;
}
```

#### Output
![g-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/073cdef8-080a-4181-aa09-8c2d76fedf7a)

#### Deskripsi
Program tersebut merupakan program yang menggunakan fungsi  hash table untuk menyimpan pasangan kunci-nilai. Setiap elemen hash table direpresentasikan sebagai node yang terdiri dari kunci (key) dan nilai (value). Program menyediakan operasi dasar seperti penambahan (insertion), pencarian (searching), penghapusan (deletion), dan penelusuran (traversal) pada hash table. </br>

Pertama program membuat objek HashTable yang merupakan representasi dari hash table. Selanjutnya, beberapa pasangan kunci-nilai dimasukkan ke dalam hash table menggunakan operasi `insert`. Operasi pencarian (`get`) digunakan untuk mencari nilai yang terkait dengan kunci tertentu. Jika kunci tidak ditemukan, akan dikembalikan nilai -1. Penghapusan elemen dilakukan dengan operasi `remove`, yang mencari elemen dengan kunci yang diberikan dan menghapusnya dari hash table.Program juga memiliki operasi `traverse`, yang digunakan untuk menelusuri seluruh isi hash table dan mencetak kunci-nilai dari setiap node. Hasil dari operasi-insert, pencarian, penghapusan, dan penelusuran dicetak pada output program.</br>


### 2. Program Hash Table

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode 
{
    public:
        string name;
        string phone_number;
        HashNode(string name, string phone_number) 
        {
            this->name = name;
            this->phone_number = phone_number;
        }
};

class HashMap 
{
    private :
        vector<HashNode*> table[TABLE_SIZE];
    
    public :
        int hashFunc(string key) 
        {
            int hash_val = 0;
            for (char c : key) 
            {
                hash_val += c;
            }
            return hash_val % TABLE_SIZE;
        }
        
        void insert(string name, string phone_number) 
        {
            int hash_val = hashFunc(name);
            for (auto node : table[hash_val]) 
            {
                if (node->name == name) 
                {
                    node->phone_number = phone_number;
                    return;
                }
            }    
            table[hash_val].push_back(new HashNode(name, phone_number));
        }

        void remove(string name) 
        {
            int hash_val = hashFunc(name);
            for (auto it = table[hash_val].begin(); it !=
            table[hash_val].end(); it++) 
            {
                if ((*it)->name == name) 
                {
                    table[hash_val].erase(it);
                    return;
                 }
            }
        }
        
        string searchByName(string name) 
        {
            int hash_val = hashFunc(name);
            for (auto node : table[hash_val]) 
            {
                if (node->name == name) 
                {
                    return node->phone_number;
                }
            }
            return "";
        }

        void print() 
        {
            for (int i = 0; i < TABLE_SIZE; i++) 
            {
                cout << i << ": ";
                for (auto pair : table[i]) 
                {
                    if(pair != nullptr)
                    {
                        cout << "[" << pair->name << ", " << pair->phone_number << "]";
                    }
                }
                cout << endl;
            }
        }
};

int main() 
{
    HashMap employee_map;
    
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    
    employee_map.remove("Mistah");
    
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    
    cout << "Hash Table : " << endl;
    
    employee_map.print();
    
    return 0;
}   
```

#### Output
![g-2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7e888fda-5f4e-4caf-a321-c71747129b76)

#### Deskripsi
Program di atas adalah implementasi sederhana dari struktur data hash table dalam bahasa C++. Hash table digunakan untuk menyimpan data pasangan nama dan nomor telepon karyawan. Program tersebut menggunakan metode chaining untuk menangani tabrakan, di mana setiap slot dalam tabel hash menyimpan sebuah vektor (vector) yang berisi node-node (objek HashNode) yang memiliki kunci (nama) yang sama. Setiap karyawan direpresentasikan oleh sebuah objek HashNode yang memiliki atribut nama dan nomor telepon. Program menyediakan operasi penambahan (insert), penghapusan (remove), dan pencarian (searchByName) karyawan berdasarkan nama. Hasil operasi-operasi tersebut dicetak sebagai output program.</br>

Program pertama-tama membuat objek HashMap yang akan digunakan untuk menyimpan data karyawan.Tiga karyawan ditambahkan ke dalam hash map menggunakan metode insert, di mana nama karyawan dijadikan kunci dan nomor telepon sebagai nilai. Program mencari nomor telepon dari dua karyawan, "Mistah" dan "Pastah", menggunakan metode searchByName dan mencetaknya. Kemudian, karyawan dengan nama "Mistah" dihapus dari hash map menggunakan metode remove. Program mencari nomor telepon karyawan "Mistah" lagi setelah dihapus, dan karena karyawan tersebut telah dihapus, program mengembalikan nilai string kosong. Terakhir, program mencetak isi hash table menggunakan metode print, yang menampilkan nama dan nomor telepon semua karyawan yang tersimpan dalam hash map.</br>


## UNGUIDED
### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : </br>
**a. Setiap Mahasiswa memiliki NIM dan nilai.** </br>
**Program memiliki tampilan pilihan menu berisi poin C.** </br>
**Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).** </br>

#### Source Code
```C++
// Yesika Widiyani
// 2311102195

#include <iostream>
#include <vector>

using namespace std;

//Ukuran Hash table
const int TABLE_SIZE = 100;

//Struktur data untuk Mahasiswa
struct Mahasiswa 
{
    string nama;
    string nim;
    int nilai;
};

class HashTable 
{
    private:
        vector<Mahasiswa>* table;

        // Fungsi hash sederhana untuk menghasilkan indeks dari NIM
        int hashFunction(const string& nim) 
        {
            int sum = 0;
            for (char c : nim)
            {
                sum += c;
            }
            return sum % TABLE_SIZE;
        }

    public :
        // Konstruktor
        HashTable() 
        {
            table = new vector<Mahasiswa>[TABLE_SIZE];
        }

        // Destruktor
        ~HashTable() 
        {
            delete[] table;
        }

        // Fungsi untuk menambahkan data mahasiswa baru
        void tambahMahasiswa(string nama, string nim, int nilai) 
        {
            Mahasiswa mhs;
            mhs.nama = nama;
            mhs.nim = nim;
            mhs.nilai = nilai;

            int index = hashFunction(nim);
            table[index].push_back(mhs);
        }

        // Fungsi untuk menampilkan seluruh data mahasiswa
        void tampilkanSeluruhData() 
        {
            cout << ">>>> DATA MAHASISWA <<<<" << endl;
            cout << "No\tNAMA\t\tNIM\t\tNILAI" << endl;
            int nomor = 1;
            for (int i = 0; i < TABLE_SIZE; ++i)
            {
                for (const Mahasiswa& mhs : table[i])
                {
                    cout << nomor++ << "\t" << mhs.nama << "\t" << mhs.nim << "\t" << mhs.nilai << endl;
                }
            }
        }

         // Fungsi untuk mencari data mahasiswa berdasarkan NIM
        Mahasiswa* cariMahasiswaNIM(const string& nim) 
        {
            int index = hashFunction(nim);
            for (int i = 0; i < table[index].size(); ++i) 
            {
                if (table[index][i].nim == nim) 
                {
                    return &table[index][i];
                }
            }
            return nullptr;
        }

         // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
        vector<Mahasiswa*> cariMahasiswaNilai() 
        {
            vector<Mahasiswa*> hasil;
            for (int i = 0; i < TABLE_SIZE; ++i) 
            {
                for (int j = 0; j < table[i].size(); ++j) 
                {
                    if (table[i][j].nilai >= 80 && table[i][j].nilai <= 90) 
                    {
                        hasil.push_back(&table[i][j]);
                    }
                }
            }
            return hasil;
        }

        void tampilkanMahasiswaNilai() 
        {
            vector<Mahasiswa*> mahasiswas = cariMahasiswaNilai();
            cout << ">>>>> DATA MAHASISWA DENGAN NILAI 80-90 <<<<<" << endl;
            cout << "No\tNAMA\t\tNIM\t\tNilai" << endl;
            int nomor = 1;
            for (Mahasiswa* mhs : mahasiswas) 
            {
                cout << nomor++ << "\t" << mhs->nama << "\t" << mhs->nim << "\t" << mhs->nilai << endl;
            }
        }

         // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
        void hapusMahasiswa(const string& nim) 
        {
            int index = hashFunction(nim);
            for (int i = 0; i < table[index].size(); ++i) 
            {
                if (table[index][i].nim == nim) 
                {
                    table[index].erase(table[index].begin() + i);
                    return;
                }
            }
        }
};

// Fungsi untuk menampilkan menu dan meminta input dari pengguna
void tampilkanMenu() 
{
    cout << ">>>>> M E N U <<<<<" << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Tampilkan Seluruh Data Mahasiswa" << endl;
    cout << "3. Cari Data Mahasiswa berdasarkan NIM" << endl;
    cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80 - 90)" << endl;
    cout << "5. Hapus Data Mahasiswa" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih opsi: ";
}

int main() 
{
    HashTable hashTable;

    int opsi;
    do {
        tampilkanMenu();
        cin >> opsi;

        switch (opsi) 
        {
            case 1: 
            {
                string nama, nim;
                int nilai;
                cout << "Masukkan nama mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                hashTable.tambahMahasiswa(nama, nim, nilai);
                cout << "Mahasiswa berhasil ditambahkan." << endl;
                break;
            }
            case 2: 
            {
                hashTable.tampilkanSeluruhData();
                break;
            }
            case 3: 
            {
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> nim;
                Mahasiswa* mhs = hashTable.cariMahasiswaNIM(nim);
                if (mhs != nullptr) {
                    cout << "Data Mahasiswa ditemukan dengan \nNama: " << mhs->nama << "\nNIM: " << mhs->nim << "\nNilai: " << mhs->nilai << endl;
                } else {
                    cout << "Data Mahasiswa tidak ditemukan." << endl;
                }
                break;
            }
            case 4: 
            {
                hashTable.tampilkanMahasiswaNilai();
                break;
            }
            case 5: 
            {
                string nim;
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
                cin >> nim;
                hashTable.hapusMahasiswa(nim);
                cout << "Data Mahasiswa berhasil dihapus." << endl;
                break;
            }
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan pilih lagi." << endl;
        }

        cout << endl;
    } while (opsi != 6);

    return 0;
}
```

#### Output
##### Tampilan Menu 
![menu](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/904e4342-be22-4aec-992c-ffb495364933)

##### Tampilan pada saat memilih opsi 1 untuk menambah Data Mahasiswa
![tambahmhs](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/b0f7400b-94af-4823-8b24-65f1709c99d4)

##### Tampilan pada saat memilih opsi 2 untuk menampilkan seluruh Data Mahasiswa yang telah ditambahkan
![slrhdtmhs](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/cffb7be8-98a8-4cf7-a537-160d0d927951)

##### Tampilan pada saat memilih opsi 3 untuk mencari mahasiswa berdasarkan NIM
![searchbynim](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/8cbfccd5-74e6-471f-a052-ea18b252416b)

##### Tampilan pada saat memilih opsi 4 untuk menampilkan Data Mahasiswa dengan Nilai 80-90
![mhs80-90](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/e4749815-10e9-4eff-847b-21e09cb3baac)

##### Tampilan pada saat memilih opsi 5 untuk emnghapus Data yang dipilih berdasarkan NIM dan Tampilan pada seluruh Data Mahasiswa setelah data terhapus
![hpsmhs](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/44d82559-1a44-4187-a3a0-dc1174e1d1bc)

##### Tampilan akhir dari Seluruh Data Mahasiswa dan keluar dari program
![last](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/6aa9eb09-98cc-4e7f-8ed2-5b557829c13c)

#### Deskripsi Program
Program di atas merupakan implementasi sederhana dari hash table dalam bahasa C++ untuk mengelola data mahasiswa. Program ini memungkinkan pengguna untuk menambahkan data mahasiswa, menampilkan seluruh data mahasiswa, mencari data mahasiswa berdasarkan NIM, mencari data mahasiswa berdasarkan rentang nilai (80-90), dan menghapus data mahasiswa.</br>

Program dimulai dengan mendefinisikan struktur data `Mahasiswa` yang berisi nama, NIM, dan nilai mahasiswa. Kemudian, dibuat kelas `HashTable` yang menggunakan vektor untuk menyimpan data mahasiswa.</br>

Setiap elemen dalam vektor merupakan tabel hash yang berisi daftar mahasiswa dengan NIM yang menghasilkan indeks yang sama. Program memiliki fungsi hash sederhana untuk mengonversi NIM menjadi indeks dalam tabel hash. Fungsi ini menggunakan pendekatan penjumlahan karakter dari NIM. Terdapat berbagai fungsi dalam kelas `HashTable` seperti `tambahMahasiswa` untuk menambahkan data mahasiswa baru, `tampilkanSeluruhData` untuk menampilkan seluruh data mahasiswa, `cariMahasiswaNIM` untuk mencari data mahasiswa berdasarkan NIM, `cariMahasiswaNilai` untuk mencari data mahasiswa berdasarkan rentang nilai (80-90), dan `hapusMahasiswa` untuk menghapus data mahasiswa berdasarkan NIM. </br>

Program juga menyediakan fungsi `tampilkanMenu` untuk menampilkan menu dan meminta input dari pengguna. Pada fungsi `main`, program menggunakan loop `do-while` untuk menampilkan menu, menerima input dari pengguna, dan menjalankan operasi yang sesuai berdasarkan pilihan pengguna.</br>

Proses berlangsung terus menerus hingga pengguna memilih opsi untuk keluar dari program. </br>


## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Hash table adalah struktur data yang digunakan untuk menyimpan data dengan cara mengonversi kunci (key) menjadi indeks dalam sebuah array menggunakan fungsi hash. Dalam bahasa pemrograman C++, hash table dapat diimplementasikan menggunakan array dan teknik penanganan tabrakan, seperti chaining (menyimpan data dengan kunci yang sama dalam linked list pada setiap slot tabel hash) atau linear probing (mencari slot kosong terdekat untuk menyimpan data yang menabrak).</br>

Implementasi hash table dapat digunakan dalam berbagai aplikasi, termasuk pengelolaan data mahasiswa seperti yang terlihat dalam contoh program di Guided 1, Guided 2, dan Unguided. </br>

Dalam unguided, program hash table untuk pengelolaan data mahasiswa, fungsi hash digunakan untuk mengonversi NIM menjadi indeks dalam tabel hash, memungkinkan pengaksesan data yang cepat. Program tersebut juga memberikan antarmuka yang interaktif kepada pengguna untuk melakukan operasi seperti penambahan, pencarian, dan penghapusan data mahasiswa. Dengan menggunakan hash table, pengelolaan data mahasiswa menjadi lebih efisien dan cepat dibandingkan dengan struktur data lainnya, terutama ketika jumlah data menjadi besar.</br>

Penggunaan hash table membutuhkan pemikiran yang cermat dalam pemilihan fungsi hash yang baik untuk mendistribusikan data dengan merata ke dalam tabel hash. Melalui program tersebut, kita dapat melihat bagaimana penggunaan hash table dapat meningkatkan efisiensi dalam pengelolaan data mahasiswa dengan menyediakan antarmuka yang mudah digunakan.</br>
<div/>
  
## Referensi
[1] Rahim, I., Anwar, N., Widodo, A. M., Juman, K. K., & Setiawan, I. (2023). "Komparasi Fungsi Hash Md5 Dan Sha256 Dalam Keamanan Gambar Dan Teks." Jurnal Ilmiah Teknik Informatika. Program Studi Teknik Informatika Fakultas Ilmu Komputer Universitas Esa Unggul dan Program Studi Teknik Informatika Fakultas Engineering, Computer and Design, Universitas Nusa Putra. </br>
[2]  W. Rifa'i, "Fungsi Hash berdasarkan Henon Map. (2022)." Program Studi Teknik Informatika, Sekolah Teknik Elektro dan Informatika, Institut Teknologi Bandung, No. Mahasiswa: 13513073.</br>
[3] Prestiliano, Jasson. (2010). "Aplikasi Table Hash dalam Pengarsipan dan Pencarian Data". Jurnal Teknologi Informasi, Vol. 4, No. 1,p. 41-56 </br>
[4] S. W. Bray. (2020). "Implementing Cryptography using Python". Indianapolis: John Wiley & Sons, Inc. </br>
[5] Cormen, Thomas H. (2009). "Introduction to AlgorithmS". Text Book. 3rd edition(Mit Press).</br>
[6] Weiss, Mark. "Data Structures & Algorithm Analysis in C++". Text Book. 4th Edition.</br>
[7] Weiss, Mark. (2013). "Data Structures and Algorithm Analysis in Java". Text Book. 2nd Edition.</br>

