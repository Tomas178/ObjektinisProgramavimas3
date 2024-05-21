#include "../Headers/Zmogus.h"
#include "../Headers/funkcijos.h"
#include <vector>

const int N = 10;
int programos_veikimas;

int main() {
    try {
        int norima_isvedimo_vieta;
        int norimas_rikiavimas;
        int norima_strategija;
        ManoVector<Studentas> Studentai;
        ManoVector<Studentas> Kieti;
        srand(time(nullptr));

        do {
            try {
                while (true) {
                    cout << "Pasirinkite programos eiga:\n1 - Vedimas ranka.\n2 - Generuoti pazymius.\n3 - Generuoti ir studentu pazymius, ir vardus bei pavardes.\n4 - Baigti darba.\n5 - imti duomenis is failo.\n6 - Generuoti faila.\n7 - Atlikti testa su vektoriais.\nPasirinkite: ";
                    cin >> programos_veikimas;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw runtime_error("Iveskite skaiciu!");
                    }
                    if (programos_veikimas > 0 && programos_veikimas < 8)
                        break;
                    else
                        throw runtime_error("Iveskite skaiciu intervale [1, 7]");
                }
            } catch (const invalid_argument& e) {
                cerr << "Klaida: " << e.what() << endl;
                continue;
            } catch (const out_of_range& e) {
                cerr << "Klaida: " << e.what() << endl;
                continue;
            } catch (const exception& e) {
                cerr << "Klaida: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            Studentas Studentokai;
            char programos_tesinys;
            char choice3;

            if(programos_veikimas == 1 || programos_veikimas == 2){
                cin >> Studentokai;
                Studentai.push_back(move(Studentokai));
            }

            if(programos_veikimas == 3){
                int KiekisGeneravimui;
                cout << "Kiek studentu generuoti?: "; cin >> KiekisGeneravimui; 
                Studentai.reserve(KiekisGeneravimui);
                for(int i = 0; i < KiekisGeneravimui; i++){
                    cin >> Studentokai;
                    Studentai.push_back(move(Studentokai));
                }
                cout << "Generavimas baigtas:)" << endl;
            }

            if(programos_veikimas == 4){
                break;
            }

            if (programos_veikimas == 5) {
                try {
                    cout << "Cia jusu failai: " << endl;
                    system("dir *.txt");
                    string fileName;
                    cout << "Iveskite failo pavadinima: ";
                    cin >> fileName;

                    ifstream DF(fileName);
                    if (!DF.is_open()) {
                        throw runtime_error("Nepavyko atidaryti failo");
                    }

                    auto Pradzia_Skaitymo = chrono::high_resolution_clock::now();

                    string line;
                    getline(DF, line);

                    while (getline(DF, line)) {
                        istringstream iss(line);
                        iss >> Studentokai;
                        Studentai.push_back(move(Studentokai));
                    }

                    DF.close();
                    cout << "Nuskaitymas sekmingas:)" << endl;
                    Studentai.shrink_to_fit();
                    auto Pabaiga_Skaitymo = chrono::high_resolution_clock::now();

                    auto Skaitymo_trukme = chrono::duration_cast<chrono::milliseconds>(Pabaiga_Skaitymo - Pradzia_Skaitymo).count();
                    cout << "Failas Nuskaitytas per: " << Skaitymo_trukme / 1000.0 << " s." << endl;

                    cout << "Vektoriaus capacity: " << Studentai.capacity() << endl;
                    cout << "Vektoriaus size: " << Studentai.size() << endl; 

                } catch (const exception& e) {
                    cerr << "Klaida: " << e.what() << endl;
                    continue;
                }
            }

            if(programos_veikimas == 6){
                int kiekis;
                int nd_kiekis;
                cout << "Keliu studentu faila generuoti?: "; cin >> kiekis;
                cout << "Kiek norite, kad studentas turetu namu darbu?: "; cin >> nd_kiekis;
                GeneruotiFaila(kiekis, nd_kiekis);
            }

            if(programos_veikimas = 7) {
                std::cout << std::fixed << std::setprecision(6);
                std::cout << "\nElementu skaicius | std::vector laikas s      | ManoVector laikas s      | std::vector reallocs | Vector reallocs\n";
                std::cout << "----------------------------------------------------------------------------------------------------------------------\n";

                for (unsigned int sz : {10000, 100000, 1000000, 10000000, 100000000})
                {
                    // Measurement with std::vector
                    auto start_v1 = std::chrono::high_resolution_clock::now();
                    std::vector<int> v1;
                    int reallocations_std_vector = 0;
                    for (unsigned int i = 1; i <= sz; ++i)
                    {
                        v1.push_back(i);
                        if (v1.capacity() == v1.size())
                        {
                            ++reallocations_std_vector;
                        }
                    }
                    auto finish_v1 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_v1 = finish_v1 - start_v1;

                    // Measurement with your Vector class
                    auto start_v2 = std::chrono::high_resolution_clock::now();
                    ManoVector<int> v2;
                    int reallocations_custom_vector = 0;
                    for (unsigned int i = 1; i <= sz; ++i)
                    {
                        v2.push_back(i);
                        if (v2.capacity() == v2.size())
                        {
                            ++reallocations_custom_vector;
                        }
                    }
                    auto finish_v2 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_v2 = finish_v2 - start_v2;

                    // Print results in a table with proper formatting
                    std::cout << std::setw(15) << sz << " | " << std::setw(27) << elapsed_v1.count() << " | " << std::setw(20) << elapsed_v2.count() << " | " << std::setw(20) << reallocations_std_vector << " | " << std::setw(15) << reallocations_custom_vector << "\n";
                }
                std::cout << "\n";
            }

            if(Studentokai.Nd_dydis() > 0 && programos_veikimas != 5 && programos_veikimas != 6 && programos_veikimas != 7){
                Studentokai.nd_rusiavimas();
                Studentokai.SetMediana(Studentokai.medianosSkaiciavimas(Studentokai.Get_Nd(), Studentokai.Nd_dydis(), Studentokai.Get_Egzaminas()));
                Studentokai.setVidurkis(Studentokai.Vidurkis(Studentokai.Nd_dydis(), Studentokai.Nd_Suma(), Studentokai.Get_Egzaminas()));
            }

            cout << "Ar noresite ivesti dar viena studenta? (Y/N): ";
            cin >> programos_tesinys;
            if(toupper(programos_tesinys) != 'Y') break;
        } while (true);

        while(!Studentai.empty()){
            cout << "\n1 - Isvesti rezultata konsoleje\n2 - Isvesti rezultata faile\nPasirinkite: ";
            cin >> norima_isvedimo_vieta;
            if(cin.fail()){
                cout << "Prasome ivesti skaiciu.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(norima_isvedimo_vieta != 1 && norima_isvedimo_vieta != 2){
                cout << "Ivedete netinkama skaiciu.\n";
            }
            else
                break;
        }

        while(!Studentai.empty()){
            cout << "\n1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal vidurki\n4 - Rikiuoti pagal mediana\nPasirinkite: ";
            cin >> norimas_rikiavimas;
            if(cin.fail()){
                cout << "Prasome ivesti skaiciu.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(norimas_rikiavimas < 1 || norimas_rikiavimas > 4){
                cout << "Ivedete netinkama skaiciu.\n";
            }
            else{
                if(norimas_rikiavimas == 1){
                    sort(Studentai.begin(), Studentai.end(), palygintiPagalVarda);
                    break;
                } else if(norimas_rikiavimas == 2){
                    sort(Studentai.begin(), Studentai.end(), palygintiPagalPavarde);
                    break;
                } else if(norimas_rikiavimas == 3){
                    auto Rusiavimo_pradzia = chrono::high_resolution_clock::now();
                    sort(Studentai.begin(), Studentai.end(), palygintiPagalVidurki);
                    auto Rusiavimo_pabaiga = chrono::high_resolution_clock::now();
                    auto Rusiavimo_trukme = chrono::duration_cast<chrono::milliseconds>(Rusiavimo_pabaiga - Rusiavimo_pradzia).count();
                    cout << "Studentu rusiavimo didejant trukme: " << Rusiavimo_trukme/1000.0 << " s." << endl;

                    auto Skirstymo_pradzia = chrono::high_resolution_clock::now();
                    for(auto stud : Studentai){
                        if(stud.Get_Vidurkis() >= 5.0){
                            Kieti.push_back(move(stud));
                        }
                    }
                    Kieti.shrink_to_fit();
                    PasalintiKietusStudentus(Studentai, norimas_rikiavimas);
                    auto Skirstymo_pabaiga = chrono::high_resolution_clock::now();
                    auto Skirstymo_trukme = chrono::duration_cast<chrono::milliseconds>(Skirstymo_pabaiga - Skirstymo_pradzia).count();
                    cout << "Studentu Skirstymo i lievus ir kietus trukme: " << Skirstymo_trukme/1000.0 << " s." << endl;
                    break;
                } else if(norimas_rikiavimas == 4){
                    auto Rusiavimo_pradzia = chrono::high_resolution_clock::now();
                    sort(Studentai.begin(), Studentai.end(), palygintiPagalMediana);
                    auto Rusiavimo_pabaiga = chrono::high_resolution_clock::now();
                    auto Rusiavimo_trukme = chrono::duration_cast<chrono::milliseconds>(Rusiavimo_pabaiga - Rusiavimo_pradzia).count();
                    cout << "Studentu rusiavimo didejant trukme: " << Rusiavimo_trukme/1000.0 << " s." << endl;

                    auto Skirstymo_pradzia = chrono::high_resolution_clock::now();
                    for(auto stud : Studentai){
                        if(stud.Get_Mediana() >= 5.0){
                            Kieti.push_back(move(stud));
                        }
                    }
                    Kieti.shrink_to_fit();
                    PasalintiKietusStudentus(Studentai, norimas_rikiavimas);
                    auto Skirstymo_pabaiga = chrono::high_resolution_clock::now();
                    auto Skirstymo_trukme = chrono::duration_cast<chrono::milliseconds>(Skirstymo_pabaiga - Skirstymo_pradzia).count();
                    cout << "Studentu Skirstymo i lievus ir kietus trukme: " << Skirstymo_trukme/1000.0 << " s." << endl;
                    break;
                } 
            }
        }

        if(!Studentai.empty()){
            if(norimas_rikiavimas == 1 || norimas_rikiavimas == 2)
                IsvestiRezultatus("Studentai", Studentai, norima_isvedimo_vieta);
            if(norimas_rikiavimas == 3 || norimas_rikiavimas == 4){
                IsvestiRezultatus("Lievi", Studentai, norima_isvedimo_vieta);
                IsvestiRezultatus("Kieti", Kieti, norima_isvedimo_vieta);
            }
        }

        system("pause");
        return 0;

    } catch(const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
}