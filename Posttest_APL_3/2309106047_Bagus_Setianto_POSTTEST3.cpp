#include <iostream>
#include <string>

using namespace std;

// Nama  : Bagus Setianto
// NIM   : 2309106047
// Tema  : Daftar kontak email



const int maksKontak = 100; //jumlah maksimal kontak yang dapat ditampung

string daftarKontak[maksKontak][4]; //terdapat 4 data yang dapat dimasukkan dalam array daftarKontak yaitu 
                                    //Nama lengkap, Nama Panggilan, Email, Telepon
int jumlahKontak = 0;   //variable untuk melihat total jumlah kontak yg telah tertampung, juga berfungsi sebagai patokan index di berbagai fungsi


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

string pilihmenu() {
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

void tambahKontak() {   //fungsi untuk menambahkan kontak baru
    string nama, namaPanggilan, email, telepon;
    cout << "\nMasukkan nama lengkap\t: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan nama panggilan\t: ";
    cin >> namaPanggilan;
    cout << "Masukkan alamat email\t: ";
    cin >> email;
    cout << "Masukkan nomor telepon\t: ";
    cin >> telepon;

    if (jumlahKontak < maksKontak) {
        daftarKontak[jumlahKontak][0] = nama;
        daftarKontak[jumlahKontak][1] = namaPanggilan;
        daftarKontak[jumlahKontak][2] = email;
        daftarKontak[jumlahKontak][3] = telepon;
        jumlahKontak++;
        cout << "Kontak berhasil ditambahkan\n";
    } else {
        cout << "Maaf, jumlah maksimal kontak telah tercapai.\n";
    }
    char lanjut;
    cout << "Tambah kontak lagi? (y/n): ";
    cin >> lanjut;
    if (lanjut == 'y' || lanjut == 'Y') {
        tambahKontak();
    }

}

void tampilkan(int no) {    //fungsi untuk menampilkan kontak
    if (jumlahKontak > 0) {
        cout << "\nDaftar Kontak:\n";
        for (int i = 0; i < jumlahKontak; ++i) {
            no ++;
            cout << no << ". Nama: " << daftarKontak[i][0] << ", Nama Panggilan: " << daftarKontak[i][1]
                 << ", Alamat Email: " << daftarKontak[i][2] << ", Telepon: " << daftarKontak[i][3] << endl;
        }
    } else {
        cout << "Daftar kontak kosong.\n";
    }
}

void updateKontak(int no) {     //fungsi untuk mengupdate atau mngedit kontak
    if (no >= 0 && no < jumlahKontak) {
        cout << "Kontak saat ini: " << daftarKontak[no][0] << endl;
        cout << "Nama Panggilan\t: " << daftarKontak[no][1] << endl;
        cout << "Email\t\t: " << daftarKontak[no][2] << endl;
        cout << "Telepon\t\t: " << daftarKontak[no][3] << endl;

        string namabaru, namapanggilanbaru, emailBaru,teleponbaru;
        cout << "Masukkan nama baru\t: ";
        cin.ignore();
        getline(cin, namabaru);
        cout << "Masukkan nama panggilan baru\t: ";
        cin >> namapanggilanbaru;
        cout << "Masukkan email baru\t\t: ";
        cin >> emailBaru;
        cout << "Masukkan nomor telepon baru\t: ";
        cin >> teleponbaru;
         if (!namabaru.empty()) {
            daftarKontak[no][0] = namabaru;
         }
        if (!namapanggilanbaru.empty()) {
            daftarKontak[no][1] = namapanggilanbaru;
        }
        if (!emailBaru.empty()) {
            daftarKontak[no][2] = emailBaru;
        }
        if (!teleponbaru.empty()) {
            daftarKontak[no][3] = (teleponbaru);
        }
        cout << "Kontak nomor " << no+1 << " berhasil diupdate\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

void hapusKontak(int no) {  //fungsi untuk menghapus kontak
    if (no >= 0 && no < jumlahKontak) {
        for (int i = no; i < jumlahKontak - 1;) {
            for (int j = 0; j < 4;) {
                daftarKontak[i][j] = daftarKontak[i + 1][j];
            }
        }
        jumlahKontak--;
        cout << "Kontak nomor " << no+1 << " berhasil dihapus\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

int main() {    //main program

    if(!login(3)){
        return 0;
    }

    while (true) {  //perulangan main program, program berhenti jika user memilih menu ke 5 yaitu keluar
        
    string pilih = pilihmenu();

        if (pilih == "1") {
            tambahKontak();
        } else if (pilih == "2") {
            int no = 0;
            tampilkan(no);
        } else if (pilih == "3") {
            int no;
            cout << "Masukkan nomor urut kontak yang ingin diupdate: ";
            cin >> no;
            no--;
            updateKontak(no);
        } else if (pilih == "4") {
            int no;
            cout << "Masukkan nomor urut kontak yang ingin dihapus: ";
            cin >> no;
            no--;
            hapusKontak(no);
        } else if (pilih == "5") {
            cout << "Selesai\n";
            break;
        } else {
            cout << "Pilihan tidak valid. Mohon masukkan pilihan dengan benar.\n";
        }
    }

    return 0;
}