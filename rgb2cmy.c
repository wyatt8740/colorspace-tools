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
  if(argc==4)
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
  C = 1.0 - ( R / 255.0 );
  M = 1.0 - ( G / 255.0 );
  Y = 1.0 - ( B / 255.0 );
  
  printf("C: %d%%\nM: %d%%\nY: %d%%\n",percentize(C),percentize(M),percentize(Y));
}
