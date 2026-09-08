#ifndef EDITOR_H
#define EDITOR_H

typedef struct {
    char **lines;
    int count;
    int capacity;
} Document;


/* Document management */
void initDocument(Document *doc);
void resizeDocument(Document *doc);
void freeDocument(Document *doc);


/* Core features */
void insertLine(Document *doc, int position, const char *text);
void deleteLine(Document *doc, int position);
void displayDocument(const Document *doc);


/* Validation */
int isValidLineNumber(const Document *doc, int position);


/* Bonus features */
void searchDocument(const Document *doc, const char *word);

int saveDocument(const Document *doc, const char *filename);
int loadDocument(Document *doc, const char *filename);

void documentStatistics(const Document *doc);


/* User interface */
void showHelp(void);

#endif