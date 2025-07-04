#include <stdio.h>//menggunakan library stdio.h

//mendeklarasikan fungsi untuk menghitung Fungsi Totien Euler
int eulerTotient(int n){
    int result = n;//mulai dengan result = n
    
    //menghitung faktor prima dari n
    for(int p = 2; p * p <= n; p++){
        //jika p adalah faktor dari n
        if (n % p == 0){
            //faktor prima ditemukan, lakukan perhitungan
            while (n % p == 0){
                n /= p;//Menghapus faktor p dari n
            }
            result -= result / p;//sesuaikan result dengan rumus
        }
    }
    
    //jika n > 1, maka n adalah faktor prima terakhir
    if (n > 1){
        result -= result / n;
    }
    
    return result;
}

int main(){
    //mendeklarasikan variabel n untuk menampung nilai masukan
    int n;
    
    //meminta masukan dari user
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    
    //menghitung dan menampilkan hasil fungsi totien Euler
    printf("Fungsi Totien Euler dari %d adalah: %d\n", n, eulerTotient(n));
    
    return 0;
}
//done