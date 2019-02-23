#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Wiener.h"

/*The following code simulates a sample path of Wiener process
 * where the increments of the process have a Gaussian distribution
 * with a zero mean and and variances equal to the length of time.
 * In order to simulate the increments a pair of normally distributed
 * random numbers are generated using the Polar-Marsaglia method.*/
int main() {
    double g1, g2; //Declaration of random Gaussian variables
    const double INIT_T=0.0, END_T=40.0; //Initialize start and stop times
    const int NUM_INVS=16384; //Initialize the number of sub-intervals
    double delta, sqdelta, w_t, t; //step size, square-root of step size, value of Wiener, time
    int i=0;
    FILE *f_out1;

    f_out1 = fopen("Wiener_sample", "w+");
    delta = (END_T - INIT_T)/NUM_INVS; //Determine delta using the start and stop times and the length of intervals
    sqdelta = sqrt(delta);
    w_t = 0.0; //Initialize the Wiener value to zero
    g2 = 0.0; //Initialize the second random variable to zero
    t = INIT_T; //Initialize time to the start time
    fprintf(f_out1, "%f, %f\n", t, w_t); //Print the first value of the Wiener process to the file
    i++; //Increment i by one, now i=1
    for (i; i<=NUM_INVS; i++) {
        srand((unsigned) i+4); //Initialize the seed for the uniform random number generator, here the numeral value is arbitrary
        if (i % 2 == 1) {
            MP_PRNG(&g1, &g2); //In case i is odd, use polar-Marsaglia to generate to Gaussian random numbers
        }
        else {
            g1 = g2; //If i is even don't do anything and take g2 value as the next random number
        }
        t += delta; //Increment time
        w_t += g1*sqdelta; //Multiply the generated random number by the square root of the length of the interval to get the suitable-
        fprintf(f_out1, "%f, %f\n", t, w_t); //-Wiener increment
    }
    fclose(f_out1);
    return 0;
}
