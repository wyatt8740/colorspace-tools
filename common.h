/**
 * some common functions used by multiple programs in this "suite."
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <limits.h>


void promptCMYK(char c, char input[]);
int promptRGB(char c, char input[]);
int percentize(double d);
int doubles_are_equal(double a, double b);
double str2dbl(char *input);
int str2int(char *input);
