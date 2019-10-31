#include <stdio.h>
#include "utils.h"

/* main - hello, world
 *
 * Do the standard new language test and
 * print "hello world".
 */
void main() {
  printf("hello, world\n\n");
  cel_table(20, 160, 20, print_cel_asc);
  printf("\n");
  cel_table(20, 160, 20, print_cel_desc);

}
