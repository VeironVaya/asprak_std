#include "stack_v1.h"

void createStackMK(stackMK &SMK) {
    SMK.topMK = nullptr;
}

void createStackMhs(stackMhs &SM) {
    SM.topMhs = nullptr;
}

adrMK createElmMK() {
    adrMK p = new elmStackMK;
    cout << "Masukkan Kode MK       : "; cin >> p->info.kodeMK;
    cout << "Masukkan Nama MK       : "; cin >> p->info.namaMK;
    cout << "Masukkan Kuota Maks    : "; cin >> p->info.kuotaMaks;
    p->info.jumlahMhs = 0;
    cout << "Masukkan Jadwal Hari   : "; cin >> p->info.jadwalHari;
    p->topRelasi = nullptr;
    p->nextMK = nullptr;
    return p;
}

adrMhs createElmMhs() {
    adrMhs p = new elmStackMhs;
    cout << "Masukkan NIM           : "; cin >> p->info.nim;
    cout << "Masukkan Nama Mhs      : "; cin >> p->info.namaMhs;
    cout << "Masukkan Umur          : "; cin >> p->info.umurMhs;
    cout << "Masukkan Jenis Kelamin : "; cin >> p->info.jenisKelamin;
    cout << "Masukkan Alamat        : "; cin >> p->info.alamatMhs;
    p->nextMhs = nullptr;
    return p;
}

adrRelasi createElmRelasi() {
    adrRelasi r = new elmStackRelasi;
    r->nextRelasi = nullptr;
    r->toMhs = nullptr;
    return r;
}

void pushRelasi(adrMK mk, adrMhs mhs, adrRelasi r) {
    r->toMhs = mhs;
    if (mk->topRelasi == nullptr) {
        mk->topRelasi = r;
    } else {
        r->nextRelasi = mk->topRelasi;
        mk->topRelasi = r;
    }
}

void popRelasi(adrMK mk, adrRelasi &r) {
    if (mk->topRelasi != nullptr) {
        r = mk->topRelasi;
        mk->topRelasi = r->nextRelasi;
        r->nextRelasi = nullptr;
    } else {
        r = nullptr;
    }
}

void pushMK(stackMK &SMK, adrMK p) {
    if (SMK.topMK == nullptr) {
        SMK.topMK = p;
    } else {
        p->nextMK = SMK.topMK;
        SMK.topMK = p;
    }
}

void popMK(stackMK &SMK, adrMK &p) {
    if (SMK.topMK != nullptr) {
        p = SMK.topMK;
        SMK.topMK = p->nextMK;
        p->nextMK = nullptr;
    } else {
        p = nullptr;
    }
}

void tambahMK(stackMK &SMK) {
    int i, n;
    adrMK p;
    cout << "Berapa banyak Mata Kuliah yang ingin ditambahkan: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        p = createElmMK();
        pushMK(SMK, p);
    }
}

adrMK cariMK(stackMK SMK, string namaMK) {
    adrMK q = SMK.topMK;
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

void pushMhs(stackMhs &SM, adrMhs p) {
    if (SM.topMhs == nullptr) {
        SM.topMhs = p;
    } else {
        p->nextMhs = SM.topMhs;
        SM.topMhs = p;
    }
    cout << "Mahasiswa " << p->info.nim << " berhasil dimasukkan ke master data" << endl;
}

void popMhs(stackMhs &SM, adrMhs &p) {
    if (SM.topMhs != nullptr) {
        p = SM.topMhs;
        SM.topMhs = p->nextMhs;
        p->nextMhs = nullptr;
    } else {
        p = nullptr;
    }
}

void printAllMK(stackMK SMK) {
    adrMK q = SMK.topMK;
    while (q != nullptr) {
        cout << q->info.kodeMK << endl;
        cout << q->info.namaMK << endl;
        cout << q->info.kuotaMaks << endl;
        cout << q->info.jumlahMhs << endl;
        cout << q->info.jadwalHari << endl;
        q = q->nextMK;
    }
}

void printAllMKWithMhs(stackMK SMK) {
    adrMK mk = SMK.topMK;

    while (mk != nullptr) {
        cout << "  Kode MK         : " << mk->info.kodeMK << endl;
        cout << "  Nama MK         : " << mk->info.namaMK << endl;
        cout << "  Kuota Kelas     : " << mk->info.jumlahMhs << " / " << mk->info.kuotaMaks << " Mahasiswa" << endl;
        cout << "  Jadwal          : " << mk->info.jadwalHari << endl;
        cout << "===========Mahasiswa===========" << endl;
        cout << "===============================" << endl;

        adrRelasi r = mk->topRelasi;
        while (r != nullptr) {
            cout << "  NIM           : " << r->toMhs->info.nim << endl;
            cout << "  Nama Mhs      : " << r->toMhs->info.namaMhs << endl;
            cout << "  Umur          : " << r->toMhs->info.umurMhs << " tahun" << endl;
            cout << "  Jenis Kelamin : " << r->toMhs->info.jenisKelamin << endl;
            cout << "  Alamat        : " << r->toMhs->info.alamatMhs << endl << endl;
            r = r->nextRelasi;
        }
        cout << "===============================" << endl;
        mk = mk->nextMK;
    }
}

void updateMK(stackMK &SMK, string namaMK) {
    adrMK p = cariMK(SMK, namaMK);
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

void deleteMhsDariMK(stackMK &SMK, string namaMK, string nim) {
    adrMK mk = cariMK(SMK, namaMK);

    if (mk == nullptr) {
        cout << "Gagal: Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    if (mk->info.jumlahMhs == 0) {
        cout << "Gagal: Kelas Mata Kuliah ini kosong!" << endl;
        return;
    }

    adrRelasi current = mk->topRelasi;
    adrRelasi prev = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->toMhs->info.nim == nim) {
            found = true;
            break;
        }
        prev = current;
        current = current->nextRelasi;
    }

    if (found) {
        if (prev == nullptr) {
            mk->topRelasi = current->nextRelasi;
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

void insertMhsToMK(stackMK &SMK, stackMhs &SM) {
    int i, n;
    adrMhs mhs;
    adrMK mk;
    adrRelasi r;
    string namaMK, nim;

    cout << "Nama Mata Kuliah yang ingin diambil: ";
    cin >> namaMK;

    mk = cariMK(SMK, namaMK);
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

        mhs = cariMhs(SM, nim);
        if (mhs == nullptr) {
            mhs = new elmStackMhs;
            mhs->info.nim = nim;
            cout << "Masukkan Nama Mhs      : "; cin >> mhs->info.namaMhs;
            cout << "Masukkan Umur          : "; cin >> mhs->info.umurMhs;
            cout << "Masukkan Jenis Kelamin : "; cin >> mhs->info.jenisKelamin;
            cout << "Masukkan Alamat        : "; cin >> mhs->info.alamatMhs;
            mhs->nextMhs = nullptr;
            pushMhs(SM, mhs);
        } else {
            cout << "=> Mahasiswa ditemukan di database (Nama: " << mhs->info.namaMhs << ")" << endl;
        }

        if (cariRelasi(mk, nim) != nullptr) {
            cout << "=> GAGAL: Mahasiswa NIM " << nim << " sudah terdaftar di kelas ini!" << endl;
        } else {
            r = createElmRelasi();
            pushRelasi(mk, mhs, r);
            mk->info.jumlahMhs++;
            cout << "=> BERHASIL didaftarkan ke kelas!" << endl;
        }
    }
}

adrMhs cariMhs(stackMhs SM, string nim) {
    adrMhs q = SM.topMhs;
    while (q != nullptr) {
        if (q->info.nim == nim) {
            return q;
        }
        q = q->nextMhs;
    }
    return nullptr;
}

void printAllMhs(stackMhs SM) {
    adrMhs q = SM.topMhs;
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

void updateMhs(stackMhs &SM, string nim) {
    adrMhs p = cariMhs(SM, nim);
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

adrRelasi cariRelasi(adrMK mk, string nim) {
    adrRelasi q = mk->topRelasi;
    while (q != nullptr) {
        if (q->toMhs->info.nim == nim) {
            return q;
        }
        q = q->nextRelasi;
    }
    return nullptr;
}

void deleteMKByNama(stackMK &SMK, string namaMK) {
    adrMK mk = cariMK(SMK, namaMK);
    if (mk == nullptr) {
        cout << "Mata Kuliah tidak ditemukan!" << endl;
        return;
    }

    adrRelasi currentR = mk->topRelasi;
    while (currentR != nullptr) {
        adrRelasi hapusR = currentR;
        currentR = currentR->nextRelasi;
        hapusR->nextRelasi = nullptr;
        delete hapusR;
    }
    mk->topRelasi = nullptr;
    mk->info.jumlahMhs = 0;

    adrMK hapusMK;
    if (SMK.topMK == mk) {
        popMK(SMK, hapusMK);
    } else {
        adrMK prevMK = SMK.topMK;
        while (prevMK->nextMK != mk) {
            prevMK = prevMK->nextMK;
        }
        prevMK->nextMK = mk->nextMK;
        mk->nextMK = nullptr;
        hapusMK = mk;
        delete hapusMK;
    }

    cout << "Mata Kuliah " << namaMK << " beserta data KRS didalamnya berhasil dihapus!" << endl;
}
