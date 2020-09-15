/*
** EPITECH PROJECT, 2020
** norminette
** File description:
** checker.h
*/

#ifndef NORMINETTE_CHECKER_H
#define NORMINETTE_CHECKER_H


#include <stdio.h>
#include "../args_management/args.h"
#include "../data/style_errors.h"

typedef struct checker_state_s {
	const args_t *args;
	char *decl_name;
	const char *decl_type;
	unsigned lines_scanned;
	unsigned mistakes_counts[NB_OF_MISTAKES];
} checker_state_t;

void check_paths(const args_t *args, char **paths);
void check_path(checker_state_t *state, const char *path);
void check_folder(checker_state_t *state, const char *path);
void check_file(checker_state_t *state, const char *path, bool force);
void check_stream(checker_state_t *state, FILE *stream);


#endif //NORMINETTE_CHECKER_H
