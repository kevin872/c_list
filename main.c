#include <stdio.h>
#include <stdlib.h>

int * init_list(int size) {
    int * list =  malloc(size * (sizeof (*list)));
    int * hd = list;
    while (hd - list < size) {
        *hd = 0;
        hd++;
    }
    return list;
}

void * set_value(int * list, int nitems, int idx, int value) {
    int * hd = list;
    while (hd - list < nitems) {
        if (hd - list == idx) {
            *hd = value; return 0;
        }
        hd++;
    }
    return 0;
}

void print_list(int * list, int nitems) {
    int * hd = list;
    printf("[%luUL; %d] :: { ", sizeof(*list), nitems);
    while (hd - list < nitems - 1) {
        printf("%d, ", *hd);
        hd++;
    }
    printf("%d }\n", *hd);
}

void deinit(int * list) {
    free(list);
}

int main() {
    int size = 10;
    int * list = init_list(size);
    set_value(list, size, 1, 100);
    print_list(list, size);
    deinit(list);   
}