#include "myops.h"
#include <string.h>

double calculate(char* op, double a, double b) {
    printf("Calculating.....\n");
    if(strcmp(op, "+") == 0) return myadd(a, b);
    else if (strcmp(op, "-") == 0) return mysub(a, b);
    else if (strcmp(op, "*") == 0) return mymul(a, b);
    else if (strcmp(op, "/") == 0) return mydiv(a, b);
    else if (strcmp(op, "%") == 0) return mymod(a, b);
    else if (strcmp(op, "^") == 0) return mypow(a, b); 
}

int main() {
    char op[3];
    double a, b;

    printf("~~~ Welcome to my calculator  ~~~\n\n");
    printf("Enter expression(e.g., 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Result: %.2lf\n", calculate(op, a, b));
    printf("~~~ Good bye. See you again ~~~\n\n");

    return 0;
}
