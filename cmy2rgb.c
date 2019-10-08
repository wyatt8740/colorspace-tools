#include <common.h>

int main(int argc, char **argv)
{
  double C;
  double M;
  double Y;
  int R;
  int G;
  int B;
  if(argc==4) /* passed on CLI */
  {
    C=str2dbl(&*argv[1]);
    M=str2dbl(&*argv[2]);
    Y=str2dbl(&*argv[3]);
  }
  else
  {
/*CMYK and CMY values from 0 to 1 */
    char input[20]; /* 18 chars plus newline plus \0 */
    promptCMYK('C', input);
    C = strtod((char*)input,NULL) / 100.0;

    promptCMYK('M', input);
    M = strtod((char*)input,NULL) / 100.0;

    promptCMYK('Y', input);
    Y = strtod((char*)input,NULL) / 100.0;
  }
  R = (int)round(( 1.0 - C ) * 255.0);
  G = (int)round(( 1.0 - M ) * 255.0);
  B = (int)round(( 1.0 - Y ) * 255.0);
  printf("R: %d\nG: %d\nB: %d\n",R,G,B);
}
/*CMY values from 0 to 1
  RGB results from 0 to 255 */
