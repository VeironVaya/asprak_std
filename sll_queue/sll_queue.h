#ifndef SLL_QUEUE_H_INCLUDED
#define SLL_QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

struct Pelanggan {
    string idPelanggan;
    string namaPelanggan;
    string keperluan;
    int nomorAntrean;
};

typedef Pelanggan infotype;

struct elmNode {
    infotype info;
    elmNode* next;
};

typedef elmNode* address;

struct Queue {
    address head;
    address tail;
};

void createQueue(Queue &Q);
address createElement(infotype x);
bool isEmpty(Queue Q);
void enqueue(Queue &Q, address p);
void dequeue(Queue &Q, address &p);
void printQueue(Queue Q);
void clearQueue(Queue &Q);

#endif
