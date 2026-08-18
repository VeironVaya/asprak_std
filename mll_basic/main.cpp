#include "mll_basic.h"
#include <iostream>

using namespace std;

int main() {
    listMK LMK;
    createListMK(LMK);

    int pilihan;
    string namaTarget;
    string nimTarget;
    adrMK p, prec, hapus;

    do {
        cout << "\n===========================================" << endl;
        cout << "     MENU SISTEM AKADEMIK (MLL BASIC)      " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Tambah MK (Insert First - Multiple)" << endl;
        cout << " 2. Tambah MK di Akhir (Insert Last)" << endl;
        cout << " 3. Tambah MK Setelah MK Tertentu" << endl;
        cout << " 4. Update Data MK" << endl;
        cout << " 5. Hapus MK Pertama (Delete First)" << endl;
        cout << " 6. Hapus MK Terakhir (Delete Last)" << endl;
        cout << " 7. Hapus MK Setelah MK Tertentu" << endl;
        cout << " 8. Daftarkan Mahasiswa ke MK" << endl;
        cout << " 9. Tampilkan Semua MK (Tanpa Mahasiswa)" << endl;
        cout << "10. Tampilkan Semua MK Beserta Mahasiswanya" << endl;
        cout << "11. Urutkan MK Berdasarkan Nama (A-Z)" << endl;
        cout << "12. Hapus Mahasiswa dari MK Tertentu" << endl;
        cout << "13. Update Data Mahasiswa dalam MK" << endl;
        cout << "14. Hapus MK Spesifik (By Nama)" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-14): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah MK (Insert First) ---" << endl;
                tambahMK(LMK);
                break;
            case 2:
                cout << "\n--- Tambah MK di Akhir ---" << endl;
                p = createElmMK();
                insertLastMK(LMK, p);
                cout << "Mata Kuliah berhasil ditambahkan di akhir!" << endl;
                break;
            case 3:
                cout << "\n--- Tambah MK Setelah ---" << endl;
                cout << "Masukkan Nama MK referensi (sebelumnya): "; cin >> namaTarget;
                prec = cariMK(LMK, namaTarget);
                if (prec != nullptr) {
                    cout << "MK referensi ditemukan! Masukkan data MK baru:" << endl;
                    p = createElmMK();
                    insertAfterMK(LMK, prec, p);
                    cout << "Mata Kuliah berhasil ditambahkan!" << endl;
                } else {
                    cout << "MK referensi tidak ditemukan!" << endl;
                }
                break;
            case 4:
                cout << "\n--- Update Data MK ---" << endl;
                cout << "Masukkan Nama MK yang ingin diupdate: "; cin >> namaTarget;
                updateMK(LMK, namaTarget);
                break;
            case 5:
                cout << "\n--- Hapus MK Pertama ---" << endl;
                if (LMK.firstMK != nullptr && LMK.firstMK->info.jumlahMhs > 0) {
                    cout << "Gagal hapus! MK masih berisi Mahasiswa. (Gunakan menu 14)" << endl;
                } else {
                    deleteFirstMK(LMK, hapus);
                    if (hapus != nullptr) {
                        cout << "MK " << hapus->info.namaMK << " berhasil dihapus!" << endl;
                    } else { cout << "List MK kosong!" << endl; }
                }
                break;
            case 6:
                cout << "\n--- Hapus MK Terakhir ---" << endl;
                deleteLastMK(LMK, hapus);
                if (hapus != nullptr) cout << "MK berhasil dihapus!" << endl;
                else cout << "List MK kosong!" << endl;
                break;
            case 7:
                cout << "\n--- Hapus MK Setelah MK Tertentu ---" << endl;
                cout << "Masukkan Nama MK referensi: "; cin >> namaTarget;
                prec = cariMK(LMK, namaTarget);
                if (prec != nullptr) {
                    deleteAfterMK(LMK, prec, hapus);
                    if (hapus != nullptr) cout << "MK berhasil dihapus!" << endl;
                    else cout << "Tidak ada MK setelah " << namaTarget << "!" << endl;
                } else cout << "MK referensi tidak ditemukan!" << endl;
                break;
            case 8:
                cout << "\n--- Daftarkan Mahasiswa ---" << endl;
                insertMhsToMK(LMK);
                break;
            case 9:
                cout << "\n--- Daftar Semua MK ---" << endl;
                if (LMK.firstMK == nullptr) cout << "Data MK kosong!" << endl;
                else printAllMK(LMK);
                break;
            case 10:
                cout << "\n--- Daftar MK & Mahasiswanya ---" << endl;
                if (LMK.firstMK == nullptr) cout << "Data MK kosong!" << endl;
                else printAllMKWithMhs(LMK);
                break;
            case 11:
                cout << "\n--- Urutkan Data MK ---" << endl;
                sortMK(LMK);
                break;
            case 12:
                cout << "\n--- Hapus Mahasiswa dari MK ---" << endl;
                if (LMK.firstMK == nullptr) {
                    cout << "Belum ada MK terdaftar!" << endl;
                } else {
                    cout << "Masukkan Nama MK: "; cin >> namaTarget;
                    cout << "Masukkan NIM Mahasiswa: "; cin >> nimTarget;
                    deleteMhsDariMK(LMK, namaTarget, nimTarget);
                }
                break;
            case 13:
                cout << "\n--- Update Data Mahasiswa ---" << endl;
                if (LMK.firstMK == nullptr) {
                    cout << "Belum ada MK terdaftar!" << endl;
                } else {
                    cout << "Masukkan Nama MK: "; cin >> namaTarget;
                    cout << "Masukkan NIM Mahasiswa: "; cin >> nimTarget;
                    updateMhsDiMK(LMK, namaTarget, nimTarget);
                }
                break;
            case 14:
                cout << "\n--- Hapus MK (Paksa by Nama) ---" << endl;
                cout << "Masukkan Nama MK yang akan dihapus: "; cin >> namaTarget;
                deleteMKByNama(LMK, namaTarget);
                break;
            case 0:
                cout << "\nTerima kasih! Program selesai." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
