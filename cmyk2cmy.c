#include <common.h>

int main(int argc, char **argv)
{
/*CMYK and CMY values from 0 to 1 */
  char input[20]; /* 18 chars plus newline plus \0 */
  double C;
  double M;
  double Y;
  double K;
  if(argc == 5)
  {
    C=str2int(&*argv[1]);
    M=str2int(&*argv[2]);
    Y=str2int(&*argv[3]);
    K=str2int(&*argv[4]);
  }
  else
  {
    promptCMYK('C', input);
    C = strtod((char*)input,NULL);

    promptCMYK('M', input);
    M = strtod((char*)input,NULL);

    promptCMYK('Y', input);
    Y = strtod((char*)input,NULL);

    promptCMYK('K', input);
    K = strtod((char*)input,NULL);
  }
  C = ( C * ( 1.0 - K ) + K );
  M = ( M * ( 1.0 - K ) + K );
  Y = ( Y * ( 1.0 - K ) + K );
  
  printf("C: %d%%\nM: %d%%\nY: %d%%\n",percentize(C),percentize(M),percentize(Y));
}
