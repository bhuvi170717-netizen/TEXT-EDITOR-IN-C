#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"

#define INITIAL_CAPACITY 10
#define MAX_LINE_LENGTH 500


void initDocument(Document *doc)
{
    // Teammate will implement
    
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
}


void insertLine(Document *doc, int position, const char *text)
{
    // Teammate will implement
     Valid insertion positions are:
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
}


int saveDocument(const Document *doc, const char *filename)
{
    // Teammate will implement
    return 0;
}


int loadDocument(Document *doc, const char *filename)
{
    // Teammate will implement
    return 0;
}


void documentStatistics(const Document *doc)
{
    // Teammate will implement
}


void showHelp(void)
{
    // Teammate will implement
}


int main(void)
{
    Document doc;

    initDocument(&doc);

    /*
        Command processing will go here.
    */

    freeDocument(&doc);

    return 0;
}