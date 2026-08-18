#ifndef MLL_ONETON_H_INCLUDED
#define MLL_ONETON_H_INCLUDED

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

struct elmListMK {
    InfoMK info;
    adrMK nextMK;
};

struct elmListMhs {
    InfoMhs info;
    adrMK toMK;
    adrMhs nextMhs;
};

struct listMK {
    adrMK firstMK;
};

struct listMhs {
    adrMhs firstMhs;
};

void createListMK(listMK &LMK);
void createListMhs(listMhs &LM);
adrMK createElmMK();
adrMhs createElmMhs();
void insertFirstMK(listMK &LMK, adrMK p);
void tambahMK(listMK &LMK);
adrMK cariMK(listMK LMK, string namaMK);
bool cekKapasitasMK(listMK LMK, adrMK p);
void insertFirstMhs(listMhs &LM, adrMhs p);
void insertMhsToMK(listMK &LMK, listMhs &LM);
void printAllMK(listMK LMK);
void printAllMKWithMhs(listMK LMK, listMhs LM);
void insertAfterMK(listMK &LMK, adrMK prec, adrMK p);
void insertLastMK(listMK &LMK, adrMK p);
void updateMK(listMK &LMK, string namaMK);
void deleteFirstMK(listMK &LMK, adrMK &p);
void deleteLastMK(listMK &LMK, adrMK &p);
void deleteAfterMK(listMK &LMK, adrMK prec, adrMK &p);
void sortMK(listMK &LMK);
void deleteMhsDariMK(listMK &LMK, listMhs &LM, string namaMK, string nim);
adrMhs cariMhs(listMhs LM, string nim);
void printAllMhs(listMhs LM);
void updateMhs(listMhs &LM, string nim);
void deleteMKByNama(listMK &LMK, listMhs &LM, string namaMK);

#endif
