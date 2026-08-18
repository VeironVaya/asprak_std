#include "binary_tree.h"

void createTree(Tree &T) {
    T.root = nullptr;
}

address createElement(infotype x) {
    address p = new elmNode;
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

bool isEmpty(Tree T) {
    return T.root == nullptr;
}

void insertNode(address &root, address p) {
    if (root == nullptr) {
        root = p;
    } else if (p->info.harga < root->info.harga) {
        insertNode(root->left, p);
    } else {
        insertNode(root->right, p);
    }
}

address searchNode(address root, double harga) {
    if (root == nullptr || root->info.harga == harga) {
        return root;
    }
    if (harga < root->info.harga) {
        return searchNode(root->left, harga);
    }
    return searchNode(root->right, harga);
}

void preOrder(address root) {
    if (root != nullptr) {
        cout << "ID       : " << root->info.idProduk << endl;
        cout << "Nama     : " << root->info.namaProduk << endl;
        cout << "Kategori : " << root->info.kategori << endl;
        cout << "Harga    : " << root->info.harga << endl;
        cout << "Stok     : " << root->info.stok << endl;
        cout << "-------------------------" << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << "ID       : " << root->info.idProduk << endl;
        cout << "Nama     : " << root->info.namaProduk << endl;
        cout << "Kategori : " << root->info.kategori << endl;
        cout << "Harga    : " << root->info.harga << endl;
        cout << "Stok     : " << root->info.stok << endl;
        cout << "-------------------------" << endl;
        inOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << "ID       : " << root->info.idProduk << endl;
        cout << "Nama     : " << root->info.namaProduk << endl;
        cout << "Kategori : " << root->info.kategori << endl;
        cout << "Harga    : " << root->info.harga << endl;
        cout << "Stok     : " << root->info.stok << endl;
        cout << "-------------------------" << endl;
    }
}

int tinggiTree(address root) {
    if (root == nullptr) {
        return -1;
    } else {
        int u = tinggiTree(root->left);
        int v = tinggiTree(root->right);
        if (u > v) {
            return u + 1;
        } else {
            return v + 1;
        }
    }
}

int hitungLeaf(address root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return hitungLeaf(root->left) + hitungLeaf(root->right);
}

address findMin(address root) {
    address current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

address deleteNode(address root, double harga) {
    if (root == nullptr) {
        return root;
    }

    if (harga < root->info.harga) {
        root->left = deleteNode(root->left, harga);
    } else if (harga > root->info.harga) {
        root->right = deleteNode(root->right, harga);
    } else {
        if (root->left == nullptr) {
            address temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            address temp = root->left;
            delete root;
            return temp;
        }

        address temp = findMin(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info.harga);
    }
    return root;
}
