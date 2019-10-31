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
void cel_table(int lower, int upper, int step, void(*print_fn)(const double, const double,  const int)) {

  float fahr, celsius;

  if (upper >= CEL_MAX)
    upper = CEL_MAX;

  if (lower < CEL_MIN)
    lower = CEL_MIN;

  if (step <= 0)
    error(1, 0, "step must be > 0");

  celsius = lower;

  print_fn(lower, upper, step);

}


/**
 * @brief print_cel_asc -- print celsius -> fahr table in ascending order.
 *
 * @param lower        the lower bound on the temperature table
 * @param upper        the upper bound on the temperature table
 * @param step         amount in celsius to increment in each row by
 *
 * Print the celsius to fahr table in ascending order. The results are casted
 * into floats.
 */
void print_cel_asc(const double lower, const double upper, const int  step) {
  double celsius = lower;
  double fahr;

  printf("Celsius \t Farenheit (asc)\n");

  for (; celsius <= upper; celsius += step) {
    fahr = (celsius * 9.0/5.0) + 32;
    printf("%3.0f \t\t %6.1f\n", celsius, fahr);
  }

}

/**
 * @brief print_cel_desc -- print celsius -> fahr table in descending order.
 *
 * @param lower        the lower bound on the temperature table
 * @param upper        the upper bound on the temperature table
 * @param step         amount in celsius to decrement in each row by
 *
 * Print the celsius to fahr table in descending order. The results are casted
 * into floats.
 */
void print_cel_desc(const double lower, const double upper, const int  step) {
  double celsius = upper;
  double fahr;

  printf("Celsius \t Farenheit\n");

  for (; celsius >= lower; celsius -= step) {
    fahr = (celsius * 9.0/5.0) + 32;
    printf("%3.0f \t\t %6.1f\n", celsius, fahr);
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
