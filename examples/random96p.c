#include <stdio.h>
#include "pix.h"

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
