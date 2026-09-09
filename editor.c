#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"

#define INITIAL_CAPACITY 10
#define MAX_LINE_LENGTH 500

void initDocument(Document *doc)
{
    // Teammate will implement
    doc->count = 0;
    doc->capacity = INITIAL_CAPACITY;

    doc->lines = malloc(doc->capacity * sizeof(char *));

    if (doc->lines == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

void resizeDocument(Document *doc)
{
    // Teammate will implement
    doc->capacity = doc->capacity * 2;

    char **temp = realloc(doc->lines,
                          doc->capacity * sizeof(char *));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    doc->lines = temp;
}

void freeDocument(Document *doc)
{
    // Teammate will implement
    for (int i = 0; i < doc->count; i++)
    {
        free(doc->lines[i]);
    }

    free(doc->lines);

    doc->lines = NULL;
    doc->count = 0;
    doc->capacity = 0;
}

void insertLine(Document *doc, int position, const char *text)
{
    // Teammate will implement
    /* Valid insertion positions are:
        1 to count + 1

        Example:
        count = 3

        Position 1 → insert at beginning
        Position 2 → insert between lines
        Position 4 → insert at end
    */

    if (position < 1 || position > doc->count + 1)
    {
        printf("Invalid line position.\n");
        return;
    }

    /* Resize if the array is full */
    if (doc->count == doc->capacity)
    {
        resizeDocument(doc);
    }

    /*
        Shift existing pointers one position to the right.
        Start from the last element to avoid overwriting data.
    */
    for (int i = doc->count; i >= position; i--)
    {
        doc->lines[i] = doc->lines[i - 1];
    }

    /* Allocate memory for the new line */
    doc->lines[position - 1] =
        malloc((strlen(text) + 1) * sizeof(char));

    if (doc->lines[position - 1] == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    /* Copy the string */
    strcpy(doc->lines[position - 1], text);

    /* Increase number of lines */
    doc->count++;
}

void deleteLine(Document *doc, int position)
{
    // Teammate will implement
    if (!isValidLineNumber(doc, position))
    {
        printf("Invalid line position.\n");
        return;
    }

    /* Free the memory occupied by the deleted line */
    free(doc->lines[position - 1]);

    /*
        Shift all lines after the deleted line
        one position to the left.
    */
    for (int i = position - 1; i < doc->count - 1; i++)
    {
        doc->lines[i] = doc->lines[i + 1];
    }

    /* Decrease number of lines */
    doc->count--;

    /*
        We don't reduce capacity here.
        The allocated pointer array can be reused
        for future insertions.
    */
}

void displayDocument(const Document *doc)
{
    // Teammate will implement
    if (doc->count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    for (int i = 0; i < doc->count; i++)
    {
        printf("%d. %s\n", i + 1, doc->lines[i]);
    }
}

int isValidLineNumber(const Document *doc, int position)
{
    // Teammate will implement
    if (position < 1 || position > doc->count)
    {
        return 0;
    }

    return 1;
}

void searchDocument(const Document *doc, const char *word)
{
    // Teammate will implement
    int found = 0;

    for (int i = 0; i < doc->count; i++)
    {
        if (strstr(doc->lines[i], word) != NULL)
        {
            printf("Found \"%s\" in line %d: %s\n",
                   word, i + 1, doc->lines[i]);

            found = 1;
        }
    }

    if (!found)
    {
        printf("\"%s\" not found.\n", word);
    }
}

int saveDocument(const Document *doc, const char *filename)
{
    // Teammate will implement
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Unable to open file for saving.\n");
        return 0;
    }

    for (int i = 0; i < doc->count; i++)
    {
        fprintf(file, "%s\n", doc->lines[i]);
    }

    fclose(file);

    printf("Document saved successfully to %s\n", filename);

    return 1;
}

int loadDocument(Document *doc, const char *filename)
{
    // Teammate will implement
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Unable to open file for loading.\n");
        return 0;
    }

    /* Clear the current document */
    for (int i = 0; i < doc->count; i++)
    {
        free(doc->lines[i]);
    }

    doc->count = 0;

    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL)
    {
        /* Remove newline character */
        buffer[strcspn(buffer, "\r\n")] = '\0';

        /* Resize if necessary */
        if (doc->count == doc->capacity)
        {
            resizeDocument(doc);
        }

        doc->lines[doc->count] =
            malloc((strlen(buffer) + 1) * sizeof(char));

        if (doc->lines[doc->count] == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(file);
            return 0;
        }

        strcpy(doc->lines[doc->count], buffer);

        doc->count++;
    }

    fclose(file);

    printf("Document loaded successfully from %s\n", filename);

    return 1;
}

void documentStatistics(const Document *doc)
{
    // Teammate will implement
    int words = 0;
    int characters = 0;

    for (int i = 0; i < doc->count; i++)
    {
        characters += strlen(doc->lines[i]);

        int inWord = 0;

        for (int j = 0; doc->lines[i][j] != '\0'; j++)
        {
            if (doc->lines[i][j] == ' ' ||
                doc->lines[i][j] == '\t')
            {
                inWord = 0;
            }
            else if (inWord == 0)
            {
                words++;
                inWord = 1;
            }
        }
    }

    printf("Number of lines: %d\n", doc->count);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
}

void showHelp(void)
{
    // Teammate will implement
    printf("\n");
    printf("========== TEXT EDITOR HELP ==========\n");
    printf("\n");

    printf("i <position> <text>  - Insert a line\n");
    printf("d <position>         - Delete a line\n");
    printf("p                    - Display document\n");
    printf("f <word>             - Search document\n");
    printf("s <filename>         - Save document\n");
    printf("l <filename>         - Load document\n");
    printf("stats                - Show statistics\n");
    printf("h                    - Show help\n");
    printf("q                    - Quit\n");

    printf("\n");
    printf("======================================\n");
}

int main(void)
{
    Document doc;

    char command[20];
    int position;
    char text[MAX_LINE_LENGTH];
    char word[100];
    char filename[100];

    initDocument(&doc);

    printf("=====================================\n");
    printf("        SIMPLE LINE EDITOR\n");
    printf("=====================================\n");

    showHelp();

    while (1)
    {
        printf("\nEnter command: ");
        scanf("%19s", command);

        if (strcmp(command, "i") == 0)
        {
            if (scanf("%d", &position) != 1)
            {
                printf("Invalid line position. Please enter a number.\n");

                while (getchar() != '\n')
                {
                }

                continue;
            }

            getchar();

            fgets(text, MAX_LINE_LENGTH, stdin);

            text[strcspn(text, "\r\n")] = '\0';

            insertLine(&doc, position, text);
        }

        else if (strcmp(command, "d") == 0)
        {
            if (scanf("%d", &position) != 1)
            {
                printf("Invalid line position. Please enter a number.\n");

                while (getchar() != '\n')
                {
                }

                continue;
            }

            deleteLine(&doc, position);
        }

        else if (strcmp(command, "p") == 0)
        {
            displayDocument(&doc);
        }

        else if (strcmp(command, "f") == 0)
        {
            scanf("%99s", word);

            searchDocument(&doc, word);
        }

        else if (strcmp(command, "s") == 0)
        {
            getchar();

            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\r\n")] = '\0';

            if (strlen(filename) == 0)
            {
                printf("Filename cannot be empty.\n");
                continue;
            }

            saveDocument(&doc, filename);
        }

        else if (strcmp(command, "l") == 0)
        {
            getchar();

            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\r\n")] = '\0';

            if (strlen(filename) == 0)
            {
                printf("Filename cannot be empty.\n");
                continue;
            }

            loadDocument(&doc, filename);
        }

        else if (strcmp(command, "stats") == 0)
        {
            documentStatistics(&doc);
        }

        else if (strcmp(command, "h") == 0)
        {
            showHelp();
        }

        else if (strcmp(command, "q") == 0)
        {
            printf("Exiting editor...\n");
            break;
        }

        else
        {
            printf("Unknown command. Type 'h' for help.\n");
        }
    }

    freeDocument(&doc);

    return 0;
}
