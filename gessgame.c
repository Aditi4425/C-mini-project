#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int random,gess,attempts=0;
    srand(time(NULL));
    printf("welcome to world of gaming");
    random=rand()%100;
    do
    {
        printf("\nplease enter your gess number");
        scanf("%d",&gess);
        attempts++;
        
        if(gess>random)
        {
            printf("\ngess small number ");
        }
        else if(gess<random)
        {
            printf("\ngess large number ");
        }
        else 
        {
            printf("\nCongratulations, You got success in gessing number in %d attempts",attempts);
        }
    }
    while(gess != random);
    printf("\nThanks for playing");
    printf("\nThis game is develope by Aditi");

}