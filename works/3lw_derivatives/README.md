# Laboratorijas darbs Nr.3 - Atvasinājumi - atskaite

## Teorija

Dotā sākuma funkcija f(x) = (1-x) * e^-x

Tās pirmās kārtas atvasinājums izmantojo analītisko metodi:
f(x)' = (-1 * e^-x) + ((1-x)* e^-x * -1) = -2e^-x + (e^-x * x) = (-e^-x)(2 - x)
Izmantojo skaitlisko metodi:
f(x)' = (f(x + h) - f(x)) / h

Tās otrās kārtas atvasinājums izmantojo analītisko metodi:
f(x)'' = 2e^-x + (-e^-x * x) + (e^-x) = (e^-x)(3 - x)
Izmantojo skaitlisko metodi:
f(x)'' = ( ((f(x+2h)-f(x+h)) / h)-((f(x+h)-f(x)) / h) ) / h

Pēc teorijas abām metodēm rezultātiem būtu jābūt gandrīz vienlīdzīgiem, jo izmantojo skaitlisko metodi, tā ir parasto atvasinājumu tuvinājums.

### Kods
```C
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
```
Var nokompilēt uz Windows izmantojot GCC for Windows, kā arī MSVC. 

### Rezultāts
```
ievadiet saakuma veertiibu: -5

ievadiet beigu veertiibu: 2

ievadiet precizitaati(soli): 0.01

x(min) = -5.0000
x(max) =  2.0000
delta_x =  0.0100

        x|      f(x)|  an f'(x)| num f'(x)| an f''(x)|num f''(x)|
  -5.0000|  890.4790|-1038.8921|-1032.9778| 1187.3053| 1174.0343|
  -4.9900|  880.1492|-1027.0856|-1021.2374| 1174.0220| 1160.8977|
  -4.9800|  869.9368|-1015.4112|-1009.6285| 1160.8856| 1147.9063|
  [...]
   1.9700|   -0.1353|   -0.0042|   -0.0035|    0.1436|    0.1408|
   1.9800|   -0.1353|   -0.0028|   -0.0021|    0.1408|    0.1381|
   1.9900|   -0.1353|   -0.0014|   -0.0007|    0.1381|    0.1353|

```

### Analīze

Grafika attēla mērogs ir liels, tāpēc neredz atšķirību starp analītisko un skaitlisko atvasinājumu, bet tā tur ir, ja izmanto gnuplot grafika pietuvināšanu programmā.

### Attēli
Atvasinājumu grafiki
![Atvasinājumu grafiki](https://raw.githubusercontent.com/okass/RTR105/master/works/3lw_derivatives/graph.png)
