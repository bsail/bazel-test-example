#include "library.h"

static volatile int counter = 0;

void library_func(int a)
{
	counter += a;
	if (counter > 100)
		counter = 0;
}
