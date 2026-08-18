#ifndef SLL_BASIC_H_INCLUDED
#define SLL_BASIC_H_INCLUDED

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim;
    string namaMhs;
    string kelasMK;
    int umurMhs;
    string alamatMhs;
};

typedef Mahasiswa infotype;

struct elmNode {
    infotype info;
    elmNode* next;
};

typedef elmNode* address;

struct ListMahasiswa {
    address head;
};

void createList(ListMahasiswa &L);
address createElement(infotype x);
bool isEmpty(ListMahasiswa L);
void insertFirst(ListMahasiswa &L, address p);
void insertLast(ListMahasiswa &L, address p);
void deleteFirst(ListMahasiswa &L, address &p);
void deleteLast(ListMahasiswa &L, address &p);
address cariMahasiswa(ListMahasiswa L, string nim);
void updateMahasiswa(ListMahasiswa &L, string nim);
void deleteMahasiswaByNIM(ListMahasiswa &L, string nim);
void printList(ListMahasiswa L);
void clearList(ListMahasiswa &L);

#endif
