#include <iostream>
#include <string>
using namespace std;

class Mahasiswa 
{
    public:
        string nama;
        string nim;
        string namaBaru;
        Mahasiswa* next;

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
        Mahasiswa* head;

    public:
        LinkedList() 
        {
            head = nullptr;
        }

        //Fungsi untuk menambahkan data di depan
        void tambahDepan(string nama, string nim, string namaBaru) 
        {
            Mahasiswa* newNode = new Mahasiswa(nama, nim, namaBaru);
            newNode->next = head;
            head = newNode;
        }

        //Fungsi untuk menambahkan data di belakang
        void tambahBelakang(string nama, string nim, string namaBaru) 
        {
            Mahasiswa* newNode = new Mahasiswa(nama, nim, namaBaru);
            if (head == nullptr) 
            {
                head = newNode;
                return;
            }
            Mahasiswa* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        // Fungsi untuk menambahkan data di Tengah
        void tambahTengah(string nama, string nim, string namaBaru, int posisi) 
        {
            if (posisi < 1) 
            {
                cout << "Posisi tidak tepat." << endl;
                return;
            }
            Mahasiswa* newNode = new Mahasiswa(nama, nim, namaBaru);
            if (posisi == 1) 
            {
                newNode->next = head;
                head = newNode;
                return;
            }
            Mahasiswa* temp = head;
            for (int i = 1; i < posisi - 1; i++) 
            {
                if (temp == nullptr) 
                {
                    cout << "Posisi tidak tepat." << endl;
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        //Fungsi untuk mengubah data dengan posisi di depan
        void ubahDepan(string nama, string nim, string namaBaru) 
        {
            if (head == nullptr) 
            {
                cout << "Linked list kosong." << endl;
                return;
            }
            head->nama = nama;
            head->nim = nim;
            head->namaBaru = namaBaru;
            cout << "Data " << head->nama << " telah berhasil diubah dengan data " << namaBaru << "." << endl;
        }

        //Fungsi untuk mengubah data dengan posisi di Belakang
        void ubahBelakang(string nama, string nim, string namaBaru) 
        {
            if (head == nullptr) 
            {
                cout << "Linked list kosong." << endl;
                return;
            }
            Mahasiswa* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->nama = nama;
            temp->nim = nim;
            temp->namaBaru = namaBaru;
            cout << "Data " << temp->nama << " terakhir telah berhasil diubah dengan data " << namaBaru << "." << endl;
        }

        //Fungsi untuk mengubah data dengan posisi di Tengah
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
            Mahasiswa* temp = head;
            for (int i = 1; i < posisi; i++) 
            {
                if (temp == nullptr) 
                {
                    cout << "Posisi tidak tepat." << endl;
                    return;
                }
                temp = temp->next;
            }
            temp->nama = nama;
            temp->nim = nim;

            string namaLama;
            temp->namaBaru = namaBaru;

            cout << "Data " << namaLama << " pada posisi " << posisi << " telah berhasil diubah dengan data " << namaBaru << "." << endl;
        }

        //Fungsi untuk menghapus data di bagian depan
        void hapusDepan() 
        {
            if (head == nullptr) 
            {
                cout << "Linked list kosong." << endl;
                return;
            }
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
            cout << "Data " << temp->namaBaru << " telah berhasil dihapus." << endl; // Menunjukan perintah yang diminta telah berhasil
        }

        //Fungsi untuk menghapus data di bagian belakang
        void hapusBelakang() 
        {
            if (head == nullptr) 
            {
                cout << "Linked list kosong." << endl;
                return;
            }
            if (head->next == nullptr) 
            {
                delete head;
                head = nullptr;
                cout << "Data " << head->namaBaru << " telah berhasil dihapus." << endl; // Menunjukan perintah yang diminta telah berhasil
                return;
            }
            Mahasiswa* temp = head;
            while (temp->next->next != nullptr) 
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            cout << "Data " << temp->next->namaBaru << " pada posisi terakhir telah berhasil dihapus." << endl;
        }
        
        //Fungsi untuk menghapus data di bagian tengah
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
            Mahasiswa* temp = head;
            for (int i = 1; i < posisi - 1; i++) 
            {
                if (temp == nullptr || temp->next == nullptr) 
                {
                    cout << "Posisi tidak tepat." << endl;
                    return;
                }
                temp = temp->next;
            }
            Mahasiswa* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << "Data " << nodeToDelete->namaBaru << " pada posisi " << posisi << " telah berhasil dihapus." << endl;
        }

        void hapusList() 
        {
            Mahasiswa* temp = head;
            while (temp != nullptr) 
            {
                Mahasiswa* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            head = nullptr;
            cout << "Seluruh data telah berhasil dihapus." << endl;
        }

        void tampilkan() 
        {
            if (head == nullptr) 
            {
                cout << "Linked list kosong." << endl;
                return;
            }
            Mahasiswa* temp = head;
            cout << "DATA MAHASISWA" << endl;
            cout << "No\tNAMA\tNIM" << endl;
            int nomor = 1;
            while (temp != nullptr) {
                cout << nomor << "\t" << temp->namaBaru << "\t" << temp->nim << endl;
                temp = temp->next;
                nomor++;
            }
        }
};

int main() 
{
    LinkedList linkedList;

    while (true) 
    {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
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

        if (pilih == 1) //Untuk memanggil fungsi menambahkan data di depan (Tambah Depan)
        {
            string nama, nim, namaBaru;
            cout << "Tambah Depan\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM: ";
            cin >> nim;
            linkedList.tambahDepan(nama, nim, namaBaru);
            cout << "Data telah berhasil ditambahkan" << endl;
        }
        else if (pilih == 2) //Untuk memanggil fungsi menambahkan data di belakang (Tambah Belakang)
        {
            string nama, nim, namaBaru;
            cout << "Tambah Belakang\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM: ";
            cin >> nim;
            linkedList.tambahBelakang(nama, nim, namaBaru);
            cout << "Data telah berhasil ditambahkan" << endl;
        }
        else if (pilih == 3) //Untuk memanggil fungsi menambahkan data di Tengah (Tambah Tengah)
        {
            string nama, nim, namaBaru;
            int posisi;
            cout << "Tambah Tengah Sesuai Posisi\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Posisi Data: ";
            cin >> posisi;
            linkedList.tambahTengah(nama, nim, namaBaru, posisi);
            cout << "Data telah berhasil ditambahkan" << endl;
        }
        else if (pilih == 4) //Untuk memanggil fungsi mengubah data di depan (Ubah Depan)
        {
            string nama, nim, namaBaru;

            cout << "Ubah Depan\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru: ";
            cin >> nim;
            linkedList.ubahDepan(nama, nim, namaBaru);
        }
        else if (pilih == 5) //Untuk memanggil fungsi mengubah data di belakang (Ubah Belakang)
        {
            string nama, nim, namaBaru;
            cout << "Ubah Belakang\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru: ";
            cin >> nim;
            linkedList.ubahBelakang(nama, nim, namaBaru);
        }
        else if (pilih == 6) // Untuk memanggil fungsi mengubah data di tengah (Ubah Tengah)
        {
            string nama, nim, namaBaru;
            int posisi;
            cout << "Ubah Tengah\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru: ";
            cin >> nim;
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            linkedList.ubahTengah(nama, nim, namaBaru, posisi);
        }
        else if (pilih == 7) {
            linkedList.hapusDepan();
        }
        else if (pilih == 8) {
            linkedList.hapusBelakang();
        }
        else if (pilih == 9) {
            int posisi;
            cout << "Masukkan Posisi Data: ";
            cin >> posisi;
            linkedList.hapusTengah(posisi);
        }
        else if (pilih == 10) {
            linkedList.hapusList();
        }
        else if (pilih == 11) {
            linkedList.tampilkan();
        }
        else if (pilih == 0) {
            cout << "Program selesai." << endl;
            break;
        }
        else {
            cout << "Pilihan tidak tepat. Silakan masukan pilihan yang tepat." << endl;
        }
    }

    return 0;
}