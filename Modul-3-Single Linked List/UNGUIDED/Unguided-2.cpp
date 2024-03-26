#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

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
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapusData(string namaProduk) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaProduk) {
                if (current == head) {
                    head = current->next;
                    if (head != NULL)
                        head->prev = NULL;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void updateData(string namaProduk, int hargaBaru) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaProduk) {
                current->harga = hargaBaru;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

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

    void hapusDataUrutanTertentu(int urutan) {
        Node* current = head;
        int pos = 1;
        while (current != NULL && pos < urutan) {
            current = current->next;
            pos++;
        }

        if (current == NULL || current == tail) {
            cout << "Urutan tidak valid" << endl;
            return;
        }

        if (current == head) {
            head = current->next;
            head->prev = NULL;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
    }

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
    DoubleLinkedList tokoSkincare;
    int pilihan;
    string namaProduk;
    int harga, urutan;

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
                tokoSkincare.tambahData(namaProduk, harga);
                break;
            case 2:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                tokoSkincare.hapusData(namaProduk);
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> namaProduk;
                cout << "Masukkan harga baru: ";
                cin >> harga;
                tokoSkincare.updateData(namaProduk, harga);
                break;
            case 4:
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan urutan: ";
                cin >> urutan;
                tokoSkincare.tambahDataUrutanTertentu(namaProduk, harga, urutan);
                break;
            case 5:
                cout << "Masukkan urutan data yang ingin dihapus: ";
                cin >> urutan;
                tokoSkincare.hapusDataUrutanTertentu(urutan);
                break;
            case 6:
                tokoSkincare.hapusSeluruhData();
                cout << "Data berhasil dihapus semua" << endl;
                break;
            case 7:
                tokoSkincare.tampilkanData();
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
