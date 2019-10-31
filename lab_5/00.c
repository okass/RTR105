/* apliecibas numurs
191REB139 */
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, N;
	N = (9 + 1) * 3;
	int a[N];

	srand(1);

	for(i = 0; i < N; i++) {
		a[i] = rand() % 10;
	}

	for(i = 0; i < N; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
