#include "header.h"

struct pentagon cons() {
	struct pentagon fig;
	scanf("%f %f", &fig.a.x, &fig.a.y);
	scanf("%f %f", &fig.b.x, &fig.b.y);
	scanf("%f %f", &fig.c.x, &fig.c.y);
	scanf("%f %f", &fig.d.x, &fig.d.y);
	scanf("%f %f", &fig.e.x, &fig.e.y);
	return fig;
}

float distance(struct point a, struct point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

float perimetr (struct pentagon fig) {
	float x1 = distance(fig.a, fig.b);
	float x2 = distance(fig.b, fig.c);
	float x3 = distance(fig.c, fig.d);
	float x4 = distance(fig.d, fig.e);
	float x5 = distance(fig.e, fig.a);
	return x1 + x2 + x3 + x4 + x5;
}
