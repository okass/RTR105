# Laboratorijas darbs Nr.1 - Teilora rindas - atskaite

## Teorija
Darbs notiek ar iepriekš norādīto funkciju(šinī gadījumā Nr.18).

Dotā funkcija:
```
f(x) = (1-x) * e^-x
```

Šo funkciju C valodā var ievadīt kā:
```C
double result = (1 - x) * exp(-x)
```

C valodā pierakstīta izteiksme satur exp(-x) funkciju, kura kāpinā e konstanti norādītājā pakāpē.
Tās vērtību var pierādīt ar Teilora rindas izteiksmi.
Teilora rinda ir nepieciešama, jo e konstanti aprēķina ar eksponentfunkcijas palīdzību un tā ir redzama nākamajā izteiksmē.

Funkcijas exp(-x) aprēķins izmantojot Teilora rindu:
```		
		 500
		-----
		\          k     k
		 \     (-1)  *  x
f(x) =    |   -------------
		 /          k!
		/
		------
		 k=0
```

Tā kā funkcijā konstante e ir kāpināta negatīvā x pakāpē, šī Teilora rinda ir izmainīta standarta eksponentfunkcija.
Lai atvieglotu programmēšanu un samazinātu nepieciešamo aprēķinu apjomu rēķinot Teilora rindas, to var sadalīt smalkākās daļās.
Šajā gadījumā pie k=0 => x(0)=1, kas ir pirmā vērtība. 
Lai nebūtu jāatkārto tie paši aprēķini, iepriekšējai vērtībai var piereizināt rekurences reizinātāju, kas ir atšķirība starp iepriekšējo vērtību un nākamo, tādējādi iegūstot nākamo vērtību.

Dotās Teilora rindas rekurences reizinātājs:
```
	(-1) * x
R = ---------
	    k
```

Šādi tiek izrēķinātas 500 iterācijas teilora rindai un tās saskatītas.
Visbeidzot, lai iegūtu dotās funkcijas vērtību sareizina Teilora rindas rezultātu ar (1 - x).

### Kods
```C
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
```
Var nokompilēt uz Windows izmantojot GCC for Windows, kā arī MSVC. 

### Result
```
ievadiet x veertiibu: 5

rezultaats izmantojot funkciju: -0.026952

priekshpeedeejaa veertiiba: 6.768699e-322
peedeejaa veertiiba: -1.482197e-323
rezultaats izmantojot teilora rindas: -0.026952

```

### Analīze

Aprēķins ar Teilora rindām sakrīt ar vienkāršu C valodā uzrakstītu funkciju.
Šis pierāda veidu, kā dators aprēķina eksponentfunkcijas.
Rezultātos arī novērojama eksponentfunkcijas iezīme, ka vērtības tuvojas nullei, bet nekad tās nesasniedz.
Tas ir redzams pievienotajā grafika attēlā. 

C valodas matemātikas bibliotēkā, specifiski GNU C library (2.3.0), aprēķins notiek šādi:
```assembly
/* e^x = 2^(x * log2(e)) */
ENTRY(__ieee754_exp)
#ifdef  PIC
	LOAD_PIC_REG (cx)
#endif
	fldl	4(%esp)
/* I added the following ugly construct because exp(+-Inf) resulted
   in NaN.  The ugliness results from the bright minds at Intel.
   For the i686 the code can be written better.
   -- drepper@cygnus.com.  */
	fxam				/* Is NaN or +-Inf?  */
	fstsw	%ax
	movb	$0x45, %dh
	andb	%ah, %dh
	cmpb	$0x05, %dh
	je	1f			/* Is +-Inf, jump.  */
	fldl2e
	fmulp				/* x * log2(e) */
	fld	%st
	frndint				/* int(x * log2(e)) */
	fsubr	%st,%st(1)		/* fract(x * log2(e)) */
	fxch
	f2xm1				/* 2^(fract(x * log2(e))) - 1 */
	fld1
	faddp				/* 2^(fract(x * log2(e))) */
	fscale				/* e^x */
	fstp	%st(1)
	DBL_NARROW_EVAL_UFLOW_NONNEG_NAN
	ret

1:	testl	$0x200, %eax		/* Test sign.  */
	jz	2f			/* If positive, jump.  */
	fstp	%st
	fldz				/* Set result to 0.  */
2:	ret
END (__ieee754_exp)
```
Piezīmes: tie ir orģinālie komentāri.

### Attēli
Funkcijas f(x) = (1-x) * e^-x grafiks
![Funkcijas f(x) = (1-x) * e^-x grafiks](https://raw.githubusercontent.com/okass/RTR105/works/1lw_series/graph.png)https://raw.githubusercontent.com/okass/RTR105/master/works/1lw_series/graph.png)
