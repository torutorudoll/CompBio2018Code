#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int main(void){
  int a[N],aa[N],i,t,r1,r2,r,k,m,mm,SUM,aaa,s;
  double ave;
  srand(time(NULL));
  for(s=1;s<11;s++){
    k=s*N/10;
    mm=100;
    SUM=0;
  for(m=0;m<100;m++){
        for(i=0;i<k;i++){
          a[i]=1;
        }
        if(k!=100){
        for(i=k;i<N;i++){
          a[i]=0;
        }
        }

        for(t=0;t<1000;t++){
          aaa=0;
          for(i=0;i<N;i++){
            r1=rand()%N;
            r2=rand()%N;
            r=rand()%2;

             if(r==0){
               aa[i]=a[r1];
             }

             if(r==1){
               aa[i]=a[r2];
             }

             aaa=aaa+aa[i];
          }
          if(aaa==100){
            SUM=SUM+t;
            break;
          }

          for(i=0;i<N;i++){
            a[i]=aa[i];
          }
        }
        if(aaa!=100){
          mm=mm-1;
        }
  }
  ave=(double)SUM/((double)mm+1);
  printf("%f\n",ave);
}
  return 0;
}
