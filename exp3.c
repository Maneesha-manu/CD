#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 100

enum TokenType {
    NUMBER,
    ID,
    KEYWORD,
    SYMBOL,
    OPERATOR,
    ERROR,
};

const char *TokenTypeStrings[] = {
    "NUMBER",
    "ID",
    "KEYWORD",
    "SYMBOL",
    "OPERATOR",
    "ERROR",
};

struct Token {
    enum TokenType type;
    char value[MAX_TOKEN_LEN];
};

int isKeyword(const char *str) {
    static const char *keywords[] = {
        "auto","break","case","char","const","continue","default","do",
        "double","else","enum","extern","float","for","goto","if",
        "int","long","register","return","short","signed","sizeof",
        "static","struct","switch","typedef","union","unsigned","void",
        "volatile","while"
    };
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

struct Token getNextToken(const char *input, int *start) {
    int len = strlen(input);
    int lineIndex = 0;
    char c = input[*start];
    while (*start < len) {
        if (isspace(c)) {
            (*start)++;
            c = input[*start];
            continue;
        }
        if (isdigit(c)) {
            struct Token t = {NUMBER, ""};
            do {
                t.value[lineIndex++] = c;
                (*start)++;
                c = input[*start];
            } while (isdigit(c));
            return t;
        }
        if (isalpha(c)) {
            struct Token t = {ID, ""\t\t};
            do {
                t.value[lineIndex++] = c;
                (*start)++;
                c = input[*start];
            } while (isalnum(c));
            t.type = isKeyword(t.value) ? KEYWORD : ID;
            return t;
        }
        if (ispunct(c)) {
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '%'|| c== '<'||c=='>'||c=='!'||c=='|'||c=='&') {
            struct Token t = {OPERATOR, ""\t\t};
            t.value[lineIndex++] = c;
            (*start)++;
            return t;
        }
            struct Token t = {SYMBOL, ""\t\t};
            t.value[lineIndex++] = c;
            (*start)++;
            return t;
        }
        struct Token t = {ERROR, ""\t\t};
        t.value[lineIndex++] = c;
        (*start)++;
        return t;
    }
    struct Token t = {EOF, ""\t\t};
    return t;
}
int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%[^\n]s", input);
    int start = 0;
    struct Token t;
    while ((t = getNextToken(input, &start)).type != EOF) {
        printf("%s\t%s\n", TokenTypeStrings[t.type], t.value);
    }
    return 0;
}

------------------------OUTPUT----------------------------------

Enter a string: int a = b+1 
KEYWORD	int
ID	a
OPERATOR	=
ID	b
OPERATOR	+
NUMBER	1

Enter a string: for(int i=0;i<10;i++)
KEYWORD	for
SYMBOL	(
KEYWORD	int
ID	i
OPERATOR	=
NUMBER	0
SYMBOL	;
ID	i
OPERATOR	<
NUMBER	10
SYMBOL	;
ID	i
OPERATOR	+
OPERATOR	+
SYMBOL	)



