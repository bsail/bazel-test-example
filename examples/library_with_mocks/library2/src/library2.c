#include "library2.h"
#include "library1.h"

static volatile int counter = 0;

int library2_func(int a)
{
	library1_func(0);
	counter += a;
	if (counter > 100)
		counter = 0;
	return counter;
}
