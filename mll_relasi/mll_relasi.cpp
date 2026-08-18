#include "mll_relasi.h"

void createListMK(listMK &LMK) {
    LMK.firstMK = nullptr;
}

void createListMhs(listMhs &LM) {
    LM.firstMhs = nullptr;
}

void createListRelasi(listRelasi &LR) {
    LR.firstRelasi = nullptr;
}

adrMK createElmMK() {
    adrMK p = new elmListMK;
    cout << "Masukkan Kode MK       : "; cin >> p->info.kodeMK;
    cout << "Masukkan Nama MK       : "; cin >> p->info.namaMK;
    cout << "Masukkan Kuota Maks    : "; cin >> p->info.kuotaMaks;
    p->info.jumlahMhs = 0;
    cout << "Masukkan Jadwal Hari   : "; cin >> p->info.jadwalHari;
    p->nextMK = nullptr;
    return p;
}

adrMhs createElmMhs() {
    adrMhs p = new elmListMhs;
    cout << "Masukkan NIM           : "; cin >> p->info.nim;
    cout << "Masukkan Nama Mhs      : "; cin >> p->info.namaMhs;
    cout << "Masukkan Umur          : "; cin >> p->info.umurMhs;
    cout << "Masukkan Jenis Kelamin : "; cin >> p->info.jenisKelamin;
    cout << "Masukkan Alamat        : "; cin >> p->info.alamatMhs;
    p->nextMhs = nullptr;
    return p;
}

adrRelasi createElmRelasi() {
    adrRelasi r = new elmListRelasi;
    return r;
}

void insertFirstRelasi(listRelasi &LR, adrMK mk, adrMhs mhs, adrRelasi r) {
    if (LR.firstRelasi == nullptr) {
        LR.firstRelasi = r;
        LR.firstRelasi->nextRelasi = nullptr;
    } else {
        r->nextRelasi = LR.firstRelasi;
        LR.firstRelasi = r;
    }
    r->toMK = mk;
    r->toMhs = mhs;
}

void insertFirstMK(listMK &LMK, adrMK p) {
    if (LMK.firstMK == nullptr) {
        LMK.firstMK = p;
        LMK.firstMK->nextMK = nullptr;
    } else {
        p->nextMK = LMK.firstMK;
        LMK.firstMK = p;
    }
}

void tambahMK(listMK &LMK) {
    int i, n;
    adrMK p;
    cout << "Berapa banyak Mata Kuliah yang ingin ditambahkan: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        p = createElmMK();
        insertFirstMK(LMK, p);
    }
}

adrMK cariMK(listMK LMK, string namaMK) {
    adrMK q = LMK.firstMK;
    while (q != nullptr) {
        if (q->info.namaMK == namaMK) {
            return q;
        }
        q = q->nextMK;
    }
    return nullptr;
}

bool cekKapasitasMK(listMK LMK, adrMK p) {
    bool penuh = false;
    if (p != nullptr) {
        penuh = p->info.kuotaMaks <= p->info.jumlahMhs;
    }
    return penuh;
}

void insertFirstMhs(listMhs &LM, adrMhs p) {
    if (LM.firstMhs == nullptr) {
        LM.firstMhs = p;
        LM.firstMhs->nextMhs = nullptr;
    } else {
        p->nextMhs = LM.firstMhs;
        LM.firstMhs = p;
    }
    cout << "Mahasiswa " << p->info.nim << " berhasil dimasukkan" << endl;
}

void printAllMK(listMK LMK) {
    adrMK q = LMK.firstMK;
    while (q != nullptr) {
        cout << q->info.kodeMK << endl;
        cout << q->info.namaMK << endl;
        cout << q->info.kuotaMaks << endl;
        cout << q->info.jumlahMhs << endl;
        cout << q->info.jadwalHari << endl;
        q = q->nextMK;
    }
}

void printAllMKWithMhs(listMK LMK, listRelasi LR) {
    adrRelasi r = LR.firstRelasi;
    adrMK mk = LMK.firstMK;

    while (mk != nullptr) {
        cout << "  Kode MK         : " << mk->info.kodeMK << endl;
        cout << "  Nama MK         : " << mk->info.namaMK << endl;
        cout << "  Kuota Kelas     : " << mk->info.jumlahMhs << " / " << mk->info.kuotaMaks << " Mahasiswa" << endl;
        cout << "  Jadwal          : " << mk->info.jadwalHari << endl;
        cout << "===========Mahasiswa===========" << endl;
        cout << "===============================" << endl;

        while (r != nullptr) {
            if (mk->info.kodeMK == r->toMK->info.kodeMK) {
                cout << "  NIM           : " << r->toMhs->info.nim << endl;
                cout << "  Nama Mhs      : " << r->toMhs->info.namaMhs << endl;
                cout << "  Umur          : " << r->toMhs->info.umurMhs << " tahun" << endl;
                cout << "  Jenis Kelamin : " << r->toMhs->info.jenisKelamin << endl;
                cout << "  Alamat        : " << r->toMhs->info.alamatMhs << endl << endl;
            }
            r = r->nextRelasi;
        }
        cout << "===============================" << endl;
        mk = mk->nextMK;
        r = LR.firstRelasi;
    }
}

void insertAfterMK(listMK &LMK, adrMK prec, adrMK p) {
    if (prec != nullptr) {
        p->nextMK = prec->nextMK;
        prec->nextMK = p;
    }
}

void insertLastMK(listMK &LMK, adrMK p) {
    if (LMK.firstMK == nullptr) {
        LMK.firstMK = p;
        p->nextMK = nullptr;
    } else {
        adrMK q = LMK.firstMK;
        while (q->nextMK != nullptr) {
            q = q->nextMK;
        }
        q->nextMK = p;
        p->nextMK = nullptr;
    }
}

void updateMK(listMK &LMK, string namaMK) {
    adrMK p = cariMK(LMK, namaMK);
    if (p != nullptr) {
        cout << "Masukkan Kode MK Baru    : "; cin >> p->info.kodeMK;
        cout << "Masukkan Nama MK Baru    : "; cin >> p->info.namaMK;
        cout << "Masukkan Kuota Maks Baru : "; cin >> p->info.kuotaMaks;
        cout << "Masukkan Jadwal Baru     : "; cin >> p->info.jadwalHari;
        cout << "Update berhasil!" << endl;
    } else {
        cout << "Mata Kuliah tidak ditemukan!" << endl;
    }
}

void deleteFirstMK(listMK &LMK, adrMK &p) {
    if (LMK.firstMK != nullptr) {
        p = LMK.firstMK;
        LMK.firstMK = p->nextMK;
        p->nextMK = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteLastMK(listMK &LMK, adrMK &p) {
    if (LMK.firstMK != nullptr) {
        if (LMK.firstMK->nextMK == nullptr) {
            p = LMK.firstMK;
            LMK.firstMK = nullptr;
        } else {
            adrMK q = LMK.firstMK;
            while (q->nextMK->nextMK != nullptr) {
                q = q->nextMK;
            }
            p = q->nextMK;
            q->nextMK = nullptr;
        }
    } else {
        p = nullptr;
    }
}

void deleteAfterMK(listMK &LMK, adrMK prec, adrMK &p) {
    if (prec != nullptr && prec->nextMK != nullptr) {
        p = prec->nextMK;
        prec->nextMK = p->nextMK;
        p->nextMK = nullptr;
    } else {
        p = nullptr;
    }
}

void sortMK(listMK &LMK) {
    if (LMK.firstMK == nullptr || LMK.firstMK->nextMK == nullptr) {
        cout << "Data Mata Kuliah kosong atau hanya 1, tidak perlu diurutkan." << endl;
        return;
    }

    bool swapped;
    adrMK current, prev, nextNode;
    adrMK batasAkhir = nullptr;

    do {
        swapped = false;
        current = LMK.firstMK;
        prev = nullptr;

        while (current->nextMK != batasAkhir) {
            nextNode = current->nextMK;

            if (current->info.namaMK > nextNode->info.namaMK) {
                swapped = true;

                if (prev != nullptr) {
                    prev->nextMK = nextNode;
                } else {
                    LMK.firstMK = nextNode;
                }

                current->nextMK = nextNode->nextMK;
                nextNode->nextMK = current;
                prev = nextNode;
            } else {
                prev = current;
                current = current->nextMK;
            }
        }
        batasAkhir = current;
    } while (swapped);

    cout << "Mata Kuliah berhasil diurutkan berdasarkan Nama (A-Z)!" << endl;
}

void deleteMhsDariMK(listMK &LMK, listRelasi &LR, string namaMK, string nim) {
    adrMK mk = cariMK(LMK, namaMK);

    if (mk == nullptr) {
        cout << "Gagal: Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    if (mk->info.jumlahMhs == 0) {
        cout << "Gagal: Kelas Mata Kuliah ini kosong!" << endl;
        return;
    }

    adrRelasi current = LR.firstRelasi;
    adrRelasi prev = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->toMK->info.namaMK == namaMK && current->toMhs->info.nim == nim) {
            found = true;
            break;
        }
        prev = current;
        current = current->nextRelasi;
    }

    if (found) {
        if (prev == nullptr) {
            LR.firstRelasi = current->nextRelasi;
        } else {
            prev->nextRelasi = current->nextRelasi;
        }

        current->nextRelasi = nullptr;
        delete current;

        mk->info.jumlahMhs--;
        cout << "Berhasil: Mahasiswa dengan NIM " << nim << " dibatalkan dari MK " << namaMK << "!" << endl;
    } else {
        cout << "Gagal: Mahasiswa NIM " << nim << " tidak mengambil kelas " << namaMK << "!" << endl;
    }
}

void insertMhsToMK(listMK &LMK, listMhs &LM, listRelasi &LR) {
    int i, n;
    adrMhs mhs;
    adrMK mk;
    adrRelasi r;
    string namaMK, nim;

    cout << "Nama Mata Kuliah yang ingin diambil: ";
    cin >> namaMK;

    mk = cariMK(LMK, namaMK);
    if (mk == nullptr) {
        cout << "Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    bool penuh = cekKapasitasMK(LMK, mk);
    if (penuh) {
        cout << "Kapasitas kelas penuh!" << endl;
        return;
    }

    cout << "Berapa banyak Mahasiswa yang mendaftar kelas ini: ";
    cin >> n;

    if (mk->info.jumlahMhs + n > mk->info.kuotaMaks) {
        cout << "Gagal! Sisa kuota kelas hanya untuk "
             << (mk->info.kuotaMaks - mk->info.jumlahMhs) << " mahasiswa." << endl;
        return;
    }

    for (i = 0; i < n; i++) {
        cout << "\n--- Data Mahasiswa ke-" << (i+1) << " ---" << endl;
        cout << "Masukkan NIM: ";
        cin >> nim;

        mhs = cariMhs(LM, nim);
        if (mhs == nullptr) {
            mhs = new elmListMhs;
            mhs->info.nim = nim;
            cout << "Masukkan Nama Mhs      : "; cin >> mhs->info.namaMhs;
            cout << "Masukkan Umur          : "; cin >> mhs->info.umurMhs;
            cout << "Masukkan Jenis Kelamin : "; cin >> mhs->info.jenisKelamin;
            cout << "Masukkan Alamat        : "; cin >> mhs->info.alamatMhs;
            mhs->nextMhs = nullptr;
            insertFirstMhs(LM, mhs);
        } else {
            cout << "=> Mahasiswa ditemukan di database (Nama: " << mhs->info.namaMhs << ")" << endl;
        }

        if (cariRelasi(LR, namaMK, nim) != nullptr) {
            cout << "=> GAGAL: Mahasiswa NIM " << nim << " sudah terdaftar di kelas ini!" << endl;
        } else {
            r = createElmRelasi();
            insertFirstRelasi(LR, mk, mhs, r);
            mk->info.jumlahMhs++;
            cout << "=> BERHASIL didaftarkan ke kelas!" << endl;
        }
    }
}

adrMhs cariMhs(listMhs LM, string nim) {
    adrMhs q = LM.firstMhs;
    while (q != nullptr) {
        if (q->info.nim == nim) {
            return q;
        }
        q = q->nextMhs;
    }
    return nullptr;
}

void printAllMhs(listMhs LM) {
    adrMhs q = LM.firstMhs;
    if (q == nullptr) {
        cout << "Data Mahasiswa masih kosong!" << endl;
        return;
    }
    cout << "================ MASTER DATA MAHASISWA ================" << endl;
    while (q != nullptr) {
        cout << "NIM           : " << q->info.nim << endl;
        cout << "Nama Mhs      : " << q->info.namaMhs << endl;
        cout << "Umur          : " << q->info.umurMhs << " tahun" << endl;
        cout << "Jenis Kelamin : " << q->info.jenisKelamin << endl;
        cout << "Alamat        : " << q->info.alamatMhs << endl;
        cout << "-------------------------------------------------------" << endl;
        q = q->nextMhs;
    }
}

void updateMhs(listMhs &LM, string nim) {
    adrMhs p = cariMhs(LM, nim);
    if (p != nullptr) {
        cout << "Masukkan Nama Baru   : "; cin >> p->info.namaMhs;
        cout << "Masukkan Umur Baru   : "; cin >> p->info.umurMhs;
        cout << "Masukkan Gender Baru : "; cin >> p->info.jenisKelamin;
        cout << "Masukkan Alamat Baru : "; cin >> p->info.alamatMhs;
        cout << "Update berhasil!" << endl;
    } else {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan!" << endl;
    }
}

adrRelasi cariRelasi(listRelasi LR, string namaMK, string nim) {
    adrRelasi q = LR.firstRelasi;
    while (q != nullptr) {
        if (q->toMK->info.namaMK == namaMK && q->toMhs->info.nim == nim) {
            return q;
        }
        q = q->nextRelasi;
    }
    return nullptr;
}

void deleteMKByNama(listMK &LMK, listRelasi &LR, string namaMK) {
    adrMK mk = cariMK(LMK, namaMK);
    if (mk == nullptr) {
        cout << "Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    adrRelasi currentR = LR.firstRelasi;
    adrRelasi prevR = nullptr;
    while (currentR != nullptr) {
        if (currentR->toMK == mk) {
            adrRelasi hapusR = currentR;
            if (prevR == nullptr) {
                LR.firstRelasi = currentR->nextRelasi;
                currentR = LR.firstRelasi;
            } else {
                prevR->nextRelasi = currentR->nextRelasi;
                currentR = currentR->nextRelasi;
            }
            hapusR->nextRelasi = nullptr;
            delete hapusR;
        } else {
            prevR = currentR;
            currentR = currentR->nextRelasi;
        }
    }

    adrMK hapusMK;
    if (LMK.firstMK == mk) {
        deleteFirstMK(LMK, hapusMK);
    } else {
        adrMK prevMK = LMK.firstMK;
        while (prevMK->nextMK != mk) {
            prevMK = prevMK->nextMK;
        }
        deleteAfterMK(LMK, prevMK, hapusMK);
    }

    cout << "Mata Kuliah " << namaMK << " beserta data KRS didalamnya berhasil dihapus!" << endl;
}
