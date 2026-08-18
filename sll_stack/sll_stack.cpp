#include "sll_stack.h"

void createStack(Stack &S) {
    S.top = nullptr;
}

address createElement(infotype x) {
    address p = new elmNode;
    p->info = x;
    p->next = nullptr;
    return p;
}

bool isEmpty(Stack S) {
    return S.top == nullptr;
}

void push(Stack &S, address p) {
    if (isEmpty(S)) {
        S.top = p;
    } else {
        p->next = S.top;
        S.top = p;
    }
}

void pop(Stack &S, address &p) {
    if (isEmpty(S)) {
        p = nullptr;
    } else {
        p = S.top;
        S.top = S.top->next;
        p->next = nullptr;
    }
}

void printStack(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        address q = S.top;
        cout << "\n=== ISI STACK BUKU (TOP TO BOTTOM) ===" << endl;
        while (q != nullptr) {
            cout << "ID Buku      : " << q->info.idBuku << endl;
            cout << "Judul Buku   : " << q->info.judulBuku << endl;
            cout << "Penulis      : " << q->info.penulis << endl;
            cout << "Tahun Terbit : " << q->info.tahunTerbit << endl;
            cout << "-------------------------------------" << endl;
            q = q->next;
        }
    }
}

void clearStack(Stack &S) {
    address p;
    while (!isEmpty(S)) {
        pop(S, p);
        delete p;
    }
}
