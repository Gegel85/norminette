/*
** EPITECH PROJECT, 2020
** norminette
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils/exceptions.h"
#include "args_management/args.h"
#include "checker/checker.h"
#include "utils/regex.h"

int main(int argc, char **argv)
{
	args_t args;

	//printf("%i\n", match_regex(argv[1], argv[2]));
	//return EXIT_SUCCESS;
	init_exceptions();

	try {
		args = parse_args(argc, argv);
		check_paths(&args, args.paths);
		free_args(&args);
	} catch (InvalidArgumentException) {
		fprintf(stderr, "Use %s -h for help.\n", argv[0]);
		return EXIT_FAILURE;
	} catch (InvalidArgumentFormatException) {
		fprintf(stderr, "%s\n", get_last_exception_desc());
		return EXIT_FAILURE;
	}
	end_try;

	free_exceptions();
}