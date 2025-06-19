#ifndef FEATURES_H
#define FEATURES_H
#include <stdio.h>

void dimension (char *source_path);

void helloWorld();
void dimension (char *source_path);
void first_pixel (char *source_path);
void tenth_pixel (char *source_path);
void second_line(char *source_path);
void color_green(char *source_path);
void color_blue(char *source_path);
void color_gray(char *source_path);
void color_gray_luminance(char *source_path);
void color_invert(char *source_path);
void crop_image(char *source_path);
void get_pixel(char *source_path);
void desaturate_image(char *source_path);
void mirror_totale(char*filename, int x, int y, int z);
void mirror_verticale(char*filename, int x, int y, int z);
void mirror_horizontal(char*filename, int x, int y, int z);
void rotate_acw(char*filename, int x, int y, int z);
void rotate_cw(char *filename, int x, int y, int z);
#endif