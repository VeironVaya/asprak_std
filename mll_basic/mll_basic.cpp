#include "mll_basic.h"

void createListMK(listMK &LMK) {
    LMK.firstMK = nullptr;
}

adrMK createElmMK() {
    adrMK p = new elmListMK;
    cout << "Masukkan Kode MK       : "; cin >> p->info.kodeMK;
    cout << "Masukkan Nama MK       : "; cin >> p->info.namaMK;
    cout << "Masukkan Kuota Maks    : "; cin >> p->info.kuotaMaks;
    p->info.jumlahMhs = 0;
    cout << "Masukkan Jadwal Hari   : "; cin >> p->info.jadwalHari;
    p->firstMhs = nullptr;
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

void insertFirstMK(listMK &LMK, adrMK p) {
    if (LMK.firstMK == nullptr) {
        LMK.firstMK = p;
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

bool cekKapasitasMK(adrMK p) {
    bool penuh = false;
    if (p != nullptr) {
        penuh = p->info.kuotaMaks <= p->info.jumlahMhs;
    }
    return penuh;
}

void insertFirstMhsInMK(adrMK mk, adrMhs p) {
    if (mk->firstMhs == nullptr) {
        mk->firstMhs = p;
    } else {
        p->nextMhs = mk->firstMhs;
        mk->firstMhs = p;
    }
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

void printAllMKWithMhs(listMK LMK) {
    adrMK mk = LMK.firstMK;

    while (mk != nullptr) {
        cout << "  Kode MK         : " << mk->info.kodeMK << endl;
        cout << "  Nama MK         : " << mk->info.namaMK << endl;
        cout << "  Kuota Kelas     : " << mk->info.jumlahMhs << " / " << mk->info.kuotaMaks << " Mahasiswa" << endl;
        cout << "  Jadwal          : " << mk->info.jadwalHari << endl;
        cout << "===========Mahasiswa===========" << endl;
        cout << "===============================" << endl;

        adrMhs mhs = mk->firstMhs;
        while (mhs != nullptr) {
            cout << "  NIM           : " << mhs->info.nim << endl;
            cout << "  Nama Mhs      : " << mhs->info.namaMhs << endl;
            cout << "  Umur          : " << mhs->info.umurMhs << " tahun" << endl;
            cout << "  Jenis Kelamin : " << mhs->info.jenisKelamin << endl;
            cout << "  Alamat        : " << mhs->info.alamatMhs << endl << endl;
            mhs = mhs->nextMhs;
        }
        cout << "===============================" << endl;
        mk = mk->nextMK;
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
    } else {
        adrMK q = LMK.firstMK;
        while (q->nextMK != nullptr) {
            q = q->nextMK;
        }
        q->nextMK = p;
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

void hapusSemuaMhsDiMK(adrMK mk) {
    adrMhs currentM = mk->firstMhs;
    while (currentM != nullptr) {
        adrMhs hapusM = currentM;
        currentM = currentM->nextMhs;
        hapusM->nextMhs = nullptr;
        delete hapusM;
    }
    mk->firstMhs = nullptr;
    mk->info.jumlahMhs = 0;
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

void deleteMhsDariMK(listMK &LMK, string namaMK, string nim) {
    adrMK mk = cariMK(LMK, namaMK);

    if (mk == nullptr) {
        cout << "Gagal: Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    adrMhs current = mk->firstMhs;
    adrMhs prev = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->info.nim == nim) {
            found = true;
            break;
        }
        prev = current;
        current = current->nextMhs;
    }

    if (found) {
        if (prev == nullptr) {
            mk->firstMhs = current->nextMhs;
        } else {
            prev->nextMhs = current->nextMhs;
        }

        current->nextMhs = nullptr;
        delete current;

        mk->info.jumlahMhs--;
        cout << "Berhasil: Mahasiswa dengan NIM " << nim << " dibatalkan dari MK " << namaMK << "!" << endl;
    } else {
        cout << "Gagal: Mahasiswa NIM " << nim << " tidak terdaftar di kelas " << namaMK << "!" << endl;
    }
}

void insertMhsToMK(listMK &LMK) {
    int i, n;
    adrMhs mhs;
    adrMK mk;
    string namaMK, nim;

    cout << "Nama Mata Kuliah yang ingin diambil: ";
    cin >> namaMK;

    mk = cariMK(LMK, namaMK);
    if (mk == nullptr) {
        cout << "Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    bool penuh = cekKapasitasMK(mk);
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

        if (cariMhsDiMK(mk, nim) != nullptr) {
            cout << "=> GAGAL: Mahasiswa NIM " << nim << " sudah terdaftar di kelas ini!" << endl;
        } else {
            mhs = createElmMhs();
            mhs->info.nim = nim;
            insertFirstMhsInMK(mk, mhs);
            mk->info.jumlahMhs++;
            cout << "=> BERHASIL didaftarkan ke kelas!" << endl;
        }
    }
}

adrMhs cariMhsDiMK(adrMK mk, string nim) {
    adrMhs q = mk->firstMhs;
    while (q != nullptr) {
        if (q->info.nim == nim) {
            return q;
        }
        q = q->nextMhs;
    }
    return nullptr;
}

void updateMhsDiMK(listMK &LMK, string namaMK, string nim) {
    adrMK mk = cariMK(LMK, namaMK);
    if (mk == nullptr) {
        cout << "Mata Kuliah tidak ditemukan!" << endl;
        return;
    }
    adrMhs p = cariMhsDiMK(mk, nim);
    if (p != nullptr) {
        cout << "Masukkan Nama Baru   : "; cin >> p->info.namaMhs;
        cout << "Masukkan Umur Baru   : "; cin >> p->info.umurMhs;
        cout << "Masukkan Gender Baru : "; cin >> p->info.jenisKelamin;
        cout << "Masukkan Alamat Baru : "; cin >> p->info.alamatMhs;
        cout << "Update berhasil!" << endl;
    } else {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan di kelas ini!" << endl;
    }
}

void deleteMKByNama(listMK &LMK, string namaMK) {
    adrMK mk = cariMK(LMK, namaMK);
    if (mk == nullptr) {
        cout << "Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    hapusSemuaMhsDiMK(mk);

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

    cout << "Mata Kuliah " << namaMK << " beserta seluruh mahasiswanya berhasil dihapus!" << endl;
}
