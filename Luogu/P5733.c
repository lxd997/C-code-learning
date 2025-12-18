#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[105];
    if (scanf("%104s", s) != 1) return 0;
    for (int i = 0; s[i]; ++i) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
    printf("%s\n", s);
    return 0;
}