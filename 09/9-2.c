#include <stdio.h>

int rule(int cell1,int cell2, int cell3, int cell4, int cell5, int cell6, int cell7, int cell8, int cell9);

int main(void){
  int t,i,j;
  int cell[100][100];
  int tempcell[100][100];

  FILE *fp;
  fp=fopen("CGL2.csv","w");

  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      cell[i][j]=0;
      tempcell[i][j]=0;
    }
  }
    //固定物体
    cell[2][2]=1;
    cell[2][3]=1;
    cell[3][2]=1;
    cell[3][3]=1;
    //振動子
    cell[2][50]=1;
    cell[2][51]=1;
    cell[2][52]=1;
    //移動物体
    cell[10][11]=1;
    cell[11][12]=1;
    cell[12][10]=1;
    cell[12][11]=1;
    cell[12][12]=1;
    //puffer
    cell[50][53]=1;
    cell[50][55]=1;
    cell[51][52]=1;
    cell[52][53]=1;
    cell[52][56]=1;
    cell[53][55]=1;
    cell[53][56]=1;
    cell[53][57]=1;
    cell[54][78]=1;
    cell[54][79]=1;
    cell[55][78]=1;
    cell[55][79]=1;

    for(i=0;i<100;i++){
      for(j=0;j<100;j++){
        fprintf(fp,"%d",cell[i][j]);
        if(j!=99){
          fprintf(fp,",");
        }
        if(j==99){
          fprintf(fp,"\n");
        }
      }
    }
      fprintf(fp,"\n");

      for(t=1;t<100;t++){
        for(i=0;i<100;i++){
          tempcell[i][0]=0;
          tempcell[i][99]=0;
          }
          for(j=0;j<100;j++){
            tempcell[0][j]=0;
            tempcell[99][j]=0;
          }
        for(i=1;i<99;i++){
          for(j=1;j<99;j++){
            tempcell[i][j]=rule(cell[i-1][j-1],cell[i-1][j],cell[i-1][j+1],cell[i][j-1],cell[i][j+1],cell[i+1][j-1],cell[i+1][j],cell[i+1][j+1],cell[i][j]);
          }
        }
        for(i=0;i<100;i++){
          for(j=0;j<100;j++){
            cell[i][j]=tempcell[i][j];
            fprintf(fp,"%d",cell[i][j]);
            if(j!=99){
              fprintf(fp,",");
            }
            if(j==99){
              fprintf(fp,"\n");
            }
          }
        }
        fprintf(fp,"\n");
      }
      fclose(fp);
      return 0;
    }

    int rule(int cell1,int cell2, int cell3, int cell4, int cell5, int cell6, int cell7, int cell8, int cell9){
      int sum;
      sum=cell1+cell2+cell3+cell4+cell5+cell6+cell7+cell8;
      if(sum==3){
        return 1;
      }
      if(sum==2){
        return cell9;
      }
      if(sum<=1){
        return 0;
      }
      if(sum>=4){
        return 0;
      }
      return -1;
    }
