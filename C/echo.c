/* echo.c - minimalist implementation of echo (1).
 *
 * NAME
 *     echo – write arguments to the standard output
 *
 * SYNOPSIS
 *     echo [-n] [string ...]
 * 
 * DESCRIPTION
 *     The echo utility writes any specified operands, separated by single blank
 *     characters and followed by a newline (‘\n’) character, to the standard
 *     output.
 *
 *     The following option is available:
 *
 *     -n    Do not print the trailing newline character.
 *
 * LICENSE
 *     GPL 3.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int opt_n = !--argc || !strncmp(argv[1], "-n", 2);

  if (opt_n)
    argc--, argv++;

  if (argc > 0) {
    for (int i = 1; i < argc; i++)
      printf("%s ", argv[i]);
    printf("%s", argv[argc]);
  }

  if (!opt_n)
    putchar('\n');

  return EXIT_SUCCESS;
}
