#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 20
#define MAX_GAP 5

int a[LEN] = {0};

void init(void){
	int i;
	srand(time(NULL));
	a[0] = 1;
	printf("%d\t", a[0]);
	for (i=1; i<LEN; i++){
		a[i] = a[i-1] + rand() % MAX_GAP;
		printf("%d\t", a[i]);
	}
	putchar('\n');
}

int search(int n){
	int start = 0, end = LEN - 1, mid;
	
	while (end >= start){
		mid = (start + end) / 2;
		if (n > a[mid]){
			start = mid + 1;
		} else if (n < a[mid]){
			end = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main(void){
	int n = 5;
	init();
	printf("%d is found at %d\n", n, search(n));
	return 0;
}
