#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <assert.h>

using namespace std;

struct point
{
	long double x,y;
};

int main(int argc, char* argv[])
{
	if(argc != 3){
		fprintf(stderr, "not valid number of arguments\n");
		return 1;
	}
	FILE *fp_in;
	if((fp_in = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "input file open failed!\n");
		return 1;
	}	
	int N = 0, M = 0;
	fscanf(fp_in, "%d", &N);
	assert(N >= 0);
	point* control = new point[N];

	for(int i = 0; i < N; i++){
		fscanf(fp_in, "%Lf%Lf", &control[i].x, &control[i].y);
	}
	fscanf(fp_in, "%d", &M);
	assert(M >= 0);
	fclose(fp_in);

	FILE *fp_out;
	if((fp_out = fopen(argv[2], "w")) == NULL){
		fprintf(stderr, "output file open failed!\n");
		return 1;
	}

//******REAL WORK*******
	point* B = new point[N];

	long double t = 0;
	long double d = ((long double)(1.00)) / (M - 1);//the interval of sampled
	for(int sampled = 0; sampled < M; sampled++){
		for(int j = 0; j < N; j++){//B[i][j] is determined after B[i + 1][j], take j as first index
			for(int i = j; i >= 0; i--){
				if(i == j){
					B[i] = control[i];
				}
				else{
					B[i].x = (1 - t) * B[i].x + t * B[i + 1].x;
					B[i].y = (1 - t) * B[i].y + t * B[i + 1].y;			
				}
			}
		}
		fprintf(fp_out, "%.2f\t%.2f\n", (double)(B[0].x), (double)(B[0].y));
		t += d;
	}
//******REAL WORK*******
	delete[] B;
	delete[] control;
	fclose(fp_out);

	return 0;
}
