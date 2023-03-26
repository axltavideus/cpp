#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// struct untuk menyimpan data siswa

struct Siswa
{
    string nama;
    string password;
    int nilai[5];
    float rataRata;
    int nilaiMax;
    int nilaiMin;
};

bool sortByRataRataAsc(const Siswa &a, const Siswa &b) //mengurutkan siswa dengan cara membandingkan 
{                                                      //diurutkan dengan format ascending
    return a.rataRata < b.rataRata;
}

bool sortByRataRataDesc(const Siswa &a, const Siswa &b)//mengurutkan siswa dengan cara membandingkan 
{                                                       //diurutkan dengan format descending
    return a.rataRata > b.rataRata;
}

int main()
{
    // inisialisasi data siswa
    Siswa siswa[3] = {
        {"Andi", "andi12345", {75, 83, 80, 92, 82}},
        {"Fina", "fina12345", {70, 90, 80, 75, 85}},
        {"Budi", "budi12345", {89, 73, 90, 79, 78}}};
    bool isLoginValid = false;
    do
    {
        // input login
        string username, password;
        cout<< "Login\n";
        cout<< "Username: ";
        cin>> username;
        cout<< "Password: ";
        cin>> password;
        // validasi login
        if (username == "walas" && password == "12345")
        {
            isLoginValid = true;
            for (int i = 0; i < 3; i++)
            {
                // hitung rata-rata nilai
                float total = 0;
                for (int j = 0; j < 5; j++)
                {
                    total += siswa[i].nilai[j]; //menambahkan nilai siswa pada indeks j ke variabel total pada setiap iterasinya.
                }
                siswa[i].rataRata = total / 5;  //menghitung rata-rata dari nilai siswa 
                // tampilkan data nilai
                cout << "\nData nilai untuk " << siswa[i].nama << endl;
                cout << "---------------------------------------" << endl;
                cout << "Nilai Matematika: " << siswa[i].nilai[0] << endl;
                cout << "Nilai Fisika: " << siswa[i].nilai[1] << endl;
                cout << "Nilai Bahasa Indonesia: " << siswa[i].nilai[2] << endl;
                cout << "Nilai English: " << siswa[i].nilai[3] << endl;
                cout << "Nilai OOP: " << siswa[i].nilai[4] << endl;
                cout << "Rata-rata nilai: " << siswa[i].rataRata << endl;
            }
            // menampilkan menu filter data
            int filter;
            cout << "\nSorting nilai murid berdasarkan rata-rata:\n";
            cout << "1. Ascending\n";
            cout << "2. Descending\n";
            cout << "Masukan pilihan anda: ";
            cin >> filter;
            
            if (filter == 1) //jika nilai filter = 1
            {
                sort(siswa, siswa + 3, sortByRataRataAsc); //jalankan fungsi sortByRataRataAsc 
            }
            else if (filter == 2) // jika nilai filter = 2
            {
                sort(siswa, siswa + 3, sortByRataRataDesc); //jalankan fungsi sortByRataRataDesc
            }
            
            cout << "\nData siswa setelah difilter:\n";// tampilkan data siswa setelah difilter

            for (int i = 0; i < 3; i++) //perulangan untuk output sorting
            {
                cout << siswa[i].nama << " dengan rata2 nilai: " << siswa[i].rataRata << endl;
            }
        }
        else
        {
            isLoginValid = true;
            for (int i = 0; i < 3; i++)
            {
                if (username == siswa[i].nama && password == siswa[i].password) //validasi login
                {
                    // hitung rata-rata nilai
                    float total = 0;
                    for (int j = 0; j < 5; j++)
                    {
                        total += siswa[i].nilai[j];
                    }
                    siswa[i].rataRata = total / 5;
                    // cari nilai maksimum dan minimum
                    int maxNilai = siswa[i].nilai[0];
                    int minNilai = siswa[i].nilai[0];
                    for (int j = 1; j < 5; j++)
                    {
                        if (siswa[i].nilai[j] > maxNilai)
                        {
                            maxNilai = siswa[i].nilai[j];
                        }
                        if (siswa[i].nilai[j] < minNilai)
                        {
                            minNilai = siswa[i].nilai[j];
                        }
                    }
                    siswa[i].nilaiMax = maxNilai;
                    siswa[i].nilaiMin = minNilai;
                    // tampilkan data nilai
                    cout << "\nData nilai untuk " << siswa[i].nama << endl;
                    cout << "---------------------------------------" << endl;
                    cout << "Nilai Matematika: " << siswa[i].nilai[0] << endl;
                    cout << "Nilai Fisika: " << siswa[i].nilai[1] << endl;
                    cout << "Nilai Bahasa Indonesia: " << siswa[i].nilai[2] << endl;
                    cout << "Nilai English: " << siswa[i].nilai[3] << endl;
                    cout << "Nilai OOP: " << siswa[i].nilai[4] << endl;
                    cout << "Rata-rata nilai: " << siswa[i].rataRata << endl;
                    cout << "Nilai maksimum: " << siswa[i].nilaiMax << endl;
                    cout << "Nilai minimum: " << siswa[i].nilaiMin << endl;
                    break;
                }
            }
        }
        if (!isLoginValid) //error jika variabel isLoginValid tidak true
        {
            cout << "Login gagal, username atau password salah\n"
                 << endl;
        }
    } while (!isLoginValid);
    return 0;
}
