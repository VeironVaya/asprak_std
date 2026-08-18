#include "sll_stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    createStack(S);

    int pilihan;
    infotype x;
    address p;

    do {
        cout << "\n===========================================" << endl;
        cout << "         MENU STACK SINGLE LINKED LIST     " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Push (Tambah Buku ke Stack)" << endl;
        cout << " 2. Pop (Hapus Buku Teratas)" << endl;
        cout << " 3. Tampilkan Semua Stack" << endl;
        cout << " 4. Kosongkan Stack" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Push Buku Baru ---" << endl;
                cout << "Masukkan ID Buku      : "; cin >> x.idBuku;
                cout << "Masukkan Judul Buku   : "; cin >> x.judulBuku;
                cout << "Masukkan Penulis      : "; cin >> x.penulis;
                cout << "Masukkan Tahun Terbit : "; cin >> x.tahunTerbit;

                p = createElement(x);
                push(S, p);
                cout << "Buku berhasil di-push ke stack!" << endl;
                break;

            case 2:
                cout << "\n--- Pop Buku Teratas ---" << endl;
                pop(S, p);
                if (p != nullptr) {
                    cout << "Buku yang dihapus (Popped): " << p->info.judulBuku << endl;
                    delete p;
                } else {
                    cout << "Stack kosong, tidak ada yang bisa di-pop!" << endl;
                }
                break;

            case 3:
                printStack(S);
                break;

            case 4:
                clearStack(S);
                cout << "Stack berhasil dikosongkan!" << endl;
                break;

            case 0:
                clearStack(S);
                cout << "\nTerima kasih! Program selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
