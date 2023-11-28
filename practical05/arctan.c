#include<stdio.h> 
#include<math.h>

//Function prototype for Maclaurin series approximation

double arctanh1 (const double x, const double delta);

/* Function prototype for formula*/
double arctanh2 (const double x) ;

int main() {

    double delta, x;
    printf ("Enter the precision for the Maclaurin series: \n"); 
    scanf ("%lf", &delta);

    int length=1000;
    double tan1 [length]; /*storing the reult of arctan1 */
    double tan2[length]; /*storing the reult of arctan2*/

    int j=0; /*j: array index */
    x=-0.9;
    while (x<=0.9 && j< length){
        tan1 [j]=arctanh1 (x, delta);
        tan2 [j]=arctanh2 (x);
        printf ("The difference at x=%lf between them is %.101f. \n", x, fabs (tan1 [j]-tan2 [j]));
        j++;
        x=x+0.01; 
    }

    return 0;
}

/* Maclaurin series approximation of arctanh()*/
double arctanh1 (const double x, const double delta) {
double arcTan=0; /*approximation */
double elem, val; /*element in the series */
int n=0; /*sum parameter*/

do {
    val=2*n+1;
    elem=pow(x, val)/val;
    arcTan += elem;
    n++;
    } while (fabs (elem)>=delta); /* Loop until the desired precision is reached*/

return arcTan;
}

/* Direct formula for the archtanh() - natural logarithm*/
double arctanh2 (const double x) {
     return (log(1+x) - log(1-x))/2;
}

