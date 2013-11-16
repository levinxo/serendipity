#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 20
#define RAN_MAX 50

void init(int *a, int length){
	int i;
	srand(time(NULL));
	for (i=0; i<length; i++){
		a[i] = rand() % RAN_MAX;
	}
}

void sort(int *a, int length){
	int i, j, tmp;
	for (i=0; i<length-1; i++){
		for (j=length-1; j>i; j--){
			if (a[j]<a[j-1]){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}

int main(void){
    int a[LEN] = {0}, i;
	init(a, LEN);
	sort(a, LEN);
	for (i=0; i<LEN; i++){
		printf("%d\t", a[i]);
	}
	return 0;
}
