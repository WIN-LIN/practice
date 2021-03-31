#include <stdio.h>
#define MAX 100000

int main(void) {
  int point[MAX][2];
  for(int i = 0; i<MAX;i++){
    for(int j = 0; j<2;j++){
      point[i][j]=0;
    }
  }

  int input_count = 0;
  while(scanf("%d",&point[input_count][0])!=EOF){
    input_count++;
  }

  int flag = 0;
  int mario = 0;
  int current_max = 0; 
  int global_max = 0;
  int round = 1;
  //-1 3 -2 -3 3 2 -3 2
  while(flag == 0){
    printf("break alreay\n");
    if(mario > input_count-1){
      mario = 0;//
    }
    if(point[mario][1] < round && (current_max + point[mario][0] >= 0)){
      current_max += point[mario][0];
      point[mario][1] = round;
      mario++;
      if(global_max < current_max){
        global_max = current_max;
      }
      //printf("Round:%d 1.global_max:%d current_max:%d\n",round,global_max,current_max);
      continue;
    }
    else if(point[mario][1] < round && (current_max + point[mario][0] < 0)){
      if(current_max == 0){
        point[mario][1] = round;
        mario++;
        printf("Round:%d 2.global_max:%d current_max:%d\n",round,global_max,current_max);
      // continue;
      }
      else{
        current_max = 0;
        point[mario][1] = round;
        //printf("Round:%d 3.global_max:%d current_max:%d\n",round,global_max,current_max);
        round++;
        mario++;
      }     
    }
    else if(point[mario][1] == round){
        printf("%d",global_max);
        flag = 1;
    }
  }
  
  return 0;
}

// http://algorithm.cs.nccu.edu.tw/problem/HW1-cs
