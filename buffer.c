#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct
{
    char data[BUFFER_SIZE];
    int start, end;
} InputBuffer;

void initBuffer(InputBuffer *buffer)
{
    buffer->start = buffer->end = 0;
}

void addToBuffer(InputBuffer *buffer, char c)
{
    if ((buffer->end + 1) % BUFFER_SIZE == buffer->start)
    {
        printf("Buffer overflow!\n");
        return;
    }
    buffer->data[buffer->end] = c;
    buffer->end = (buffer->end + 1) % BUFFER_SIZE;
}

char removeFromBuffer(InputBuffer *buffer)
{
    if (buffer->start == buffer->end)
        return '\0';
    char c = buffer->data[buffer->start];
    buffer->start = (buffer->start + 1) % BUFFER_SIZE;
    return c;
}

int main()
{
    InputBuffer buffer;
    initBuffer(&buffer);

    char input[BUFFER_SIZE];
    printf("Enter text (type 'exit' to stop):\n");

    while (1)
    {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0)
            break;
        for (int i = 0; input[i]; i++)
            addToBuffer(&buffer, input[i]);
    }

    printf("Buffer contents:\n");
    for (char c; (c = removeFromBuffer(&buffer)) != '\0';)
        printf("%c", c);
    printf("\n");

    return 0;
}
