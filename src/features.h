#ifndef FEATURES_H
#define FEATURES_H
#include <stdio.h>

void dimension (char *source_path);

void helloWorld();
void dimension (char *source_path);
void first_pixel (char *source_path);
void tenth_pixel (char *source_path);
void second_line(char *source_path);
void rotate_cw(char *filename, int x, int y, int z);
void rotate_acw(char*filename, int x, int y, int z) ;
void mirror_horizontal(char*filename, int x, int y, int z) ;
void mirror_verticale(char*filename, int x, int y, int z) ;
void mirror_totale(char*filename, int x, int y, int z) ;
#endif