/*
 *
 * Data Types and Sizes
 * Exercise: 2-1
 *
 * Determine the range of char, short, int and long variables,
 * both signed and unsigned.
 */

#include <stdio.h>
#include <limits.h>

/**
 * limits_range - Print data type ranges from limits.h
 *
 * Description:
 * Print the range values of various data types as
 * declared in the standard header.
 */
void limits_range() {
  printf("---------------------------------------------------------------------------\n");
  printf("CHAR u:[%u, %u] s:[%d, %d]\n", 0, UCHAR_MAX, SCHAR_MIN, SCHAR_MAX);
  printf("SHORT u:[%u, %u] s:[%d,%d]\n", 0, USHRT_MAX, SHRT_MIN, SHRT_MAX);
  printf("INT u:[%d, %u] s:[%d, %d]\n", 0, UINT_MAX, INT_MIN, INT_MAX);
  printf("LONG u[%d, %lu] s:[%ld, %ld]\n", 0, ULONG_MAX, LONG_MIN, LONG_MAX);
}

/* signed-max - Generate maximum signed value
 * @bitwidth: size of digits in bits.
 *
 * Description:
 * For a given bitwidth generate the maximum signed value.
 */
long signed_max(int bitwidth) {
  long result;

  result = 1L << (bitwidth - 1);

  // Make space for 0
  result -= 1;

  return result;
}

/* signed-min - generate minimum signed value
 *
 * Generate the minimum signed value from a given bitwidth.
 * @bitwidth: size of digit in bits.
 *
 * Description:
 * For a given bitwidth generate the minium signed value.
 */
long signed_min(int bitwidth) {
  long result;

  // Use the bit flip technique
  result = ~signed_max(bitwidth);

  return result;
}

/**
 * range_generator - Calculate and print datatype ranges
 *
 * Use bitwise operations to calculate and print the value ranges
 * for various data types.
*/
void range_generator() {
  char charType;
  short shortType;
  int intType;
  long longType;

  int char_bitwidth = sizeof(charType) * CHAR_BIT;
  int short_bitwidth = sizeof(shortType) * CHAR_BIT;
  int int_bitwidth = sizeof(intType) * CHAR_BIT;
  int long_bitwidth = sizeof(longType) * CHAR_BIT;

  printf("---------------------------------------------------------------------------\n");
  printf("CHAR s:[%ld, %ld]\n", signed_min(char_bitwidth), signed_max(char_bitwidth));
  printf("SHORT s:[%ld, %ld]\n", signed_min(short_bitwidth), signed_max(short_bitwidth));
  printf("INT s:[%ld, %ld]\n", signed_min(int_bitwidth), signed_max(int_bitwidth));
  printf("LONG s:[%ld, %ld]\n", signed_min(long_bitwidth), signed_max(long_bitwidth));
}


int main(int argc, char *argv[])
{
  // Print from standard headers
  limits_range();

  //Print from range_generator
  range_generator();

  return 0;
}
