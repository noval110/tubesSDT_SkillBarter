#include <iostream>
#include "queue_barter.h"
using namespace std;

void createQueue(QueueBarter &Q) {
    Q.front = nullptr;
    Q.rear = nullptr;
    Q.jumlah = 0;
}

void enqueue(QueueBarter &Q, const PermintaanBarter &data) {
    NodeQueue* baru = new NodeQueue;
    baru->info = data;
    baru->next = nullptr;

    if (Q.front == nullptr) {
        Q.front = baru;
        Q.rear = baru;
    } else {
        Q.rear->next = baru;
        Q.rear = baru;
    }
    Q.jumlah++;
}

bool dequeue(QueueBarter &Q, PermintaanBarter &dataKeluar) {
    bool berhasil = false;
    NodeQueue* hapus;

    if (Q.front != nullptr) {
        hapus = Q.front;
        dataKeluar = hapus->info;
        Q.front = Q.front->next;

        if (Q.front == nullptr) {
            Q.rear = nullptr;
        }

        delete hapus;
        Q.jumlah--;
        berhasil = true;
    }

    return berhasil;
}

void tampilkanQueue(const QueueBarter &Q) {
    NodeQueue* bantu = Q.front;
    int nomor = 1;

    cout << "\n========== ANTREAN PERMINTAAN BARTER (FIFO) ==========" << endl;
    if (bantu == nullptr) {
        cout << "Antrean masih kosong.\n";
    } else {
        while (bantu != nullptr) {
            cout << nomor << ". " << bantu->info.idPermintaan << " | "
                 << bantu->info.namaPemohon << " -> " << bantu->info.namaTujuan
                 << " | Menawarkan: " << bantu->info.skillDitawarkan
                 << " | Meminta: " << bantu->info.skillDiminta << endl;
            bantu = bantu->next;
            nomor++;
        }
        cout << "Front = permintaan paling awal, Rear = permintaan paling akhir." << endl;
    }
}

void hapusQueue(QueueBarter &Q) {
    NodeQueue* hapus;

    while (Q.front != nullptr) {
        hapus = Q.front;
        Q.front = Q.front->next;
        delete hapus;
    }
    Q.rear = nullptr;
    Q.jumlah = 0;
}
