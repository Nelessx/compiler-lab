#include <stdio.h>
#include <string.h>

void identifyComments(const char *code)
{
    int inSingleLineComment = 0, inMultiLineComment = 0;

    for (int i = 0; code[i] != '\0'; i++)
    {
        if (inSingleLineComment && code[i] == '\n')
        {
            inSingleLineComment = 0;
        }
        else if (inMultiLineComment && code[i] == '*' && code[i + 1] == '/')
        {
            inMultiLineComment = 0;
            i++;
        }
        else if (!inSingleLineComment && !inMultiLineComment)
        {
            if (code[i] == '/' && code[i + 1] == '/')
            {
                inSingleLineComment = 1;
                printf("Single-line comment: //");
                i++;
            }
            else if (code[i] == '/' && code[i + 1] == '*')
            {
                inMultiLineComment = 1;
                printf("Multi-line comment: /*");
                i++;
            }
        }

        if (inSingleLineComment || inMultiLineComment)
        {
            putchar(code[i]);
        }
    }

    printf("\n");
}

int main()
{
    char code[1024];
    printf("Enter code (end with an empty line):\n");

    char line[256];
    code[0] = '\0';

    while (fgets(line, sizeof(line), stdin) && strcmp(line, "\n") != 0)
    {
        strcat(code, line);
    }

    identifyComments(code);

    return 0;
}
