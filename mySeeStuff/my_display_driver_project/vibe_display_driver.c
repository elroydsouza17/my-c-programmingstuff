#include "vibe_display_driver.h"
#include "fonts.h"

uint8_t VDD_FRAME_BUFFER[VDD_FB_SIZE] = {0};


void VDD_set_pixel(int x, int y, bool val) {

  int pos = (y * VDD_FB_WIDTH + x) >> 3;
  // printf("Postion is : %d\n", pos);

  if (val) {
    VDD_FRAME_BUFFER[pos] |= (0x80 >> (x & 0x7));
  } else {
    VDD_FRAME_BUFFER[pos] &= ~(0x80 >> (x & 0x7));
  }

}

int VDD_get_pixel(int x, int y) {

  int pos = (y * VDD_FB_WIDTH + x) >> 3;

  // printf("Pixel value is : %d\n", VDD_FRAME_BUFFER[pos] & (0x80 << (x & 0x7)));
  return VDD_FRAME_BUFFER[pos] & (0x80 >> (x & 0x7));
}

void VDD_draw_bitmap(int x, int y, int width, int height, const uint8_t* bitmap) {
  uint8_t chk_mask = 0;
  
  int orginal_x = x;
  int orginal_y = y;

  int bitmap_size = (height * width) >> 3;

  for (int i = 0; i < bitmap_size; i++) {
    for (int j = 0; j < 8; j++) {
      chk_mask = 0x80 >> j;
      VDD_set_pixel(x, y, bitmap[i] & chk_mask);
      x++;

      if (x - orginal_x == width) {
        y++;
        x = orginal_x;
      } 

      if (y - orginal_y == height) {
        return;
      }
    }
  }
}

void draw_rectangle(int x, int y, int length, int breadth) {

  int size = length * breadth >> 3;
  int orginal_x = x;
  int orginal_y = y;

 for (int i = y; i < y + length; i++) {
  for (int j = x; j < x + breadth; j++) {
    VDD_set_pixel(j, i, 1);

    if (i >= VDD_FB_HEIGHT) {
      return;
    }

    if (j >= VDD_FB_WIDTH) {
      return;
    }
  }
 }
}

void draw_text(int x, int y, int size, char* text) {
  printf("len : %ld\n", strlen(text));
  const uint8_t* font;
  const uint8_t* draw_char;

  int running_x = x;
  int running_y = y;

  int target;

  switch(size) {
    case 16:
    default: font = fonts_bitmap;
  }

  for (int i = 0; i < strlen(text); i++) {

    if (running_x >= VDD_FB_WIDTH) {
      running_y += size;
      running_x = x;
    }

    if (running_y == VDD_FB_HEIGHT) {
      return;
    }

    target = (size * size >> 3) * (text[i] - ' ');
    draw_char = font + target;
    VDD_draw_bitmap(running_x, running_y, size, size, draw_char);
    running_x += size;
  }
}


