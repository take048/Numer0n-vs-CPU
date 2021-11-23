#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(int argc,char*argv[])
{
  int ques;//答え
  int ans;//プレイヤーの回答
  int keta,suu,i=0;
  srand((unsigned int)time(NULL));//ランダム生成の準備

  while(i==0){//答えの生成
    ques=rand()%(999-100+1)+100;//３桁の数字をランダム生成
    //百の位と十の位と一の位がそれぞれ違う数字かを判定
    //同じ数字が含まれている時もう一度ランダム生成
    if(ques/10-ques/100*10==ques-ques/10*10
      ||ques/100==ques/10-ques/100*10
      ||ques/100==ques-ques/10*10){i=0;}
    else{i=1;}
  }

  printf("3桁の数を入力してください（同じ数字は使えません）：");
  i=0;
  while(1){//正答できるまでループ
    i++;//解答回数として加算
    keta=0;//桁と数字が一致している数
    suu=0;//数字だけが一致している数
    scanf("%d",&ans);//入力の取得
    if(ans==0){printf("%d\n",ques);}//0が入力されたとき答えの表示

    //入力した数に同じ数字字が含まれている時、もう一度入力させる
    if(ans/100==ans/10-ans/100*10
      ||ans/100==ans-ans/10*10
      ||ans/10-ans/100*10==ans-ans/10*10){
        printf("入力が間違えています\n\nもう一度：");
        i--;
        continue;
      }

    //百の位の数字が一致しているとき加算
    if(ques/100==ans/100){keta++;}
    //十の位の数字が一致しているとき加算
    if(ques/10-ques/100*10==ans/10-ans/100*10){keta++;}
    //一の位の数字が一致しているとき加算
    if(ques-ques/10*10==ans-ans/10*10){keta++;}

    if(keta==3){//桁と数字が一致している数が3の時、答えと回答が同じなのでループ終了
      printf("\n%d回目で当たり！！\n\n",i);//正答までの回答回数を表示
      break;
    }

    //答えの百の位と、回答の十、一の位の数字が一致しているとき加算
    if(ques/100==ans/10-ans/100*10||ques/100==ans-ans/10*10){suu++;}
    //答えの十の位と、回答の百、一の位の数字が一致しているとき加算
    if(ques/10-ques/100*10==ans/100||ques/10-ques/100*10==ans-ans/10*10){suu++;}
    //答えの一の位と、回答の百、十の位の数字が一致しているとき加算
    if(ques-ques/10*10==ans/100||ques-ques/10*10==ans/10-ans/100*10){suu++;}

    //ヒントの表示
    printf("%dつの桁と数字が一致。残りの%dつの数字のうち、%dつの数字が一致\n\nもう一度：",keta,3-keta,suu);
  }
  return 0;
}
