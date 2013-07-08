#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 20
#define RAN_MAX 50
int a[LEN] = {0};

void init(void){
	int i;
	srand(time(NULL));
	for (i=0; i<LEN; i++){
		a[i] = rand() % RAN_MAX;
	}
}

void sort(void){
	int i, j, tmp;
	for (i=1; i<LEN; i++){
		tmp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > tmp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
	for (i=0; i<LEN; i++){
		printf("%d\t", a[i]);
	}
}

int main(void){
	init();
	sort();
	return 0;
}
