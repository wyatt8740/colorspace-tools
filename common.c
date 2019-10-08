/**
 * some common functions used by multiple programs in this "suite."
*/

#include <common.h>

void promptCMYK(char c, char input[])
{
  input[0]='\n';
  input[1]='\0';
  while(input[0] == '\n') /* user entered nothing */
  {
    printf("Please enter a percentage for %c, range 0 to 100: ", c);
    fgets(input,20,stdin);
  }
  strtok((char*)input, "\n"); /* strip any \n */
}

int promptRGB(char c, char input[])
{ /* yucky */
  int ret=0;
  input[0]='\n';
  input[1]='\0';
  while(input[0] == '\n') /* user entered nothing */
  {
    printf("Please enter a number for %c, range 0 to 255: ", c);
    fgets(input,20,stdin);
  }
  strtok((char*)input, "\n"); /* strip any \n */
  long inTmp;
  inTmp = strtol(input,NULL,10);
  ret=(int)inTmp; /* risky */
  if(ret >= 0 && ret <= 255)
    return ret;
  else
  {
    fprintf(stderr, "Invalid input. Try again.\n");
    fprintf(stderr, "got: %d\n",ret);
    exit(1);
  }
}

int percentize(double d)
{
  return (int)round(d * 100.0);
}

int doubles_are_equal(double a, double b)
{
  return fabs(a - b) < 0.001; /* 0.001 will be a double by default I think */
}

int str2int(char *input)
{
  return strtol((char*)input, NULL, 10);
}

double str2dbl(char *input)
{
  return strtod((char*)input,NULL) / 100.0;
}

