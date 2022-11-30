#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct RGB {
    int r;
    int g;
    int b;
};

// COLOR CONSTANTS
const struct RGB WHITE = {255, 255, 255};

void printRGB(struct RGB* rgb) {
    printf("r: %d, g: %d, b: %d", rgb->r, rgb->g, rgb->b);
}

struct Painting {
    char* name;
    size_t width;
    size_t height;
    struct RGB* map;
};

struct Painting newPainting(char* name, size_t width, size_t height) {
    struct Painting p;
    p.name = name;
    p.width = width;
    p.height = height;
    void* s = malloc(width*height*sizeof(struct RGB));
    p.map = s;

    for(size_t i = 0; i < height*width; i++) {
            p.map[i] = WHITE;
    }

    free(s);
    return p;
}

int exportPainting(struct Painting* painting) {
    FILE *f = fopen(painting->name, "wb");
    if (f == NULL) {
        fclose(f);
        return 0;
    }
    fprintf(f, "P6\n%zu %zu 255\n", painting->width, painting->height);

    for(size_t i = 0; i < painting->height*painting->width; i++) {
        // char rgb[100] = "";
        // sprintf(rgb,"%d %d %d", painting->map[i].r, painting->map[i].g, painting->map[i].b);
        fputs("255 255 255\n", f);
    }

    fclose(f);
    return 1;
}