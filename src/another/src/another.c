#include "another.h"

static volatile int counter = 0;

void another_func(int a)
{
	counter += a;
	if (counter > 100)
		counter = 0;
}
