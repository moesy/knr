#include <stdio.h>
#include <error.h>

#define FAHR_MAX 400
#define FAHR_MIN -459.67
#define CEL_MAX 150
#define CEL_MIN -273.15

/*
 * cel_table - print Celsius-Farenheit table
 *
 * @lower            lower limit of the temperature table (floor is 0)
 * @upper            upper limit (ceiling is CEL_MAX)
 * @step             step size
 *
 * Print a fahr-celsius table bound by the input parameters.
 *
 */
void cel_table(int lower, int upper, int step) {

  float fahr, celsius;

  if (upper >= CEL_MAX)
    upper = CEL_MAX;

  if (lower < CEL_MIN)
    lower = CEL_MIN;

  if (step <= 0)
    error(1, 0, "step must be > 0");

  celsius = lower;

  // Print table heading
  printf("Celsius \t Farenheit\n");

  while (celsius <= upper) {
    fahr = (celsius * 9.0/5.0) + 32;
    printf("%3.0f \t\t %6.1f\n", celsius, fahr);
    celsius += step;
  }

}

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

  if (step <= 0)
    error(1, 0, "step must be > 0");

  fahr = lower;

  // Print table heading
  printf("Fahrenheit \t Celsius\n");

  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f \t\t %6.1f\n", fahr, celsius);
    fahr += step;
  }

}
