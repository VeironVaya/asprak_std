#include "sll_queue.h"
#include <iostream>

using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    int pilihan;
    infotype x;
    address p;
    int nomorCounter = 1;

    do {
        cout << "\n===========================================" << endl;
        cout << "         MENU QUEUE SINGLE LINKED LIST     " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Enqueue (Tambah Antrean Baru)" << endl;
        cout << " 2. Dequeue (Panggil/Layani Antrean Depan)" << endl;
        cout << " 3. Tampilkan Semua Antrean" << endl;
        cout << " 4. Kosongkan Antrean" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah Antrean Baru ---" << endl;
                cout << "Masukkan ID Pelanggan : "; cin >> x.idPelanggan;
                cout << "Masukkan Nama         : "; cin >> x.namaPelanggan;
                cout << "Masukkan Keperluan    : "; cin >> x.keperluan;
                x.nomorAntrean = nomorCounter++;

                p = createElement(x);
                enqueue(Q, p);
                cout << "Pelanggan berhasil masuk antrean dengan No: " << x.nomorAntrean << endl;
                break;

            case 2:
                cout << "\n--- Layani Antrean (Dequeue) ---" << endl;
                dequeue(Q, p);
                if (p != nullptr) {
                    cout << "Melayani Pelanggan: " << p->info.namaPelanggan
                         << " (No. Antrean: " << p->info.nomorAntrean << ")" << endl;
                    delete p;
                } else {
                    cout << "Antrean kosong, tidak ada yang dilayani!" << endl;
                }
                break;

            case 3:
                printQueue(Q);
                break;

            case 4:
                clearQueue(Q);
                nomorCounter = 1;
                cout << "Antrean berhasil dikosongkan!" << endl;
                break;

            case 0:
                clearQueue(Q);
                cout << "\nTerima kasih! Program selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
