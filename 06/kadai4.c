#include <stdio.h>
#include <math.h>

int main(void){
  int i,n,j;
  double sumA,sumB,sumAA,sumBB,x,xx;
  double t[1001],S[1001],I[1001],R[1001];
  double r;
  int ret;

  FILE *fp;

  fp=fopen("output_kadai6_3_2.csv","r");
  i=0;
  while((ret=fscanf(fp,"%lf,%lf,%lf,%lf",&t[i],&S[i],&I[i],&R[i]))!=EOF){
    i++;
  }
  fclose(fp);

  x=10.0;
  for(i=0;i<10000;i++){
    sumA=0.0;
    sumB=0.0;

    for(j=0;j<50;j++){
      sumAA=sumA+(I[j]-I[0]*exp(x*t[j]))*I[0]*t[j]*exp(x*t[j]);
      sumBB=sumB+(I[j]-2.0*I[0]*exp(x*t[j]))*I[0]*(t[j])*(t[j])*exp(x*t[j]);
      sumA=sumAA;
      sumB=sumBB;
    }

    xx=x-(sumA)/(sumB);
    if(xx==x){
      printf("%f\n",xx);
      break;
    }
    x=xx;
  }
  return 0;
}
