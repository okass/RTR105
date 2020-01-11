#include <stdio.h>
#include <math.h>

int main(){
	int prec;
	scanf("%d", &prec);
	float a = 1, b = 6, c = 9, x, delta_x = pow(10, (-1) * prec);//1.e-5;
	float funca, funcb;
	int k = 0;
	
	funca = sin(a);
	funcb = sin(b);
	
	if (funca * funcb > 0){
		printf("[%.2f;%.2f] sin(x) has no roots or "
			"its root count is pair number\n",
			a, b);
		return 1;
	}
	
		printf("sin(a) = %f; sin(b) = %f\n", sin(a), sin(b));

	while ((b-a) > delta_x){
		k++;
		x = (a + b) / 2;
		if (funca * sin(x) > 0){
			a = x;
		} else {
			b = x;
		}
		printf("%2.d a %7.3f %7.3f", k, a, sin(a));
		printf(" b %7.3f %7.3f", b, sin(b));
		printf(" x %7.3f %7.3f\n", x, sin(x));
		//printf("%2.d a %e %e", k, a, sin(a));
		//printf(" b %e %e", b, sin(b));
		//printf(" x %e %e\n", x, sin(x));
		
	}
	//printf("%7.3f %7.3f", a, sin(a));
	//printf("%7.3f %7.3f", x, sin(x));
	//printf("%7.3f %7.3f\n", b, sin(b));
	printf("x %e %e over %d iters\n", x, sin(x), k);
	return 0;
}
