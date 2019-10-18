#include <stdio.h>

#define FAHR_MAX 400
#define FAHR_MIN -459.67

/*
 * fahr_table - print Farenheit-Celsius table
 *
 * @lower            lower limit of the temperature table (floor is 0)
 * @upper            upper limit (ceiling is FAHR_MAX)
 * @step             step size
 *
 * Print a fahr-celsius table bound by the input parameters.
 *
 */
void fahr_table(int lower, int upper, int step) {

  float fahr, celsius;

  if (upper >= FAHR_MAX)
    upper = FAHR_MAX;

  if (lower < FAHR_MIN)
    lower = FAHR_MIN;

  fahr = lower;

  // Print table heading
  printf("Fahrenheit \t Celsius\n");

  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f \t\t %6.1f\n", fahr, celsius);
    fahr += step;
  }

}
