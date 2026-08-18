#ifndef QUEUE_ARRAY_H_INCLUDED
#define QUEUE_ARRAY_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Pelanggan {
    string idPelanggan;
    string namaPelanggan;
    string keperluan;
    int nomorAntrean;
};

typedef Pelanggan infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, infotype x);
void dequeue(Queue &Q, infotype &x);
void printQueue(Queue Q);
void clearQueue(Queue &Q);

#endif
