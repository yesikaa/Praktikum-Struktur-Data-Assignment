//Yesika Widiyani
//2311102195

#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon 
{
    char data_yes2311102195;
    Pohon *left, *right, *parent; //pointer
};

// Pointer global
Pohon *root;

// Inisialisasi
void init() 
{
    root = NULL;
}

bool isEmpty() 
{
    return root == NULL;
}

Pohon *newPohon(char data) 
{
    Pohon *node = new Pohon();
    node->data_yes2311102195 = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) 
{
    if (isEmpty()) 
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else 
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) 
        {
            cout << "\nNode " << node->data_yes2311102195 << " sudah ada child kiri!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data_yes2311102195 << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else 
    {
        if (node->right != NULL) 
        {
            cout << "\nNode " << node->data_yes2311102195 << " sudah ada child kanan!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data_yes2311102195 << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) 
        {
            cout << "\nNode yang ingin diganti tidak ada!" << endl;
        } else 
        {
            char temp = node->data_yes2311102195;
            node->data_yes2311102195 = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) 
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else 
        {
            cout << "\nData node: " << node->data_yes2311102195 << endl;
        }
    }
}

void find(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) 
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else 
        {
            cout << "\nData Node : " << node->data_yes2311102195 << endl;
            cout << "Root : " << root->data_yes2311102195 << endl;
            if (!node->parent) 
            {
                cout << "Parent : (tidak punya parent)" << endl;
            } else 
            {
                cout << "Parent : " << node->parent->data_yes2311102195 << endl;
                if (node->parent->left != node && node->parent->right == node)
                    cout << "Sibling : " << node->parent->left->data_yes2311102195 << endl;
                else if (node->parent->right != node && node->parent->left == node)
                    cout << "Sibling : " << node->parent->right->data_yes2311102195 << endl;
                else
                    cout << "Sibling : (tidak punya sibling)" << endl;
            }
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data_yes2311102195 << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data_yes2311102195 << endl;
        }
    }
}

void displayChildren(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else if (!node) 
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    } else {
        cout << "\nData Node : " << node->data_yes2311102195 << endl;
        if (!node->left)
            cout << "Child Kiri : (tidak punya Child kiri)" << endl;
        else
            cout << "Child Kiri : " << node->left->data_yes2311102195 << endl;
        if (!node->right)
            cout << "Child Kanan : (tidak punya Child kanan)" << endl;
        else
            cout << "Child Kanan : " << node->right->data_yes2311102195 << endl;
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) 
{
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data_yes2311102195 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

void displayDescendants(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else if (!node) 
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    } else 
    {
        cout << "\nDescendants of Node " << node->data_yes2311102195 << " : ";
        preOrder(node);
        cout << endl;
    }   
}

// inOrder
void inOrder(Pohon *node) 
{
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data_yes2311102195 << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) 
{
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data_yes2311102195 << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) 
{
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) 
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) 
            {
                delete root;
                root = NULL;
            } else 
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data_yes2311102195 << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else 
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {

    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) 
        {
            return 0;
        } else 
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) 
        {
            return 0;
        } else 
        {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        }
    }
}

void characteristic() 
{
    if (!isEmpty()) 
    {
        cout << "\nKarakteristik Tree";
        cout << "\nSize : " << size(root);
        cout << "\nHeight : " << height(root) << endl;
    } else 
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    }
}

// Fungsi untuk mencari node berdasarkan data
Pohon* findNode(Pohon* node, char data) {
    if (!node) return NULL;
    if (node->data_yes2311102195 == data) return node;
    Pohon* foundNode = findNode(node->left, data);
    if (foundNode) return foundNode;
    return findNode(node->right, data);
}

void menu() 
{
    int choice;
    char data;
    char parentData;
    Pohon *node = nullptr;

    do 
    {
        cout << "\n>>>>> M E N U <<<<<:";
        cout << "\n1. Buat Root Node";
        cout << "\n2. Tambah Child Kiri";
        cout << "\n3. Tambah Child Kanan";
        cout << "\n4. Update Node";
        cout << "\n5. Retrieve Node";
        cout << "\n6. Find Node";
        cout << "\n7. Tampilkan Child Node";
        cout << "\n8. Tampilkan Descendants Node";
        cout << "\n9. PreOrder Traversal";
        cout << "\n10. InOrder Traversal";
        cout << "\n11. PostOrder Traversal";
        cout << "\n12. Tampilkan Karakteristik Tree";
        cout << "\n13. Hapus SubTree";
        cout << "\n14. Clear Tree";
        cout << "\n0. Exit";
        cout << "\nPilih menu: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data child kiri: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    insertLeft(data, node);
                else
                    cout << "\nParent node tidak ditemukan!" << endl;
                break;
            case 3:
                cout << "Masukkan data child kanan: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    insertRight(data, node);
                else
                    cout << "\nParent node tidak ditemukan!" << endl;
                break;
            case 4:
                cout << "Masukkan data baru: ";
                cin >> data;
                cout << "Masukkan node yang akan diupdate: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    update(data, node);
                else
                    cout << "\nNode tidak ditemukan!" << endl;
                break;
            case 5:
                cout << "Masukkan node yang akan diretrieve: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    retrieve(node);
                else
                    cout << "\nNode tidak ditemukan!" << endl;
                break;
            case 6:
                cout << "Masukkan node yang akan ditemukan: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    find(node);
                else
                    cout << "\nNode tidak ditemukan!" << endl;
                break;
            case 7:
                cout << "Masukkan node yang akan ditampilkan child-nya: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    displayChildren(node);
                else
                    cout << "\nNode tidak ditemukan!" << endl;
                break;
            case 8:
                cout << "Masukkan node yang akan ditampilkan descendants-nya: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    displayDescendants(node);
                else
                    cout << "\nNode tidak ditemukan!" << endl;
                break;
            case 9:
                cout << "PreOrder Traversal:" << endl;
                preOrder(root);
                cout << endl;
                break;
            case 10:
                cout << "InOrder Traversal:" << endl;
                inOrder(root);
                cout << endl;
                break;
            case 11:
                cout << "PostOrder Traversal:" << endl;
                postOrder(root);
                cout << endl;
                break;
            case 12:
                characteristic();
                break;
            case 13:
                cout << "Masukkan node subtree yang akan dihapus: ";
                cin >> parentData;
                node = findNode(root, parentData);
                if (node)
                    deleteSub(node);
                else
                    cout << "\nNode tidak ditemukan!" << endl;
                break;
            case 14:
                clear();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 0);
}

int main() 
{
    init();
    menu();
    return 0;
}
