#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P;

    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    cout << "Masukkan Nomor Polisi yang dicari   : ";
    cin >> x.nopol;
    cout << endl;
    P = findElm(L, x);
    if (P != Nil) {
        cout << "Nomor Polisi   : " << P->info.nopol << endl;
        cout << "Warna          : " << P->info.warna << endl;
        cout << "Tahun          : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    }
    cout << endl;

    cout << "Masukkan Nomor Polisi yang akan dihapus   : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    } else {
        address D;
        if (P == L.First) {
            deleteFirst(L, D);
        } else if (P == L.Last) {
            deleteLast(L, D);
        } else {
            deleteAfter(P->prev, D);
        }
        dealokasi(D);
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
    }

    cout << endl << "DATA LIST 1" << endl << endl;
    printInfo(L);

    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    return 0;
}