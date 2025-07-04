#include <stdio.h>

int main() {
	int m, n, q, r;
	
	
	printf("Masukan nilai m (m >= 0):\n");
	if(scanf("%i", &m) !=1) {
		return 1;
	}
	printf("Masukan nilai n (n >=0):\n");
	if(scanf("%i", &n) !=1) {
		return 1;
	}
	if(n<0 || m<0) {
		printf("Masukan tidak valid");
		return 1;
	} else if(n==0) {
		printf("%i", m);
		return 2;
	} else if(m==0) {
		printf("%i", n);
		return 3;
	}
	
	while(1) {
	
		q = m / n;
		r = m % n;
		if (r == 0){
			break;
		}
		m = n;
		n = r;
	}

	printf("Maka FPBnya adalah %i", n);
	
	return 0;
}