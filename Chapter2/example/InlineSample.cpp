#include <iostream>
#include <cstdio>

#define ADD(a, b)((a) + (b))

int Add(int a, int b) {
    return a + b;
}

inline int AddNew(int a, int b) {
    return a + b;
}

int main(int argc, char* argv[]) {
    int a, b;
    scanf("%d%d", &a, &b);

    printf("ADD(): %d\n", ADD(a, b));
    printf("Add(): %d\n", Add(a, b));
    printf("AddNew(): %d\n", AddNew(a, b));

    return 0;
}