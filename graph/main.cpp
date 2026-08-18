#include "../Headers/graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    int pilihan;
    string nama1, nama2;

    do {
        cout << "\n===========================================" << endl;
        cout << "     MENU GRAPH MEDSOS (ADJACENCY LIST)    " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Tambah User Baru (Vertex)" << endl;
        cout << " 2. Tambah Hubungan Pertemanan (Edge)" << endl;
        cout << " 3. Tampilkan Jaringan Pertemanan" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah User Baru ---" << endl;
                cout << "Masukkan Nama User: ";
                cin >> nama1;
                tambahUser(G, nama1);
                break;

            case 2:
                cout << "\n--- Tambah Pertemanan ---" << endl;
                cout << "Masukkan Nama User Pertama : "; cin >> nama1;
                cout << "Masukkan Nama User Kedua   : "; cin >> nama2;
                tambahPertemanan(G, nama1, nama2);
                break;

            case 3:
                printGraph(G);
                break;

            case 0:
                clearGraph(G);
                cout << "\nTerima kasih! Program selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
