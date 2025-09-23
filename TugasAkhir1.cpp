#include <iostream>
#include <string>
using namespace std;

int main() {
    int jumlahMhs;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMhs;

    string mahasiswa[3][3];

    for(int i = 0; i < jumlahMhs; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Masukkan NIM   : ";
        cin >> mahasiswa[i][0];
        cout << "Masukkan Nama  : ";
        cin >> mahasiswa[i][1];
        cout << "Masukkan IPK : ";
        cin >> mahasiswa[i][2];
    }

    cout << "\n=== Data Mahasiswa ===\n";
    for(int i = 0; i < jumlahMhs; i++) {
        cout << "NIM: " << mahasiswa[i][0]
             << ", Nama: " << mahasiswa[i][1]
             << ", Nilai: " << mahasiswa[i][2] << endl;
    }

    string cariNIM;
    cout << "\nMasukkan NIM yang ingin dicari: ";
    cin >> cariNIM;

    bool ditemukan = false;
    for(int i = 0; i < jumlahMhs; i++) {
        if(mahasiswa[i][0] == cariNIM) {
            cout << "Mahasiswa ditemukan: "
                 << "NIM: " << mahasiswa[i][0]
                 << ", Nama: " << mahasiswa[i][1]
                 << ", Nilai: " << mahasiswa[i][2] << endl;
            ditemukan = true;
            break;
        }
    }

    if(!ditemukan) {
        cout << "Mahasiswa dengan NIM " << cariNIM << " tidak ditemukan.\n";
    }

    return 0;
}
