#include <stdio.h>
void add(float, float); // function prototypes
void sub(float, float);
void mul(float, float);
void div(float, float);

int main()
{
    float a, b;
    char op;
    scanf("%f %f %c", &a, &b, &op);

    void (*operations[])(float, float)= { add, sub, mul, div }; // declaring array of function pointers
    
    switch (op) // switch case to select the required function
    {
        case '+':
            (operations[0])(a, b); // calling add function using 0th index of array of function pointers
            break;
        case '-':
            (operations[1])(a, b);
            break;
        case '*':
            (operations[2])(a, b);
            break; // break to prevent fall through
        case '/':
            (operations[3])(a, b);
            break;
    }

    return 0;
}

void add(float a, float b)
{
    printf("%.4f", a + b); // .4 denotes precision to four decimal places
}

void sub(float a, float b)
{
    printf("%.4f", a - b);
}

void mul(float a, float b)
{
    printf("%.4f", a * b);
}

void div(float a, float b)
{
    printf("%.4f", a / b);
}
