#include <stdio.h>

//Function declerations
long long is_prime(long long n);
void goldbach(long long g);

int main(){
    long long number = 0;
    scanf("%lld",&number);
    number -= 3;
    goldbach(number);
    return 0;
}


//Check is prime number?
long long is_prime(long long n){
    long long flag = 1;
    if (n == 4) return 0;
    for (long long t = 2; t < n/2; t++)
    {
        
        if((n%t) == 0){
            return flag-1;
        }
    }
    return flag;
}


//Goldbach solution of a double integer greater than 2
void goldbach(long long g){
    long long i = 2;
    for (long long j = g-i; j > 1; j--)
    {
        if(is_prime(i) == 1 && is_prime(j) == 1)
        {
            printf("3 %lld %lld\n", i,j);
            break;
        }
        i++;
    }
}

