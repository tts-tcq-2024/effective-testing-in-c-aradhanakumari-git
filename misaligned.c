#include <stdio.h>
#include <string.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

void testPrintColorMap() {
    char buff[1000];
    memset(buff, 0, sizeof(buff));
    setvbuf(stdout, buff, _IOFBF, sizeof(buff));
    
    int result = printColorMap();
    fflush(stdout);

    const char* expecOutput =
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"


    assert(strcmp(buff, expecOutput) == 0);
    assert(result == 25);
}
int main() {
    testPrintColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
