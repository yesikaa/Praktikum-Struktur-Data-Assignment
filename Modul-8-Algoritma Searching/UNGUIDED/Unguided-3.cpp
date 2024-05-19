#include <iostream>
#include <vector>
#include <utility> // Untuk std::pair

using namespace std;

// Fungsi untuk menghitung berapa banyak angka 4 dalam array menggunakan Sequential Search
int hitungAngkaEmpat(const vector<int>& data, vector<pair<int, int>>& urutanAngkaEmpat) {
    int jumlahEmpat = 0;
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == 4) {
            jumlahEmpat++;
            urutanAngkaEmpat.push_back(make_pair(data[i], i)); // Menyimpan angka 4 beserta posisinya
        }
    }
    
    return jumlahEmpat;
}

int main() {
    // Data yang diberikan
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    vector<pair<int, int>> urutanAngkaEmpat;

    // Menghitung jumlah angka 4 dan mendapatkan urutan serta posisi angka 4
    int jumlahEmpat = hitungAngkaEmpat(data, urutanAngkaEmpat);

    // Menampilkan pesan "Menghitung angka 4" beserta data
    cout << "Menghitung angka 4\nData: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Menampilkan hasil jumlah angka 4
    cout << "Jumlah angka 4 dalam data adalah: " << jumlahEmpat << endl;

    // Menampilkan urutan angka 4 dan posisinya
    cout << "Urutan angka 4 dalam data beserta posisinya: ";
    for (auto p : urutanAngkaEmpat) {
        cout << p.first << " (posisi: " << p.second << ") ";
    }
    cout << endl;

    return 0;
}