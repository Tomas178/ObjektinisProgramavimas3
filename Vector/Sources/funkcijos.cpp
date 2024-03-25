#include "../Headers/funkcijos.h"

double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

double medianosSkaiciavimas(const vector<int> &namu_darbai, int nd_kiekis, int egzaminas){
    if(nd_kiekis % 2 == 0 && nd_kiekis > 0)
        return (namu_darbai[nd_kiekis/2-1] + namu_darbai[nd_kiekis/2])/2.0*0.4 + 0.6*egzaminas;
    else if(nd_kiekis % 2 != 0 && nd_kiekis > 0)
        return namu_darbai[nd_kiekis/2]*0.4 + 0.6*egzaminas;
    else 
        return 0.6*egzaminas;
}

bool palygintiPagalVarda(const Studentas &a, const Studentas &b) {
    return a.Vardas() < b.Vardas();
}

bool palygintiPagalPavarde(const Studentas &a, const Studentas &b) {
    return a.Pavarde() < b.Pavarde();
}

bool palygintiPagalVidurki(const Studentas &a, const Studentas &b) {
    return a.Get_Vidurkis() < b.Get_Vidurkis();
}

bool palygintiPagalMediana(const Studentas &a, const Studentas &b) {
    return a.Get_Mediana() < b.Get_Mediana();
}

void PasalintiKietusStudentus(vector<Studentas> &Studentai, int norimas_rikiavimas){
    try{
    if (norimas_rikiavimas == 3) {
        auto it = find_if(Studentai.begin(), Studentai.end(),
                               [](const Studentas &stud) {
                                   return stud.Get_Vidurkis() >= 5.0;
                               });

        if (it != Studentai.end()) {
            Studentai.erase(it, Studentai.end());
        } else {
            throw runtime_error("Nera studento su vidurkiu >= 5.0");
        }
    }

    if (norimas_rikiavimas == 4) {
        auto it = find_if(Studentai.begin(), Studentai.end(),
                               [](const Studentas &stud) {
                                   return stud.Get_Mediana() >= 5.0;
                               });

        if (it != Studentai.end()) {
            Studentai.erase(it, Studentai.end());
        } else {
            throw runtime_error("Nera studento su mediana >= 5.0");
        }
    }
    } catch (const exception &e){
                cerr << e.what() << endl;
    }
}

void GeneruotiFaila(int kiekis, int nd_kiekis){
    string FailoPavadinimas = "Studentai" + to_string(kiekis) + ".txt";
    ofstream FF(FailoPavadinimas);
    stringstream RF;
    try
    {
        if (!RF) { 
            throw runtime_error("Nepavyko atidaryti failo: " + FailoPavadinimas);
        }

        RF << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
        for(int i = 1; i <= nd_kiekis; i++){
            RF << setw(7) << "ND" + to_string(i);
        }
        RF << setw(7) << "Egz." << "\n";

        for(int i = 1; i <= kiekis; i++){
            RF << left << setw(20) << "Vardas"+to_string(i) << setw(20) << "Pavarde"+to_string(i);
            for(int j = 0; j < nd_kiekis+1; j++){
                RF << setw(7) << rand()%10+1;
            }
            if(i != kiekis)
            RF << "\n";
        }

        FF << RF.str();
        RF.clear();
        FF.close();
        cout << "Failas: " << FailoPavadinimas << " sugeneruotas sekmingai:)" << endl;
    }
    catch(const exception &e)
    {
        cerr << e.what() << '\n';
    }  
}

void IsvestiRezultatus(string pavadinimas, const vector<Studentas> &Studentai, int norima_isvedimo_vieta) {

        size_t IlgiausiasVardas = 0;
        size_t IlgiausiaPavarde = 0;
        for (const auto& student : Studentai) {
            IlgiausiasVardas = max(IlgiausiasVardas, student.Vardas().length());
            IlgiausiaPavarde = max(IlgiausiaPavarde, student.Pavarde().length());
    }

    if (Studentai.size() > 0) {
        if (norima_isvedimo_vieta == 1) {
            cout << left << setw(IlgiausiasVardas + 5) << "Vardas" << setw(IlgiausiaPavarde + 5) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
                << "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------------------------" << endl;

            for (const auto& studentas : Studentai) {
                cout << left << setw(IlgiausiasVardas + 5) << studentas.Vardas() << setw(IlgiausiaPavarde + 5) << studentas.Pavarde() << setw(20)
                    << fixed << setprecision(2) << studentas.Get_Vidurkis() << setw(20) << fixed << setprecision(2) << studentas.Get_Mediana() << endl;
            }
        } else if (norima_isvedimo_vieta == 2) {
            string FailoPavadinimas = pavadinimas + ".txt";
            ofstream FF(FailoPavadinimas);
            stringstream RF;
            RF << left << setw(IlgiausiasVardas + 5) << "Vardas" << setw(IlgiausiaPavarde + 5) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20)
                << "Galutinis(Med.)" << endl;
            RF << "----------------------------------------------------------------------" << endl;
            for (const auto& studentas : Studentai) {
                RF << left << setw(IlgiausiasVardas + 5) << studentas.Vardas() << setw(IlgiausiaPavarde + 5) << studentas.Pavarde() << setw(20)
                    << fixed << setprecision(2) << studentas.Get_Vidurkis() << setw(20) << fixed << setprecision(2) << studentas.Get_Mediana() << endl;
            }
            FF << RF.str();
            RF.clear();
            FF.close();
            cout << "Rezultatai isvesti " << FailoPavadinimas <<" faile." << endl;
        }
    }
}

Studentas::Studentas(std::istream& is) { 
  // kreipiasi į Studentas::readStudent;
  readStudent(is);  
}

istream& Studentas::readStudent(std::istream&) {
  // Member funkcijos realizacija paremta ankstesniojo 2-ojo darbo funkcija: 
  std::istream& readStudent(std::istream&, Studentas&);
}