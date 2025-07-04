#include <stdio.h>//menggunakan library stdio.h

//mendeklarasikan fungsi untuk menentukan faktor prima
void fakPrima(int n){
    if (n < 2){//jika n < 2 maka tidak memiliki faktor prima
        printf("angka %d tidak memiliki faktor prima\n", n);
        return;//menghentikan prosedurnya
    }

    //jika lebih dari 1
    printf("faktor prima dari angka %d adalah: ", n); 

    //memeriksa faktor 2
    while (n % 2 == 0){ 
        printf("2 ");
        n /= 2;
    }
    //memeriksa bilangan ganjil mulai dari 3
    for (int i = 3; i * i <= n; i += 2){
        while (n % i == 0){
            printf("%d ", i);
            n /= i;
        }
    }

    //Jika n adalah bilangan prima lebih besar dari 2
    if (n > 2){
        printf("%d", n);
    }
    printf("\n");
}

int main(){
    //mendeklarasikan variabel n unurk menampung nilai angka masukan
    int n;

    //meminta masukan dari user
    printf("masukkan angka positif: ");
    scanf("%d", &n);

    //menjalakan program dengan memanggil prosedur fakPrima untuk menentukan hasil faktor faktor primanya
    fakPrima(n);

    return 0;
}
//done