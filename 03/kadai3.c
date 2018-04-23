#include <stdio.h>
#include <math.h>

int main(void){
  int i;
  double x0,xr,x,xx,r,k;
  double dt;
  x0=10.0;
  x=x0;
  xr=x0;
  k=100.0;
  r=1.2;
  dt=1.0;

  FILE *fp;
  fp=fopen("output3.dat","w");
  fprintf(fp,"%f %f %f\n",0.0,xr,x);

  for(i=1;i<10;i++){
    xr=k/(1+(k/x0-1)*exp(-1*r*dt*i));

    xx=x+dt*r*(1-x/k)*x;
    x=xx;

    fprintf(fp,"%f %f %f\n",dt*i,xr,x);
  }
  fclose(fp);
  return 0;
}
