#ifndef MLL_RELASI_H_INCLUDED
#define MLL_RELASI_H_INCLUDED

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
typedef struct elmListRelasi *adrRelasi;

struct elmListMK {
    adrMK nextMK;
    InfoMK info;
};

struct elmListMhs {
    adrMhs nextMhs;
    InfoMhs info;
};

struct elmListRelasi {
    adrMK toMK;
    adrMhs toMhs;
    adrRelasi nextRelasi;
};

struct listMK {
    adrMK firstMK;
};
struct listMhs {
    adrMhs firstMhs;
};
struct listRelasi {
    adrRelasi firstRelasi;
};

void createListMK(listMK &LMK);
void createListMhs(listMhs &LM);
void createListRelasi(listRelasi &LR);
adrMK createElmMK();
adrMhs createElmMhs();
adrRelasi createElmRelasi();
void insertFirstRelasi(listRelasi &LR, adrMK mk, adrMhs mhs, adrRelasi r);
void insertFirstMK(listMK &LMK, adrMK p);
void tambahMK(listMK &LMK);
adrMK cariMK(listMK LMK, string namaMK);
bool cekKapasitasMK(listMK LMK, adrMK p);
void insertFirstMhs(listMhs &LM, adrMhs p);
void insertMhsToMK(listMK &LMK, listMhs &LM, listRelasi &LR);
void printAllMK(listMK LMK);
void printAllMKWithMhs(listMK LMK, listRelasi LR);
void insertAfterMK(listMK &LMK, adrMK prec, adrMK p);
void insertLastMK(listMK &LMK, adrMK p);
void updateMK(listMK &LMK, string namaMK);
void deleteFirstMK(listMK &LMK, adrMK &p);
void deleteLastMK(listMK &LMK, adrMK &p);
void deleteAfterMK(listMK &LMK, adrMK prec, adrMK &p);
void sortMK(listMK &LMK);
void deleteMhsDariMK(listMK &LMK, listRelasi &LR, string namaMK, string nim);
adrMhs cariMhs(listMhs LM, string nim);
void printAllMhs(listMhs LM);
void updateMhs(listMhs &LM, string nim);
adrRelasi cariRelasi(listRelasi LR, string namaMK, string nim);
void deleteMKByNama(listMK &LMK, listRelasi &LR, string namaMK);

#endif // MLL_RELASI_H_INCLUDED
