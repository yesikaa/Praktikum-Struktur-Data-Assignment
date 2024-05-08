#include <iostream>
#include <stack>
#include <string>
#include <locale>

using namespace std;

//Fungsi Untuk mengabaikan spasi dan mengubah huruf agar tetap terbaca lowercase
string preprocess (string str) 
{
    string result = "";
    for (char c : str) 
    {
        if (isalpha(c))
            result += tolower(c);
    }
    return result;
}

bool isPolindrome(string str)
{
    stack<char> s;
    int len = str.length();

    // Menambah setengah karakter pertama ke stack
    for (int i = 0; i < len/2; ++i) 
    {
        s.push(str[i]);
    }

    //Mengecek apakah kalimat tersebut adalah polindrom atau tidak
    for (int i = (len+1)/2; i < len; ++i) 
    {
        if (str[i] != s.top()) 
        {
            return false;
        }
        s.pop();
    }
    return true;
} 

int main()
{
    string kalimat;
    cout << "Masukkan sebuah kalimat : " << endl;
    getline(cin, kalimat);

    string processed = preprocess(kalimat);

    if (isPolindrome(processed))
    {
        cout << "Kalimat tersebut merupakan kalimat polindrom." << endl;
    } 
    else
    {
        cout << "Kalimat tersebut bukan kalimat polindrom." << endl;
    }

    return 0;
}