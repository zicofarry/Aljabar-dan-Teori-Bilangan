#include <stdio.h>//menggunakan library stdio.h

//mendeklarasikan fungsi fpb
int fpb(int a, int m){
    if(m==0){//jika m = 0 maka fpb nya a
        return a;
    }else{//jika tidak
        int temp = a % m;
        return fpb(m, temp);//lakukan operasi fpb (menggunakan pemanggilan rekursif)
    }
}

//mendeklarasikan fungsi untuk mencari invers Modulo
int invmod(int a, int m){ // fungsi untuk mencari invers Modulo
    int m0 = m, i, j;
    int y = 0, x = 1;
     while (a > 1) {
        //j adalah hasil bagi
        int j = a / m;
        int i = m;

        //m adalah sisa
        m = a % m;
        a = i;
        i = y;

        //mengupdate y dan x
        y = x - j * y;
        x = i;
    }

    if (x >= m0) {
        x -= m0;
    }
    
    return x;//mengembalikan nilai x
}

int main(){
    int a, m;
    printf("input nilai a : ");
    scanf("%d", &a);
    printf("input nilai m : ");
    scanf("%d", &m);
    
    if(fpb(a, m) == 1){ //jika FPB a dan m adalah 1 maka memiliki invers
        printf("invers dari %d modulo %d adalah: %d\n", a, m, invmod(a, m));
    }else{ //jika FPB a dan m bukan 1 maka tidak memiliki invers
        printf("invers modulo TIDAK ADA karena FPB(%d, %d) != 1", a, m);
    }

    return 0;
}
//done