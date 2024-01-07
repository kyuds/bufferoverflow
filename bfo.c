#include "bfo.h"

int main(void) {
    if (!is64bit()) {
        printf("Example is for a 64-bit machine.\n");
        return 0;
    }

    void (*p)(void) = &not_called;
    printf("'not_called()': %p\n", p);
    printf("Executing vulnerable function.\n");

    long long v = (long long) p;

    char malicious[9];
    malicious[0] = 'a';
    malicious[8] = '\0';

    for (int i = 0; i < 8; i++) {
        char tmp = v >> (8 * i) & 0xff;
        malicious[i + 1] = tmp;
    }

    vulnerable(malicious);

    printf("Executed as normal.\n");
    return 0;
}

void vulnerable(char * input) {
    char b[9];
    memcpy(b, input, 9);
    for (int i = 0; i < 9; i++) {
        printf("%x\n", b[i]);
    }
}

void not_called() {
   printf("Buffer overflow exploited!\n");
   exit(1);
}

int is64bit() {
    if (sizeof(char *) == 8)
        return 1;
    return 0;
}
