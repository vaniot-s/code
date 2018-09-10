//
// Created by vaniot on 18-9-9.
//

#include <stdio.h>
int main(){
    int i,j,t,e,d,count;
     count=0;
    int arr[10];
    while(count!=10){
        printf("请输入一个数：");
        scanf("%d\n",&d);
        if (d>0){
            arr[count++]=d;
            printf("\n");
        }
    }
    for (j=1;j<=9;j++ ) {
        for (i = 1; i <= 10 - j; i++)
            if (arr[i] > arr[i + 1]) {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i++] = t;
            }
            printf("这串输入的数组为：");
    }
    for (i=10; i <11 ; i--) {
        printf("%d",arr[i]);
    }
}