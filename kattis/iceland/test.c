
#include <stdio.h>

//Function declerations
int is_prime(int n);
void goldbach(int g);

int main(){
    int number = 0;
    while(1){
        printf("Enter even number:");
        scanf("%d",&number);
        if(number>2 && number%2==0){
            goldbach(number);
        }
        else{
            printf("Incorrect number!\n");
        }
        printf("\n");
    }
    return 0;
}


//Check is prime number?
int is_prime(int n){
    int flag = 1;
    for (int j = 2; j < n/2; j++)
    {
        if((n%j) == 0){
            return flag-1;
        }
    }
    return flag;
}


//Goldbach solution of a double integer greater than 2
void goldbach(int g){
    int i = 2;

    for (int j = g-i; j > 2; j--)
    {
        if(is_prime(i) == 1 && is_prime(j) == 1)
        {
            printf("%d = %d + %d\n",g,i,j);
            break;
        }
        i++;
    }
}

