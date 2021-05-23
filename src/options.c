#include "bastion-timer.h"

int options_parse(int argc, char **argv)
{
	int c = 0;
	int interval = 10;
	opterr = 0;

	while ((c = getopt(argc, argv, "nae")) != -1) {
		if (optind > 2) {
			printf("Ignoring other options...\n");
			break;
		}
		switch (c) {
			case 'e':
				interval = 8;
				break;
			case 'n':
			case 'a':
				interval = 10;
				break;
			default:
			case '?':
				interval = -1;
				break;
		}
	}

	if (interval > 0) {
		printf("Interval is %d seconds\n", interval);
	}

	return interval;
}