#include <common.h>

int main(int argc, char **argv)
{
/*CMYK and CMY values from 0 to 1 */
  int R;
  int G;
  int B;
  double C;
  double M;
  double Y;
  double K;
  if(argc == 4)
  {
    R=str2int(&*argv[1]);
    G=str2int(&*argv[2]);
    B=str2int(&*argv[3]);
  }
  else
  {
    char input[20]; /* 18 chars plus newline plus \0 */
    R=promptRGB('R', input); /* recycle input buffer */
    G=promptRGB('G', input);
    B=promptRGB('B', input);
  }
/* Convert RGB to CMY: */
  C = 1.0 - ( R / 255.0 );
  M = 1.0 - ( G / 255.0 );
  Y = 1.0 - ( B / 255.0 );
/* Convert CMY to CMYK: */
  K=1;
  if ( C < K )
    K = C;
  if ( M < K )
    K = M;
  if ( Y < K )
    K = Y;
  if ( doubles_are_equal(K, 1.0) ) //Pure black
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
