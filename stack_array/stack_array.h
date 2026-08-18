#ifndef STACK_ARRAY_H_INCLUDED
#define STACK_ARRAY_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Buku {
    string idBuku;
    string judulBuku;
    string penulis;
    int tahunTerbit;
};

typedef Buku infotype;

struct Stack {
    infotype info[MAX_SIZE];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
void pop(Stack &S, infotype &x);
void printStack(Stack S);
void clearStack(Stack &S);

#endif
