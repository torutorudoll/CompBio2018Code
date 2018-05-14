#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
  int r,M,N,x,xx,i,t;
  double ave;
  srand(time(NULL));
  M=1;
  N=6;
  xx=0;
  for(t=0;t<1000;t++){
    x=0;
    for(i=0;i<100;i++){
      r=rand()%(N-M+1)+M;
      x=x+r;
      if(x>=100){
        xx=xx+i;
        if(t==0||t==4||t==9||t==99||t==999){
              ave=(double)xx/((double)t+1.0);
              printf("%f\n",ave);
        }
        break;
      }
    }
  }
  return 0;
}
