#include "stack_v1.h"
#include <iostream>

using namespace std;

int main() {
    stackMK SMK;
    stackMhs SM;

    createStackMK(SMK);
    createStackMhs(SM);

    int pilihan;
    string namaTarget;
    string nimTarget;
    adrMK p, poped;

    do {
        cout << "\n===========================================" << endl;
        cout << "         MENU SISTEM AKADEMIK STACK        " << endl;
        cout << "===========================================" << endl;
        cout << " 1. Push MK (Tambah MK ke Stack)" << endl;
        cout << " 2. Pop MK (Hapus MK Teratas Stack)" << endl;
        cout << " 3. Update Data MK" << endl;
        cout << " 4. Daftarkan Mahasiswa (Isi KRS)" << endl;
        cout << " 5. Tampilkan Semua MK (Tanpa Mahasiswa)" << endl;
        cout << " 6. Tampilkan Semua MK Beserta Kelasnya" << endl;
        cout << " 7. Batalkan KRS (Hapus Mhs dari Kelas)" << endl;
        cout << " 8. Tampilkan Semua Master Data Mahasiswa" << endl;
        cout << " 9. Update Master Data Mahasiswa" << endl;
        cout << "10. Hapus MK Spesifik (By Nama)" << endl;
        cout << " 0. Keluar" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu (0-10): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Push Mata Kuliah ---" << endl;
                tambahMK(SMK);
                break;
            case 2:
                cout << "\n--- Pop Mata Kuliah Teratas ---" << endl;
                if (SMK.topMK != nullptr && SMK.topMK->info.jumlahMhs > 0) {
                    cout << "Gagal Pop! MK teratas masih berisi Mahasiswa." << endl;
                } else {
                    popMK(SMK, poped);
                    if (poped != nullptr) {
                        cout << "MK " << poped->info.namaMK << " berhasil di-pop dari stack!" << endl;
                        delete poped;
                    } else {
                        cout << "Stack MK kosong!" << endl;
                    }
                }
                break;
            case 3:
                cout << "\n--- Update Data MK ---" << endl;
                cout << "Masukkan Nama MK yang ingin diupdate: "; cin >> namaTarget;
                updateMK(SMK, namaTarget);
                break;
            case 4:
                cout << "\n--- Daftarkan Mahasiswa ---" << endl;
                insertMhsToMK(SMK, SM);
                break;
            case 5:
                cout << "\n--- Daftar Semua MK ---" << endl;
                if (SMK.topMK == nullptr) cout << "Data MK kosong!" << endl;
                else printAllMK(SMK);
                break;
            case 6:
                cout << "\n--- Daftar MK & Mahasiswanya ---" << endl;
                if (SMK.topMK == nullptr) cout << "Data MK kosong!" << endl;
                else printAllMKWithMhs(SMK);
                break;
            case 7:
                cout << "\n--- Hapus Mahasiswa dari MK ---" << endl;
                if (SMK.topMK == nullptr) {
                    cout << "Belum ada MK terdaftar!" << endl;
                } else {
                    cout << "Masukkan Nama MK: "; cin >> namaTarget;
                    cout << "Masukkan NIM Mahasiswa: "; cin >> nimTarget;
                    deleteMhsDariMK(SMK, namaTarget, nimTarget);
                }
                break;
            case 8:
                cout << "\n--- Daftar Master Data Mahasiswa ---" << endl;
                printAllMhs(SM);
                break;
            case 9:
                cout << "\n--- Update Data Mahasiswa ---" << endl;
                cout << "Masukkan NIM Mahasiswa yang ingin diupdate: "; cin >> nimTarget;
                updateMhs(SM, nimTarget);
                break;
            case 10:
                cout << "\n--- Hapus MK Spesifik by Nama ---" << endl;
                cout << "Masukkan Nama MK yang akan dihapus: "; cin >> namaTarget;
                deleteMKByNama(SMK, namaTarget);
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
