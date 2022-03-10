#include <cstdio>

char map[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char mirror(char c) {
    if (c >= 'A' && c <= 'Z') return map[c - 'A'];
    if (c >= '1' && c <= '9') return map[c - '1' + 26];
    return ' ';
}

int main() {
    char c;
    scanf("%c", &c);
    printf("%c\n", mirror(c));
    return 0;
}
