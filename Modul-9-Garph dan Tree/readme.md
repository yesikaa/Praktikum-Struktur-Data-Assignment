# <h1 align="center">Laporan Praktikum Modul GARPH and TREE	</h1>
<p align="center" style="font-size:16px;">Yesika Widiyani</p>
<p align="center" style="font-size:16px;">2311102195</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Tujuan Praktikum
```
1. Mahasiswa diharapkan mampu memahami graph dan tree
2. Mahasiswa diharapkan mampu mengimplementasikan graph dan tree pada pemrograman
```

## Dasar Teori
<p style="text-align: justify; font-size: 12px;">
Graf atau Graph adalah suatu kumpulan simpul atau yang biasa disebut juga dengan node, yang dihubungkan satu sama lain melalui sisi / busur.  Graph ini merupakan alah atu jenis struktur data yang terdiri dari titik (vertex) dan garis(edges) dimana dalam graf tersebut vertex saling dihubungkan oleh edge. Ada dua jenis graph yaitu, graph berarah dan graph tidak berarah[1]. Graph yang tidak berarah ini merupakan graf yang sisi-sisinya tidak mengarah ke segala arah[2].</br>

Secara singkat suatu graph dapat ditulis sebagai G = (V,E) yang dalam hal ini[3]:</br>
V = Himpunan berhingga dan tidak kosong dari simpul-simpul (vertex).</br>
  = { v1, v2,…vn }</br>
E = Himpunan sisi yang menghubungkan sepasang simpul.</br>
  = { e1, e2,…en }</br>
[3]</br>

Simpul pada graph dapat dinomori dengan huruf, seperti v,w,…, dengan bilangan asli 1,
2,3,…, atau gabungan keduanya. Sisi (edge) yang menghubungkan dua simpul (vertex) vi dan vj dinyatakan dengan pasangan (vi , vj) atau dengan lambang e1, e2 , dengan kata lain, jika e adalah sisi yang menghubungkan simpul vi dan vj, maka e dapat ditulis sebagai e = (vi , vj).</br>
[3]</br>

Menurut arah dan bobotnya, graf dibagi menjadi empat bagian, yaitu:</br>
1.  Graf berarah dan berbobot : tiap busur mempunyai anak panah dan bobot.</br>
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/abbd1eb7-e220-4844-9df2-8686f2828d36)
2. Graf tidak berarah dan berbobot : tiap busur tidak mempunyai anak panah tetapi mempunyai bobot.</br>
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/f61cb885-fd65-475e-b97d-7f1edde254f6)
3. Graf berarah dan tidak berbobot: tiap busur mempunyai anak panah yang tidak berbobot.</br>
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/e48891cf-d907-44ef-b0e0-1af202d31c44)
4. Graf tidak berarah dan tidak berbobot: tiap busur tidak mempunyai anak panah dan tidak berbobot.</br>
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/4f0df519-8d96-47e5-918a-f6cf304e1c64)
[3].</br>

Tree adalah graf terhubung dan tidak memiliki sirkuit. Penerapan minimal spaning tree dapat memecahkan masalah yang meliputi berbagai bidang dalam kehidupan sehari-hari[2]. Pada tree sendiri terdapat node dimana salah satu node yang sering digunakan adalah root[4]. </br>

Konsep pohon (tree) adalah konsep yang paling terkenal dan cukup penting dibandingkan konsep lainnya yang ada dalam teori graf, karena mampu menyelesaikan permasalahan dalam berbagai terapan masalah graf, misalnya konsep pohon merentang (Spanning Tree) yang digunakan oleh perusahaan kereta api dalam menentukan jalur yang akan dilalui oleh kereta, dengan mempertimbangkan bobot biaya yang minimum. Jika konsep spanning tree digunakan untuk menyelesaikan suatu permasalahan dengan unsur pencarian bobot minimum pada sebuah graf berbobot, maka akan disebut sebagai MST (Minimum Spanning Tree)[5].</br>

1. Pohon Rentang (Spanning Tree) 
Pohon Rentang (Spanning Tree) merupakan suatu Subgraph dari suatu graph dimana setiap simpul pada pohon rentang sama dengan semua simpul pada graph[3].</br>
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/a48d0023-089a-4607-80cd-3181e61e00f4)

2. Pohon Rentang Minimum ( Minimum spanning tree )
Pohon Rentang (Spanning Tree) pada suatu graph adalah subgraph minimal yang menghubungkan semua simpul pada graph. Apabila graph tersebut adalah graph berbobot (Weighted Graph), kemudian dari pohon rentang yang dimiliki oleh graph didefinisikan sebagai penjumlahan dari bobot – bobot seluruh cabang pada pohon rentang maka akan diperoleh pohon rentang yang memiliki bobot. Pohon rentang yang memiliki bobot terkecil pada suatu graph berbobot disebut Pohon rentang Minimum (Minimum spanning tree)[3].</br>
![image](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/c045b578-2f17-4936-b0f7-1ec8a8491697)

## GUIDED
### Guided 1 - Contoh Program Graph
#### Source Code
```C++
// Program Graph

#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = 
{
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

int busur[7][7] = 
{
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph()
{
    for (int baris = 0; baris <7; baris ++)
    {
        cout <<" " << setiosflags (ios::left) << setw (15) << simpul [baris] << " : ";
        for (int kolom = 0; kolom<7; kolom++)
        {
            if (busur[baris][kolom]!=0)
            {
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main()
{
    tampilGraph();
    return 0;
}
```
#### Output
![g-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/a59eeae5-5e98-4090-9f68-986bd8478041)

#### Deskripsi Program
Program ini mengimplementasikan representasi dan visualisasi dari sebuah graf berbasis adjacency matrix menggunakan bahasa pemrograman C++. Program ini menampilkan sebuah graf yang terdiri dari 7 simpul, yaitu "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", dan "Yogyakarta". Setiap simpul direpresentasikan dalam array string bernama `simpul`. Hubungan atau busur antara simpul-simpul tersebut direpresentasikan dalam sebuah matriks 2D `busur`, dimana nilai-nilai dalam matriks menunjukkan bobot dari busur antara simpul-simpul terkait. Nilai nol dalam matriks mengindikasikan tidak adanya busur antara dua simpul.</br>

Cara Kerja program tersebut adalah sebagai berikut :
1. Pertama program akan melakukan inisialisasi Array `simpul` berisi nama-nama kota yang akan menjadi simpul dalam graf, dan Matriks `busur` adalah adjacency matrix yang menunjukkan bobot dari busur yang menghubungkan simpul-simpul tersebut. Contoh: `busur[0][1]` bernilai 7, yang berarti ada busur dari simpul "Ciamis" ke "Bandung" dengan bobot 7. </br>
2. Kemudian untuk fungsi dari `tampilGraph()` yaitu untuk Fungsi ini menampilkan graf dalam bentuk yang mudah dibaca. Iterasi melalui setiap baris dari matriks `busur` yang mewakili simpul awal. Untuk setiap simpul awal, fungsi ini akan mencetak nama simpul tersebut, diikuti oleh daftar simpul tujuan yang terhubung dengan bobot busur di dalam tanda kurung. Jika `busur[baris][kolom]` tidak sama dengan nol, itu berarti ada busur dari simpul awal (`simpul[baris]`) ke simpul tujuan (`simpul[kolom]`) dengan bobot tertentu, dan informasi ini akan dicetak.</br>
3. Fungsi `main()` memanggil fungsi `tampilGraph()` untuk menampilkan graf dan kemudian mengakhiri eksekusi program.
4. Pada output program di atas, graf ditampilkan dengan setiap simpul diikuti oleh daftar simpul tujuan yang terhubung beserta bobot busur antara mereka. Misalnya, "Ciamis" memiliki busur ke "Bandung" dengan bobot 7 dan ke "Bekasi" dengan bobot 8. Output ini memberikan representasi yang jelas tentang struktur graf dan hubungan antar simpul.

### Guided 2 - Contoh Program Tree
#### Source Code
```C++
//Program Tree

#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon 
{
    char data;
    Pohon *left, *right, *parent; //pointer
};

//pointer global
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
    node->data = data;
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
        cout << "\nNode " << data << " berhasil dibuat menjadi root." <<
        endl;
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
    } else 
    {
        if (node->left != NULL) 
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
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
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else 
    {
        if (!node)
        cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else 
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        } else 
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else 
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else 
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else 
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
            cout << "Parent : (tidak punya parent)" << endl;
            
            else
            cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)

            cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)

            cout << "Sibling : " << node->parent->right->data << endl;

            else
            cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
            cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            
            else
            cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
            cout << "Child Kanan : (tidak punya Child kanan)" << endl;

            else
            cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
    if (node != NULL) 
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
    }
}

// inOrder
void inOrder(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
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
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    else 
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else 
    {
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
    } else 
    {
        if (!node) 
        {
            return 0;
        } else 
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) 
            {
                return heightKiri + 1;
            } else 
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() 
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
    cout << "Average Node of Tree : " << s / h << endl;
    else
    cout << "Average Node of Tree : 0" << endl;
}

int main() 
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
    *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}
```
#### Output
![g-2-a](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/e7b8e761-5648-4477-b2b6-347bfd04286a)
![g-2-b](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/dfed7b44-c776-4431-9799-a6cf30370946)

#### Deskripsi Program
Program ini mengimplementasikan sebuah pohon biner (binary tree) menggunakan bahasa pemrograman C++. Pohon biner tersebut terdiri dari simpul (node) yang masing-masing memiliki data, serta pointer ke anak kiri, anak kanan, dan induk (parent). Program ini mencakup berbagai fungsi untuk manipulasi dan penelusuran pohon, seperti menambahkan node, memperbarui data node, menemukan node tertentu, serta melakukan traversal dalam tiga cara: pre-order, in-order, dan post-order. Selain itu, program ini juga memiliki fungsi untuk menghapus node, subpohon (subtree), atau seluruh pohon, serta menghitung ukuran (size) dan tinggi (height) pohon.</br>

Cara Kerja program tersebut adalah sebagai berikut :
1. Inisialisasi dan Pembuatan Node dengan `init()` untuk Menginisialisasi pohon dengan root diatur ke NULL. Selanjutnya `newPohon(char data)` untuk Membuat node baru dengan data tertentu, pointer anak dan induk diatur ke NULL. Dan `buatNode(char data)` untuk membuat root node jika pohon kosong, atau menampilkan pesan jika pohon sudah ada.</br>
2. Penambahakn Node dengan `insertLeft(char data, Pohon *node)` menambahkan node baru sebagai anak kiri dari node yang diberikan jika belum ada anak kiri. Dan `insertRight(char data, Pohon *node)` Menambahkan node baru sebagai anak kanan dari node yang diberikan jika belum ada anak kanan.</br>
3. Manipulasi Node dengan `update(char data, Pohon *node)` untuk Mengubah data dari node yang diberikan dengan data baru. Selanjutnya ada `retrieve(Pohon *node)` untuk menampilkan data dari node yang diberikan. Dan ada `find(Pohon *node)` untuk Menampilkan informasi detail dari node yang diberikan, termasuk root, parent, sibling, dan anak-anaknya.</br>
4. Traversal Pohon dengan `preOrder(Pohon *node)` sebagai Traversal pre-order, yang akan mencetak data node saat pertama kali dikunjungi. Selanjutnya ada `inOrder(Pohon *node)` dimana Traversal in-order, akan mencetak data node setelah mengunjungi anak kirinya. Sedangkan `postOrder(Pohon *node)` dimana Traversal post-order, akan mencetak data node setelah mengunjungi anak kiri dan kanan.</br>
5. Penghapusan Node dengan `deleteTree(Pohon *node)`unttuk  Menghapus seluruh pohon atau subpohon mulai dari node yang diberikan. Terdapat `deleteSub(Pohon *node)` utnuk Menghapus subpohon dari node yang diberikan, kecuali node itu sendiri. Dan `clear()` untuk Menghapus seluruh pohon.</br>
6. Karakteristik Pohon `size(Pohon *node)` untuk Menghitung jumlah total node dalam pohon. Selanjutnya ada `height(Pohon *node)` untuk Menghitung tinggi pohon, yaitu panjang jalur terpanjang dari root ke daun. Dan ada `characteristic()` untuk enampilkan ukuran dan tinggi pohon.</br>

## UNGUIDED
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
**Contoh Output**
![soal](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/9fbccf90-31a9-4dba-8d3f-10f828ca5d1b)

#### Source Code
```C++
//Yesika Widiyani
//2311102195

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk menampilkan adjacency matrix
void displayMatrix(vector<vector<int>>& matrix, vector<string>& nodes) 
{
    int yesika_2311102195 = matrix.size(); 

    cout << "\nAdjacency Matrix :" << endl;
    cout << "     "; 

    // Menampilkan nama-nama simpul di baris pertama
    for (int i = 0; i < yesika_2311102195; i++) 
    {
        cout << nodes[i] << "   ";
    }
    cout << endl;

    // Menampilkan isi dari adjacency matrix
    for (int i = 0; i < yesika_2311102195; i++) 
    {
        cout << nodes[i] << "    "; 
        for (int j = 0; j < yesika_2311102195; j++) {
            cout << matrix[i][j] << "   "; 
        }
        cout << endl;
    }
}

int main() 
{
    int numNodes;

    // Meminta user untuk memasukkan jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    
    // Meminta user untuk memasukkan nama-nama simpul
    cout << "Silakan masukkan nama simpul: " << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Membuat adjacency matrix dengan ukuran numNodes x numNodes
    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes));

    // Meminta user untuk memasukkan bobot antar simpul
    cout << "\nSilakan masukkan bobot antar simpul: " << endl;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << nodes[i] << " -> " << nodes[j] << " = ";
            cin >> adjacencyMatrix[i][j];
        }
    }

    // Menampilkan adjacency matrix
    displayMatrix(adjacencyMatrix, nodes);

    return 0;
}
```

#### Output
![UN-1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/0c7d0774-be7a-4edf-8cba-c59eebe05a5c)

#### Deskripsi Program
Program di atas adalah sebuah implementasi C++ untuk mengelola dan menampilkan adjacency matrix dari sebuah graf yang tidak berarah. Program dimulai dengan meminta pengguna untuk memasukkan jumlah simpul yang akan digunakan dalam graf. Setelah itu, pengguna diminta untuk memasukkan nama-nama dari setiap simpul yang telah ditentukan jumlahnya. Selanjutnya, program membuat adjacency matrix dengan ukuran sesuai jumlah simpul yang diberikan. Pengguna kemudian diminta untuk memasukkan bobot antar setiap pasangan simpul, yang berarti pengguna harus mengisi nilai dalam matriks yang menunjukkan adanya atau tidak adanya dan bobot koneksi antara dua simpul tertentu. Setelah semua input diterima, program menampilkan adjacency matrix yang telah terbentuk dengan mencetak nama-nama simpul di baris dan kolom pertama, diikuti oleh nilai-nilai bobot koneksi antar simpul yang diinput oleh pengguna. Fungsi `displayMatrix` bertugas menampilkan adjacency matrix ini dengan format yang rapi, membantu pengguna melihat hubungan antar simpul dengan jelas.</br>

Cara programnya bekerja adalah sebagai berikut:</br>
**1.Inisialisasi dan Input Jumlah Simpul** : Program dimulai dengan meminta pengguna untuk memasukkan jumlah simpul (node) dalam graf. Jumlah ini disimpan dalam variabel `numNodes`.</br>
**2. Input Nama Simpul**: Setelah jumlah simpul ditentukan, program meminta pengguna untuk memasukkan nama untuk setiap simpul. Nama-nama simpul ini disimpan dalam sebuah vektor `nodes` yang berukuran sesuai dengan jumlah simpul.</br>
**3. Pembuatan Adjacency Matrix**: Program kemudian membuat adjacency matrix berupa vektor dua dimensi `adjacencyMatrix` dengan ukuran `numNodes x numNodes`. Matriks ini akan digunakan untuk menyimpan bobot (weight) atau nilai hubungan antar simpul.</br>
**4. Input Bobot Antar Simpul**:Pengguna diminta untuk memasukkan bobot antar setiap pasangan simpul. Program menampilkan prompt untuk setiap pasangan simpul, memandu pengguna untuk mengisi nilai dalam adjacency matrix. Pengguna memasukkan bobot hubungan dari simpul `i` ke simpul `j`, yang kemudian disimpan dalam `adjacencyMatrix[i][j]`.</br>
**5. Menampilkan Adjacency Matrix** : Setelah semua nilai bobot diinput, program memanggil fungsi `displayMatrix` untuk menampilkan adjacency matrix dengan format yang rapi. Fungsi ini menampilkan nama-nama simpul pada baris dan kolom pertama, diikuti oleh nilai-nilai bobot yang menunjukkan hubungan antar simpul.</br>

Secara keseluruhan, program ini mengelola dan menampilkan adjacency matrix dari sebuah graf, memungkinkan pengguna untuk dengan mudah memasukkan dan melihat hubungan antar simpul dalam bentuk matriks.</br>

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

#### Source Code
```C++
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
```

#### Output
##### Tampilan Outpun Menu - Pilihan 1
![UN2-MN1](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/da81549c-77bf-4749-91b4-a254c28352ff)

##### Tampilan Output Menu - Pilihan 2
![UN2-MN2](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/c720511b-f2e8-4c1d-b0d8-f1f1cd86ff84)

##### Tampilan Output Menu - Pilihan 3
![UN2-MN3](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/f516f4b0-174b-440f-954f-9ad1d328e896)

##### Tampilan Output Menu - Pilihan 4
![UN2-MN4](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/60237517-2505-41c7-90f6-f611cc735534)

##### Tampilan Output Menu - Pilihan 5
![UN2-MN5](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/26817ef3-6e5b-4d3d-90e3-7231ff6f7152)

##### Tampilan Output Menu - Pilihan 6
![UN2-MN6](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/d16935f6-2de7-47e4-921b-b0a77c5e122f)

##### Tampilan Output Menu - Pilihan 7
![UN2-MN7](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/5cb13a3e-9e61-4bd5-b502-43910333127d)

##### Tampilan Output Menu - Pilihan 8
![UN2-MN8](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/0367830c-6a5c-496f-8fee-4a7097e731c4)

##### Tampilan Output Menu - Pilihan 9
![UN2-MN9](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/c821296e-24c4-4060-b3b3-3c09681c255d)

##### Tampilan Output Menu - Pilihan 10
![UN2-MN10](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/debb05c7-b682-46fa-9ec6-5adec1cd41aa)

##### Tampilan Output Menu - Pilihan 11
![UN2-MN11](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/8f955c60-6b6c-4ea8-9723-422b4d6aa8a2)

##### Tampilan Output Menu - Pilihan 12
![UN2-12](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/4e9d8184-09e3-44d3-a57f-f1bcf1384bec)

##### Tampilan Output Menu - Pilihan 13
![UN2-MN13](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/7254a29c-3433-42bc-b29a-8d6f0ff7d8dd)

##### Tampilan Output Menu - Pilihan 14
![UN2-MN14](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/650a08e7-1e45-4a85-98b5-452ea1007172)

##### Tampilan Output Menu - Pilihan 12 - setelah dilakukan clear tree
![UN2-MN12-AFTER](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/20b57499-787b-4c58-b856-b3311c59c7c6)

##### Tampilan Output Menu - Pilihan 0
![UN2-MN0](https://github.com/yesikaa/Praktikum-Struktur-Data-Assignment/assets/158696794/689e8021-e1aa-49ce-9bca-b9ead3ecb6c3)

#### Deskripsi Program
Program ini merupakan implementasi struktur data binary tree (pohon biner) dalam bahasa C++. Program ini memungkinkan pengguna untuk membuat dan memanipulasi pohon biner melalui berbagai operasi seperti menambah node, memperbarui node, menampilkan node, dan menghapus node atau subtree. Program ini juga menyediakan fungsi untuk traversal pohon dalam urutan pre-order, in-order, dan post-order. Selain itu, program ini menampilkan karakteristik pohon seperti ukuran (jumlah node) dan tinggi (tingkat kedalaman maksimum).</br>

Cara kerja program ini adalah sebagai berikut : </br>

1. Inisialisasi dan Pembuatan Node :</br>
   - `init()`: Menginisialisasi pohon dengan mengatur root menjadi NULL.</br>
   - `newPohon(char data)`: Membuat node baru dengan data yang diberikan dan mengatur pointer anak dan induknya ke NULL.</br>
   - `buatNode(char data)`: Membuat node root jika pohon masih kosong. Jika pohon sudah ada, menampilkan pesan bahwa pohon sudah dibuat.</br>

2. Penambahan Node:</br>
   - `insertLeft(char data, Pohon *node)`: Menambahkan node baru sebagai anak kiri dari node yang diberikan jika belum ada anak kiri.</br>
   - `insertRight(char data, Pohon *node)`: Menambahkan node baru sebagai anak kanan dari node yang diberikan jika belum ada anak kanan.</br>

3. Manipulasi Node:</br>
   - `update(char data, Pohon *node)`: Mengubah data dari node yang diberikan dengan data baru.</br>
   - `retrieve(Pohon *node)`: Menampilkan data dari node yang diberikan.</br>
   - `find(Pohon *node)`: Menampilkan informasi detail dari node yang diberikan, termasuk root, parent, sibling, dan anak-anaknya.</br>

4. Traversal Pohon:</br>
   - `preOrder(Pohon *node)`: Traversal pre-order, mencetak data node saat pertama kali dikunjungi.</br>
   - `inOrder(Pohon *node)`: Traversal in-order, mencetak data node setelah mengunjungi anak kirinya.</br>
   - `postOrder(Pohon *node)`: Traversal post-order, mencetak data node setelah mengunjungi anak kiri dan kanan.</br>

5. Penghapusan Node:</br>
   - `deleteTree(Pohon *node)`: Menghapus seluruh pohon atau subpohon mulai dari node yang diberikan.</br>
   - `deleteSub(Pohon *node)`: Menghapus subpohon dari node yang diberikan, kecuali node itu sendiri.</br>
   - `clear()`: Menghapus seluruh pohon.</br>

6. Karakteristik Pohon:</br>
   - `size(Pohon *node)`: Menghitung jumlah total node dalam pohon.</br>
   - `height(Pohon *node)`: Menghitung tinggi pohon, yaitu panjang jalur terpanjang dari root ke daun.</br>
   - `characteristic()`: Menampilkan ukuran dan tinggi pohon.</br>

7. Fungsi Utilitas:</br>
   - `findNode(Pohon* node, char data)`: Mencari node berdasarkan data yang diberikan.</br>
   - `displayChildren(Pohon *node)`: Menampilkan anak-anak dari node yang diberikan.</br>
   - `displayDescendants(Pohon *node)`: Menampilkan seluruh keturunan dari node yang diberikan dalam urutan pre-order.</br>

8. Menu Interaktif:</br>
   - `menu()`: Menampilkan menu interaktif yang memungkinkan pengguna memilih operasi yang ingin dilakukan. Menu ini menyediakan berbagai opsi seperti membuat root, menambah anak kiri/kanan, memperbarui node, menampilkan node, traversal, dan penghapusan pohon atau subtree.</br>

Dengan cara kerja ini, program memberikan cara yang efektif dan interaktif untuk memanipulasi dan mengelola pohon biner, memungkinkan pengguna untuk memahami dan bekerja dengan struktur data ini dengan mudah.</br>

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Kesimpulan dari materi dan praktikum mengenai graf dan pohon biner ini adalah bahwa struktur data graf dan pohon biner memiliki peran penting dalam berbagai aplikasi komputasi. Graf, yang terdiri dari simpul (vertex) dan sisi (edges), digunakan untuk merepresentasikan hubungan antara objek dalam banyak konteks seperti jaringan komputer, jalur transportasi, dan hubungan sosial. Ada dua jenis graf utama, yaitu graf berarah dan graf tidak berarah, yang masing-masing dapat memiliki bobot atau tidak. </br>
  
Pohon biner adalah jenis khusus dari graf yang tidak memiliki sirkuit dan merupakan alat yang sangat efisien untuk berbagai algoritma dan struktur data, termasuk pencarian dan pengurutan. </br>

Pohon rentang minimum (Minimum Spanning Tree, MST) adalah aplikasi penting dari pohon dalam graf berbobot yang digunakan untuk menemukan jalur dengan bobot minimum yang menghubungkan semua simpul. Dalam praktikum, implementasi graf menggunakan adjacency matrix memungkinkan pengguna untuk memahami representasi dan manipulasi graf secara efisien. Di sisi lain, implementasi pohon biner dengan berbagai operasi seperti penambahan, penghapusan, dan traversal memberikan wawasan praktis tentang bagaimana struktur ini dapat dikelola dan dimanfaatkan dalam pemrograman. Dengan pemahaman dan pengalaman praktis ini, kita dapat melihat bagaimana teori graf dan pohon biner dapat diterapkan untuk menyelesaikan masalah nyata secara efisien dan efektif.</br>

## Referensi
[1] M Melladia, G Efendi, A Zahmi. "Algoritma dan Struktur Data dengan Pemrograman Pascal dan Phyton". Buku Ajar Informatika (2024). </br>
[2] Erkamim dkk. "Buku Ajar Algoritma dan Struktur Data". PT. Sonpedia Publishing Indonesia. (2024).</br>
[3] Irawan Afrianto, Euis Widiani Jamilah. "PENYELESAIAN MASALAH MINIMUM SPANNING TREE (MST) MENGGUNAKAN ANT COLONY SYSTEM (ACS)". Jurnal Ilmiah Komputer dan Informatika (KOMPUTA). Volume. I Nomor. 2. (2022).</br>
[4] MN Fakhruzzaman, IQ Utami. "BUKU AJAR ALGORITMA PEMROGRAMAN". Books Google. (2023).</br>
[5] Hendarman Lubis, Dwi Budi Srisulistiowati. "ALGORITMA PRIM DAN KRUSKAL DALAM MENCARI MINIMUM SPANNING TREE PADA BAHASA PEMROGRAMAN C". Fakultas Ilmu Komputer, Program Studi Informatika, Universitas Bhayangkara. (2023). </br>
