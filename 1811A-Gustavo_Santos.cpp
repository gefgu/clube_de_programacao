#include <stdio.h>

#define MAX 212345

char s[MAX];

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        int n, i;
        char d;

        scanf("%d %c %s", &n, &d, &s);
        for (i = 0; s[i] && s[i] >= d; i++)
            printf("%c", s[i]);
        printf("%c", d);
        for(;s[i]; i++) 
            printf("%c", s[i]);
        printf("\n");

    }

    return 0;
}