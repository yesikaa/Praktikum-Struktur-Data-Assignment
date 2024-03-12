#include <iostream>
using namespace std;

// Struct untuk menampilkan data Anggota
struct Anggota
{
    string name;
    int angkatan;
};
// Class untuk menampilkan data divisi anggota
class Divisi {
    public : 
    string organisasi;
    int tahun;
    string divisi;
    
    //Menampilkan data Anggota
    void TampilkanData(){
        cout << "Organisasi :" << organisasi << endl;
        cout << "Tahun :" << tahun << endl;
        cout << "Divisi :" << divisi << endl;
    }
};

// Main Program
int main ()
{
    //Menggunakan struct Anggota
    Anggota mhs;
    mhs.name = "Yesika";
    mhs.angkatan = 23;
    cout << "Nama Anggota : " << mhs.name << endl;
    cout << "Angkatan : " << mhs.angkatan << endl;

    // Menggunakan Class Divisi
    Divisi agt;
    agt.organisasi = "Kepanitiaan Teknik Informatika";
    agt.tahun = 2023;
    agt.divisi = "Sekretaris";
    agt.TampilkanData();

return 0;

}