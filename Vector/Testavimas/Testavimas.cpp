#include "../Headers/funkcijos.h"
#include "../Headers/Vector.h"
#include <gtest/gtest.h>

int programos_veikimas;

TEST(Studento_Testavimas, ManoVector_Kartu_Su_Studentu) {
    ManoVector<Studentas> studentai;
    for(int i = 0; i < 10; i++) {
        studentai.push_back(Studentas());
    }
    EXPECT_EQ(studentai.size(), 10);
    EXPECT_EQ(studentai.capacity(), 16);
    studentai.shrink_to_fit();
    EXPECT_EQ(studentai.capacity(), 10);
    EXPECT_EQ(studentai.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, ManoVector_Kartu_Su_Studentu_Konstruktorius) {
    ManoVector<Studentas> studentas;
    EXPECT_EQ(studentas.size(), 0);
    EXPECT_EQ(studentas.capacity(), 0);
    EXPECT_EQ(studentas.empty(), true);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Kopijavimo_Konstruktorius) {
    ManoVector<Studentas> studentas1;
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    ManoVector<Studentas> studentas2(studentas1);
    EXPECT_EQ(studentas2.size(), 1);
    EXPECT_EQ(studentas2.capacity(), 1);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.size(), 1);
    EXPECT_EQ(studentas1.capacity(), 1);
    EXPECT_EQ(studentas1.empty(), false);
}

TEST(Studento_Testavimas, Studento_Default_Konstruktorius) {
    Studentas studentas;
    EXPECT_EQ(studentas.Get_Vardas(), "");
    EXPECT_EQ(studentas.Get_Pavarde(), "");
    EXPECT_EQ(studentas.Nd_empty(), true);
    EXPECT_EQ(studentas.Nd_dydis(), 0);
    EXPECT_EQ(studentas.Get_Egzaminas(), 0);
    EXPECT_EQ(studentas.Get_Vidurkis(), 0.0);
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Move_Konstruktorius) {
    ManoVector<Studentas> studentas1;
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    ManoVector<Studentas> studentas2;
    studentas2 = std::move(studentas1);
    EXPECT_EQ(studentas2.size(), 1);
    EXPECT_EQ(studentas2.capacity(), 1);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.capacity(), 0);
    EXPECT_EQ(studentas1.size(), 0);
    EXPECT_EQ(studentas1.empty(), true);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Kopijavimo_Operatorius) {
    ManoVector<Studentas> studentas1;
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    ManoVector<Studentas> studentas2;
    studentas2 = studentas1;
    EXPECT_EQ(studentas2.size(), 1);
    EXPECT_EQ(studentas2.capacity(), 1);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.size(), 1);
    EXPECT_EQ(studentas1.capacity(), 1);
    EXPECT_EQ(studentas1.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, initializer_list) {
    ManoVector<Studentas> studentas1 = {Studentas("Tomas", "Petronis"), Studentas("Petras", "Petraitis"), Studentas("Jonas", "Jonaitis")};
    EXPECT_EQ(studentas1.size(), 3);
    EXPECT_EQ(studentas1.capacity(), 3);
    EXPECT_EQ(studentas1.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Move_Operatorius) {
    ManoVector<Studentas> studentas1;
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    studentas1.push_back(Studentas("Petras", "Petraitis"));
    ManoVector<Studentas> studentas2(std::move(studentas1));
    EXPECT_EQ(studentas2.size(), 2);
    EXPECT_EQ(studentas1.size(), 0);
    EXPECT_EQ(studentas2.capacity(), 2);
    EXPECT_EQ(studentas1.capacity(), 0);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.empty(), true);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Front_Funkcija_Studentas) {
    ManoVector<Studentas> vector;
    Studentas studentas1("Tomas", "Petronis");
    Studentas studentas2("Jonas", "Jonatisi");
    vector.push_back(studentas1);
    vector.push_back(studentas2);
    EXPECT_EQ(vector.front().Get_Vardas(), "Tomas");
    EXPECT_EQ(vector.front().Get_Pavarde(), "Petronis");
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Back_Funkcija_Studentas) {
    ManoVector<Studentas> vector;
    Studentas studentas1("Tomas", "Petronis");
    Studentas studentas2("Jonas", "Jonaitis");
    vector.push_back(studentas1);
    vector.push_back(studentas2);
    EXPECT_EQ(vector.back().Get_Vardas(), "Jonas");
    EXPECT_EQ(vector.back().Get_Pavarde(), "Jonaitis");
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Reserve_Funkcija) {
    ManoVector<Studentas> studentas1;
    EXPECT_EQ(studentas1.capacity(), 0);
    studentas1.reserve(10);
    EXPECT_EQ(studentas1.capacity(), 10);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Clear_Funkcija) {
    ManoVector<Studentas> studentas1;
    studentas1.push_back(Studentas("Jonas", "Jonaitis"));
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    EXPECT_EQ(studentas1.size(), 2);
    studentas1.clear();
    EXPECT_EQ(studentas1.size(), 0);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Emplace_Funkcija_Studentas) {
    ManoVector<Studentas> vector;
    Studentas studentas1("Tomas", "Petronis");
    Studentas studentas2("Jonas", "Jonaitis");
    Studentas studentas3("Petras", "Petraitis");

    vector.push_back(studentas1);
    vector.push_back(studentas2);
    vector.emplace(1, move(studentas3));

    EXPECT_EQ(vector.size(), 3);
    EXPECT_EQ(vector[0].Get_Vardas(), "Tomas");
    EXPECT_EQ(vector[0].Get_Pavarde(), "Petronis");
    EXPECT_EQ(vector[1].Get_Vardas(), "Petras");
    EXPECT_EQ(vector[1].Get_Pavarde(), "Petraitis");
    EXPECT_EQ(vector[2].Get_Vardas(), "Jonas");
    EXPECT_EQ(vector[2].Get_Pavarde(), "Jonaitis");
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Pop_Back_Funkcija) {
    ManoVector<Studentas> studentas1;
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    studentas1.push_back(Studentas("Jonas", "Jonaitis"));
    studentas1.push_back(Studentas("Petras", "Petraitis"));
    EXPECT_EQ(studentas1.size(), 3);
    studentas1.pop_back();
    EXPECT_EQ(studentas1.size(), 2);
    EXPECT_THROW(studentas1.at(2), std::out_of_range);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Resize_Funkcija) {
    ManoVector<Studentas> studentas1;
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    studentas1.push_back(Studentas("Jonas", "Jonaitis"));
    EXPECT_EQ(studentas1.size(), 2);
    studentas1.resize(4);
    studentas1.emplace(2, move(Studentas("Petras", "Petraitis")));
    cout << studentas1.at(2);
    EXPECT_EQ(studentas1.size(), 5);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Swap_Funkcija) {
    ManoVector<Studentas> studentas1;
    studentas1.reserve(10);
    studentas1.push_back(Studentas("Tomas", "Petronis"));
    studentas1.push_back(Studentas("Jonas", "Jonaitis"));
    ManoVector<Studentas> studentas2;
    studentas2.push_back(Studentas("Petras", "Petraitis"));
    studentas2.push_back(Studentas("Ieva", "Ievaite"));
    studentas1.swap(studentas2);
    EXPECT_EQ(studentas1.size(), 2);
    EXPECT_EQ(studentas1.capacity(), 2);
    EXPECT_EQ(studentas2.size(), 2);
    EXPECT_EQ(studentas2.capacity(), 10);
    EXPECT_EQ(studentas1[0].Get_Vardas(), "Petras");
    EXPECT_EQ(studentas1[0].Get_Pavarde(), "Petraitis");
    EXPECT_EQ(studentas1[1].Get_Vardas(), "Ieva");
    EXPECT_EQ(studentas1[1].Get_Pavarde(), "Ievaite");

    EXPECT_EQ(studentas2[0].Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2[0].Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2[1].Get_Vardas(), "Jonas");
    EXPECT_EQ(studentas2[1].Get_Pavarde(), "Jonaitis");
}


TEST(Studento_Testavimas, Studento_Parametirinis_Konstruktorius) {
    Studentas studentas("Tomas", "Petronis");
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas.Nd_empty(), true);
    EXPECT_EQ(studentas.Nd_dydis(), 0);
    EXPECT_EQ(studentas.Get_Egzaminas(), 0);
    EXPECT_EQ(studentas.Get_Vidurkis(), 0.0);
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);
}

TEST(Studento_Testavimas, Studento_Move_konstruktorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2(move(studentas));
    EXPECT_EQ(studentas.Get_Vardas(), "");
    EXPECT_EQ(studentas.Get_Pavarde(), "");
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_Copy_konstruktorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2(studentas);
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas.Get_Mediana(), 8.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_kopijavimo_operatorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2 = studentas;
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas.Get_Mediana(), 8.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_move_operatorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2 = move(studentas);
    EXPECT_EQ(studentas.Get_Vardas(), "");
    EXPECT_EQ(studentas.Get_Pavarde(), "");
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_Seteriai_ir_Geteriai) {
    Studentas studentas;
    studentas.SetVardas("Tomas");
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    studentas.SetPavarde("Petronis");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    studentas.setNd(10);
    studentas.setNd(5);
    EXPECT_EQ(studentas.Nd_empty(), false);
    EXPECT_EQ(studentas.Nd_dydis(), 2);
    EXPECT_EQ(studentas.Get_Last_Nd(), 5);
    studentas.setEgzaminas(10);
    EXPECT_EQ(studentas.Get_Egzaminas(), 10);
    studentas.setVidurkis(7.5);
    EXPECT_EQ(studentas.Get_Vidurkis(), 7.5);
    studentas.SetMediana(8.0);
    EXPECT_EQ(studentas.Get_Mediana(), 8.0);
    studentas.DeleteLastNd();
    EXPECT_EQ(studentas.Nd_empty(), false);
    EXPECT_EQ(studentas.Nd_dydis(), 1);
    EXPECT_EQ(studentas.Get_Last_Nd(), 10);
}

int main(int argc, char** argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
