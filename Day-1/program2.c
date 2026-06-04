#include<stdio.h>
int main(){
    int num;
    printf("Enter a number by which you want to create a multiplication table= ");
    scanf("%d",&num);
    printf("here is your table of %d/n",num);
    for(int i=1; i<=10; i++)
     {
        printf("%dx%d =%d\n",num,i,num * i);
    }

    return 0;
}