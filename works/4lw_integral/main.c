#include <stdio.h>
#include <math.h>
#include <string.h>

// analiitiskaas formulas

// (1-x) * e^-x
double fnc(double x){
	double result;
	double previous_val;
	int max_k = 500;
	
	result = 1;
	previous_val = result;
	
	for(int i = 1; i <= max_k && previous_val != 0; i++){
		// rekurences reizinaajums
		double current_val = previous_val * (-1.) *x / i;
		
		result += current_val;
		
		previous_val = current_val;
	}

	return (1. - x) * result;
}

int main(){
	double a, b, delta_x, h, integr1 = 0., integr2;
	int k = 0, n = 2;
	
	printf("ievadiet saakuma veertiibu: ");
	scanf("%lf", &a);
	printf("\n");
	
	printf("ievadiet beigu veertiibu: ");
	scanf("%lf", &b);
	printf("\n");
	
	printf("ievadiet precizitaati(soli): ");
	scanf("%lf", &delta_x);
	
	printf("\nx(min) = %7.4lf\nx(max) = %7.4lf\ndelta_x = %7.4lf\n\n",
			a, b, delta_x);
	
	// taisnstuura metode
	// S = h * w =>
	// h = f((a + b) / 2)
	// w = b - a
	integr2 = fnc((a + b) / n) * (b - a);
	
	while (fabs(integr2 - integr1) > delta_x){
		n *= 2;
		h = (b - a) / n;
		integr1 = integr2;
		integr2 = 0;
		for (k = 0;k < n;k++){
			integr2 += h * fnc(a + (k + 0.5) * h);
		}
	}
	
	printf("Integraalja veertiiba izmantojo taisnstuura metodi: %.4lf\n", integr2);
	
	
	
	return 0;
}