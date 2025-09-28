#include <iostream>
#include <string>
using namespace std;

int main() {
    int N = 10; 
    string buku[N];

    cout << "Masukkan judul 10 buku:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Buku ke-" << i + 1 << ": ";
        getline(cin, buku[i]);
    }

    for (int i = 1; i < N; i++) {
        string key = buku[i];
        int j = i - 1;

        while (j >= 0 && buku[j] > key) {
            buku[j + 1] = buku[j];
            j--;
        }
        buku[j + 1] = key;
    }

    cout << "\nDaftar buku setelah diurutkan (A-Z):" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << buku[i] << endl;
    }

    return 0;
}