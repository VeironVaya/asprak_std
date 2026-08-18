#ifndef MLL_BASIC_H_INCLUDED
#define MLL_BASIC_H_INCLUDED

#include <iostream>
using namespace std;

struct MataKuliah {
    string kodeMK;
    string namaMK;
    int kuotaMaks;
    int jumlahMhs;
    string jadwalHari;
};

struct Mahasiswa {
    string nim;
    string namaMhs;
    string jenisKelamin;
    int umurMhs;
    string alamatMhs;
};

typedef MataKuliah InfoMK;
typedef Mahasiswa InfoMhs;

typedef struct elmListMK *adrMK;
typedef struct elmListMhs *adrMhs;

struct elmListMhs {
    InfoMhs info;
    adrMhs nextMhs;
};

struct elmListMK {
    InfoMK info;
    adrMhs firstMhs;
    adrMK nextMK;
};

struct listMK {
    adrMK firstMK;
};

void createListMK(listMK &LMK);
adrMK createElmMK();
adrMhs createElmMhs();
void insertFirstMK(listMK &LMK, adrMK p);
void tambahMK(listMK &LMK);
adrMK cariMK(listMK LMK, string namaMK);
bool cekKapasitasMK(adrMK p);
void insertFirstMhsInMK(adrMK mk, adrMhs p);
void insertMhsToMK(listMK &LMK);
void printAllMK(listMK LMK);
void printAllMKWithMhs(listMK LMK);
void insertAfterMK(listMK &LMK, adrMK prec, adrMK p);
void insertLastMK(listMK &LMK, adrMK p);
void updateMK(listMK &LMK, string namaMK);
void hapusSemuaMhsDiMK(adrMK mk);
void deleteFirstMK(listMK &LMK, adrMK &p);
void deleteLastMK(listMK &LMK, adrMK &p);
void deleteAfterMK(listMK &LMK, adrMK prec, adrMK &p);
void sortMK(listMK &LMK);
void deleteMhsDariMK(listMK &LMK, string namaMK, string nim);
adrMhs cariMhsDiMK(adrMK mk, string nim);
void updateMhsDiMK(listMK &LMK, string namaMK, string nim);
void deleteMKByNama(listMK &LMK, string namaMK);

#endif
