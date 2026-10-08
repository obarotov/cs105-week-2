#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(const char text[]);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    // Validate the command-line argument.
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key to an integer.
    int key = atoi(argv[1]) % 26;

    // Read the plaintext.
    char plaintext[1000];
    printf("plaintext:  ");
    scanf("%999[^\n]", plaintext);

    // Rotate and print every character.
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

int only_digits(const char text[])
{
    // Return 1 if text is non-empty and contains only digits; otherwise 0.
    if (text[0] == '\0')
    {
        return 0;
    }
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char) text[i]))
        {
            return 0;
        }
    }
    return 1;
}

char rotate(char c, int key)
{
    // Rotate letters and return non-letter characters unchanged.
    if (isupper((unsigned char) c))
    {
        return (c - 'A' + key) % 26 + 'A';
    }
    if (islower((unsigned char) c))
    {
        return (c - 'a' + key) % 26 + 'a';
    }
    return c;
}