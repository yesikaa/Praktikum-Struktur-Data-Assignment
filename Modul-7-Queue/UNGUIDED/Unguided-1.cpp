// Yesika Widiyani
// 2311102195

#include <iostream>

using namespace std;

//Struktur node untuk linked list
struct Node {
    string data;
    Node* next;
};

//Pointer untuk front dan back dari queue
Node* front = nullptr;
Node* back = nullptr;

//Fungsi mengecek apakah queue penuh
bool isFull()
{
    return false; // Linked list tidak pernah penuh (bergantung pada memori)
}

//Fungsi mengecek apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

//Fungsi menambahkan elemen ke dalam queue
void enqueueAntrian(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if(isEmpty()) 
    {
        front = back = newNode;
    } else
    {
        back->next = newNode;
        back = newNode;
    }
}

//Fungsi menghapus elemen dari queue
void dequeueAntrian()
{
    if(isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    } else{
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            back = nullptr;
        }
    }
}

//Fungsi menghitung jumlah elemen dalam queue
int countQueue() 
{
    int count = 0;
    Node* current = front;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi menghapus semua elemen dalam queue
void clearQueue() 
{
    while (!isEmpty()) 
    {
        dequeueAntrian();
    }
}

// Fungsi melihat elemen-elemen dalam queue
void viewQueue() 
{
    cout << "Data antrian teller:" << endl;
    Node* current = front;
    int index = 1;
    while (current != nullptr) 
    {
        cout << index << ". " << current->data << endl;
        current = current->next;
        index++;
    }
    if (index == 1) 
    {
        cout << "Antrian kosong" << endl;
    }
}

// Fungsi utama untuk menjalankan contoh penggunaan
int main() 
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    cout << "\n" << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    cout << "\n" << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    cout << "\n" << endl;    clearQueue();

    return 0;
}