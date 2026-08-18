#include "sll_basic.h"

void createList(ListMahasiswa &L) {
    L.head = nullptr;
}

address createElement(infotype x) {
    address p = new elmNode;
    p->info = x;
    p->next = nullptr;
    return p;
}

bool isEmpty(ListMahasiswa L) {
    return L.head == nullptr;
}

void insertFirst(ListMahasiswa &L, address p) {
    if (isEmpty(L)) {
        L.head = p;
    } else {
        p->next = L.head;
        L.head = p;
    }
}

void insertLast(ListMahasiswa &L, address p) {
    if (isEmpty(L)) {
        L.head = p;
    } else {
        address q = L.head;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void deleteFirst(ListMahasiswa &L, address &p) {
    if (isEmpty(L)) {
        p = nullptr;
    } else {
        p = L.head;
        L.head = L.head->next;
        p->next = nullptr;
    }
}

void deleteLast(ListMahasiswa &L, address &p) {
    if (isEmpty(L)) {
        p = nullptr;
    } else if (L.head->next == nullptr) {
        p = L.head;
        L.head = nullptr;
    } else {
        address q = L.head;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

address cariMahasiswa(ListMahasiswa L, string nim) {
    address q = L.head;
    while (q != nullptr) {
        if (q->info.nim == nim) {
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void updateMahasiswa(ListMahasiswa &L, string nim) {
    address p = cariMahasiswa(L, nim);
    if (p != nullptr) {
        cout << "Masukkan Nama Baru   : "; cin >> p->info.namaMhs;
        cout << "Masukkan Kelas MK Baru: "; cin >> p->info.kelasMK;
        cout << "Masukkan Umur Baru   : "; cin >> p->info.umurMhs;
        cout << "Masukkan Alamat Baru : "; cin >> p->info.alamatMhs;
        cout << "Data mahasiswa berhasil diupdate!" << endl;
    } else {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan!" << endl;
    }
}

void deleteMahasiswaByNIM(ListMahasiswa &L, string nim) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    address p = L.head;
    if (p->info.nim == nim) {
        L.head = p->next;
        p->next = nullptr;
        delete p;
        cout << "Mahasiswa berhasil dihapus dari list!" << endl;
        return;
    }

    address prev = nullptr;
    while (p != nullptr && p->info.nim != nim) {
        prev = p;
        p = p->next;
    }

    if (p != nullptr) {
        prev->next = p->next;
        p->next = nullptr;
        delete p;
        cout << "Mahasiswa berhasil dihapus dari list!" << endl;
    } else {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan!" << endl;
    }
}

void printList(ListMahasiswa L) {
    if (isEmpty(L)) {
        cout << "Data Mahasiswa kosong!" << endl;
    } else {
        address q = L.head;
        cout << "\n================ DAFTAR MAHASISWA ================" << endl;
        while (q != nullptr) {
            cout << "NIM           : " << q->info.nim << endl;
            cout << "Nama          : " << q->info.namaMhs << endl;
            cout << "Kelas MK      : " << q->info.kelasMK << endl;
            cout << "Umur          : " << q->info.umurMhs << " tahun" << endl;
            cout << "Alamat        : " << q->info.alamatMhs << endl;
            cout << "--------------------------------------------------" << endl;
            q = q->next;
        }
    }
}

void clearList(ListMahasiswa &L) {
    address p;
    while (!isEmpty(L)) {
        deleteFirst(L, p);
        delete p;
    }
}
