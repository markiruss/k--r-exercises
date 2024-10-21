#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Add commands for handling variables. (It's easy to provide 26 variables with
// single-letter names.) Add a variable for the most recently printed value.

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

// reverse Polish calculator
int main()
{
    int type;
    int currvar;
    double op2;
    char s[MAXOP];
    double variables[26];
    double lastresult;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;

        case '\n':
            lastresult = pop();
            printf("answer: %.8g\n", lastresult);
            break;

        case 'r':
            push(lastresult);
            break;

        case '=':
            if (isupper(currvar))
            {
                // get rid of pushed variable
                pop();
                variables[currvar - 'A'] = pop();
            }
            else
            {
                printf("error: last command is not a variable\n");
            }
            break;

        default:
            if (isupper(type))
            {
                push(variables[type - 'A']);
            }
            else
            {
                printf("error: unknown command %s\n", s);
            }
            break;
        }
        currvar = type;
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    val[sp++] = f;
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}