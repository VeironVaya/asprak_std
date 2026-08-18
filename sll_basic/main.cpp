#include "sll_basic.h"
#include <iostream>

using namespace std;

int main() {
    ListMahasiswa L;
    createList(L);

    int pilihan;
    infotype x;
    address p;
    string targetNIM;

    do {
        cout << "\n===========================================" << endl;
        cout << "     MENU SINGLE LINKED LIST (BASIC)       " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Insert First (Tambah di Awal)" << endl;
        cout << " 2. Insert Last (Tambah di Akhir)" << endl;
        cout << " 3. Delete First (Hapus di Awal)" << endl;
        cout << " 4. Delete Last (Hapus di Akhir)" << endl;
        cout << " 5. Cari Mahasiswa Berdasarkan NIM" << endl;
        cout << " 6. Update Data Mahasiswa" << endl;
        cout << " 7. Hapus Mahasiswa Spesifik (By NIM)" << endl;
        cout << " 8. Tampilkan Semua Mahasiswa" << endl;
        cout << " 9. Kosongkan List" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-9): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Insert First ---" << endl;
                cout << "Masukkan NIM          : "; cin >> x.nim;
                cout << "Masukkan Nama         : "; cin >> x.namaMhs;
                cout << "Masukkan Kelas MK     : "; cin >> x.kelasMK;
                cout << "Masukkan Umur         : "; cin >> x.umurMhs;
                cout << "Masukkan Alamat       : "; cin >> x.alamatMhs;

                p = createElement(x);
                insertFirst(L, p);
                cout << "Data berhasil ditambahkan di awal!" << endl;
                break;

            case 2:
                cout << "\n--- Insert Last ---" << endl;
                cout << "Masukkan NIM          : "; cin >> x.nim;
                cout << "Masukkan Nama         : "; cin >> x.namaMhs;
                cout << "Masukkan Kelas MK     : "; cin >> x.kelasMK;
                cout << "Masukkan Umur         : "; cin >> x.umurMhs;
                cout << "Masukkan Alamat       : "; cin >> x.alamatMhs;

                p = createElement(x);
                insertLast(L, p);
                cout << "Data berhasil ditambahkan di akhir!" << endl;
                break;

            case 3:
                cout << "\n--- Delete First ---" << endl;
                deleteFirst(L, p);
                if (p != nullptr) {
                    cout << "Mahasiswa yang dihapus: " << p->info.namaMhs << " (NIM: " << p->info.nim << ")" << endl;
                    delete p;
                } else {
                    cout << "List kosong!" << endl;
                }
                break;

            case 4:
                cout << "\n--- Delete Last ---" << endl;
                deleteLast(L, p);
                if (p != nullptr) {
                    cout << "Mahasiswa yang dihapus: " << p->info.namaMhs << " (NIM: " << p->info.nim << ")" << endl;
                    delete p;
                } else {
                    cout << "List kosong!" << endl;
                }
                break;

            case 5:
                cout << "\n--- Cari Mahasiswa ---" << endl;
                cout << "Masukkan NIM yang dicari: "; cin >> targetNIM;
                p = cariMahasiswa(L, targetNIM);
                if (p != nullptr) {
                    cout << "=> Ditemukan! Nama: " << p->info.namaMhs << ", Kelas MK: " << p->info.kelasMK << endl;
                } else {
                    cout << "=> Mahasiswa tidak ditemukan!" << endl;
                }
                break;

            case 6:
                cout << "\n--- Update Mahasiswa ---" << endl;
                cout << "Masukkan NIM mahasiswa yang ingin diupdate: "; cin >> targetNIM;
                updateMahasiswa(L, targetNIM);
                break;

            case 7:
                cout << "\n--- Hapus Mahasiswa by NIM ---" << endl;
                cout << "Masukkan NIM mahasiswa yang akan dihapus: "; cin >> targetNIM;
                deleteMahasiswaByNIM(L, targetNIM);
                break;

            case 8:
                printList(L);
                break;

            case 9:
                clearList(L);
                cout << "List berhasil dikosongkan!" << endl;
                break;

            case 0:
                clearList(L);
                cout << "\nTerima kasih! Program selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);

    return 0;
}
