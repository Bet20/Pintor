#include <stdio.h>
#include "pintor.c"

const unsigned int WIDTH = 16;
const unsigned int HEIGHT = 16;

int main(int argc, char *argv[]) {
    struct Painting p = newPainting("painting1.ppm", WIDTH, HEIGHT);
    paintPixel(1, 1, &p, WHITE);
    paintPixel(5, 5, &p, WHITE);
    paintPixel(2, 7, &p, WHITE);

    if(exportPainting(&p) == 0) {
        printf("%s", "error creating painting...");
        return 1;
    }
    printf("%s", "painting created...");
    return 0;
}