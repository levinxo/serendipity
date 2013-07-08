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

void merge(int start, int mid, int end){
	int n1 = mid - start + 1, n2 = end - mid;
	int left[n1], right[n2];
	int i, j, k;
	for (i=0; i<n1; i++){
		left[i] = a[start+i];
	}
	for (j=0; j<n2; j++){
		right[j] = a[mid+1+j];
	}
	i = j = 0;
	k = start;
	while (i<n1 && j<n2){
		if (left[i] < right[j]){
			a[k++] = left[i++];
		} else {
			a[k++] = right[j++];
		}
	}
	while (i<n1){
		a[k++] = left[i++];
	}
	while (j<n2){
		a[k++] = right[j++];
	}
}

void sort(int start, int end){
	int mid;
	if (start < end){
		mid = (start + end) / 2;
		sort(start, mid);
		sort(mid+1, end);
		merge(start, mid, end);
	}
}

int main(void){
	int i;
	init();
	sort(0, LEN-1);
	for (i=0; i<LEN; i++){
		printf("%d\t", a[i]);
	}
	return 0;
}
