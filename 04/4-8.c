#include <stdio.h>

int main(void){
  int i,j,k;
  double t,dt;
  double x[2];
  double xx[2];
  double a,b,c,d,e,f;

  FILE *fp;
  fp=fopen("output_4-8.csv","w");

  dt=0.0001;
  a=2.0;
  b=1.0;
  c=1.0;
  d=2.0;
  e=3.0;
  f=3.0;

  t=0.0;
  x[0]=0.01;
  x[1]=0.01;
  fprintf(fp,"%f, %f, %f\n",t,x[0],x[1]);
  for(i=1;i<=1000000;i++){
    t=dt*i;
    xx[0]=x[0]+dt*(a-b*x[0]+c*x[1])*x[0];
    xx[1]=x[1]+dt*(d+e*x[0]-f*x[1])*x[1];
    x[0]=xx[0];
    x[1]=xx[1];

    if(i%100==0){
      fprintf(fp,"%f, %f, %f\n",t,x[0],x[1]);
    }
  }

  fclose(fp);
  return 0;
}
