#include <stdio.h>
#include <stdlib.h>

char resp_char(int);
void my_strrev(char*); // function prototypes
void itob(int, char*, int);

char resp_char(int n) // function that takes number and returns the char equivalent
{
    if (n >= 0 && n <= 9)
        return (char)(n + '0');
    else
        return (char)(n - 10 + 'A'); // to implement that A=10, B=11 ... Z=35
}


void my_strrev(char* str) // function to print the string in reverse order without using auxillary array
{
    int l = 0;
    while (str[l])
        ++l; // finding out length of string without using library function

    int i;
    for (i = 0; i < l / 2; i++)
    {
        char temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }
}


void itob(int n, char* p, int b)
{
    int i = 0;

    while (n > 0)
    {
        p[i] = resp_char(n % b);
        i++;
        n = n / b;
    }
    p[i] = '\0'; // appending a null character to indicate end of string

    my_strrev(p); // reversing the result string
}

int main()
{
    int num, base;
    scanf("%d %d", &num, &base);
    char* p = (char*)malloc(255); // dynamically allocating memory for the result string
    itob(num, p, base);
    printf("%s", p);
    free(p);
    return 0;
}
