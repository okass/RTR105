# Laboratorijas darbs Nr.2 - Kvadrātsaknes - atskaite

## Teorija
Uzdevums ir parādīt, kā izvilkt kvadrātsakni, neizmantojo iebūvēto sqrt() funkciju matemātikas bibliotēkā.
Šajā gadījuma to izdara ar Hērona metodi.

### Kods
```C
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
	
	printf("f(x) kvadraatsakne izmantojot heerona metodi: %7.16lf over %d iters\n"
		"kvadraatsakne izmantojot iebuuveeto sqrt(): %7.16lf \n",
		x, k, sqrt(funcc));
	return 0;
}
```
Var nokompilēt uz Windows izmantojot GCC for Windows, kā arī MSVC. 

### Rezultāts
```
ievadiet precizitaati: 13

ievadiet mazaako pieljaujamo veertiibu: 0

ievadiet lielaako pieljaujamo veertiibu: 40

ievadiet x veertiibu: -1

a =   0.000; b =  40.000; f(c) = 5.436564
f(x)=5.436564
f(x) kvadraatsakne izmantojot heerona metodi: 2.3316439815971242 over 9 iters
kvadraatskane izmantojot iebuuveeto sqrt(): 2.3316439815971242

```

### Analīze

Kods pārstāj darboties pie precizitātes 14 visticamāk float dēļ.
Manuprāt, precizitāte pati nestrādā pareizi, toties kvadrātsakne tiek izvilkta pareizi, jo tā sakrīt ar sqrt() vērtību.
Interesanti, ka x86_64 procesorā ir iebūvēta kvadrātsaknes funkcija.
Lielākajai daļai arhitektūru tā ir iebūvēta, bet vecākām, kā, piemēram, PowerPC tāda nav, tāpēc tai C bibliotēkā tā ir definēta asemblerā.
No GNU C library (2.3.0) tā ir definēta kā
```C
__ieee754_sqrt (double x)
{
  double res;

  asm ("sqrtsd %1, %0" : "=x" (res) : "xm" (x));

  return res;
}
```

### Attēli
Funkcijas f(x) = (1-x) * e^-x grafiks ar atliktu saknes punktu
![Funkcijas f(x) = (1-x) * e^-x grafiks](https://raw.githubusercontent.com/okass/RTR105/master/works/2lw_roots/graph.png)
