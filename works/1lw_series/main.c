#include <stdio.h>
#include <math.h>

// (1-x) * e^-x
double fnc(double x){
	double result;
	double previous_val;
	int max_k = 500;
	double priekspedeja;
	
	// lieka darbiiba, bet principa peec
	//k = 0; (  (-1)^k    * x^k) / k! => 1
	result = (pow(-1., 0) *  1 ) / 1;
	previous_val = result;
	
	for(int i = 1; i <= max_k && previous_val != 0; i++){
		// rekurences reizinaajums
		double current_val = previous_val * (-1.) *x / i;
		
		result += current_val;
		
		// saglabaa veertiibas veelaakai paraadiishanai
		if (current_val != 0){
			priekspedeja = previous_val;
			previous_val = current_val;
		}
	}
	
	// 4
	printf("priekshpeedeejaa veertiiba: %7.6e\n", priekspedeja);
	// 5
	printf("peedeejaa veertiiba: %7.6e\n", previous_val);
	
	return (1. - x) * result;
}

int main(){
	double inp;
	
	// 1
	printf("ievadiet x veertiibu: ");
	scanf("%lf", &inp);
	printf("\n");
	
	// 2
	// f(x) = (1-x) * e^-x
	printf("rezultaats izmantojot funkciju: %lf\n\n", 
	( (1 - inp) * exp(-inp) ) );
	
	// 3
	printf("rezultaats izmantojot teilora rindas: %lf\n", fnc(inp));
	
	return 0;
}