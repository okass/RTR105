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
	unsigned int k = 0, n = 2;
	
	printf("ievadiet intervaala saakuma veertiibu: ");
	scanf("%lf", &a);
	printf("\n");
	
	printf("ievadiet intervaala beigu veertiibu: ");
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
	
	printf("Integraalja veertiiba izmantojo taisnstuura metodi: %.8lf\n", integr2);
	
	// trapeces metode
	// (h/2) * (f(a) + 2f(a+h) + 2f(a+2h) + ... + f(b))
	// izreekjinaa cik intervaalos sadaliit funkciju
	// ar doto precizitaati
	n = (unsigned int)((fabs(a) + fabs(b)) / delta_x);
	h = fabs(b - a) / n;
	integr2 = 0;
	
	for (int i = 1; i < n; i++){
		integr1 = a + (i * h);
		integr2 += fnc(integr1);
	}
	
	printf("Integraalja veertiiba izmantojo trapeces metodi: %.8lf\n",
		(h / 2) * (fnc(a) + fnc(b) + (2 * integr2) ));
	
	
	// simpsona metode
	// (h/3) * (f(a) + 4f(a+h) + 2f(a+2h) + 
	// + 4f(a+3h) + 2f(a+4h) + .. + f(b))
	n = (unsigned int)((fabs(a) + fabs(b)) / delta_x);
	// paara skaitlja paarbaude
	if (n % 2 == 1){n++;}
	h = fabs(b - a) / n;
	integr2 = 0;
	
	for (int i = 1; i < n; i++){
		integr1 = a + (i * h);
		if (i % 2 == 0){
			integr2 += 2 * fnc(integr1);
		} else{
			integr2 += 4 * fnc(integr1);
		}
	} 
	
	printf("Integraalja veertiiba izmantojo simsona metodi: %.8lf\n",
		(h / 3) * (fnc(a) + fnc(b) + integr2));
	
	return 0;
}