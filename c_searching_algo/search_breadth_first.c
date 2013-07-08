#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point {int row, col, predecessor;} queue[512];
int start = 0, end = 0;

void enqueue(struct point p){
	queue[end++] = p;
}

struct point dequeue(void){
	return queue[start++];
}

int is_empty(){
	return start == end;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void){
	int i, j;
	for (i=0; i<MAX_ROW; i++){
		for (j=0; j<MAX_COL; j++){
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("*********\n");
}

void visit(int row, int col){
	struct point visit_point = {row, col, start-1};
	enqueue(visit_point);
	maze[row][col] = 2;
}

int main(void){
	struct point p = {0, 0, -1};
	
	enqueue(p);
	maze[p.row][p.col] = 2;
	
	while (!is_empty()){
		p = dequeue();
		if (p.row == MAX_ROW-1 && p.col == MAX_COL-1){
			break;
		}
		if (p.row-1 >= 0 && maze[p.row-1][p.col] == 0){
			visit(p.row-1, p.col);
		}
		if (p.col+1 < MAX_COL && maze[p.row][p.col+1] == 0){
			visit(p.row, p.col+1);
		}
		if (p.row+1 < MAX_ROW && maze[p.row+1][p.col] == 0){
			visit(p.row+1, p.col);
		}
		if (p.col-1 >= 0 && maze[p.row][p.col-1] == 0){
			visit(p.row, p.col-1);
		}
		print_maze();
	}
	if (p.row == MAX_ROW-1 && p.col == MAX_COL-1){
		printf("(%d, %d)\n", p.row, p.col);
		while (p.predecessor != -1){
			p = queue[p.predecessor];
			printf("(%d, %d)\n", p.row, p.col);
		}
	} else {
		printf("No path!\n");
	}
	
	return 0;
}
