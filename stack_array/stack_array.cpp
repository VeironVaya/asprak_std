#include "stack_array.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX_SIZE - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh (Overflow)!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
        cout << "Buku berhasil di-push ke stack!" << endl;
    }
}

void pop(Stack &S, infotype &x) {
    if (isEmpty(S)) {
        cout << "Stack Kosong (Underflow)!" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }
}

void printStack(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "\n=== ISI STACK BUKU (TOP TO BOTTOM) ===" << endl;
        for (int i = S.top; i >= 0; i--) {
            cout << "ID Buku      : " << S.info[i].idBuku << endl;
            cout << "Judul Buku   : " << S.info[i].judulBuku << endl;
            cout << "Penulis      : " << S.info[i].penulis << endl;
            cout << "Tahun Terbit : " << S.info[i].tahunTerbit << endl;
            cout << "-------------------------------------" << endl;
        }
    }
}

void clearStack(Stack &S) {
    S.top = -1;
}
