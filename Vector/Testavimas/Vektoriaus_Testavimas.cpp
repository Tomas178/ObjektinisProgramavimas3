#include "../Headers/Vector.h"
#include <gtest/gtest.h>

TEST(Vektoriaus_Member_Funkciju_Testavimas, konstruktorius) {
    ManoVector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
    EXPECT_EQ(v.empty(), true);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Kopijavimo_Konstruktorius) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    ManoVector<int> v2(v);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 2);
    EXPECT_EQ(v2.empty(), false);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);
    EXPECT_EQ(v.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Move_Konstruktorius) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    ManoVector<int> v2;
    v2 = std::move(v);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 2);
    EXPECT_EQ(v2.empty(), false);
    EXPECT_EQ(v.capacity(), 0);
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.empty(), true);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Kopijavimo_Operatorius) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    ManoVector<int> v2;
    v2 = v;
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 2);
    EXPECT_EQ(v2.empty(), false);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);
    EXPECT_EQ(v.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, initializer_list) {
    ManoVector<std::string> v = {"Tomas", "Jonas", "Petras"};
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 3);
    EXPECT_EQ(v.empty(), false);
    EXPECT_EQ(v[0], "Tomas");
    EXPECT_EQ(v[1], "Jonas");
    EXPECT_EQ(v[2], "Petras");
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Move_Operatorius) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    ManoVector<int> v2(std::move(v));
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v2.capacity(), 2);
    EXPECT_EQ(v.capacity(), 0);
    EXPECT_EQ(v2.empty(), false);
    EXPECT_EQ(v.empty(), true);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Operatorius_Kvadratiniu_Sklaustu){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, At_Funkcija){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.at(0), 1);
    EXPECT_EQ(v.at(1), 2);
    EXPECT_THROW(v.at(2), std::out_of_range);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Front_Funkcija){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.front(), 1);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Back_Funkcija){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.back(), 2);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Data_Funkcija){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.data()[0], 1);
    EXPECT_EQ(v.data()[1], 2);
}

TEST(Vektoriaus_Iterator_Funkciju_Testavimas, Begin_Funkcija){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(*v.begin(), 1);
}

TEST(Vektoriaus_Iterator_Funkciju_Testavimas, End_Funkcija){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(*(v.end() - 1), 2);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Capacity_Funkcija){
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.capacity(), 2);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Size_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Empty_Funkcija) {
    ManoVector<int> v;
    EXPECT_EQ(v.empty(), true);
    v.push_back(1);
    EXPECT_EQ(v.empty(), false);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Reserve_Funkcija) {
    ManoVector<int> v;
    EXPECT_EQ(v.capacity(), 0);
    v.reserve(10);
    EXPECT_EQ(v.capacity(), 10);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Shrink_to_fit_Funkcija) {
    ManoVector<int> v;
    v.reserve(10);
    v.push_back(1);
    v.push_back(2);
    v.shrink_to_fit();
    EXPECT_EQ(v.capacity(), 2);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Assign_Funkcija) {
    ManoVector<int> v;
    v.assign(10, 5);
    EXPECT_EQ(v.size(), 10);
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(v[i], 5);
    }
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Clear_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    v.clear();
    EXPECT_EQ(v.size(), 0);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Push_Back_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 1);
    EXPECT_EQ(v[0], 1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);
    EXPECT_EQ(v[1], 2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);
    EXPECT_EQ(v[2], 3);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Emplace_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.emplace(1, 3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 3);
    EXPECT_EQ(v[2], 2);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Emplace_Back_Funkcija) {
    ManoVector<int> v;
    v.emplace_back(1);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 1);
    EXPECT_EQ(v[0], 1);
    v.emplace_back(2);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);
    EXPECT_EQ(v[1], 2);
    v.emplace_back(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);
    EXPECT_EQ(v[2], 3);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Pop_Back_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
    v.pop_back();
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_THROW(v.at(2), std::out_of_range);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Resize_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    v.resize(4);
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 0);
    EXPECT_EQ(v[3], 0);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Swap_Funkcija) {
    ManoVector<int> v1;
    v1.reserve(10);
    v1.push_back(1);
    v1.push_back(2);
    ManoVector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
    v1.swap(v2);
    EXPECT_EQ(v1.size(), 2);
    EXPECT_EQ(v1.capacity(), 2);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 10);
    EXPECT_EQ(v1[0], 3);
    EXPECT_EQ(v1[1], 4);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Insert_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.insert(1, 3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 3);
    EXPECT_EQ(v[2], 2);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Erase_Funkcija_Pagal_Pozicija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.erase(1);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 3);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Erase_Funkcija) {
    ManoVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    int* pirmas_elementas_salinimui = v.data() + 1;
    int* paskutinis_elementas_salinimui = v.data() + 3;
    int* result = v.erase(pirmas_elementas_salinimui, paskutinis_elementas_salinimui);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 4);
    EXPECT_EQ(v[2], 5);
}

int main(int argc, char** argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}