#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct RGB {
    int r;
    int g;
    int b;
};

// COLOR CONSTANTS
static unsigned char WHITE[3] = {255, 255, 255};
static unsigned char BLACK[3] = {0, 0, 0};
static unsigned char RED[3] = {255, 0, 0};
static unsigned char GREEN[3] = {0, 255, 0};
static unsigned char BLUE[3] = {0, 0, 255};

void printRGB(struct RGB* rgb) {
    printf("r: %d, g: %d, b: %d", rgb->r, rgb->g, rgb->b);
}

struct Painting {
    char* name;
    size_t width;
    size_t height;
    unsigned char** map;
};

struct Painting newPainting(char* name, size_t width, size_t height) {
    struct Painting p;
    p.name = name;
    p.width = width;
    p.height = height;
    void* s = malloc(width*height*sizeof(unsigned char[3]));
    p.map = s;

    for(size_t i = 0; i < height*width; i++) {
            p.map[i][0] = BLACK[0];
            p.map[i][1] = BLACK[1];
            p.map[i][2] = BLACK[2];
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
    fprintf(f, "P6\n%d %d 255\n", (int) painting->width, (int) painting->height);
    printf("PAINTING SIZE: %d %d\n", (int) painting->width, (int) painting->height);

    for(size_t i = 0; i < painting->height*painting->width; i++) {
        // char rgb[100] = "";
        // sprintf(rgb,"%d %d %d", painting->map[i].r, painting->map[i].g, painting->map[i].b);
        fwrite(painting->map[painting->height*painting->width], 1, 3, f);
    }

    fclose(f);
    return 1;
}

int paintPixel(int x, int y, struct Painting* p, unsigned char color[3]) {
    // returns 0 if the point given is out of reach
    if(x*y > p->height*p->width) return 0;
    p->map[x*y] = color;
    return 1;
}

int paintSquareFill(int x, int y, int size, struct Painting* p, struct RGB color) {
    for(int i = x; i < size; i++) {
        //
    }
    return 1;
}