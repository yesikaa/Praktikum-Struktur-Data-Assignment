#include <iostream>
#include <map>
using namespace std;

//Main Program
int main()
{
    map<string, string> NoHandphone;

    //Menambahkan informasi nomor handphone ke dalam map
    NoHandphone["Yesika"] = "878-5458-7496";
    NoHandphone["Anggi"] = "813-2580-6705";
    NoHandphone["Haura"] = "821-0427-2004";
    NoHandphone["Syamil"] = "878-1030-8932";
    NoHandphone["Okta"] = "896-4242-6232";
    NoHandphone["Defa"] = "812-9090-3012";
    NoHandphone["Kaza"] = "821-1616-6475";
    NoHandphone["Widiya"] = "821-2604-2509";
    NoHandphone["Mei"] = "896-5555-7675";
    NoHandphone["Amanda"] = "812-1314-5657";
    NoHandphone["Satria"] = "878-7777-4535";

    //Menampilkan informasi Nomor handphone
    cout << "Informasi Nomor Telephone : " << endl;
    for (const auto& entry : NoHandphone){
        cout << entry.first << ": " << entry.second << endl;
    }
    return 0;
}

