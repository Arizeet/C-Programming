//Armstrong Number
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int num,num1,num2,current_num,count=0,sum=0;
    system("cls");
    printf("Enter a no: ");
    scanf("%d",&num);
    num1=num;
    num2=num;
    while (num>0)
    {
        num=num/10;
        count++;
    }
    while (num1>0)
    {
        current_num=num1%10;
        sum=sum+pow(current_num,count);
        num1=num1/10;
        //printf("%d\n",sum);
    }
    if(sum==num2)
        printf("%d is an Armstrong number",num2);
    // else if (num2==153){
    //     printf("153 is an Armstrong number");}
    else
        printf("%d is not a Armstrong number",num2);
    return 0;
}