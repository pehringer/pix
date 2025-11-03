# ***pix*** - ***PIX***els
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
---
# Library Functions
---
### ```pix_t* pix_Create(size_t lines, size_t columns)```
---
### ```void pix_Destroy(pix_t *p)```
---
### ```size_t pix_Rows(pix_t *p)```
---
### ```size_t pix_Columns(pix_t *p)```
---
### ```unsigned char* pix_Bitmap(pix_t *p)```
---
### ```void pix_Display(pix_t *p)```
---
