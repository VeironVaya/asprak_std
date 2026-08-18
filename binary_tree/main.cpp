#include "binary_tree.h"
#include <iostream>

using namespace std;

int main() {
    Tree T;
    createTree(T);

    int pilihan;
    infotype x;
    double targetHarga;
    address p;

    do {
        cout << "\n===========================================" << endl;
        cout << "      MENU E-COMMERCE (BINARY SEARCH TREE) " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Insert Produk Baru (Berdasarkan Harga)" << endl;
        cout << " 2. Cari Produk (Berdasarkan Harga)" << endl;
        cout << " 3. Hapus Produk (Berdasarkan Harga)" << endl;
        cout << " 4. Traversal Preorder" << endl;
        cout << " 5. Traversal Inorder" << endl;
        cout << " 6. Traversal Postorder" << endl;
        cout << " 7. Hitung Tinggi BST" << endl;
        cout << " 8. Hitung Jumlah Leaf Node" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-8): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Insert Produk ---" << endl;
                cout << "Masukkan ID Produk    : "; cin >> x.idProduk;
                cout << "Masukkan Nama Produk  : "; cin >> x.namaProduk;
                cout << "Masukkan Kategori     : "; cin >> x.kategori;
                cout << "Masukkan Harga        : "; cin >> x.harga;
                cout << "Masukkan Stok         : "; cin >> x.stok;

                p = createElement(x);
                insertNode(T.root, p);
                cout << "Produk berhasil ditambahkan ke BST!" << endl;
                break;

            case 2:
                cout << "\n--- Cari Produk ---" << endl;
                cout << "Masukkan Harga yang dicari: "; cin >> targetHarga;
                p = searchNode(T.root, targetHarga);
                if (p != nullptr) {
                    cout << "=> Produk Ditemukan!" << endl;
                    cout << "ID     : " << p->info.idProduk << endl;
                    cout << "Nama   : " << p->info.namaProduk << endl;
                    cout << "Harga  : " << p->info.harga << endl;
                    cout << "Stok   : " << p->info.stok << endl;
                } else {
                    cout << "=> Produk dengan harga tersebut tidak ditemukan!" << endl;
                }
                break;

            case 3:
                cout << "\n--- Hapus Produk ---" << endl;
                cout << "Masukkan Harga produk yang akan dihapus: "; cin >> targetHarga;
                T.root = deleteNode(T.root, targetHarga);
                cout << "Proses hapus selesai." << endl;
                break;

            case 4:
                cout << "\n--- Traversal Preorder ---" << endl;
                if (isEmpty(T)) cout << "Tree kosong!" << endl;
                else preOrder(T.root);
                break;

            case 5:
                cout << "\n--- Traversal Inorder ---" << endl;
                if (isEmpty(T)) cout << "Tree kosong!" << endl;
                else inOrder(T.root);
                break;

            case 6:
                cout << "\n--- Traversal Postorder ---" << endl;
                if (isEmpty(T)) cout << "Tree kosong!" << endl;
                else postOrder(T.root);
                break;

            case 7:
                cout << "\nTinggi BST : " << tinggiTree(T.root) << endl;
                break;

            case 8:
                cout << "\nJumlah Leaf Node : " << hitungLeaf(T.root) << endl;
                break;

            case 0:
                cout << "\nTerima kasih! Program selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
