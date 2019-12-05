#include <stdio.h>
#include <math.h>

int main(){
	float a=0.01, b=1.5 * M_PI, x, delta_x=1.e-5;
	float funca, funcb;
	funca = sin(a);
	funcb = sin(b);

	if (funca * funcb > 0){
		printf("[%.2f;%.2f] sin(x) has no roots or "
			"its root count is pair number\n",
			a, b);
		return 1;
	}

	while ((b-a) > delta_x){
		k++;
		x = (a + b) / 2;
		if (funca * sin(x) > 0){
			a = x;
		} else {
			b = x;
		}
		printf("%7.3f %7.3f", a, sin(a));
		printf("%7.3f %7.3f", x, sin(x));
		printf("%7.3f %7.3f\n", b, sin(b));

	}
	printf("%7.3f %7.3f", a, sin(a));
	printf("%7.3f %7.3f", x, sin(x));
	printf("%7.3f %7.3f\n", b, sin(b));
	return 0;
}
