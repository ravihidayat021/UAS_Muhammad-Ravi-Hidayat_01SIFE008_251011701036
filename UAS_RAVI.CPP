#include <iostream>
#include <iomanip>
using namespace std;

const int HONOR_PER_JAM = 1000;
const int JAM_NORMAL = 8;
const int HONOR_LEMBUR = 1500;


void hitungGaji() {
    int n;
    cout << "\nMasukkan jumlah pegawai: ";
    cin >> n;

    string *nama = new string[n];
    int *jamKerja = new int[n];
    int *honor = new int[n];
    int *lembur = new int[n];
    int *total = new int[n];

    int totalHonor = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nPegawai ke-" << i + 1 << endl;
        cout << "Nama        : ";
        cin >> nama[i];
        cout << "Jam Kerja   : ";
        cin >> jamKerja[i];

        honor[i] = jamKerja[i] * HONOR_PER_JAM;

        if (jamKerja[i] > JAM_NORMAL) {
            lembur[i] = (jamKerja[i] - JAM_NORMAL) * HONOR_LEMBUR;
        } else {
            lembur[i] = 0;
        }

        total[i] = honor[i] + lembur[i];
        totalHonor += total[i];
    }

    cout << "\n\nPT. Meriang Gembira\n";
    cout << "Tanggal: 12 Januari 2026\n";
    cout << "=============================================================\n";
    cout << left << setw(5) << "No"
         << setw(12) << "Nama"
         << setw(10) << "Honor"
         << setw(12) << "Jam Kerja"
         << setw(14) << "Honor Lembur"
         << setw(10) << "Total" << endl;
    cout << "=============================================================\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i + 1
             << setw(12) << nama[i]
             << setw(10) << honor[i]
             << setw(12) << jamKerja[i]
             << setw(14) << lembur[i]
             << setw(10) << total[i] << endl;
    }

    cout << "=============================================================\n";
    cout << "Total Honor Pegawai Sebesar : Rp " << totalHonor << endl;

    delete[] nama;
    delete[] jamKerja;
    delete[] honor;
    delete[] lembur;
    delete[] total;
}

int main() {
    int menu;
    char ulang;

    do {
        cout << "\n=== MENU PENGGAJIAN ===\n";
        cout << "1. Hitung Gaji Pegawai\n";
        cout << "2. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            hitungGaji();
        } else if (menu == 2) {
            cout << "\nTerima kasih.\n";
            break;
        } else {
            cout << "\nMenu tidak valid!\n";
        }

        cout << "\nKembali ke menu? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
