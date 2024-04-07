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
