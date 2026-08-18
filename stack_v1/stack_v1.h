#ifndef STACK_V1_H_INCLUDED
#define STACK_V1_H_INCLUDED

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

typedef struct elmStackMK *adrMK;
typedef struct elmStackMhs *adrMhs;
typedef struct elmStackRelasi *adrRelasi;

struct elmStackMhs {
    InfoMhs info;
    adrMhs nextMhs;
};

struct elmStackRelasi {
    adrMhs toMhs;
    adrRelasi nextRelasi;
};

struct elmStackMK {
    InfoMK info;
    adrRelasi topRelasi;
    adrMK nextMK;
};

struct stackMK {
    adrMK topMK;
};

struct stackMhs {
    adrMhs topMhs;
};

void createStackMK(stackMK &SMK);
void createStackMhs(stackMhs &SM);
adrMK createElmMK();
adrMhs createElmMhs();
adrRelasi createElmRelasi();
void pushRelasi(adrMK mk, adrMhs mhs, adrRelasi r);
void popRelasi(adrMK mk, adrRelasi &r);
void pushMK(stackMK &SMK, adrMK p);
void popMK(stackMK &SMK, adrMK &p);
void tambahMK(stackMK &SMK);
adrMK cariMK(stackMK SMK, string namaMK);
bool cekKapasitasMK(adrMK p);
void pushMhs(stackMhs &SM, adrMhs p);
void popMhs(stackMhs &SM, adrMhs &p);
void insertMhsToMK(stackMK &SMK, stackMhs &SM);
void printAllMK(stackMK SMK);
void printAllMKWithMhs(stackMK SMK);
void updateMK(stackMK &SMK, string namaMK);
void deleteMhsDariMK(stackMK &SMK, string namaMK, string nim);
adrMhs cariMhs(stackMhs SM, string nim);
void printAllMhs(stackMhs SM);
void updateMhs(stackMhs &SM, string nim);
adrRelasi cariRelasi(adrMK mk, string nim);
void deleteMKByNama(stackMK &SMK, string namaMK);

#endif
