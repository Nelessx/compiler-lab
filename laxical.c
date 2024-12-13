#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(const char *str)
{
    const char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do",
                              "double", "else", "enum", "extern", "float", "for", "goto", "if",
                              "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                              "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isValidIdentifier(const char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;
    for (int i = 1; str[i]; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    return 1;
}

int main()
{
    char input[100];

    printf("Enter an identifier: ");
    scanf("%99s", input);

    if (isKeyword(input))
    {
        printf("'%s' is a C keyword.\n", input);
    }
    else if (isdigit(input[0]))
    {
        printf("'%s' starts with a digit, so it is not a valid identifier.\n", input);
    }
    else if (isValidIdentifier(input))
    {
        printf("'%s' is a valid identifier.\n", input);
    }
    else
    {
        printf("'%s' is not a valid identifier.\n", input);
    }

    return 0;
}
