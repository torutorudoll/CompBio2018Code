#include <stdio.h>
#include <math.h>

int main(void){
  int t;
  double r, x, xx, k;
  r=0.01;
  k=300.0;
  x=10.0;

  FILE *fp;
  fp=fopen("outputr=0.01.dat", "w");
  fprintf(fp, "%d %f\n", 0, x);

  for(t=1; t<300; t++){

    xx=x+r*(1-x/k)*x;

    fprintf(fp, "%d %f\n", t, xx);
    x=xx;
  }
  fclose(fp);

  return 0;
}
