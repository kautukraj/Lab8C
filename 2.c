#include <stdio.h>
#include <stdlib.h>

int strend(char*, char*); // function prototypes
int my_strlen(char*);

int main()
{
    char* s = (char*)(malloc(256 * sizeof(char))); // dynamic memory allocation using malloc
    char* t = (char*)(malloc(256 * sizeof(char)));
    scanf("%[^' '] %s", s, t);
    int f = strend(s, t); // calling the function strend

    if (f == 1)
        printf("%s", t);
    else
        printf("0");

    free(t); // freeing up the space allocated to t
    return 0;
}

int strend(char* s, char* t)
{
    int l_search = my_strlen(t);
    int l_str = my_strlen(s);
    char* tmp = (char*)(malloc(l_search)); // creating a temporary variable
    int i = 0, c = 0;
    for (i = l_str - l_search; i < l_str; i++)
    {
        tmp[c] = s[i];
        c++;
    }
    int flag = 1;
    int j = 0;
    while (*(t + j) != '\0' || *(tmp + j) != '\0') /* till we reach the end of the string */
    {
        if (*(t + j) != *(tmp + j)) /* checking if each char position element is equal or not */
        {
            flag = 0;
            break;
        }
        j++;
    }
    free(tmp);
    free(s);
    return (flag);
}

int my_strlen(char* p) /* implementing a function to find the length of string passed into it */
{
    int l = 0;
    while (p[l])
        ++l;
    return l; /* returning length */
}
