#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * elem1, const void * elem2) {
    char f = *((char*)elem1);
    char s = *((char*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

float findMedian(char * buffer, int bufferSize, 
				unsigned int letterCount){
	float median;
	unsigned char buf [4096];
	
	// read from buffer and create median array
	for (unsigned int i = 0; i < bufferSize; i++){
		char letter = buffer[i];
        
        // detects if string has ended in buffer
        if (letter == 0xA) {
            break;
        }
		buf[i] = letter;
    }
	
	// sort
	qsort(&buf, letterCount, 1, cmpfunc);
	
	if((letterCount & 0x1) == 0){
		median = (float)(buf[(letterCount - 1) / 2] 
					+ buf[(letterCount - 1) / 2 + 1]) / 2;
	} else{
		median = buf[(letterCount) / 2];
	}
	
	printf("Sorted characters: ");
	for (int i = 0; i < letterCount; i++){
		printf("%c", buf[i]);
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
	
	*average = (float)sum / (float)letterCount;
	
	return letterCount;
}

int main(){
	char buffer[4096];
	unsigned char biggest = 0;
	unsigned char smallest = 0xFF;
	float average = 0;
	float median = 0;
	
	printf("Please enter letters:\n>");
    fgets(&buffer, 4096, stdin);
    unsigned int charCount = getStringLenght(&buffer, sizeof(buffer), 
									&biggest, &smallest, &average);
	median = findMedian(&buffer, sizeof(buffer),
						charCount);
					
    printf("Counted %d chars.\n", charCount);
	printf("Biggest: %c(%d)\nSmallest: %c(%d)\n", biggest, biggest, 
												smallest, smallest);
	printf("Average: %7.3f\n", average);
	printf("Median: %7.3f\n", median);
	
	return 0;
}