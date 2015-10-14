#include <stdio.h>

int main (int argc, char ** argv)
{
	struct clock {
		int i;
		struct finger {
			char name[128];
		} myfinger;
	};

	printf ("Hello world\n");

	return 0;
}
