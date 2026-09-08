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
}


void freeDocument(Document *doc)
{
    // Teammate will implement
}


void insertLine(Document *doc, int position, const char *text)
{
    // Teammate will implement
}


void deleteLine(Document *doc, int position)
{
    // Teammate will implement
}


void displayDocument(const Document *doc)
{
    // Teammate will implement
}


int isValidLineNumber(const Document *doc, int position)
{
    // Teammate will implement
    return 0;
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