#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printlist(int * list, long int lenght) {
    for (long int i = 0; i < lenght; i++) {
        printf("list[%li] = %i\n", i, list[i]);
    }
}

void sort_list(int * list, long int lenght) {
    int big = 0;
    for (int i = 0; i < lenght; i++) {
        if (big < list[i]) {
            big = list[i];
        }
    }
    int counters[10];
    int *output = malloc(sizeof(int) * lenght);
    int index = 1;
    int * tmp;
    do  {
        // sort elements
        memset(counters, 0, 10*sizeof(*counters));
        for (long int i=0; i < lenght; i++) {
            counters[list[i]/index%10] += 1;
        }
        for (int i = 1; i < 10; i++) {
            counters[i] += counters[i-1];
        }
        for (long int i = lenght-1; i > -1; i--) {
            output[--counters[list[i]/index%10]] = list[i];
        }
        tmp = output;
        output = list;
        list = tmp;

        index *= 10;
    } while (big /= 10);
    free(output);
}

int main(int argc, char ** argv) {
    if (argc < 2 || argc > 2) {
        puts("usage: ./radix <number of elements>");
        return 1;
    }
    char *pointer;
    long int length = strtol(argv[1], &pointer, 10);

    int * list = malloc(sizeof(int)*length);

    for (long int i = 0; i < length; i++) {
        list[i] = rand();
    }
    printlist(list, length);
    sort_list(list, length);
    printlist(list, length);
    return 0;
}