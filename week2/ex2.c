#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    size_t len = 256;

    char *s = malloc(sizeof(char) * len);
    fgets(s, 256, stdin);

    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        printf("%c", s[i]);
    }
}