#include <stdio.h>
#include <math.h>
#include <string.h>

// analiitiskaas formulas
// (3 - x) * e^-x
double fnc_der_two(double x){
	double result;
	double previous_val;
	int max_k = 500;
	
	// e^-x
	result = 1;
	previous_val = result;
	
	for(int i = 1; i <= max_k && previous_val != 0; i++){
		// rekurences reizinaajums
		double current_val = previous_val * (-1.) *x / i;
		
		result += current_val;
		
		previous_val = current_val;
	}
	
	return (3. - x) * result;
}

// (2 - x) * -e^-x
double fnc_der_one(double x){
	double result;
	double previous_val;
	int max_k = 500;
	
	// e^-x
	result = 1;
	previous_val = result;
	
	for(int i = 1; i <= max_k && previous_val != 0; i++){
		// rekurences reizinaajums
		double current_val = previous_val * (-1.) *x / i;
		
		result += current_val;
		
		previous_val = current_val;
	}
	
	return (2. - x) * -result;
}

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
	double a, b, delta_x;
	int k = 0;
	FILE * fp;
	fp = fopen("derivatives.dat", "wb");
	
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
	
	printf("        x|      f(x)|  an f'(x)| num f'(x)| an f''(x)|num f''(x)|\n");
	
	fprintf(fp, "%s", "\"x\"\t" "\"f(x)\"\t" "\"analytical f'(x)\"\t"
					"\"numerical f'(x)\"\t" "\"analytical f''(x)\"\t"
					"\"numerical f''(x)\"\n");
	
	while(b >= a + delta_x * k){
		double x = (a + delta_x * k);
		double y;
		
		printf("%7.4lf|", x);
		fprintf(fp, "%lf\t", x);
		
		// f(x) = (1-x) * e^-x
		y = fnc(x);
		printf("%10.4lf|", y);
		fprintf(fp, "%lf\t", y);
		
		// f(x)' = (-e^-x) * (2 - x)
		y = fnc_der_one(x);
		printf("%10.4lf|", y);
		fprintf(fp, "%lf\t", y);
		
		// h = delta_x
		// f(x) = (1-x) * e^-x
		// f(x)' = (f(x + h) - f(x)) / h
		y = (fnc(x + delta_x) - fnc(x)) / delta_x; 
		printf("%10.4lf|", y);
		fprintf(fp, "%lf\t", y);
		
		// f(x)'' = (e^-x) * (3 - x)
		y = fnc_der_two(x); 
		printf("%10.4lf|", y);
		fprintf(fp, "%lf\t", y);
		
		// h = delta_x
		// f(x) = (1-x) * e^-x
		// f(x)'' = ( ((f(x+2h)-f(x+h)) / h)-((f(x+h)-f(x)) / h) ) / h
		y = ( ( (fnc(x + 2 * delta_x) - fnc(x + delta_x)) / delta_x)
		- ( (fnc(x + delta_x) - fnc(x)) / delta_x) ) / delta_x; 
		printf("%10.4lf|\n", y);
		fprintf(fp, "%lf\n", y);
		
		k++;
	}
	
	fclose(fp);
	return 0;
}