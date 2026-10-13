#include <stdio.h>

int main() {
  char buf[256];
  for (int k = 0; k < 60; k++) {
  snprintf(buf, sizeof(buf), "output-%02d.ppm", k);
  const char* output_path = buf;
  FILE *f = fopen(output_path, "wb");
  int factor = 100;
  int w = 16 * factor;
  int h = 9 * factor;
  fprintf(f, "P6\n");
  fprintf(f, "%d %d\n",w, h);
  fprintf(f, "255\n");
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {  
      int x = (j + k)/ factor;
      int y = (i + k)/ factor;
      if ((x + y) % 2 == 0) {
        fputc(0xFF, f);
        fputc(0xFF, f);
        fputc(0x00, f);
      } else {
      fputc(0xFF, f);
      fputc(0x00, f);
      fputc(0x00, f);
      } 
    }
  }
  fclose(f);
  printf("Generated output path.. %s\n",output_path);
}
  return 0;
}



// 0 1 2 3 4 5
// 0 1 2 3 4 5
// 0 1 2 3 4 5
// 0 1 2 3 4 5