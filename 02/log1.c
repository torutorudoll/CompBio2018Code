#include <stdio.h>
#include <math.h>

int main(void){
  int t;
  double r, x, xx, k;
  r=1.0;
  k=100.0;

  FILE *fp;
  fp=fopen("output17.dat", "w");

  for(r=1.0; r<3.1; r=r+0.1){
    x=1.0;
    for(t=1; t<251; t++){

      xx=x+r*(1-x/k)*x;
      x=xx;
    }
    for(t=250; t<301; t++){
      xx=x+r*(1-x/k)*x;

      fprintf(fp, "%f %f\n", r, xx);

      x=xx;

    }
  }
  fclose(fp);

  return 0;
}
