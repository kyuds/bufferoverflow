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

    char malicious[17];
    malicious[0] = 'a';
    malicious[16] = '\0';

    for (int i = 0; i < 8; i++) {
        char tmp = v >> (8 * i) & 0xff;
        malicious[i + 9] = tmp;
        malicious[i + 1] = 'a';
    }

    // printf("%s\n", malicious);

    vulnerable(malicious);

    printf("Executed as normal.\n");
    return 0;
}

void vulnerable(char * input) {
    char b[1];
    strcpy(b, input);
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
