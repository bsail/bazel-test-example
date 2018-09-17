#include "library1.h"

static volatile int counter = 0;

int library1_func(int a)
{
	counter += a;
	if (counter > 100)
		counter = 0;
	return counter;
}
