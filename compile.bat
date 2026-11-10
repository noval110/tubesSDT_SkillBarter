@echo off
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp pengguna.cpp skill.cpp queue_barter.cpp stack_riwayat.cpp -o SkillBarter.exe
if errorlevel 1 (
    echo Kompilasi gagal. Periksa pesan error di atas.
) else (
    echo Kompilasi berhasil.
    echo Menjalankan SkillBarter...
    SkillBarter.exe
)
pause
