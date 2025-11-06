N# ***pix*** - ***PIX***els
Text-based terminal graphics using ANSI escape sequences and extended ASCII. 
- Easy to use (library only has six functions)
  + [```pix_t* pix_Create(size_t lines, size_t columns)```](#pix_t-pix_createsize_t-lines-size_t-columns)
  + [```void pix_Destroy(pix_t *p)```](#void-pix_destroypix_t-p)
  + [```size_t pix_Rows(pix_t *p)```](#size_t-pix_rowspix_t-p)
  + [```size_t pix_Columns(pix_t *p)```](#size_t-pix_columnspix_t-p)
  + [```unsigned char* pix_Bitmap(pix_t *p)```](#unsigned-char-pix_bitmappix_t-p)
  + [```void pix_Display(pix_t *p)```](#void-pix_displaypix_t-p)
- Lightweight (less than 75 lines of source code)
- Portable (only uses the C standard library)
  + ```stdio.h```
  + ```stdlib.h```
  + ```string.h```
- Universal (uses de facto terminal standards)
  + ANSI Escape Sequences
  + Extended ASCII
# Example Code
---
Display a 128 x 96 (96p) random pixel image:
```
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
```
```
pix$ make random96p 
gcc -fPIC -shared -I ./include ./src/pix.c -o ./pix.so
gcc -I ./include ./pix.so ./examples/random96p.c -o ./random96p.bin
./random96p.bin

...

rm ./random96p.bin
```
---
# Library Functions
---
### ```pix_t* pix_Create(size_t lines, size_t columns)```
Returns the allocated pixels for the specified number of terminal lines and columns.
Returns null if the allocation failed.
- ```lines``` number of terminal lines.
- ```columns``` number of terminal columns.
---
### ```void pix_Destroy(pix_t *p)```
Deallocates pixels.
- ```p``` pixels returned by pix_Create. Non null value.
---
### ```size_t pix_Rows(pix_t *p)```
Returns the number of rows of pixels.
- ```p``` pixels returned by pix_Create. Non null value.
---
### ```size_t pix_Columns(pix_t *p)```
Returns the number of columns of pixels.
- ```p``` pixels returned by pix_Create. Non null value.
---
### ```unsigned char* pix_Bitmap(pix_t *p)```
Returns a pointer to the pixel data.
Pixels are stored row by row, top to bottom, left to right.
Each pixel consists of three consecutive bytes: ```[RED][GREEN][BLUE]```.
- ```p``` pixels returned by pix_Create. Non null value.
---
### ```void pix_Display(pix_t *p)```
Renders the pixel data visually in the terminal.
- ```p``` pixels returned by pix_Create. Non null value.
---
