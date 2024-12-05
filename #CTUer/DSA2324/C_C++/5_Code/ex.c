#include <stdio.h>

int mystery(int x) {
    return (x % 2 == 0) ? x / 2 : x + 1;
}
int main() {
    int x = 7, count = 0;
    while (x != 1 && count < 5) {
        if (x > 4) {
            x-=2;
        } else {
            x = mystery(x);
        }
        count++;
    }
    printf("Ket qua: %d\n", x);
    printf("so lan lap : %d\n", count);
}