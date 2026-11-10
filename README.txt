SKILLBARTER - PROGRES 1
Kelompok 31

STRUKTUR DATA YANG DIIMPLEMENTASIKAN
1. Array of Struct : menyimpan data pengguna.
2. Linked List     : menyimpan daftar skill setiap pengguna.
3. Queue           : mengelola antrean permintaan barter dengan FIFO.
4. Stack           : menyimpan riwayat aksi dengan LIFO.

FITUR YANG TERSEDIA
- Menampilkan dan menambahkan pengguna.
- Sequential Search pengguna berdasarkan ID.
- Mengurutkan pengguna berdasarkan ID dan Binary Search.
- Menambahkan dan menampilkan skill per pengguna.
- Enqueue, menampilkan antrean, dan dequeue permintaan barter.
- Push, menampilkan riwayat, dan pop catatan riwayat.
- Data simulasi Rani, Budi, Sinta, dan Dimas dimuat otomatis saat program dijalankan.

CARA MENJALANKAN
1. Ekstrak folder SkillBarter_Progres1.
2. Buka folder tersebut di VS Code atau Code::Blocks.
3. Compile seluruh file .cpp dalam satu project.

Contoh compile menggunakan g++:
g++ -std=c++11 main.cpp pengguna.cpp skill.cpp queue_barter.cpp stack_riwayat.cpp -o SkillBarter

Jalankan:
Windows : SkillBarter.exe
Linux   : ./SkillBarter

CATATAN IMPLEMENTASI
- Data masih disimpan di memori selama program berjalan, belum menggunakan file/database.
- Binary Search mengharuskan data terurut; program menjalankan pengurutan berdasarkan ID sebelum pencarian.
- POP pada progres ini menghapus catatan paling atas dari stack riwayat. POP belum melakukan rollback terhadap perubahan data pengguna atau transaksi.
- Program ini merupakan fondasi progres pertama; validasi kecocokan skill dan proses barter lengkap dapat dikembangkan pada progres berikutnya.
