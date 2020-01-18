#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// (1-x) * e^-x
double fnc(double x){
	double result;
	double previous_val;
	int max_k = 500;
	
	result = 1;
	previous_val = result;
	
	for(int i = 1; i <= max_k && previous_val != 0; i++){
		double current_val = previous_val * (-1.) *x / i;
		
		result += current_val;
		previous_val = current_val;
	}
	
	return (1. - x) * result;
}

int main(){
	int prec;
	printf("ievadiet precizitaati: ");
	scanf("%d", &prec);
	printf("\n");
	double a, b, c, x, delta_x = pow(10, (-1) * prec);//1.e-5;
	
	///*
	// a veertiiba
	printf("ievadiet mazaako pieljaujamo veertiibu: ");
	scanf("%lf", &a);
	printf("\n");
	
	// b veertiiba
	printf("ievadiet lielaako pieljaujamo veertiibu: ");
	scanf("%lf", &b);
	printf("\n");
	
	// c veertiiba
	printf("ievadiet x veertiibu: ");
	scanf("%lf", &c);
	printf("\n");
	//*/
	
	//a, b, c = 1., 40., -5.;
	
	double funca, funcb, funcc;
	int k = 0;
	
	funca = fnc(a);
	funcb = fnc(b);
	clock_t start, end;
	start = clock();
	funcc = fnc(c);
	end = clock();
	printf("%d %d\n", start, end);
	printf("time taken: %e\n", (((double)(end - start)) / CLOCKS_PER_SEC));
	
	printf("f(a) = %lf; f(b) = %lf; f(c) = %lf\n", fnc(a), fnc(b), fnc(c));
	
	// paarbauda vai funnkcijas rezultaats nav negatiivs
	if (funcc < 0){
		printf("Funkcijas f(x) = (1-x) * e^-x veertiibas pie "
				"%f ir negatiiva", c);
		return 1;
	}
	
	if (funca * funcb > funcc){
		printf("[%.2f;%.2f] f(x) = (1-x) * e^-x has no roots or "
			"its root count is pair number\n",
			a, b);
		return 1;
	}
	
	printf("f(a) = %lf; f(b) = %lf; f(c) = %lf\n", fnc(a), fnc(b), fnc(c));
	
	x = b;
	while (fabs(x * x - funcc) > delta_x){
		k++;
		//x = (a + b) / 2;
		x = (x + (funcc/x)) / 2;
		/*
		if (funca * fnc(x) > funcc){
			a = x;
		} else {
			b = x;
		}
		/*
		printf("%2.d a %7.3f %7.3f", k, a, fnc(a));
		printf(" b %7.3f %7.3f", b, fnc(b));
		printf(" x %7.3f %7.3f\n", x, fnc(c));
		*/
		//printf("%2.d a %e %e", k, a, sin(a));
		//printf(" b %e %e", b, sin(b));
		//printf(" x %e %e\n", x, sin(x));
		
	}
	//printf("%7.3f %7.3f", a, sin(a));
	//printf("%7.3f %7.3f", x, sin(x));
	//printf("%7.3f %7.3f\n", b, sin(b));
	printf("x=%7.32f f(x)=%f over %d iters\n", x, funcc, k);
	return 0;
}
