/*Find e using Taylor series expansion for e^x*/

#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>

/*Calculate Factorial*/
int factorial (int n);

int main (void) {
    int i, order;
    double e, *terms;

/*Enter Polynomial Order*/
    printf("Enter the required polynomial order\n");
    if(scanf ("%d" , &order) !=1){
    printf ("Didn't ernter a number\n");
    return 1;
    }

/*Allocate space depending on n*/
terms = malloc(order*sizeof (double));
for (i=0; i<order; i++){
    terms [1]=1.0/(double) factorial (i+1);
    printf ("e term for order %d is %1.14lf \n", i+1, terms[i]);
}

e=1.0;

/* Sum up the terms to estimate e*/
for (i=0; i<order; i++){
    e=e+terms [i];
}
/* Free allocated memory*/
    free (terms);
    /* Print the estimated value of e and the difference from the true value*/
    printf("e is estimated as %.10lf, with difference %e\n", e, e-exp (1.0));
return 0;
}

/* Function to calculate factorial*/
int factorial (int n){
    /* We check for a negative number*/
    if (n<0) {
    printf ("Error: Negative number passed to factorial. \n");
    return (-1);
    }
    else if (n==0) {return 1;}
    /* Base case: factorial of 0 is 1*/
    else {return (n*factorial (n-1));}
    /* Recursive case: n! = n * (n-1)!*/
}


