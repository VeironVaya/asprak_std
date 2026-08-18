#include "sll_queue.h"

void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

address createElement(infotype x) {
    address p = new elmNode;
    p->info = x;
    p->next = nullptr;
    return p;
}

bool isEmpty(Queue Q) {
    return Q.head == nullptr && Q.tail == nullptr;
}

void enqueue(Queue &Q, address p) {
    if (isEmpty(Q)) {
        Q.head = p;
        Q.tail = p;
    } else {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void dequeue(Queue &Q, address &p) {
    if (isEmpty(Q)) {
        p = nullptr;
    } else if (Q.head == Q.tail) {
        p = Q.head;
        Q.head = nullptr;
        Q.tail = nullptr;
    } else {
        p = Q.head;
        Q.head = Q.head->next;
        p->next = nullptr;
    }
}

void printQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Antrean kosong!" << endl;
    } else {
        address q = Q.head;
        cout << "\n=== DAFTAR ANTREAN PELANGGAN (HEAD TO TAIL) ===" << endl;
        while (q != nullptr) {
            cout << "No Antrean   : " << q->info.nomorAntrean << endl;
            cout << "ID Pelanggan : " << q->info.idPelanggan << endl;
            cout << "Nama         : " << q->info.namaPelanggan << endl;
            cout << "Keperluan    : " << q->info.keperluan << endl;
            cout << "----------------------------------------------" << endl;
            q = q->next;
        }
    }
}

void clearQueue(Queue &Q) {
    address p;
    while (!isEmpty(Q)) {
        dequeue(Q, p);
        delete p;
    }
}
