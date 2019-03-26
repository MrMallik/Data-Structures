#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countDigits(long int n){
    return (floor(log10(n))) + 1;
}

/*float myRand(){
    int x = rand();
    int dividend = pow(10, countDigits(x)+1);

    return (float)(x / dividend);
}*/

float myRand(){
    return((rand() % 1.8) + 0.1);
}

int main()
{
    int n = 5,x;
    float k;

    for(x = 1; x<=n; x++){
        printf("%f\n", myRand());
    }

    return 0;
}
