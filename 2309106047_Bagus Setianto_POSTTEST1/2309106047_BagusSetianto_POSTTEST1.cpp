#include <iostream>
#include <string>

using namespace std;

void kmhkonvrs (double nilai){
    double cms = nilai * 100000 / 3600;
    double ms = nilai * 1000 / 3600;
    double milh = nilai / 1.60934;
    cout << cms << " cm/detik\n";
    cout << ms << " m/detik\n";
    cout << milh << " mil/jam\n";
}

void cmskonvrs (double nilai){
    double kmh = nilai / 100000 * 3600;
    double ms = nilai / 100;
    double milh = nilai / 160934.4;
    cout << kmh << " km/jam\n";
    cout << ms << " m/detik\n";
    cout << milh << " mil/jam\n";
}

void mskonvrs (double nilai){
    double kmh = nilai * 3.6;
    double cms = nilai * 100;
    double milh = nilai * 2.23694;
    cout << "1. " << kmh << " km/jam\n";
    cout << "2. " << cms << " cm/detik\n";
    cout << "3. " << milh << " mil/jam\n";
}

void milhkonvrs (double nilai){
    double kmh = nilai * 1.60934;
    double cms = nilai * 160934.4 / 3600;
    double ms = nilai * 1609.34 / 3600;
    cout << "1. " << kmh << " km/jam\n";
    cout << "2. " << cms << " cm/detik\n";
    cout << "3. " << ms << " m/detik\n";
}

int main(){
    string nama, nim;
    int kesempatan = 3;

    while (kesempatan > 0){
        cout << "Login"<< endl;
        cout << "Nama  : ";
        getline(cin,nama);
        cout << "NIM : ";
        cin >> nim;
        cin.ignore();

        if (nama == "bagus setianto" && nim == "47"){
            cout << "login berhasil\n";
            break;
        }
        else {
            cout << "Login gagal. Silakan coba lagi.\n";
            kesempatan--;
    }
}   
    if (kesempatan < 1){
        cout << "Anda telah gagal login sebanyak 3 kali. Program diberhentikan.\n";
        return 0;
}
    char lanjut;
    do{
        char menu;
        double nilai;
        cout << "\nMenu Konversi Kecepatan:\n";
        cout << "1. Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)\n";
        cout << "2. Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
        cout << "3. Meter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
        cout << "4. Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> menu;
        
        
        if (menu == '1'){
            cout << "Masukkan nilai kecepatan: ";
            cin >> nilai;
            kmhkonvrs (nilai);
            cout << "\nApakah Anda ingin melanjutkan? (y/n): ";
            cin >> lanjut;
        }
        else if (menu == '2'){
            cout << "Masukkan nilai kecepatan: ";
            cin >> nilai;
            cmskonvrs (nilai);
            cout << "\nApakah Anda ingin melanjutkan? (y/n): ";
            cin >> lanjut;
        }
        else if (menu == '3'){
            cout << "Masukkan nilai kecepatan: ";
            cin >> nilai;
            mskonvrs (nilai);
            cout << "\nApakah Anda ingin melanjutkan? (y/n): ";
            cin >> lanjut;
        }
        else if (menu == '4'){
            cout << "Masukkan nilai kecepatan: ";
            cin >> nilai;
            milhkonvrs (nilai);
            cout << "\nApakah Anda ingin melanjutkan? (y/n): ";
            cin >> lanjut;
        }
        else if(menu == '5'){
            cout << "Program telah berhenti\n"<<"Terimakasih";
            return 0;
        }
        else{
            cout << "\ninput tidak valid silahkan coba lagi";
            lanjut = 'y';
        }
        
    } while (lanjut == 'y' || lanjut == 'Y');
    cout << "Program telah berhenti\n"<<"Terimakasih";
    return 0;
}
