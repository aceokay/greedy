#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    //Defining coins to be used for calculating the number of coins
    int q = 25;
    int d = 10;
    int n = 5;

    //Get money amount from user
    float change;
    printf("Enter a dollar amount to see how few coins are needed to make that amount.\n");
    printf("$");
    change = GetFloat ();
    
    //Make sure the amount given is not negative
    while (change < 0)
    {
        printf("Whoops! I can't work with a negtive amount. Try Again.\n");
        printf("$");
        change = GetFloat ();
    }
    
    //typecasting change from a float into an integer
    int xc = round (change * 100);
    
    //This complicated code is just a series where the remainder of the coin before is used to find the number of the current coin.
    int q1 = (xc/q) - (xc % q / q);
    int d1 = (xc % q / d) - (xc % q % d / d);
    int n1 = (xc % q % d / n) - (xc % q % d % n / n);
    int p = (xc % n);
    
    //Counting the coins
    printf("%d\n", q1 + d1 + n1 + p);
    
    //if everything goes alright, return zero
    return 0;
}
