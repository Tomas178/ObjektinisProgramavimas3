# V3.0

- Visi tyrimai yra atlikti iš 5 bandymų.
- Visi failai turi po 7 namų darbus.
### Naudojami sistemos parametrai
- CPU(Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz, 2400 Mhz, 2 branduolių, 4 loginiai procesoriai)
- RAM(16,0 GB)
- HDD(TOSHIBA MQ01ABD100 512GB)

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
- V3_0_Vector.exe failą rasite Debug folder'yje, o Testas.exe rasite Testavimo_rezultatai folder'yje, kurie atsiras po CMake įvykdymo.