#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
    char *p = s;

    for (char *i = s; *i; i++) {
        switch (*i) {
            case '(': *p++ = ')';
            break;

            case '{': *p++ = '}';
            break;

            case '[': *p++ = ']';
            break;

            default:
                if (p == s || *i != *--p) 
                    return false;
        }
    }

    return p == s;
}

int main() {
    char str[100];

    printf("Digite a string: ");
    scanf("%s", str);

    if (isValid(str))
        printf("A string está balanceada.\n");
    else
        printf("A string não está balanceada.\n");

    return 0;
}