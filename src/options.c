#include "bastion-timer.h"
#include <argp.h>

const struct argp_option difficulties[] = {
	{	
		.name = 0x0,
		.key = 'n',
		.arg = 0x0,
		.flags = 0,
		.doc = "normal difficulty"
	},
	{
		.name = 0x0,
		.key = 'a',
		.arg = 0x0,
		.flags = 0,
		.doc = "advanced difficulty (default)"
	},
	{
		.name = 0x0,
		.key = 'e',
		.arg = 0x0,
		.flags = 0,
		.doc = "elite difficulty"
	},
	{
		.name = "diff",
		.key = 'd',
		.arg = "seconds",
		.flags = 0,
		.doc = "custom difficulty"
	},
	{ 0 }
};

int check_seconds(const char *string, int *output)
{
	int to_ret;
	char *tail = 0x0;

	to_ret = (int) strtol(string, &tail, 10);
	if (to_ret > 0 && !*tail) {
		printf("Set new seconds to %d\n", to_ret);
		*output = to_ret;
		return 0;
	} else {
		return -1;
	}
}

error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	int *interval = (int *) state->input;
	switch (key) {
		case 'n':
		case 'a':
			*interval = 10;
			break;
		case 'e':
			*interval = 8;
			break;
		case ARGP_KEY_ARG:
			if (state->arg_num >= 2) {
				argp_usage(state);
			}
			break;
		case 'd':
			if (check_seconds(arg, interval)) {
				argp_error(state, "Invalid argument '%s'. "
						"Must be a positive non-zero " "value.", arg);
			}
			break;
		case ARGP_KEY_END:
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}

	return 0;
}

const struct argp diffs = {
	.options = difficulties,
	.parser = parse_opt,
	.args_doc = 0x0,
	.doc = "Gives a timer for kraken bastion."
	" Arguments must be a positive non-zero value"
};