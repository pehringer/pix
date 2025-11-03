#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

Pix memory layout:

          pix_t.begin           pix_t.end
         /                     /
_______________________________
| pix_t | pixel | ... | pixel |
|       | 0     |     | n     |
|_______|_______|_____|_______|


pixel memory layout:

  red        green      blue
 /          /          /
__________________________________
| unsigned | unsigned | unsigned |
| char     | char     | char     |
|__________|__________|__________|

*/

struct pix_t {
    size_t rows;
    size_t columns;
    unsigned char *begin;
    unsigned char *end;
};

typedef struct pix_t pix_t;

pix_t* pix_Create(size_t lines, size_t columns) {
    pix_t *p = malloc(sizeof(pix_t) + (lines * 2) * (columns * 3));
    if(p == 0) {
        return 0;
    }
    p->rows = lines * 2;
    p->columns = columns;
    p->begin = (unsigned char*) (p + 1);
    p->end = p->begin + (lines * 2) * (columns * 3);
    memset(p->begin, 0, (lines * 2) * (columns * 3));
    return p;
}

void pix_Destroy(pix_t *p) {
    free(p);
}

size_t pix_Rows(pix_t *p) {
    return p->rows;
}

size_t pix_Columns(pix_t *p) {
    return p->columns;
}

unsigned char* pix_Bitmap(pix_t *p) {
    return p->begin;
}

void pix_Display(pix_t *p) {
    // Move to the start of the current line.
    printf("\r");
    unsigned char *fg = p->begin;
    unsigned char *bg = fg + p->columns * 3;
    unsigned char *eol = bg + p->columns * 3;
    while(fg < p->end) {
        // Set foreground color.
    	printf("\033[38;2;%d;%d;%dm", fg[0], fg[1], fg[2]);
        // Set background color.
    	printf("\033[48;2;%d;%d;%dm", bg[0], bg[1], bg[2]);
        // Print upper half block.
        printf("\u2580");
        fg += 3;
        bg += 3;
        if(bg == eol) {
            // Reset styles and colors.
            printf("\033[0m");
            // Move to the start of the next line.
            printf("\n");
            fg = eol;
            bg = fg + p->columns * 3;
            eol = bg + p->columns * 3;
        }
    }
}

int main() {
    pix_t *p = pix_Create(48, 128); // (48 lines, 128 columns) e.g. 96p 128x96
    unsigned char *bm = pix_Bitmap(p);
    for(int i = 0; i < pix_Rows(p) * pix_Columns(p); i++) {
    	// random pixel color
        bm[0] = rand() % 256; // red
        bm[1] = rand() % 256; // green
        bm[2] = rand() % 256; // blue
        bm += 3;
    }
    pix_Display(p);
    pix_Destroy(p);
}
