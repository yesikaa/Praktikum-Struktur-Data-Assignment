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