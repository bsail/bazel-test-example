#include "library.h"

static volatile int counter = 0;

int library_func(int a)
{
	counter += a;
	if (counter > 100)
		counter = 0;
	return counter;
}
