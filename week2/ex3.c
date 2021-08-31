#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args) {
    int n = atoi(args[1]);   
	int width = 2 * n - 1;
	
    for (int i = 1; i <= width; i += 2)
    {
        for (int space = 0; space < n - (i / 2); space++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}