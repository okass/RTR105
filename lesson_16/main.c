#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int launchPlot(int count){
	char * commands[] = {"set title \"graph sin\";"
				" set style data lines;"
				" plot sin(x) lc rgb \"#00FF00\"," 
				" '-' \n"};
	double xvals[count];
	double yvals[count];

	FILE * plotPipe = popen("gnuplot -persistent ", "w");

	for (int i = 0; i < count; i++){
		double y = calcSin(i * .1);
		xvals[i] = (double)i * .1;
		yvals[i] = y;
	}

	fprintf(plotPipe, "%s ", commands[0]);

	for(int i = 0; i < count; i++){
		fprintf(plotPipe, "%lf %lf \n", xvals[i], yvals[i]);
	}

	fprintf(plotPipe, "e");
	fflush(plotPipe);

	return 0;
};

int main(){
	int x = 0;

	printf("Enter x value: ");
	scanf("%d", &x);
	printf("\n");
	if (x > 0){
		launchPlot(x * 10);
	};
};
