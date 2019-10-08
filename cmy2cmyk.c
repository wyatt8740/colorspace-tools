#include <common.h>

int main(int argc, char **argv)
{
/*CMYK and CMY values from 0 to 1 */
  char input[20]; /* 18 chars plus newline plus \0 */
  double C;
  double M;
  double Y;
  double K;
  if(argc == 4)
  {
    C=str2int(&*argv[1]);
    M=str2int(&*argv[2]);
    Y=str2int(&*argv[3]);
  }
  else
  {
    promptCMYK('C', input);
    C = strtod((char*)input,NULL) / 100.0;
    
    promptCMYK('M', input);
    M = strtod((char*)input,NULL) / 100.0;
    
    promptCMYK('Y', input);
    Y = strtod((char*)input,NULL) / 100.0;
  }
  K=1;
  if ( C < K )
    K = C;
  if ( M < K )
    K = M;
  if ( Y < K )
    K = Y;
  if ( doubles_are_equal(K, 1.0) ) //Black
  {
    C = 0.0;
    M = 0.0;
    Y = 0.0;
  }
  else {
    C = ( C - K ) / ( 1.0 - K );
    M = ( M - K ) / ( 1.0 - K );
    Y = ( Y - K ) / ( 1.0 - K );
  }
  printf("C: %d%%\nM: %d%%\nY: %d%%\nK: %d%%\n",percentize(C),percentize(M),percentize(Y),percentize(K));
}

