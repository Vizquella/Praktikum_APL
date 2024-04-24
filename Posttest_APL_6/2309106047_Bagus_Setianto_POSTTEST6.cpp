#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Nama  : Bagus Setianto
// NIM   : 2309106047
// Tema  : Daftar kontak email

const int maksKontak = 100;

struct Info {
    string namaLengkap;
    string namaPanggilan;
    string email;
    int telepon;
};

struct DaftarKontak {
    Info *kontak;
    int jumlahKontak;
};

bool login(int kesempatan);
string pilihMenu();
void tambahKontak(DaftarKontak *daftar);
void tampilkan(DaftarKontak *daftar);
void updateKontak(DaftarKontak *daftar, int *no);
void hapusKontak(DaftarKontak *daftar, int *no);
void quicksortascend(Info arr[], int rendah, int tinggi);
void bubblesortdescend(Info arr[], int n);
void insertionascend(Info arr[], int n);
int binarySearchAscending(Info arr[], int n, string nama);
int sequentialSearchDescending(Info arr[], int n, int telepon);

int main() {
    if (!login(3)) {
        return 0;
    }

    DaftarKontak daftar;
    daftar.kontak = new Info[maksKontak];
    daftar.jumlahKontak = 0;

    while (true) {
        string pilih = pilihMenu();

        if (pilih == "1") {
            tambahKontak(&daftar);
        } else if (pilih == "2") {
            string sortir;
            cout << "Sortir menurut :\n";
            cout << "1. Nama Lengkap -- Ascending"<<endl;
            cout << "2. Nomor telepon -- Descending"<<endl;
            cout << "3. Nama Panggilan -- Ascending "<<endl;
            cout << "pilih : ";
            cin >> sortir; 
            if (sortir == "1") {
                quicksortascend(daftar.kontak, 0, daftar.jumlahKontak - 1);
                tampilkan(&daftar);
            } else if (sortir == "2") {
                bubblesortdescend(daftar.kontak, daftar.jumlahKontak);
                tampilkan(&daftar);
            } else if (sortir == "3") {
                insertionascend(daftar.kontak, daftar.jumlahKontak);
                tampilkan(&daftar);
            }
            else{
                cout << "Pilihan tidak valid"<<endl;
            };
            
        } else if (pilih == "3") {
            int no;
            cout << "Masukkan nomor urut kontak yang ingin diupdate: ";
            cin >> no;
            updateKontak(&daftar, &no); 
        } else if (pilih == "4") {
            int no;
            cout << "Masukkan nomor urut kontak yang ingin dihapus: ";
            cin >> no;
            hapusKontak(&daftar, &no);
        }else if (pilih == "5"){
            string cari;
            cout << "Cari berdasarkan :"<<endl;
            cout << "1. Nama -- Ascending"<<endl;
            cout << "2. Nomor Telepon -- Descending"<<endl;
            cout << "Pilih : ";
            cin >> cari;
            if (cari == "1"){
                string namaCari;
                cout << "Masukkan nama kontak yang ingin dicari: ";
                cin.ignore();
                getline(cin, namaCari);
                int resultAscending = binarySearchAscending(daftar.kontak, daftar.jumlahKontak, namaCari);
                if (resultAscending != -1) {
                    cout << "Kontak ditemukan" << endl;
                    cout << "Detail Kontak:\n";
                    cout << "Nama: " << daftar.kontak[resultAscending].namaLengkap << ", Nama Panggilan: " << daftar.kontak[resultAscending].namaPanggilan
                        << ", Alamat Email: " << daftar.kontak[resultAscending].email << ", Telepon: " << daftar.kontak[resultAscending].telepon << endl;
                } else {
                    cout << "Kontak tidak ditemukan.\n";
                }
            }
            else if (cari == "2"){
                int teleponCari;
                cout << "Masukkan nomor telepon yang ingin dicari: ";
                cin >> teleponCari;
                int resultDescending = sequentialSearchDescending(daftar.kontak, daftar.jumlahKontak, teleponCari);
                if (resultDescending != -1) {
                    cout << "Kontak ditemukan " << endl;
                    cout << "Detail Kontak:\n";
                    cout << "Nama: " << daftar.kontak[resultDescending].namaLengkap << ", Nama Panggilan: " << daftar.kontak[resultDescending].namaPanggilan
                        << ", Alamat Email: " << daftar.kontak[resultDescending].email << ", Telepon: " << daftar.kontak[resultDescending].telepon << endl;
                } else {
                    cout << "Kontak tidak ditemukan.\n";
                }
            }
            else {
                cout << "pilihan tidak valid"<<endl;
            }
        } else if (pilih == "6") {
            cout << "Selesai\n";
            break;
        } else {
            cout << "Pilihan tidak valid. Mohon masukkan pilihan dengan benar.\n";
        }
    }

    delete[] daftar.kontak;
    return 0;
}

void tambahKontak(DaftarKontak *daftar) {
    if (daftar->jumlahKontak < maksKontak) {
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

        daftar->kontak[daftar->jumlahKontak] = k;
        daftar->jumlahKontak++;
        cout << "Kontak berhasil ditambahkan\n";
    } else {
        cout << "Maaf, jumlah maksimal kontak telah tercapai.\n";
    }
}

void updateKontak(DaftarKontak *daftar, int *no) {
    if (*no >= 0 && *no < daftar->jumlahKontak) {
        Info *kontak = &(daftar->kontak[*no]);
        cout << "Kontak saat ini: " << kontak->namaLengkap << endl;
        cout << "Nama Panggilan\t: " << kontak->namaPanggilan << endl;
        cout << "Email\t\t: " << kontak->email << endl;
        cout << "Telepon\t\t: " << kontak->telepon << endl;

        string namabaru, namapanggilanbaru, emailBaru;
        int teleponbaru;
        cout << "Masukkan nama baru\t: ";
        cin.ignore();
        getline(cin, namabaru);
        cout << "Masukkan nama panggilan baru\t: ";
        cin >> namapanggilanbaru;
        cout << "Masukkan email baru\t\t: ";
        cin >> emailBaru;

        string teleponStr;
        bool angka = false;
        do {
            cout << "Masukkan nomor telepon baru\t: ";
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

        teleponbaru = stoi(teleponStr);

        if (!namabaru.empty()) {
            kontak->namaLengkap = namabaru;
        }
        if (!namapanggilanbaru.empty()) {
            kontak->namaPanggilan = namapanggilanbaru;
        }
        if (!emailBaru.empty()) {
            kontak->email = emailBaru;
        }
        kontak->telepon = teleponbaru;

        cout << "Kontak nomor " << *no + 1 << " berhasil diupdate\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

void tampilkan(DaftarKontak *daftar) {
    if (daftar->jumlahKontak > 0) {
        cout << "\nDaftar Kontak:\n";
        for (int i = 0; i < daftar->jumlahKontak; ++i) {
            cout << i + 1 << ". Nama: " << daftar->kontak[i].namaLengkap << ", Nama Panggilan: " << daftar->kontak[i].namaPanggilan
                 << ", Alamat Email: " << daftar->kontak[i].email << ", Telepon: " << daftar->kontak[i].telepon << endl;
        }
    } else {
        cout << "Daftar kontak kosong.\n";
    }
}

void hapusKontak(DaftarKontak *daftar, int *no) {
    if (*no >= 0 && *no < daftar->jumlahKontak) {
        for (int i = *no; i < daftar->jumlahKontak - 1; ++i) {
            daftar->kontak[i] = daftar->kontak[i + 1];
        }
        daftar->jumlahKontak--;
        cout << "Kontak nomor " << *no + 1 << " berhasil dihapus\n";
        for (int i = *no; i < daftar->jumlahKontak; ++i) {
            daftar->kontak[i].telepon--;
        }
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

        if (nama == "bagus" && nim == "47") {
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
    cout << "5. cari Kontak\n";
    cout << "6. Keluar\n";
    cout << "Pilih (1-6): ";
    cin >> pilih;
    return pilih;
}

int pisah(Info arr[], int low, int high) {
    string pivot = arr[high].namaLengkap;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].namaLengkap < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksortascend(Info arr[], int rendah, int tinggi) {
    if (rendah < tinggi) {
        int pi = pisah(arr, rendah, tinggi);

        quicksortascend(arr, rendah, pi - 1);
        quicksortascend(arr, pi + 1, tinggi);
    }
}



void bubblesortdescend(Info arr[], int n) {
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].telepon < arr[j + 1].telepon) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionascend(Info arr[], int n) {
    int i, j;
    Info key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].namaPanggilan > key.namaPanggilan) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int binarySearchAscending(Info arr[], int n, string nama) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].namaLengkap == nama)
            return mid;
        else if (arr[mid].namaLengkap < nama)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int sequentialSearchDescending(Info arr[], int n, int telepon) {
    for (int i = 0; i < n; i++) {
        if (arr[i].telepon == telepon)
            return i;
    }
    return -1;
}