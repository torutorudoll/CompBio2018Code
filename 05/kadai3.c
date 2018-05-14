#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int r,x,i,t;
  srand(time(NULL));
  x=0;
  FILE *fp;
  fp=fopen("output_kadai3-4.dat","w");
    for(i=0;i<100;i++){
      r=rand()%2;
      if(r==0){
        x=x+1;
      }
      else{
        x=x-1;
      }
      fprintf(fp,"%d %d\n",i,x);
    }
  fclose(fp);
  return 0;
}
