#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    printf("Please, enter your name \n");
    string initials, name = get_string();
    int res = 1, itteration = 0, len = strlen(name);

    for (int i = 0; i <= len; i++)
    {
        if (isspace(name[i]))
        res++;
    }

    char result[res];
    result[0] = toupper(name[0]);
    for (int i = 0; i < len;i++)
    {
        if (isspace(name[i]))
        {
            itteration++;
            result[itteration] = toupper(name[i + 1]);
        }
    }

    initials = result;
    printf("%s \n", initials);

}