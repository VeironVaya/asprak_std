#include "../Headers/graph.h"

void createGraph(Graph &G) {
    G.firstVertex = nullptr;
}

Vertex* createVertex(string nama) {
    Vertex* v = new Vertex;
    v->namaUser = nama;
    v->firstRelasi = nullptr;
    v->nextVertex = nullptr;
    return v;
}

SimpulRelasi* createRelasi(string namaTeman) {
    SimpulRelasi* r = new SimpulRelasi;
    r->namaTeman = namaTeman;
    r->nextRelasi = nullptr;
    return r;
}

void tambahUser(Graph &G, string nama) {
    if (cariUser(G, nama) != nullptr) {
        cout << "User '" << nama << "' sudah terdaftar!" << endl;
        return;
    }

    Vertex* v = createVertex(nama);
    if (G.firstVertex == nullptr) {
        G.firstVertex = v;
    } else {
        Vertex* p = G.firstVertex;
        while (p->nextVertex != nullptr) {
            p = p->nextVertex;
        }
        p->nextVertex = v;
    }
    cout << "[VERTEX] User '" << nama << "' berhasil ditambahkan ke medsos!" << endl;
}

Vertex* cariUser(Graph &G, string nama) {
    Vertex* p = G.firstVertex;
    while (p != nullptr) {
        if (p->namaUser == nama) {
            return p;
        }
        p = p->nextVertex;
    }
    return nullptr;
}

void tambahRelasiHelper(Vertex* v, string namaTeman) {
    SimpulRelasi* r = createRelasi(namaTeman);
    if (v->firstRelasi == nullptr) {
        v->firstRelasi = r;
    } else {
        SimpulRelasi* p = v->firstRelasi;
        while (p->nextRelasi != nullptr) {
            p = p->nextRelasi;
        }
        p->nextRelasi = r;
    }
}

void tambahPertemanan(Graph &G, string user1, string user2) {
    Vertex* v1 = cariUser(G, user1);
    Vertex* v2 = cariUser(G, user2);

    if (v1 != nullptr && v2 != nullptr) {
        tambahRelasiHelper(v1, user2);
        tambahRelasiHelper(v2, user1);
        cout << "[EDGE] Pertemanan antara " << user1 << " dan " << user2 << " berhasil terjalin!" << endl;
    } else {
        cout << "Gagal! Salah satu atau kedua user tidak ditemukan." << endl;
    }
}

void printGraph(Graph &G) {
    if (G.firstVertex == nullptr) {
        cout << "Belum ada user di dalam media sosial!" << endl;
        return;
    }

    cout << "\n================ JARINGAN PERTEMANAN MEDSOS ================" << endl;
    Vertex* v = G.firstVertex;
    while (v != nullptr) {
        cout << "[VERTEX] Akun: " << v->namaUser << endl;
        SimpulRelasi* r = v->firstRelasi;
        if (r == nullptr) {
            cout << "   └── [EDGE] Belum memiliki teman." << endl;
        } else {
            while (r != nullptr) {
                cout << "   ├── [EDGE] Berteman dengan -> " << r->namaTeman << endl;
                r = r->nextRelasi;
            }
        }
        cout << "------------------------------------------------------------" << endl;
        v = v->nextVertex;
    }
}

void clearGraph(Graph &G) {
    Vertex* v = G.firstVertex;
    while (v != nullptr) {
        SimpulRelasi* r = v->firstRelasi;
        while (r != nullptr) {
            SimpulRelasi* hapusR = r;
            r = r->nextRelasi;
            delete hapusR;
        }
        Vertex* hapusV = v;
        v = v->nextVertex;
        delete hapusV;
    }
    G.firstVertex = nullptr;
}
