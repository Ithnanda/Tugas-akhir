#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; 
string antrian[MAX];
int front = -1;
int rear = -1;
bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return (front == -1);
}

void enqueue(string nama) {
    if (isFull()) {
        cout << "Antrian sudah penuh! Tidak bisa menambahkan pasien baru.\n";
        return;
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        antrian[rear] = nama;
        cout << "Pasien " << nama << " berhasil ditambahkan ke antrian.\n";
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Tidak ada pasien dalam antrian!\n";
    } else {
        cout << "Pasien " << antrian[front] << " sedang dilayani.\n";
        front++;
        if (front > rear) { 
            front = rear = -1;
        }
    }
}

void tampilkanAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
    } else {
        cout << "\n=== DAFTAR ANTRIAN PASIEN ===\n";
        for (int i = front; i <= rear; i++) {
            cout << (i - front + 1) << ". " << antrian[i] << endl;
        }
    }
}

void hapusAntrian() {
    front = rear = -1;
    cout << "Semua antrian telah dihapus.\n";
}

int main() {
    int pilihan;
    string namaPasien;

    do {
        cout << "\n=== SISTEM ANTRIAN PASIEN RUMAH SAKIT ===\n";
        cout << "1. Tambah pasien ke antrian\n";
        cout << "2. Layani pasien berikutnya\n";
        cout << "3. Lihat daftar antrian\n";
        cout << "4. Hapus semua antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        if (pilihan == 1) {
            cout << "Masukkan nama pasien: ";
            cin.ignore(); 
            getline(cin, namaPasien);
            enqueue(namaPasien);
        } else if (pilihan == 2) {
            dequeue();
        } else if (pilihan == 3) {
            tampilkanAntrian();
        } else if (pilihan == 4) {
            hapusAntrian();
        } else if (pilihan == 5) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);
    return 0;
}