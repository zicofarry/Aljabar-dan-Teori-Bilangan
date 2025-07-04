#include <stdio.h>//menggunakan library stdio.h
#include <math.h>//menggunakan library math.h

//mendeklarasikan fungsi untuk mengecek prima atau komposit
int primavskompo(int n){
    for (int i = 2; i <= sqrt(n); i++){//looping hingga akar dari bilangan
        if (n % i == 0){//jika bisa membagi maka dia bilangan komposit
            return 0;
        }
    }
    return 1;//jika tidak, maka dia bilangan prima
}

int main(){
    //mendeklarasikan variabel n untuk menampung nilai angka masukan
    int n;

    //meminta masukan dari user
    printf("Masukkan angka positif: ");
    scanf("%d", &n);

    //menjalankan program dengan memanggil fungsi yang sudah dibuat
    if (n < 2){//membuat kondisi jika input lebih kecil dari 2
        printf("%d bukan merupakan angka komposit ataupun prima\n", n);
    }else{
        if (primavskompo(n)){//jika return bernilai true
            printf("%d adalah angka prima\n", n);
        }else{//jika return bernilai false
            printf("%d adalah angka komposit\n", n);
        }
    }

    return 0;
}
//done