#include <estia-image.h>
#include <stdio.h>
#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}


void dimension(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension: %d, %d\n", width, height);
}

void first_pixel (char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("first_pixel: %d, %d, %d\n", data[0], data[1], data[2]);
}

void tenth_pixel (char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("tenth_pixel: %d, %d, %d\n", data[30], data[28], data[29]);
}

void second_line (char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("second_line: %d, %d, %d\n", data[3 * width], data[3 * width + 1], data[3 * width + 2]);
}

void print_pixel(char *filename, int x, int y) {
    unsigned char *data;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
}

void rotate_cw(char *filename, int x, int y, int z) {
    read_image_data(filename, &data, &width, &height, &n);
    int width, heigt, zPixel;
    unsigned char *rotate_pic = malloc(zPixel);
    if (!rotate_pic) {
        printf("Problème de stockage mémoire");
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int z = 0; z < zPixel; z++) {
                image_out_bmp[(x * height + (height - 1 - y)) * zPixel + z] =
                data[(y * width + x) * zPixel + z];
            }
        }
    }
    return image_out_bmp;
}

void rotate_acw(char*filename, int x, int y, int z) {
    read_image_data(filename, &data, &width, &height, &n);
    unsigned char *rotate_pic = malloc(zPixel);
    if (!rotate_pic) {
        printf("Problème de stockage mémoire");
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int z = 0; z < zPixel; z++) {
                image_out_bmp[(y * width + (width - 1 - x)) * zPixel + z] =
                data[(y * width + x) * zPixel + z];
            }
        }
    }
    return image_out_bmp;
}

