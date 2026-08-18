#include "queue_array.h"
#include <iostream>

using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    int pilihan;
    infotype x;
    int nomorCounter = 1;

    do {
        cout << "\n===========================================" << endl;
        cout << "         MENU QUEUE BERBASIS ARRAY         " << endl;
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

                enqueue(Q, x);
                break;

            case 2:
                cout << "\n--- Layani Antrean (Dequeue) ---" << endl;
                if (!isEmpty(Q)) {
                    dequeue(Q, x);
                    cout << "Melayani Pelanggan: " << x.namaPelanggan
                         << " (No. Antrean: " << x.nomorAntrean << ")" << endl;
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
                cout << "\nTerima kasih! Program selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
