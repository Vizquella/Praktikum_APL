#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Nama  : Bagus Setianto
// NIM   : 2309106047
// Tema  : Daftar kontak email

const int maksKontak = 100; //jumlah maksimal kontak yang dapat ditampung

struct Info { //struct info berisi informasi dari suatu kontak
    string namaLengkap;
    string namaPanggilan;
    string email;
    int telepon;
};

struct DaftarKontak { //struct daftar kontak berisi nested struct info yang berupa variable array kontak dan jumlah kontak
    Info kontak[maksKontak];
    int jumlahKontak = 0;
};

bool login(int kesempatan);
string pilihMenu();
void tambahKontak(DaftarKontak &daftar);
void tampilkan(DaftarKontak &daftar);
void updateKontak(DaftarKontak &daftar, int no);
void hapusKontak(DaftarKontak &daftar, int no);


int main() {
    if (!login(3)) {
        return 0;
    }

    DaftarKontak daftar;

    while (true) {
        string pilih = pilihMenu();

        if (pilih == "1") {
            tambahKontak(daftar);
        } else if (pilih == "2") {
            tampilkan(daftar);
        } else if (pilih == "3") {
            int no;
            cout << "Masukkan nomor urut kontak yang ingin diupdate: ";
            cin >> no;
            no--;
            updateKontak(daftar, no);
        } else if (pilih == "4") {
            int no;
            cout << "Masukkan nomor urut kontak yang ingin dihapus: ";
            cin >> no;
            no--;
            hapusKontak(daftar, no);
        } else if (pilih == "5") {
            cout << "Selesai\n";
            break;
        } else {
            cout << "Pilihan tidak valid. Mohon masukkan pilihan dengan benar.\n";
        }
    }

    return 0;
}



void tambahKontak(DaftarKontak &daftar) {
    if (daftar.jumlahKontak < maksKontak) {
        Info k;
        cout << "\nMasukkan nama lengkap\t: ";
        cin.ignore();
        getline(cin, k.namaLengkap);
        cout << "Masukkan nama panggilan\t: ";
        cin >> k.namaPanggilan;
        cout << "Masukkan alamat email\t: ";
        cin >> k.email;
        
        string teleponStr;
        bool angka = false;
        do {
            cout << "Masukkan nomor telepon\t: ";
            cin >> teleponStr;
            angka = true;
            for (char c : teleponStr) {
                if (!isdigit(c)) { 
                    angka = false;
                    cout << "Nomor telepon harus berupa angka. Silakan coba lagi.\n";
                    break;
                }
            }
        } while (!angka);
        
        k.telepon = stoi(teleponStr);

        daftar.kontak[daftar.jumlahKontak] = k;
        daftar.jumlahKontak++;
        cout << "Kontak berhasil ditambahkan\n";
    } else {
        cout << "Maaf, jumlah maksimal kontak telah tercapai.\n";
    }
}

void updateKontak(DaftarKontak &daftar, int no) {
    if (no >= 0 && no < daftar.jumlahKontak) {
        cout << "Kontak saat ini: " << daftar.kontak[no].namaLengkap << endl;
        cout << "Nama Panggilan\t: " << daftar.kontak[no].namaPanggilan << endl;
        cout << "Email\t\t: " << daftar.kontak[no].email << endl;
        cout << "Telepon\t\t: " << daftar.kontak[no].telepon << endl;

        string namabaru, namapanggilanbaru, emailBaru;
        int teleponbaru;
        cout << "Masukkan nama baru\t: ";
        cin.ignore();
        getline(cin, namabaru);
        cout << "Masukkan nama panggilan baru\t: ";
        cin >> namapanggilanbaru;
        cout << "Masukkan email baru\t\t: ";
        cin >> emailBaru;
        
        //error handling untuk nomor telepon
        string teleponStr;
        bool angka = false;
        do {
            cout << "Masukkan nomor telepon baru\t: ";
            cin >> teleponStr;
            angka = true;
            for (char c : teleponStr) {
                if (!isdigit(c)) { //mengecek apakah semua karakter adalah angka
                    angka = false;
                    cout << "Nomor telepon harus berupa angka. Silakan coba lagi.\n";
                    break;
                }
            }
        } while (!angka);
        
        //konversi string teleponStr menjadi integer
        teleponbaru = stoi(teleponStr);

        if (!namabaru.empty()) {
            daftar.kontak[no].namaLengkap = namabaru;
        }
        if (!namapanggilanbaru.empty()) {
            daftar.kontak[no].namaPanggilan = namapanggilanbaru;
        }
        if (!emailBaru.empty()) {
            daftar.kontak[no].email = emailBaru;
        }
        daftar.kontak[no].telepon = teleponbaru;

        cout << "Kontak nomor " << no + 1 << " berhasil diupdate\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

void tampilkan(DaftarKontak &daftar) {
    if (daftar.jumlahKontak > 0) {
        cout << "\nDaftar Kontak:\n";
        for (int i = 0; i < daftar.jumlahKontak; ++i) {
            cout << i + 1 << ". Nama: " << daftar.kontak[i].namaLengkap << ", Nama Panggilan: " << daftar.kontak[i].namaPanggilan
                 << ", Alamat Email: " << daftar.kontak[i].email << ", Telepon: " << daftar.kontak[i].telepon << endl;
        }
    } else {
        cout << "Daftar kontak kosong.\n";
    }
}

void hapusKontak(DaftarKontak &daftar, int no) {
    if (no >= 0 && no < daftar.jumlahKontak) {
        for (int i = no; i < daftar.jumlahKontak - 1; ++i) {
            daftar.kontak[i] = daftar.kontak[i + 1];
        }
        daftar.jumlahKontak--;
        cout << "Kontak nomor " << no + 1 << " berhasil dihapus\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

bool login(int kesempatan) {
    string nama, nim;
    if (kesempatan > 0) {
        cout << "Login\n";
        cout << "Nama  : ";
        getline(cin, nama);
        cout << "NIM : ";
        cin >> nim;
        cin.ignore();

        if (nama == "bagus setianto" && nim == "2309106047") {
            cout << "Login berhasil\n";
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            return login(kesempatan - 1);
        }
    } else {
        cout << "Anda telah gagal login sebanyak 3 kali. Program diberhentikan.\n";
        return false;
    }
}

string pilihMenu() {
    string pilih;
    cout << "\nMenu:\n";
    cout << "1. Tambah Kontak\n";
    cout << "2. Lihat Kontak\n";
    cout << "3. Update Kontak\n";
    cout << "4. Hapus Kontak\n";
    cout << "5. Keluar\n";
    cout << "Pilih (1-5): ";
    cin >> pilih;
    return pilih;
}

