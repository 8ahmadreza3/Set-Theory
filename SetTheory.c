#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char remove_set(char member[10][50] , int s )
{
  int n = 50 ;
  for(int i=0 ; i<n+1 ; i++){
    for(int j=i+1 ; j<n ; j++){
      if(member[s][i]==member[s][j]){
        for(int k=j ; k<n ; k++){
          member[s][k]=member[s][k+1];
        }
        j--;
        n--;
      }
    }
  }
  return ;
}

char Joda(char a[50],int line ,char member[10][50],char name[10][5])
{
  const char x[3] = "={" , z[2]="}"   ;
  char *token , *temp , *emt ;
  char emp[5] , cst[50] ;
  token = strtok(a, x);
  strcpy(emp , token);
  for(int z=0 ; emp[z]!='\0' ; z++){
    name[line][z]=emp[z];
  }
  temp = strtok('\0', x);
  emt=strtok(temp , z);
  strcpy(cst , emt);
  for(int k=0 ; cst[k]!='\0' ; k++){
    member[line][k]=cst[k];
  }
  char tst[50];
  for(int c=0 , x=0 ; c<50 ; c++){
    if(member[line][c]!=','){
      tst[x]=member[line][c];
      x++;
    }
  }
  for(int p=0 ; p<80 ; p++){
    member[line][p]=tst[p];
  }
  return ;
}

char Universal( char umember[10][50], char u[200])
{
  for(int i=0 , x=0 ; i<20 ; i++){
    for(int j=0 ; umember[i][j]!=NULL ; j++){
      if(umember[i][j]=='^'){
        continue ;
      }
      for(int k=0 ; k<20 ; k++){
        for(int z=0 ; umember[k][z]!=NULL ; z++){
          if(umember[k][z]=='^'){
            continue ;
          }
          u[x]=umember[i][j];
          x++;
          if(umember[i][j]==umember[k][z]){
            umember[k][z]='^';
          }
        }
      }
    }
  }
  return ;
}

char print(char set[200])
{
  printf("\n={%c" , set[0]);
  for(int i=1 ; set[i]!='\0' ; i++){
    printf(",%c", set[i]);
  }
  printf("}\n");
  return ;
}

char printset(char member[10][50] , int s)
{
  printf("\n={%c" , member[s][0]);
  for(int i=1 ; member[s][i]!='\0' ; i++){
    printf(",%c", member[s][i]);
  }
  printf("}\n");
  return ;
}

char find1(char name[10][5] , char a[50] , const char c[2])
{
  char* token ;
  char set[5];
  int x , s1=-1;
  token= strtok(a , c);
  strcpy(set , token);
  for(int y=0 ; y<20 ; y++){
    x=0;
    for(int g=0 ; name[y][g]!='\0' ;g++){
      if(name[y][g]==set[g]){
        x++;
      }
      if(x==strlen(a)){
        s1=y;
        break;
      }
    }
  }
  if(s1==-1){
    printf("Not defined");
  }
  return s1;
}

char find2(char name[10][5] , char a[50] , const char c[2])
{
  char* token2;
  char set[5];
  int x , s2=-1;
  token2=strtok( a , c );
  token2=strtok(NULL , c);
  strcpy(set , token2);
  for(int y=0 ; y<20 ; y++){
    x=0;
    for(int g=0 ; name[y][g]!='\0' ;g++){
      if(name[y][g]==set[g]){
        x++;
      }
      if(x==strlen(a)){
        s2=y;
        break;
      }
    }
  }
  if(s2==-1){
    printf("Not defined");
  }
  return s2;
}

char ejtema(char member[10][50], int s1 , int s2)
{
  char res[200];
  for(int i=0 ; member[s1][i]!=NULL ; i++){
    res[i]=member[s1][i];
  }
  for(int j=(strlen(res)-1); j<200 ; j++){
    res[j]=member[s2][j];
  }
  remove_set(res , 0 );
  print(res);
  return ;
}

char eshterak(char member[10][50], int s1 , int s2)
{
  char res[200];
  for(int i=0 , x=0 ; member[s1][i]!='\0' ; i++){
    for(int j=0 ; member[s2][j]!='\0' ; j++){
      if(member[s1][i]==member[s2][j]){
        res[x]=member[s2][j];
        ++x;
      }
    }
  }
  print(res);
  return ;
}

char Motammem(char u[200] ,char member[10][50], int s2)
{
  char res[200];
  int flag=0;
  for(int r=0 , x=0 ; u[r]!=NULL ; r++){
    for(int b=0 ; member[s2][b]!=NULL ; b++){
      if(u[r]==member[s2][b]){
        ++flag;
      }
    }
    if(flag==0){
      res[x]=member[s2][r];
      ++x;
    }
  }
  print(res);
  return ;
}
