#include <stdio.h>
#include <math.h>

int main(void){
  double N,T,s,p;
  N=200.0;
  FILE *fp;
  fp=fopen("output_kadai6-1.dat","w");

  for(s=1;s<1000;s++){
    p=0.001*s;
    T=(-1)*(2*N*(1-p)*log(1-p))/p;
    fprintf(fp,"%f\n",T);
  }
  fclose(fp);
  return 0;
}
