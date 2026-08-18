#include "stack_array.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    createStack(S);

    int pilihan;
    infotype x;

    do {
        cout << "\n===========================================" << endl;
        cout << "         MENU STACK BERBASIS ARRAY         " << endl;
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

                push(S, x);
                break;

            case 2:
                cout << "\n--- Pop Buku Teratas ---" << endl;
                if (!isEmpty(S)) {
                    pop(S, x);
                    cout << "Buku yang dihapus (Popped): " << x.judulBuku << endl;
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
                cout << "\nTerima kasih! Program selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
