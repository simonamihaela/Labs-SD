#include <stdio.h>
#include <stdlib.h>

void free_matrix(int **a, int rows) {
	for (int i = 0; i < rows; i++) {
		free(a[i]);
	}
	free(a);
}

int **alloc_matrix(int rows, int collums) {
	int **a = malloc(rows * sizeof(int *));
	if (a == NULL) {
		return NULL;
	}
	for (int i = 0; i < rows; i++) {
		a[i] = malloc(collums * sizeof(int));
		if (a[i] == NULL) {
			free_matrix(a, i);
			return NULL;
		}
	}

	return a;
}
void read_matrix(int n, int m, int **mat) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void check_number(int n, int m, int **mat, int given_number) {
	int ok = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == given_number) {
				printf("TRUE");
				ok = 1;
			}
		}
	}
	if (ok == 0) {
		printf("FALSE");
	}
}

int main() {
	int n, m, given_number;
	scanf("%d%d%d", &n, &m, &given_number);
	int **mat = alloc_matrix(n, m);
	if (mat == NULL) {
		fprintf(stderr, "Aloc de memorie\n");
		exit(-1);
	}
	read_matrix(n, m, mat);
	check_number(n, m, mat, given_number);
	return 0;
}
