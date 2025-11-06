#include <stdio.h>
#include "pix.h"

int main() {
    pix_t *p = pix_Create(48, 128);
    unsigned char *bm = pix_Bitmap(p);
    for(int i = 0; i < pix_Rows(p) * pix_Columns(p); i++) {
        bm[0] = rand() % 256;
        bm[1] = rand() % 256;
        bm[2] = rand() % 256;
        bm += 3;
    }
    pix_Display(p);
    pix_Destroy(p);
}
