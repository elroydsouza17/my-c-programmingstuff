#include "vibe_display_driver.h"
#include "flanker.h"

int main() {
  VDD_draw_bitmap(0, 50, SU_30_WIDTH, SU_30_HEIGHT, flanker);
  // draw_rectangle(100, 0, 10, 10);

  // draw_rectangle(0, 100, 10, 10);
  draw_text(0, 100, 16, "elro");
    
  for (int y = 0; y < VDD_FB_HEIGHT; y++) {
    for (int x = 0; x < VDD_FB_WIDTH; x++) {
      if (VDD_get_pixel(x, y)) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf("\n");
  }
}