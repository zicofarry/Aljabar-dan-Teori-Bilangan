#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int PF[MAXN + 5];

void primeFactorization(int x){ // O(log N)
    while(x != 1){
        cout << PF[x] << " ";
        x /= PF[x];
    }
    cout << endl;
}

int main(){ // sieve of Eratosthenes, O(N log log N)
    int n; cin >> n;
    for(int i = 0; i <= n; i++) PF[i] = i;
    PF[0] = PF[1] = -1;
    for(int i = 2; i * i <= n; i++){
        if(PF[i] != i) continue;
        for(int j = i * i; j <= n; j += i){
            PF[j] = i;
        }
    }
    
    primeFactorization(n);

    return 0;
}
