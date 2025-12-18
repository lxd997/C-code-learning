#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int is_prime(int x) {
    if (x <= 1) return 0;
    if (x == 2) return 1;
    if ((x & 1) == 0) return 0;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return 0;
    return 1;
}

int main(void) {
    char word[128];
    if (scanf("%127s", word) != 1) return 0;

    int cnt[26] = {0};
    for (size_t i = 0; word[i]; ++i) {
        unsigned char c = (unsigned char)word[i];
        if (isalpha(c)) cnt[tolower(c) - 'a']++;
    }

    int max = 0, min = 1e9;
    for (int i = 0; i < 26; ++i) if (cnt[i] > 0) {
        if (cnt[i] > max) max = cnt[i];
        if (cnt[i] < min) min = cnt[i];
    }

    if (max == 0) {
        printf("No Answer\n0\n");
        return 0;
    }

    int diff = max - min;
    if (is_prime(diff)) printf("Lucky Word\n%d\n", diff);
    else printf("No Answer\n0\n");

    return 0;
}