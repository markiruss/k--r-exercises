#include <stdio.h>

// Write a program detab that replaces tabs in the input with the mminumum number of tabs
// to space to the next tab stop. Assum a fixed set of tab stops, say every n columns. Should
// n be a variable or a symbolic parameter?

#define MAXLINE 1000
#define TABSIZE 8

int getline(char line[], int maxline);
int detab(char line[], char detabedLine[], int tabsize, int maxline);
int spacesToNextTabStop(int index, int tabSize);

int main()
{
    int len;
    char line[MAXLINE];
    char detabedLine[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        detab(line, detabedLine, TABSIZE, MAXLINE);
        printf("%s", detabedLine);
    }
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

int detab(char line[], char detabedLine[], int tabsize, int maxline)
{
    // Doesn't handle if the detabed array goes over the maxline very well
    // The k&R answer book suggests a simple program without storing
    // the data in an array, just straight from getchar to putchar
    int lineIndex = 0;
    int detabedLineIndex = 0;

    while (line[lineIndex] != '\0' && detabedLineIndex < maxline - 1)
    {
        if (line[lineIndex] == '\t')
        {
            int spaces = spacesToNextTabStop(detabedLineIndex, tabsize);

            for (int i = 0; i < spaces && detabedLineIndex < maxline - 1; i++)
            {
                detabedLine[detabedLineIndex] = ' ';
                detabedLineIndex++;
            }
        }
        else
        {
            detabedLine[detabedLineIndex] = line[lineIndex];
            detabedLineIndex++;
        }
        lineIndex++;
    }

    detabedLine[detabedLineIndex] = '\0';
    return detabedLineIndex;
}

int spacesToNextTabStop(int index, int tabSize)
{
    int spaceCount = 1;
    // index is 0 base
    int remainder = tabSize - 1;

    while (index % tabSize != remainder)
    {
        spaceCount++;
        index++;
    }

    return spaceCount;
}