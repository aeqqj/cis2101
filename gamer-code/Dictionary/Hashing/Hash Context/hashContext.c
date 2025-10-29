#include <stdio.h>
#include <ctype.h>

int hundredthsHash(int digit);
int checkNameHash(char name[]);
int rgbPaletteHash(int r, int g, int b);

int main() {
    printf("\n");
    printf("%d\n", hundredthsHash(1234));
    printf("%d\n", checkNameHash("ABCD"));
    printf("%d\n", rgbPaletteHash(123, 42, 63));

    return 0;
}

int hundredthsHash(int digit) {
    return (digit / 100) % 10;
}

int checkNameHash(char name[]) {
    return (tolower(name[0]) - 97);
}

int rgbPaletteHash(int r, int g, int b) {
    return (r * g * b) % 64;
}