#include <stdio.h>//menggunakan library stdio.h

//mendeklarasikan fungsi untuk menghitung FPB dari dua angka
int fpb(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//mendeklarasikan fungsi untuk menghitung invers modulo
int invmod(int a, int m){
    int t = 0, t1 = 1;
    int r = m, r1 = a;
    while (r1 != 0) {
        int hasil = r / r1;
        t = t1;
        t1 = t - hasil * t1;
        r = r1;
        r1 = r - hasil * r1;
    }
    if (r > 1) {
        return -1;//tidak ada invers
    }
    if (t < 0) {
        t = t + m;//pastikan invers positif
    }
    return t;
}

//mendeklarasikan fungsi untuk menyelesaikan kongruensi linier ax ≡ b (mod m)
int kongruen(int a, int b, int m){
    int d = fpb(a, m);  // Menghitung FPB dari a dan m

    //jika FPB(a, m) tidak membagi b, maka tidak ada solusi
    if (b % d != 0) {
        printf("tidak ada solusi\n");
        return -1;
    }

    //sederhanakan persamaan menjadi ax' ≡ b' (mod m')
    a = a / d;
    b = b / d;
    m = m / d;

    //mencari invers modulo dari a mod m
    int inv = invmod(a, m);
    if (inv == -1) {
        printf("tidak ada invers modulo\n");
        return -1;
    }

    //solusi adalah x = (invers * b) % m
    int x = (inv * b) % m;
    return x;
}

int main(){
    /*mendeklarasikan variabel untuk menampung nilai
    a = nilai koefisien x
    b = nilai hasil kongruensi
    c = nilai modulus*/
    int a, b, m;

    //meminta masukan dari user: nilai a, b, dan m untuk kongruensi ax ≡ b (mod m)
    printf("masukkan nilai a (koefisien x): ");
    scanf("%d", &a);
    printf("masukkan nilai b (hasil kongruensi): ");
    scanf("%d", &b);
    printf("masukkan nilai m (modulus): ");
    scanf("%d", &m);

    //menyelesaikan kongruensi
    int result = kongruen(a, b, m);
    if (result != -1) {
        printf("solusi dari kongruensi adalah x = %d\n", result);
    }

    return 0;
}
//done