#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
	int k = 0;
	
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
	
	double funcc = fnc(c);
	
	printf("a = %7.3lf; b = %7.3lf; f(c) = %lf\n", a, b, fnc(c));
	
	// paarbauda vai funnkcijas rezultaats nav negatiivs
	if (funcc < 0){
		printf("Funkcijas f(x) = (1-x) * e^-x veertiibas pie "
				"%f ir negatiiva", c);
		return 1;
	}
	
	// ja a * b lielaaks par f(x) tad sakne nebuus sheit
	if (a * b > funcc){
		printf("[%.2f;%.2f] f(x) = (1-x) * e^-x nav kvadraatsaknju", a, b);
		return 1;
	}
	
	x = b;
	while (fabs(x * x - funcc) > delta_x){
		k++;
		x = (x + (funcc/x)) / 2;
	}
	
	// ja b mazaaks par f(x) kvadraatsakni tad sakne nebuus sheit
	if (b < x){
		printf("[%.2f;%.2f] f(x) = (1-x) * e^-x nav kvadraatsaknju", a, b);
		return 1;
	}
	printf("f(x)=%lf\n", funcc);
	printf("f(x) kvadraatsakne izmantojot heerona metodi: %7.16lf over %d iters\n"
			"kvadraatsakne izmantojot iebuuveeto sqrt(): %7.16lf \n",
			x, k, sqrt(funcc));
	return 0;
}
