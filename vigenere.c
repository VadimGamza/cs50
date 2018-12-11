#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //Key checking (1 argument, characters only )
    if (argc != 2)
    {
    printf("Usage: ./viginere key\n");
    return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./viginere key\n");
                return 1;
            }
        }

string key = argv[1];
int ikey[strlen(key)];

// Uppercase
for (int i = 0, n = strlen(key); i < n; i++)
{
    key[i] = toupper(key[i]);
}

//Converting key into array of integers, numbering from 0 to 25
for (int i = 0, n = strlen(key); i < n; i++)
{
    ikey[i] = (int)key[i] - 65;
}

//Asking for a plaintext
    printf("plaintext: ");
    string plaintext = get_string();

//Cycle of shifts
    for (int i = 0, n = strlen(plaintext), ik = 0; i < n; i++)
    {

        if isupper(plaintext[i])
        {
            plaintext[i] = ((((plaintext[i] - 65) + ikey[ik]) % 26) + 65);
        }
        else if islower(plaintext[i])

        {
            plaintext[i] = ((((plaintext[i] - 97) + ikey[ik]) % 26) + 97);
        }
        //Taking next part of key if it is not a space
        if (isalpha(plaintext[i]))
        ik = (ik + 1) % strlen(key);
    }



//printing result
    printf("ciphertext: %s\n", plaintext);

}