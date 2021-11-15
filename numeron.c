#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(int argc,char*argv[])
{
  int ques,ans,keta,suu,i=0;
  srand((unsigned int)time(NULL));
  //数字設定
  while(i==0){
    ques=rand()%(999-100+1)+100;
    if(ques/10-ques/100*10==ques-ques/10*10||ques/100==ques/10-ques/100*10||ques/100==ques-ques/10*10){i=0;}
    else{i=1;}
  }

  //printf("%d\n",ques);

  printf("3桁の数を入力してください（同じ数字は使えません）：");
  i=0;
  while(1){
    i++;
    keta=0;
    suu=0;
    scanf("%d",&ans);
    if(ans==0){printf("%d\n",ques);}
  //100-100
    if(ques/100==ans/100){keta++;}
  //10-10
    if(ques/10-ques/100*10==ans/10-ans/100*10){keta++;}
  //1-1
    if(ques-ques/10*10==ans-ans/10*10){keta++;}

    if(keta==3){
      printf("\n%d回目で当たり！！\n\n",i);
      break;
    }
  //100-10.1
    if(ques/100==ans/10-ans/100*10||ques/100==ans-ans/10*10){suu++;}
  //10-100.1
    if(ques/10-ques/100*10==ans/100||ques/10-ques/100*10==ans-ans/10*10){suu++;}
  //1-100.10
    if(ques-ques/10*10==ans/100||ques-ques/10*10==ans/10-ans/100*10){suu++;}
    printf("%dつの桁と数字が一致。残りの%dつの数字のうち、%dつの数字が一致\n\nもう一度：",keta,3-keta,suu);
  }
  return 0;
}
