#include "lib/inc/library.h"
#include "another/inc/another.h"
#include "example.h"

int example_func(void)
{
	another_func(55);
	for (int i = 0; i < 5; ++i)
		library_func(i);
	return 0;
}
