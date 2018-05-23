#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void){
  int i;
  double a,b,x[3],xx[3],dt,t,x1,x2,y1,N;
  srand(time(NULL));
  N=1;

  FILE *fp;
  fp=fopen("output_kadai6_3_2.csv","w");
  dt=0.0001;
  x[0]=100.0;
  x[1]=20.0;
  x[2]=0.0;
  a=0.01;
  b=0.3;
  t=0.0;
  fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);
  for(i=1;i<=10000;i++){
    t=dt*i;
    x1=(((double)rand()+1)/((double)RAND_MAX+1))*N;
    x2=(((double)rand()+1)/((double)RAND_MAX+1))*N;
    y1=sqrt(-2*log(x1))*cos(2*M_PI*x2);

    xx[0]=x[0]-dt*(a*x[0]*x[1]);
    xx[1]=x[1]+dt*(a*x[0]*x[1]-b*x[1]);
    xx[2]=x[2]+dt*b*x[1];

    x[0]=xx[0];
    x[1]=xx[1];
    x[2]=xx[2];
    if(i%10==0){
      fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1]+2.0*y1,x[2]);
    }
  }
  fclose(fp);
  return 0;
}
