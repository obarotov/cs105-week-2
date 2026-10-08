#include <ctype.h>
#include <stdio.h>
#include <string.h>

int valid_key(const char key[]);
char substitute(char c, const char key[]);

int main(int argc, char *argv[])
{
    // Check the number of arguments and validate the key.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!valid_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Read the plaintext.
    char plaintext[1000];
    printf("plaintext:  ");
    scanf("%999[^\n]", plaintext);

    // Substitute and print each character.
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        printf("%c", substitute(plaintext[i], argv[1]));
    }
    printf("\n");

    return 0;
}

int valid_key(const char key[])
{
    // Check the key's length, characters, and uniqueness.
    if (strlen(key) != 26)
    {
        return 0;
    }

    int seen[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha((unsigned char) key[i]))
        {
            return 0;
        }
        int index = toupper((unsigned char) key[i]) - 'A';
        if (seen[index])
        {
            return 0;
        }
        seen[index] = 1;
    }
    return 1;
}

char substitute(char c, const char key[])
{
    // Substitute letters, preserve case, and return other characters as-is.
    if (isupper((unsigned char) c))
    {
        return toupper((unsigned char) key[c - 'A']);
    }
    if (islower((unsigned char) c))
    {
        return tolower((unsigned char) key[c - 'a']);
    }
    return c;
}