#include "queue_array.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFull(Queue Q) {
    return Q.tail == MAX_SIZE - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFull(Q)) {
        cout << "Antrean Penuh (Overflow)!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
        cout << "Pelanggan berhasil masuk antrean dengan No: " << x.nomorAntrean << endl;
    }
}

void dequeue(Queue &Q, infotype &x) {
    if (isEmpty(Q)) {
        cout << "Antrean Kosong (Underflow)!" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
}

void printQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Antrean kosong!" << endl;
    } else {
        cout << "\n=== DAFTAR ANTREAN PELANGGAN ===" << endl;
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << "No Antrean   : " << Q.info[i].nomorAntrean << endl;
            cout << "ID Pelanggan : " << Q.info[i].idPelanggan << endl;
            cout << "Nama         : " << Q.info[i].namaPelanggan << endl;
            cout << "Keperluan    : " << Q.info[i].keperluan << endl;
            cout << "----------------------------------------------" << endl;
        }
    }
}

void clearQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}
