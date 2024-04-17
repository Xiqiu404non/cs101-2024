#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *g_mm_ptr[10];
} my_mm_t;

int g_mm[10];
my_mm_t mms;

void print_calloc_array(int flag) {
    for (int i = 0; i < 10; i++) {
        if (mms.g_mm_ptr[i] != NULL)
            printf("1");
        else
            printf("0");
    }
    if (flag == 1)
        printf("\n");
    else
        printf(" <- Out of space\n");
}

int *my_calloc(int size) {
    int count = 0, head = 0;
    for (int i = 0; i < 10; i++) {
        if (mms.g_mm_ptr[i] == NULL) {
            count++;
            if (count >= size)
                break;
        }
        else {
            count = 0;
            head = i + 1;
        }
    }
    
    if (count < size) {
        print_calloc_array(0);
        return NULL;
    }
    
    int *tmp = (int*)calloc(size, sizeof(int));
    for (int i = head; i < head + size; i++) {
            mms.g_mm_ptr[i] = tmp;
            g_mm[i] = 1;
        }
    print_calloc_array(1);
    return tmp;
}

void my_free(int *p) {
    for (int i = 0; i < 10; i++) {
        if (mms.g_mm_ptr[i] == p) {
            mms.g_mm_ptr[i] = NULL;
            g_mm[i] = 0;
        }
    }
    free(p);
    print_calloc_array(1);
}

int main() {
    int *np1 = my_calloc(1);
    int *np2 = my_calloc(2);
    int *np3 = my_calloc(3);
    int *np4 = my_calloc(4);
    my_free(np1);
    my_free(np4);
    int *np5 = my_calloc(5);
    int *np6 = my_calloc(1);
    return 0;
}
