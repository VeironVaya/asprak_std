#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

struct SimpulRelasi {
    string namaTeman;
    SimpulRelasi* nextRelasi;
};

struct Vertex {
    string namaUser;
    SimpulRelasi* firstRelasi;
    Vertex* nextVertex;
};

struct Graph {
    Vertex* firstVertex;
};

void createGraph(Graph &G);
Vertex* createVertex(string nama);
SimpulRelasi* createRelasi(string namaTeman);
void tambahUser(Graph &G, string nama);
Vertex* cariUser(Graph &G, string nama);
void tambahPertemanan(Graph &G, string user1, string user2);
void printGraph(Graph &G);
void clearGraph(Graph &G);

#endif
