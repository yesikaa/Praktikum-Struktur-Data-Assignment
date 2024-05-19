#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Fungsi untuk mencari huruf vokal dalam kalimat
int hitungVokal(const string& kalimat, string& hurufVokalDitemukan) {
    int jumlahVokal = 0;
    string vokal = "aeiouAEIOU";
    unordered_set<char> hurufVokalSet; // Set untuk menyimpan huruf vokal yang ditemukan
    
    for (char c : kalimat) {
        // Linear search untuk memeriksa apakah karakter adalah huruf vokal
        for (char v : vokal) {
            if (c == v) {
                jumlahVokal++;
                hurufVokalSet.insert(tolower(c)); // Menyimpan huruf vokal yang ditemukan
                break; // Jika ditemukan, lanjut ke karakter berikutnya dalam kalimat
            }
        }
    }
    
    // Mengkonversi set ke dalam string untuk ditampilkan
    for (char vokalDitemukan : hurufVokalSet) {
        hurufVokalDitemukan += vokalDitemukan;
    }
    
    return jumlahVokal;
}

int main() {
    string kalimat;
    string hurufVokalDitemukan; // String untuk menyimpan huruf vokal yang ditemukan

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung jumlah huruf vokal dan mendapatkan huruf vokal yang ditemukan
    int jumlahVokal = hitungVokal(kalimat, hurufVokalDitemukan);

    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal << endl;
    cout << "Huruf vokal yang ditemukan: " << hurufVokalDitemukan << endl;

    return 0;
}
