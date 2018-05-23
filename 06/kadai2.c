#include <stdio.h>

int main(void){
  int i;
  double a,b,x[3],xx[3],dt,t;
  FILE *fp;
  fp=fopen("output_kadai6_2.csv","w");
  dt=0.0001;
  x[0]=1000.0;
  x[1]=20.0;
  x[2]=0.0;
  a=0.01;
  b=5.0;
  for(i=0;i<100000;i++){
    t=dt*i;
    xx[0]=x[0]-dt*(a*x[0]*x[1]);
    xx[1]=x[1]+dt*(a*x[0]*x[1]-b*x[1]);
    xx[2]=x[2]+dt*b*x[1];

    x[0]=xx[0];
    x[1]=xx[1];
    x[2]=xx[2];
    if(i%100==0){
      fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);
    }
  }
  fclose(fp);
  return 0;
}
