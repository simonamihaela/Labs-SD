#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int coord_x;
	int coord_y;
	int radius;
} circle_type;

int main() {
	int n, number = 0;
	scanf("%d", &n);
	circle_type *circle = malloc(n * sizeof(circle_type));
	if (!circle) {
		fprintf(stderr, "malloc failed\n");
		return -1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &circle[i].coord_x, &circle[i].coord_y, &circle[i].radius);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double distance = (circle[j].coord_x - circle[i].coord_x) * (circle[j].coord_x - circle[i].coord_x) + 
					 (circle[j].coord_y - circle[i].coord_y) * (circle[j].coord_y - circle[i].coord_y);
			if ((distance <= (circle[i].radius + circle[j].radius) * (circle[i].radius + circle[j].radius))) {
				number++;
			}
		}
	}
	printf("%d\n", number);
	return 0;
}
