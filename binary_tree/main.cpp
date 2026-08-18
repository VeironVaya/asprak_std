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
        cout << " 1. Insert Produk Baru" << endl;
        cout << " 2. Cari Produk (Berdasarkan Harga)" << endl;
        cout << " 3. Hapus Produk (Berdasarkan Harga)" << endl;
        cout << " 4. Traversal Preorder" << endl;
        cout << " 5. Traversal Inorder" << endl;
        cout << " 6. Traversal Postorder" << endl;
        cout << " 7. Level Order Traversal (BFS)" << endl;
        cout << " 8. Cari Harga Minimum" << endl;
        cout << " 9. Cari Harga Maksimum" << endl;
        cout << "10. Hitung Tinggi BST" << endl;
        cout << "11. Hitung Jumlah Leaf Node" << endl;
        cout << "12. Hitung Total Size (Node)" << endl;
        cout << "13. Validasi Validitas BST" << endl;
        cout << "14. Mirror / Invert Tree" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-14): ";
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
                    cout << "=> Produk Ditemukan! Nama: " << p->info.namaProduk << endl;
                } else {
                    cout << "=> Produk tidak ditemukan!" << endl;
                }
                break;

            case 3:
                cout << "\n--- Hapus Produk ---" << endl;
                cout << "Masukkan Harga produk yang akan dihapus: "; cin >> targetHarga;
                T.root = deleteNode(T.root, targetHarga);
                cout << "Proses hapus selesai." << endl;
                break;

            case 4:
                preOrder(T.root);
                break;

            case 5:
                inOrder(T.root);
                break;

            case 6:
                postOrder(T.root);
                break;

            case 7:
                levelOrderTraversal(T.root);
                break;

            case 8:
                p = findMin(T.root);
                if (p != nullptr) cout << "Harga Minimum: " << p->info.harga << endl;
                else cout << "Tree kosong!" << endl;
                break;

            case 9:
                p = findMax(T.root);
                if (p != nullptr) cout << "Harga Maksimum: " << p->info.harga << endl;
                else cout << "Tree kosong!" << endl;
                break;

            case 10:
                cout << "Tinggi BST : " << tinggiTree(T.root) << endl;
                break;

            case 11:
                cout << "Jumlah Leaf Node : " << hitungLeaf(T.root) << endl;
                break;

            case 12:
                cout << "Total Size (Node) : " << hitungSize(T.root) << endl;
                break;

            case 13:
                if (isValidBST(T.root)) cout << "Tree ini VALID sebagai BST." << endl;
                else cout << "Tree ini TIDAK VALID sebagai BST." << endl;
                break;

            case 14:
                mirrorTree(T.root);
                cout << "Tree berhasil di-mirror / di-invert!" << endl;
                break;

            case 0:
                cout << "\nTerima kasih!" << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
