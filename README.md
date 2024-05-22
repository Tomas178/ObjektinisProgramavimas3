# V3.0

- Visi tyrimai yra atlikti iš 5 bandymų.
- Visi failai turi po 7 namų darbus.
### Naudojami sistemos parametrai
- CPU(Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz, 2400 Mhz, 2 branduolių, 4 loginiai procesoriai)
- RAM(16,0 GB)
- HDD(TOSHIBA MQ01ABD100 512GB)

# Mano nuosavas vektorius

## Funkcijų pavyzdžiai

### 1 Pavyzdys
```cpp
#include <iostream>
#include "ManoVector.h"

int main() {
    ManoVector<int> mv;
    // Pridedame elementus į nuosavą vektorių
    for (int i = 0; i < 100; ++i) {
        mv.push_back(i);
    }
    // Naudojama nuosavo vektoriaus capacity() funkcija
    std::cout << "ManoVector dabartinė talpa: " << mv.capacity() << std::endl;
    return 0;
}
```
Rezultatas, kurio tikimasi:  ```ManoVector dabartinė talpa: 128```

### 2 Pavyzdys 
```cpp
#include <iostream>
#include "ManoVector.h"

int main() {
    ManoVector<int> mv;
    // Pridedame elementus į nuosavą vektorių
    for (int i = 0; i < 100; ++i) {
        mv.push_back(i);
    }
    // Naudojama nuosavo vektoriaus size() funkcija
    std::cout << "ManoVector dabartinis dydis: " << mv.size() << std::endl;
    return 0;
}
```
Rezultatas, kurio tikimasi:  ```ManoVector dabartinis dydis: 128```

### 3 Pavyzdys
```cpp
#include <iostream>
#include "ManoVector.h"

int main() {
    ManoVector<int> mv;
    
    // Naudojama nuosavo vektoriaus empty() funkcija
    std::cout << "Ar ManoVector tuščias? " << (mv.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
```
Rezultatas, kurio tikimasi:  ```Ar ManoVector tuščias? Taip```

### 4 Pavyzdys
```cpp
#include <iostream>
#include "ManoVector.h"

int main() {
    ManoVector<int> mv;
    // Rezervuojama nauja talpa
    mv.reserve(200);
    // Naudojama nuosavo vektoriaus capacity() funkcija
    std::cout << "ManoVector dabartinė talpa po rezervavimo: " << mv.capacity() << std::endl;
    return 0;
}
```

Rezultatas, kurio tikimasi: ```ManoVector dabartinė talpa po rezervavimo: 200```


### 5 Pavyzdys
```cpp
#include <iostream>
#include "ManoVector.h"

int main() {
    ManoVector<int> mv;
    // Pridedame elementus į nuosavą vektorių
    for (int i = 0; i < 100; ++i) {
        mv.push_back(i);
    }

    // Sumažinama talpa iki dabartinio dydžio
    mv.shrink_to_fit();
    // Naudojama nuosavo vektoriaus capacity() funkcija
    std::cout << "ManoVector dabartinė talpa po sumažinimo: " << mv.capacity() << std::endl;
    return 0;
}
```

Rezultatas, kurio tikimasi: ```ManoVector dabartinė talpa po sumažinimo: 100```



## Rezultatai

| Elementų skaičius | `std::vector` laikas (s) | `ManoVector` laikas (s) | `std::vector` Atminties Perskirstymai | `ManoVector` Atminties Perskirstymai |
|-------------------|--------------------------|--------------------------|---------------------------------------|---------------------------------------|
|             10,000 |                  0.000185 |                0.000159 |                                    14 |                                   14 |
|            100,000 |                  0.000888 |                0.000799 |                                    17 |                                   17 |
|          1,000,000 |                  0.005041 |                0.004240 |                                    20 |                                   20 |
|         10,000,000 |                  0.054503 |                0.053863 |                                    24 |                                   24 |
|        100,000,000 |                  0.486738 |                0.488783 |                                    27 |                                   27 |

# Instaliavimo instrukcija
- Jeigu neturite CMake, tuomet reikia atsisiųsti iš https://cmake.org/download/ ir instaliuojant programą pasirinkti, kad nustatytų sistemos kintamuosius arba galite žiūrėti šitą video: https://www.youtube.com/watch?v=8_X5Iq9niDE.
- Taip pat reikės atsisiųsti googletest darant šiuos žingsnius folderyje: 
    - git clone https://github.com/google/googletest.git
    - cd googletest        # Main directory of the cloned repository.
    - mkdir build          # Create a directory to hold the build output.
    - cd build
    - cmake ..             # Generate native build scripts for GoogleTest.
- Tuomet build folder'yje turėtu atsirasti libgtest.a ir libgtest_main.a failai ir tada žiūrėkite į CMakeLists.txt ir nustatykite kelią iki tų failų pagal savo failų lokaciją.
- Tuomet tam folderyje, raskite run.bat script'ą ir jums viska sutvarkys automatiškai.
- V3_0_Vector.exe failą rasite Debug folder'yje, o programos_testas.exe ir vektoriaus_testas.exe rasite Testavimo_rezultatai folder'yje, kurie atsiras po CMake įvykdymo.

