#include <stdio.h>
#include "pintor.c"

const unsigned int WIDTH = 2000;
const unsigned int HEIGHT = 2000;

int main(int argc, char *argv[]) {
    struct Painting p = newPainting("painting1.ppm", WIDTH, HEIGHT);
    if(exportPainting(&p) == 0) {
        printf("%s", "error creating painting...");
        return 1;
    }
    printf("%s", "painting created...");
    return 0;
}