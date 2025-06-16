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
                image_out_bmp[(x * height + (height - 1 - y)) * zPixel + z] = data[(y * width + x) * zPixel + z];
            }
        }
    }
    return image_out_bmp;
}

void rotate_acw(char*filename, int x, int y, int z) {
    read_image_data(filename, &data, &width, &height);
    unsigned char *rotate_pic = malloc(zPixel);
    if (!rotate_pic) {
        printf("Problème de stockage mémoire");
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int z = 0; z < zPixel; z++) {
                image_out_bmp[(y * width + (width - 1 - x)) * zPixel + z] = data[(y * width + x) * zPixel + z]; /*On change juste ici la valeur de roation soit x*/
            }
        }
    }
    return image_out_bmp;
}

void mirror_horizontal(char*filename, int x, int y, int z) {
    image_out_bmp = read_image_data(filename, &data, &width, &height);
    unsigned char *symetry_pic = malloc(zPixel);
    if(!symetry_pic) {
        printf("Problème de stockge mémoire");
    }
    for(y = 0; y < height; y++) {
        for(x = 0; x < width / 2; x++) {
            int gauche = ( y * width + x) * zPixel;
            int droite = ( y * width + (width - 1 - x)) * zPixel; /*Implémentation des pixels demandées*/
            for( z = 0; z = < zPixel; z++) { /* Ici on échange les pixels de place*/
                unsigned char stock_donnee = data[gauche + z];
                data[gauche + z] = data[droite + z];
                data[droite + z] = stock_donnee;
            }
        }
    }
    return image_out_bmp ;
}

void mirror_verticale(char*filename, int x, int y, int z) {
    image_out_bmp = read_image_data(filename, &data, &width, &height);
    unsigned char *symetry_pic = malloc(zPixel);
    if(!symetry_pic) {
        printf("Problème de stockge mémoire");
    }
    for(y = 0; y < height; y++) {
        for(x = 0; x < width / 2; x++) {
            int haut = ( y * width + x) * zPixel;
            int bas = ( (height - 1 - y) * width + x) * zPixel; /*Implémentation des pixels demandées*/
            for( z = 0; z = < zPixel; z++) { /* Ici meme idee que precedemment on realise juste pour le haut et la bas */ 
                unsigned char stock_donnee = data[bas + z];
                data[bas + z] = data[haut + z];
                data[haut + z] = stock_donnee;
            }
        }
    }
    return image_out_bmp;
}

void mirror_totale(char*filename, int x, int y, int z) {
    image_out_bmp = read_image_data(filename, &data, &width, &height);
    unsigned char *symetry_pic = malloc(zPixel);
    if(!symetry_pic) {
        printf("Problème de stockge mémoire");
    }
    for(y = 0; y < height; y++) {
        for(x = 0; x < width / 2; x++) {
            int haut_gauche = ( y * width + x) * zPixel;
            int bas_droite = ( (height - 1 - y) * width + (width - 1 -x)) * zPixel; /*Implémentation des pixels demandées*/
            for( z = 0; z = < zPixel; z++) { /* Ici meme idee que precedemment on realise juste pour toutes les directions */ 
                unsigned char stock_donnee = data[haut_gauche + z];
                data[haut_gauche + z] = data[bas_droite + z];
                data[bas_droite + z] = stock_donnee;
            }
        }
    }
    return image_out_bmp;

void color_blue (char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for(int i = 0; i < width * height; i++) {
        data[i*3] = 0;
        data[i*3+1] = 0;
    }
    write_image_data("image_bleu.bmp", data, width, height);
    printf("color_blue\n");
}
void color_gray (char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char gray = (data[i] + data[i + 1] + data[i + 2]) / 3;
        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }
    write_image_data("image_grise.bmp", data, width, height);
    printf("color_gray\n");
}

void color_gray_luminance (char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char gray = (0.21 * data[i] + 0.72 * data[i + 1] + 0.07 * data[i + 2]);
        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }
    write_image_data("image_grise_luminance.bmp", data, width, height);
    printf("color_gray_luminance\n");
}

void color_invert(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for (int i = 0; i < width * height * 3; i ++) {
        data[i] = 255 - data[i];
    }
    write_image_data("image_inversion.bmp", data, width, height);
    printf("color_invert\n");
}