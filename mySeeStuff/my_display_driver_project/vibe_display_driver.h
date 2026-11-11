#ifndef VIBE_DISPLAY_DRIVER_H
#define VIBE_DISPLAY_DRIVER_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define VDD_FB_WIDTH 250
#define VDD_FB_HEIGHT 128

#define VDD_FB_SIZE (VDD_FB_WIDTH * VDD_FB_HEIGHT) / 8

#endif

void VDD_set_pixel(int x, int y, bool val);
int VDD_get_pixel(int x, int y);
void VDD_draw_bitmap(int x, int y, int width, int height, const uint8_t* bitmap); // bitmap
void draw_rectangle(int x, int y, int length, int breadth); //  vector
void draw_text(int x, int y, int size, char* text); // text 