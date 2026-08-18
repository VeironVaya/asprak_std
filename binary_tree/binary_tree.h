#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <iostream>
#include <queue>
using namespace std;

struct Produk {
    string idProduk;
    string namaProduk;
    string kategori;
    double harga;
    int stok;
};

typedef Produk infotype;

struct elmNode {
    infotype info;
    elmNode* left;
    elmNode* right;
};

typedef elmNode* address;

struct Tree {
    address root;
};

void createTree(Tree &T);
address createElement(infotype x);
bool isEmpty(Tree T);
void insertNode(address &root, address p);
address searchNode(address root, double harga);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int tinggiTree(address root);
int hitungLeaf(address root);
address findMin(address root);
address findMax(address root);
int hitungSize(address root);
void levelOrderTraversal(address root);
bool isValidBST(address root);
void mirrorTree(address root);
address deleteNode(address root, double harga);

#endif
