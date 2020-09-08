#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
	float x;
	float y;
};

struct pentagon {
	struct point a;
	struct point b;
	struct point c;
	struct point d;
	struct point e;
};

struct pentagon cons();
float distance(struct point a, struct point b);
float perimetr (struct pentagon fig);
 
#endif
