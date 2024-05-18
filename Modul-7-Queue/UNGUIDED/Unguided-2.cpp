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
