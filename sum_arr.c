#include<stdio.h>

void sum_array(const int a[],const int b[], int sumab[]);

int main(){
    int x[5]={1,2,3,4,5};
    int y[5]={3,3,3,3,3};
    int sumxy[5]={0};
    //나머지 원소들은 0으로 초기화된다.
    int n= sizeof(x)/sizeof(int);
    
    sum_array(x, y, sumxy);
    int i=0;
    while(i!=5){
        printf("%d\n", sumxy[i]);
        i++;
    }
    return 0;
}

//배열 a와 b의 원소는 유지시키기 위해 const 사용
void sum_array(const int a[], const int b[], int sumab[]){
    int i = 0; 
    while(i!=5){
        sumab[i] = a[i] + b[i];
        i++;
    }
}