#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseSentence(const string& kalimat) 
{
    stack <string> stack;
    stringstream r047(kalimat);
    string kata;

    // Memasukkan setiap kata (yang sudah dibalik) ke dalam stack
    while (r047 >> kata) 
    {
        reverse(kata.begin(), kata.end()); // Membalikkan kata
        stack.push(kata);
    }

    string reversedSentence;
    while (!stack.empty()) 
    {
        reversedSentence += stack.top();
        stack.pop();

        // Tambahkan spasi setelah kata kecuali untuk kata terakhir
        if (!stack.empty()) 
        {
            reversedSentence += " ";
        }
    }

    return reversedSentence;
}

int main() 
{
    string kalimat;
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat);
    string hasil = reverseSentence(kalimat);
    cout << "Kalimat Asli: " << kalimat << endl;
    cout << "Hasil Pembalikkan Kalimat: " << hasil << endl;
    return 0;
}
