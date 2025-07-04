#include <stdio.h> //bagian header (library)

//fungsi untuk menghitung FPB dan koefisien m dan n dengan menggunakan algoritma euclidean
int extendedEuclid(int a, int b, int *m, int *n) {
    //basis rekursif
    if (b == 0) {
        *m = 1;
        *n = 0;
        return a;
    }

    //membuat variabel untuk menyimpan nilai sementara dari m dan n
    int m1, n1;
    //rekursif memanggil fungsi dengan nilai b dan a mod b
    int fpb = extendedEuclid(b, a % b, &m1, &n1);
	
    //mengupdate nilai m dan n
    *m = n1;
    *n = m1 - (a / b) * n1;
	
    return fpb;
}

int main() {
    int a, b;//membuat variabel untuk menampung nilai a dan b (untuk input)
    int m, n;//membuat variabel untuk menampung nilai koefisien

    //meminta input dari user
    printf("Masukkan nilai a: ");
    scanf("%d", &a);
    printf("Masukkan nilai b: ");
    scanf("%d", &b);

    //memanggil fungsi untuk mencari FPB dan koefisien m, n
    int fpb = extendedEuclid(a, b, &m, &n);

    //menampilkan output/hasil menggunakan fungsi printf
    printf("FPB(%d, %d) = %d\n", a, b, fpb);
    printf("m = %d, n = %d\n", m, n);
    printf("Persamaan: %d = %d * %d + %d * %d\n", fpb, m, a, n, b);
	
	return 0;
}