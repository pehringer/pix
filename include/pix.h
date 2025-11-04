#ifndef PIX_H
#define PIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pix_t pix_t;

pix_t* pix_Create(size_t lines, size_t columns);

void pix_Destroy(pix_t *p);

size_t pix_Rows(pix_t *p);

size_t pix_Columns(pix_t *p);

unsigned char* pix_Bitmap(pix_t *p);

void pix_Display(pix_t *p);

#endif
