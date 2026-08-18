#ifndef SLL_STACK_H_INCLUDED
#define SLL_STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct Buku {
    string idBuku;
    string judulBuku;
    string penulis;
    int tahunTerbit;
};

typedef Buku infotype;

struct elmNode {
    infotype info;
    elmNode* next;
};

typedef elmNode* address;

struct Stack {
    address top;
};

void createStack(Stack &S);
address createElement(infotype x);
bool isEmpty(Stack S);
void push(Stack &S, address p);
void pop(Stack &S, address &p);
void printStack(Stack S);
void clearStack(Stack &S);

#endif
