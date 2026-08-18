# Repository Struktur Data C++ (Studi Kasus & Implementasi)

Repositori ini berisi kumpulan program implementasi Struktur Data menggunakan C++ dengan berbagai variasi arsitektur, mulai dari Linear Linked List, Stack, Queue (baik berbasis Pointer maupun Array), Multi-Linked List (MLL) dengan berbagai model relasi, hingga Binary Search Tree (BST).

---

## 📁 Daftar Modul & Arsitektur

Berikut adalah rincian folder dan jenis struktur data yang ada di dalam repositori ini:

### 1. Multi-Linked List (MLL) - Sistem Akademik / KRS & Lomba
*   **`mll_basic`**
    *   **Deskripsi:** Implementasi MLL di mana Parent memiliki *pointer* langsung ke First Child, dan setiap Child membentuk list linier sendiri ke bawah tanpa relasi terpisah.
*   **`mll_norlist`**
    *   **Deskripsi:** Implementasi MLL model *nested relation*, di mana List Relasi bersarang langsung di dalam node Parent (Mata Kuliah).
*   **`mll_oneton`**
    *   **Deskripsi:** Implementasi MLL model *One-to-N* (Child-to-Parent Pointer), di mana node Child memiliki *pointer* langsung yang menunjuk ke arah Parent.
*   **`mll_relasi` / `mll_v2`**
    *   **Deskripsi:** Implementasi MLL standar menggunakan tabel relasi terpisah (*Independent Relation List*) untuk menghubungkan entitas Parent dan Child secara fleksibel (Many-to-Many).

### 2. Single Linked List (SLL) Tunggal
*   **`sll_basic`**
    *   **Deskripsi:** Implementasi Single Linked List murni (hanya menggunakan `head` tanpa `tail`) dengan studi kasus Mahasiswa yang memiliki atribut kelas di dalamnya.
*   **`sll_stack`**
    *   **Deskripsi:** Implementasi struktur data **Stack (LIFO)** berbasis Single Linked List dengan studi kasus Manajemen Buku.
*   **`sll_queue`**
    *   **Deskripsi:** Implementasi struktur data **Queue (FIFO)** berbasis Single Linked List menggunakan `head` dan `tail` dengan studi kasus Antrean Pelanggan.

### 3. Struktur Data Berbasis Array
*   **`stack_array`**
    *   **Deskripsi:** Implementasi **Stack** statis menggunakan memori Array (`MAX_SIZE`) dengan operasi dasar *Push*, *Pop*, dan pengecekan *Overflow/Underflow*.
*   **`queue_array`**
    *   **Deskripsi:** Implementasi **Queue** statis menggunakan Array untuk pengelolaan antrean linier berbasis indeks.
*   **`stack_v1`**
    *   **Deskripsi:** Variasi implementasi Stack tambahan dengan struktur modular pendukung.

### 4. Tree
*   **`binary_tree`**
    *   **Deskripsi:** Implementasi **Binary Search Tree (BST)** dengan studi kasus E-Commerce (Manajemen Produk berdasarkan *Key* Harga). Dilengkapi fitur Traversal (*Preorder*, *Inorder*, *Postorder*), pencarian, penghapusan node, serta penghitungan tinggi *tree* dan *leaf node*.

---

## ⚙️ Cara Kompilasi & Menjalankan Program

Setiap folder di atas bersifat independen dan memiliki struktur arsitektur file yang terdiri dari folder `Sources` (`main.cpp` dan file `.cpp`) serta folder `Headers` (`.h`).

Untuk menjalankan salah satu modul (contoh untuk folder `binary_tree`):
1. Buka terminal atau compiler C++ Anda (seperti Dev-C++, Code::Blocks, atau VS Code).
2. Buat Project baru atau compile file secara bersamaan:
   ```bash
   g++ Sources/main.cpp Sources/binary_tree.cpp -o main