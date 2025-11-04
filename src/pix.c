#include "pix.h"

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

const size_t ROWS_PER_LINE = 2;
const size_t SIZEOF_PIXEL = 3;

pix_t* pix_Create(size_t lines, size_t columns) {
    pix_t *p = malloc(sizeof(pix_t) + (lines * ROWS_PER_LINE) * (columns * SIZEOF_PIXEL));
    if(p == 0) {
        return 0;
    }
    p->rows = lines * ROWS_PER_LINE;
    p->columns = columns;
    p->begin = (unsigned char*) (p + 1);
    p->end = p->begin + (lines * ROWS_PER_LINE) * (columns * SIZEOF_PIXEL);
    memset(p->begin, 0, (lines * ROWS_PER_LINE) * (columns * SIZEOF_PIXEL));
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
    unsigned char *bg = fg + p->columns * SIZEOF_PIXEL;
    unsigned char *eol = bg + p->columns * SIZEOF_PIXEL;
    while(fg < p->end) {
        // Set foreground color.
    	printf("\033[38;2;%d;%d;%dm", fg[0], fg[1], fg[2]);
        // Set background color.
    	printf("\033[48;2;%d;%d;%dm", bg[0], bg[1], bg[2]);
        // Print upper half block.
        printf("\u2580");
        fg += SIZEOF_PIXEL;
        bg += SIZEOF_PIXEL;
        if(bg == eol) {
            // Reset styles and colors.
            printf("\033[0m");
            // Move to the start of the next line.
            printf("\n");
            fg = eol;
            bg = fg + p->columns * SIZEOF_PIXEL;
            eol = bg + p->columns * SIZEOF_PIXEL;
        }
    }
}
