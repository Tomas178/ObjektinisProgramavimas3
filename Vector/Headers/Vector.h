#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <initializer_list>
#include <string>

/**
 * @class ManoVector
 * @brief Vektoriaus klasė pritaikyta šitai programai.
*/

template <typename T>
class ManoVector {
    private:
        size_t dydis; /**< Saugo dabartinį ManoVector dydį */
        size_t talpa; /**< Saugo dabartinę ManoVector talpą */
        T* duomenys; /**< Saugo rodyklę į dabartinius ManoVector duomenys */
    public:
        //Member funkcijos

        /**
         * @brief Funkcija, kuri grąžina maksimalų galimą vektoriaus dydį.
         * @return Maksimalus vektoriaus dydis.
        */
        int max_size() const { return std::numeric_limits<unsigned int>::max() / sizeof(T); }
        ManoVector() : dydis(0), talpa(0), duomenys(new T[talpa]) {} /**< Default'inis konstruktorius */
        ManoVector(std::initializer_list<T> il) : dydis(il.size()), talpa(il.size()), duomenys(new T[talpa]) {
            std::copy(il.begin(), il.end(), duomenys);
        } /**< initialiazer_list konstrukroius */

        /**
         * @brief Kopijavimo konstruktorius.
         * @param Kitas_Vektorius Vektorius, iš kurio kopijuojami duomenys.
        */
        ManoVector(const ManoVector<T>& Kitas_Vektorius) : dydis(Kitas_Vektorius.dydis), talpa(Kitas_Vektorius.talpa), duomenys(new T[talpa]) {
            for (unsigned int i = 0; i < dydis; i++) {
                duomenys[i] = Kitas_Vektorius.duomenys[i];
            }
        }

        /**
         * @brief Move konstruktorius.
         * @param Kitas_Vektorius Vektorius, iš kurio perkeliami duomenys.
        */
        ManoVector(ManoVector&& Kitas_Vektorius) noexcept : dydis(Kitas_Vektorius.dydis), talpa(Kitas_Vektorius.talpa), duomenys(Kitas_Vektorius.duomenys) {
            Kitas_Vektorius.dydis = 0;
            Kitas_Vektorius.talpa = 0;
            Kitas_Vektorius.duomenys = nullptr;
        }   

        ~ManoVector() { delete[] duomenys; } /**< ManoVector destrukroius */

        /**
         * @brief Kopijavimo operatorius.
         * @param Kitas_Vektorius Vektorius, iš kurio kopijuojami duomenys.
        */
        ManoVector& operator=(const ManoVector& Kitas_Vektorius) {
            if (this == &Kitas_Vektorius) return *this;
            delete[] duomenys;
            dydis = Kitas_Vektorius.dydis;
            talpa = Kitas_Vektorius.talpa;
            duomenys = new T[talpa];
            for (unsigned int i = 0; i < dydis; i++) {
                duomenys[i] = Kitas_Vektorius.duomenys[i];
            }
            return *this;
        }

        /**
         * @brief Move operatorius.
         * @param Kitas_Vektorius Vektorius, iš kurio perkeliami duomenys.
        */
        ManoVector& operator=(ManoVector&& Kitas_Vektorius) {
            if (this == &Kitas_Vektorius) return *this;
            delete[] duomenys;
            dydis = Kitas_Vektorius.dydis;
            talpa = Kitas_Vektorius.talpa;
            duomenys = Kitas_Vektorius.duomenys;
            Kitas_Vektorius.dydis = 0;
            Kitas_Vektorius.talpa = 0;
            Kitas_Vektorius.duomenys = nullptr;
            return *this;
        }

        //Element access funkcijos

        /**
         * @brief Operatorius, kuris grąžina nurodytą elementą.
         * @param indeksas Elemento indeksas.
        */
        T& operator[](unsigned int indeksas) {return duomenys[indeksas];}

        /**
         * @brief Operatorius, kuris grąžina nurodytą elementą.
         * @param indeksas Elemento indeksas.
        */
        const T& operator[](unsigned int indeksas) const {return duomenys[indeksas];}

        /**
         * @brief Funkcija, kuri grąžina nurodytą elementą.
         * @param indeksas Elemento indeksas.
         * @return Elementas.
         * @throw std::out_of_range Jei indeksas už ribų.
        */
        T& at(unsigned int indeksas) {
            if (indeksas >= dydis) {
                throw std::out_of_range("Indeksas už ribų");
            }
            return duomenys[indeksas];
        }

        /**
         * @brief Funkcija, kuri grąžina nurodytą elementą.
         * @param indeksas Elemento indeksas.
         * @return Elementas.
         * @throw std::out_of_range Jei indeksas už ribų.
        */
        const T& at(unsigned int indeksas) const {
            if (indeksas >= dydis) {
                throw std::out_of_range("Indeksas už ribų");
            }
            return duomenys[indeksas];
        }

        /**
         * @brief Funkcija, kuri grąžina pirmą elementą.
         * @return Pirmas elementas.
        */
        T& front() {return duomenys[0];}

        /**
         * @brief Funkcija, kuri grąžina pirmą elementą.
         * @return Pirmas elementas.
        */
        const T& front() const {return duomenys[0];}

        /**
         * @brief Funkcija, kuri grąžina paskutinį elementą.
         * @return Paskutinis elementas.
        */
        T& back() {return duomenys[dydis - 1];}

        /**
         * @brief Funkcija, kuri grąžina paskutinį elementą.
         * @return Paskutinis elementas.
        */
        const T& back() const {return duomenys[dydis - 1];}

        /**
         * @brief Funkcija, kuri grąžina rodyklę į duomenis.
         * @return Rodyklė į duomenis.
        */
        T* data() noexcept {return duomenys;}

        //Iterators funkcijos

        /**
         * @brief Funkcija, kuri grąžina rodyklę į pirmą vektoriaus elementą.
         * @return Rodyklė į pirmą vektoriaus elementą.
        */
        T* begin() noexcept {return duomenys;}

        /**
         * @brief Funkcija, kuri grąžina konstantinę rodyklę į pirmą vektoriaus elementą.
         * @return Konstantinė rodyklė į pirmą vektoriaus elementą.
        */
        const T* begin() const noexcept {return duomenys;}

        /**
         * @brief Funkcija, kuri grąžina rodyklę į vektoriaus pabaigą.
         * @return Rodyklė į vektoriaus pabaigą.
        */
        T* end() noexcept {return duomenys + dydis;}

        /**
         * @brief Funkcija, kuri grąžina konstantinę rodyklę į vektoriaus pabaigą.
         * @return Konstantinė rodyklė į vektoriaus pabaigą.
        */
        const T* end() const noexcept {return duomenys + dydis;}

        //Capacity funkcijos

        /**
         * @brief Funkcija, kuri grąžina vektoriaus talpą.
         * @return Vektoriaus talpa.
        */
        unsigned int capacity() const {return talpa;}

        /**
         * @brief Funkcija, kuri grąžina vektoriaus dydį.
         * @return Vektoriaus dydis.
        */
        unsigned int size() const {return dydis;}

        /**
         * @brief Funkcija, kuri patikrina ar vektorius tuščias.
         * @return Ar vektorius tuščias.
        */
        bool empty() const {return dydis == 0;}

        /**
         * @brief Funkcija, kuri rezervuoja vietos vektoriuje.
         * @param nauja_talpa Nauja vektoriaus talpa.
         * @throw std::length_error Jei vektorius neturi tiek vietos.
         * 
        */
        void reserve(unsigned int nauja_talpa) {
            if (nauja_talpa <= talpa) return;
            if(nauja_talpa > max_size()) throw std::length_error("Vektorius tiek vietos neturi:(");
            T* nauji_duomenys = new T[nauja_talpa];
            for (unsigned int i = 0; i < dydis; i++) {
                nauji_duomenys[i] = duomenys[i];
            }
            delete[] duomenys;
            duomenys = nauji_duomenys;
            talpa = nauja_talpa;
        }

        /**
         * @brief Funkcija, kuri sumažina vektoriaus talpą iki vektoriaus dydžio.
        */
        void shrink_to_fit() {
            if (dydis == talpa) return;
            T* nauji_duomenys = new T[dydis];
            for (unsigned int i = 0; i < dydis; i++) {
                nauji_duomenys[i] = duomenys[i];
            }
            delete[] duomenys;
            duomenys = nauji_duomenys;
            talpa = dydis;
        }

        /**
         * @brief Funkcija, kuri priskiria nurodytą elementą nurodytam kiekiui.
         * @param n Kiekis.
         * @param value Elementas.
        */
        void assign(unsigned int n, const T& value) {
            if (n > talpa) reserve(n);
            for (unsigned int i = 0; i < n; i++) {
                duomenys[i] = value;
            }
            dydis = n;
        }

        //Modifiers funkcijos
        void clear() {dydis = 0;} /**< Funkcija, išvalanti visą vektorių */

        /**
         * @brief Funkcija, kuri prideda elementą į vektoriaus pabaigą.
         * @param value Elementas, kuris turi būti pridėtas.
        */
        void push_back(const T& value) {
            if (dydis >= talpa) reserve(talpa == 0 ? 1 : dydis * 2);
            duomenys[dydis++] = value;
        }

        /**
         * @brief Funkcija, kuri prideda elementą į nurodytą poziciją.
         * @param value Elementas, kuris turi būti pridėtas.
        */
        T* insert(unsigned int indeksas, const T& value) {
            if (dydis >= talpa) reserve(talpa == 0 ? 1 : talpa * 2);
            for (unsigned int i = dydis; i > indeksas; i--) {
            duomenys[i] = duomenys[i - 1];
            }
            duomenys[indeksas] = value;
            dydis++;
            return &duomenys[indeksas];
        }

        /**
         * @brief Funkcija, kuri prideda elementą į nurodytą poziciją.
         * @param value Elementas, kuris turi būti pridėtas.
        */
        T* emplace(unsigned int indeksas, T&& value) {
            if (dydis == talpa) reserve(talpa == 0 ? 1 : talpa * 2);
            for (unsigned int i = dydis; i > indeksas; i--) {
            duomenys[i] = duomenys[i - 1];
            }
            duomenys[indeksas] = std::move(value);
            dydis++;
            return &duomenys[indeksas];
        }

        /**
         * @brief Funkcija, kuri prideda elementą į vektoriaus pabaigą.
         * @param value Elementas, kuris turi būti pridėtas.
        */
        T& emplace_back(T&& value) {
            if (dydis >= talpa) reserve(talpa == 0 ? 1 : dydis * 2);
            duomenys[dydis++] = std::move(value);
            return duomenys[dydis - 1];
        }

        /**
         * @brief Funkcija, kuri pašalina elementą iš ManoVector pabaigos.
        */
        void pop_back() {
            if (dydis > 0) {
                --dydis;
            }
        }

        /**
         * @brief Funkcija, kuri pakeičia ManoVector dydį į nurodytą dydį.
         * @param naujas_dydis Naujas ManoVector dydis.
        */
        void resize(unsigned int naujas_dydis) {
            if (naujas_dydis > talpa) reserve(naujas_dydis);
            for (unsigned int i = dydis; i < naujas_dydis; i++) {
                duomenys[i] = T();
            }
            dydis = naujas_dydis;
        }

        /**
         * @brief Funkcija, kuri sukeičia du vektorius vietomis.
         * @param Kitas_Vektorius Kitas vektorius.
        */
        void swap(ManoVector& Kitas_Vektorius) {
            std::swap(dydis, Kitas_Vektorius.dydis);
            std::swap(talpa, Kitas_Vektorius.talpa);
            std::swap(duomenys, Kitas_Vektorius.duomenys);
        }

        /**
         * @brief Funkcija, kuri išmeta nurodytą elementą.
         * @param indeksas Elemento indeksas.
        */
        T* erase(unsigned int indeksas) {
            for (unsigned int i = indeksas; i < dydis - 1; i++) {
                duomenys[i] = duomenys[i + 1];
            }
            dydis--;
            return &duomenys[indeksas];
        }

        /**
         * @brief Funkcija, kuri išmeta elementus tarp nurodytų elementų.
         * @param pirmas_elementas Pirmas elementas.
         * @param paskutinis_elementas Paskutinis elementas.
         * @return Rodyklė į paskutinį elementą.
        */
        T* erase(T* pirmas_elementas, T* paskutinis_elementas) {
            if (pirmas_elementas >= duomenys && paskutinis_elementas <= duomenys + dydis) {
                    size_t ElementaiSalinimui = paskutinis_elementas - pirmas_elementas;
                    size_t ElementaiPerkelimui = duomenys + dydis - paskutinis_elementas;

                    for (size_t i = 0; i < ElementaiPerkelimui; i++) {
                        *(pirmas_elementas + i) = *(paskutinis_elementas + i);
                    }

                    dydis -= ElementaiSalinimui;

                    if (paskutinis_elementas == duomenys + dydis) {
                        return paskutinis_elementas;
                    }
            }
            return paskutinis_elementas;
        }
};

#endif