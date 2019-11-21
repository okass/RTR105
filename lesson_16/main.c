#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define VAL_COUNT 100

double calcSin(double x){
	int max_k = 500;
	double y;
	double previous_val;
	// val 0
	y = ( (pow(-1., 0))/1 ) * pow(x, ( (2 * 0) + 1) );
	previous_val = y;

	for (int i = 1; i < max_k; i++){
		double current_val = previous_val * 
		( (-1.) / ((2 * i) * ( (2 * i) + 1 )) ) * (pow(x, 2));

		y = y + current_val;
		previous_val = current_val;
	};
	return y;
};

int main(){
	char * commands[] = {"set title \"graph sin\";"
				" set style data lines;"
				" plot sin(x) lc rgb \"#00FF00\"," 
				" '-' \n"};
	double xvals[VAL_COUNT] = {};
	double yvals[VAL_COUNT] = {};

	FILE * plotPipe = popen("gnuplot -persistent ", "w");

	for (int i = 0; i < VAL_COUNT; i++){
		double y = calcSin(i * .1);
		xvals[i] = (double)i;
		printf("%lf\n", y);
		yvals[i] = y;
	}

	fprintf(plotPipe, "%s ", commands[0]);

	printf("input vals\n");
	for(int i = 0; i < VAL_COUNT; i++){
		//printf("%lf, %lf \n", xvals[i], yvals[i]);
		fprintf(plotPipe, "%lf %lf \n", xvals[i], yvals[i]);
	}

	fprintf(plotPipe, "e");
	fflush(plotPipe);
};
