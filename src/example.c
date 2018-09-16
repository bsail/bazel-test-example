#include "lib/library.h"
#include "example.h"

int example_func(void)
{
	for (int i = 0; i < 5; ++i)
		library_func(i);
	return 0;
}
