/*
  Caesar.c
  
  [ENG] A program that encrypts messages using Caesar’s cipher. Program must
  accept a single command-line argument: a non-negative integer. If your program is executed without any
  command-line arguments or with more than one command-line argument, your
  program should yell at the user and return a value of 1.
  
  [RUS] Программа, которая шифрует сообщение применяя "шифр Цезаря". Программа должна принимать только один аргумент 
  командной строки: положительное целое число. Если программа запускается без аргументов командной строки или
  с более чем одним аргументом - она должна сообщить об этом пользователя и возвратить значение 1.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //Проверка аргументов
    if (!argv[1] || argv[2])
    {
    printf("Usage: ./caesar key\n");
    return 1;
    }
    //Проверка на число
    for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    //Перевод в целое число
    int key = atoi(argv[1]);
    
    //Проверка знака
    if (key < 0)
    {
    printf("Usage: ./caesar key\n");
    return 1;
    }

    //Было лень открывать ASCII и считать где какая буква, тупо подключил массивы с алфавитом.
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alphabetUp[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    //Запрашиваем ввести текст
    printf("plaintext: ");
    string plaintext = get_string();
    
    //Меняем буквы в соответствии с ключем
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        for (int i2 = 0; i2 <26; i2++)
        {
            if (plaintext[i] == alphabet[i2])
            {
            plaintext[i] = alphabet[(i2 + key) % 26];
            break;
            }
            
            if (plaintext[i] == alphabetUp[i2])
            {
            plaintext[i] = alphabetUp[(i2 + key) % 26];
            break;
            }
        }
    }
    //Результат
    printf("ciphertext: %s\n", plaintext);
}
