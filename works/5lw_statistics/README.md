# Laboratorijas darbs Nr.5 - Statistika - atskaite

## Teorija
Uzdevums ir sakārtot lietotāja ievadīto rindu alfabēta secībā, kā arī veikt tās analīzi, kā simbolu skaits, maksimālā un minimālā vērtība, vidējais aritmētiskais, mediāna un moda.

### Kods
```C
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void * elem1, const void * elem2){
    // qsort specifikaacija
	char f = *((char*)elem1);
    char s = *((char*)elem2);
	
    // ja elem1 > elem2 tad elem1 ir aiz elem2
	if (f > s) return  1;
    // ja elem1 < elem2 tad elem1 ir pirms elem2
	if (f < s) return -1;
	// ja elem1 == elem2 tad seciiba nemainaas
    return 0;
}

// modas
void findMode(char * buffer, int bufferSize, 
					unsigned int letterCount){
	unsigned char count[0xFF] = {0};
	unsigned int highest = 0;
	unsigned char highest_id = 0;
	
	// count
	for (int i = 0; i < letterCount; i++){
		count[buffer[i]]++; 
	}
	
	// find highest
	for (int i = 0; i < 0xFF; i++){
		if (count[i] > highest){
			highest = count[i];
			highest_id = i;
		}
	}
	
	printf("Mode(s):");
	for (int i = 0; i < 0xFF; i++){
		if (count[i] == highest){
			printf(" %d(%c)", i, i);
		}
	}
	printf(" appears %d times\n", count[highest_id]);
}

float findMedian(char * buffer, int bufferSize, 
				unsigned int letterCount){
	float median;
	// sakriit ar ievades bufera izmeeru
	unsigned char buf[4096];
	
	// read from buffer and create median array
	for (unsigned int i = 0; i < bufferSize; i++){
		char letter = (char)buffer[i];
        
        // detects if string has ended in buffer
        if (letter == 0xA) {
            break;
        }
		buf[i] = letter;
    }
	
	// sort
	// izdeviigaak sakaartot sheit
	qsort(&buf, letterCount, 1, cmpfunc);
	
	if((letterCount & 0x1) == 0){
		median = (float)(buf[(letterCount - 1) / 2] 
					+ buf[(letterCount - 1) / 2 + 1]) / 2;
	} else{
		median = buf[(letterCount) / 2];
	}
	
	printf("Sorted characters: \n");
	for (int i = 0; i < letterCount; i++){
		printf("  %c ", buf[i]);
	}
	printf("\n");
	
	//printf("Sorted character bytes: ");
	for (int i = 0; i < letterCount; i++){
		char simb = buf[i];
		if (simb > 99){
			printf("%d;", buf[i]);
		} else if (simb > 9){
			printf(" %d;", buf[i]);
		} else{
			printf("  %d;", buf[i]);
		}
	
	}
	printf("\n");
	
	return median;
}

unsigned int getStringLenght(char * buffer, int bufferSize, 
					unsigned char * biggest, 
					unsigned char * smallest,
					float * average){   
    int letterCount = 0;
	unsigned int sum = 0;
    
	// biggest and smallest values plus total character count
    for(int i = 0; i < bufferSize; i++)
    {
		char letter = buffer[i];
        
        // detects if string has ended in buffer
        if (letter == 0xA) {
            break;
        }
		
		if (letter > *biggest) *biggest = letter;
		if (letter < *smallest) *smallest = letter;
		letterCount++;
		sum += letter;
    }
	
	// average
	*average = (float)sum / (float)letterCount;
	
	return letterCount;
}

int main(){
	// ar malloc vareetu daudz lielaakas rindas uzglabaat bet tas nav nepiecieshams
	char buffer[4096];
	unsigned char biggest = 0;
	unsigned char smallest = 0xFF;
	float average = 0;
	float median = 0;
	
	// pajautaa ievadu
	printf("Please enter letters:\n>");
    fgets(&buffer, 4096, stdin);
	
    unsigned int charCount = getStringLenght(&buffer, sizeof(buffer), 
									&biggest, &smallest, &average);
									
	median = findMedian(&buffer, sizeof(buffer), charCount);
					
    printf("Counted %d chars.\n", charCount);
	printf("Biggest: %c(%d)\nSmallest: %c(%d)\n", biggest, biggest, 
												smallest, smallest);
	printf("Average: %7.3f\n", average);
	printf("Median: %7.3f\n", median);
	findMode(&buffer, sizeof(buffer), charCount);
	
	return 0;
}
```
Var nokompilēt uz Windows izmantojot GCC for Windows, kā arī MSVC. 

### Rezultāts
```
Please enter letters:
>bdefcbab
Sorted characters:
  a   b   b   b   c   d   e   f
 97; 98; 98; 98; 99;100;101;102;
Counted 8 chars.
Biggest: f(102)
Smallest: a(97)
Average:  99.125
Median:  98.500
Mode(s): 98(b) appears 3 times

```

### Analīze

Lai sakārtotu simbolu rindu, kodā tika izmantota C funkcija qsort(), kas ir QuickSort kārtošanas algoritms.
Tā kā ASCII simboli ir skaitliski sakārtoti, var izmantot to skaitliskās vērtības to kārtošanā un analīzē.
Tas ļauj izrēķināt simbolu rindas vidējo aritmētisko vērtību, atrast lielāko, mazāko vērtību, kā arī atrast mediānu un modu.

### Attēli
Datu histogrammma Rezultāta ievadam
![Datu histogrammma Rezultāta ievadam](https://raw.githubusercontent.com/okass/RTR105/master/works/5lw_statistics/graph.png)
