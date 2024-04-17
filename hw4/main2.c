#include <stdio.h>

void multiplication(int i, int j) {
    if (i < 10) {
        if (j < 9) {
            printf("%d*%d=%d ", i, j, i*j);
            multiplication(i, j + 1);
        }
        else {
            printf("%d*%d=%d\n", i, j, i*j);
            multiplication(i + 1, j - 8);
        }
    }
}

int main()
{
    multiplication(1, 1);
    return 0;
}
