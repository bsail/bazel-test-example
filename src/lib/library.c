#include "library.h"

static volatile int counter = 0;

int library_func(void)
{
	counter++;
	if(counter>100)
		counter = 0;
	return 0;
}
