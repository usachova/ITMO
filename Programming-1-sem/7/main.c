#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum confectionery {
	pie,
	cake,
	iceCream,
	candy,
	donut,
	waffle,
	cookie
};

struct square {
	struct first {
		float x;
		float y;
	} f;
	struct second {
		float x;
		float y;
	} s;
	struct third {
		float x;
		float y;
	} t;
	struct fourth {
		float x;
		float y;
	} fo;
	float perimeter;
};

union dev {
	int num;
	struct myDev {
		unsigned ready : 1;
		unsigned lowToner : 1;
		unsigned damD : 1;
		unsigned noPaper : 1;
	} printer;
} cur;

int main(int argc, char *argv[]) {
	enum confectionery x = candy;
	printf("%d\n\n", x);
	
	struct square kv;
	kv.f.x = 0;
	kv.f.y = 0;
	kv.s.x = 0;
	kv.s.y = 3;
	kv.t.x = 3;
	kv.t.y = 3;
	kv.fo.x = 3;
	kv.fo.y = 0;
	kv.perimeter = sqrt(pow(kv.f.x - kv.s.x, 2) + pow(kv.f.y - kv.s.y, 2)) + sqrt(pow(kv.t.x - kv.s.x, 2) + pow(kv.t.y - kv.s.y, 2)) + sqrt(pow(kv.t.x - kv.fo.x, 2) + pow(kv.t.y - kv.fo.y, 2))  + sqrt(pow(kv.f.x - kv.fo.x, 2) + pow(kv.f.y - kv.fo.y, 2));
	printf("%f\n\n", kv.perimeter);
	
	scanf("%x", &cur.num);
	cur.printer.ready == 0 ? printf("off\n"):printf("on\n");
	cur.printer.lowToner == 0 ? printf("off\n"):printf("on\n");
	cur.printer.damD == 0 ? printf("off\n"):printf("on\n");
	cur.printer.noPaper == 0 ? printf("off\n"):printf("on\n");
		
	return 0;
}
