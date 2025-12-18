#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	char s[55];
	if (scanf("%d", &n) != 1) return 0;
	if (scanf("%54s", s) != 1) return 0;
	n %= 26;
	for (int i = 0; s[i]; ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = (char)('a' + (s[i] - 'a' + n) % 26);
		}
	}
	printf("%s\n", s);
	return 0;
}

