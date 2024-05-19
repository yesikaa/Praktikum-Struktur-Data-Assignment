// Yesika Widiyani
// 2311102195

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Fungsi untuk melakukan binary search dan mengembalikan posisi asli huruf jika ditemukan
int binary_search(const vector<pair<char, int>>& sorted_kalimat, char cari) 
{
    int awal = 0, akhir = sorted_kalimat.size() - 1;
    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;
        if (sorted_kalimat[tengah].first == cari) {
            return sorted_kalimat[tengah].second; // Kembalikan posisi asli
        } else if (sorted_kalimat[tengah].first < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    return -1; // Kembalikan -1 jika huruf tidak ditemukan
}

int main() 
{
    string kalimat;
    char cari;
    
    cout << ">>>>> MENCARI HURUF <<<<<\n";
    cout << "Masukkan Kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> cari;
    cari = tolower(cari);

    // Membuat vector pasangan karakter dan indeks asli
    vector<pair<char, int>> indexed_kalimat;
    for (int i = 0; i < kalimat.size(); ++i) {
        indexed_kalimat.emplace_back(tolower(kalimat[i]), i);
    }

    // Sort berdasarkan karakter
    sort(indexed_kalimat.begin(), indexed_kalimat.end());

    int posisi = binary_search(indexed_kalimat, cari);
    if (posisi != -1) {
        cout << "Huruf '" << cari << "' ditemukan pada posisi asli: " << posisi << endl;
    } else {
        cout << "Huruf '" << cari << "' tidak ditemukan." << endl;
    }
    
    return 0;
}
