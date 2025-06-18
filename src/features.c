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

void color_green (char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for(int i = 0; i < width * height; i++) {
        data[i*3] = 0;
        data[i*3+2] = 0;
    }
    write_image_data("image_verte.bmp", data, width, height);
    printf("color_green\n");
}

void print_pixel(char *filename, int x, int y) {
    unsigned char *data;
    int width, height, n;
    read_image_data(filename, &data, &width, &height, &n);
}

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

char* max_pixel(char* source_path){
    unsigned char* data=NULL ;
    int hauteur , largeur , NC , X , Y ;
    int Sol=0 ;
    int Xmaxi=0 ;
    int Ymaxi=0 ;
    
    read_image_data( source_path , &data , &largeur , &hauteur , &NC ) ;
    pixelRGB*max_pixel=get_pixel( data , largeur , hauteur , NC , 0 , 0 ) ;
	pixelRGB*first_pixel=get_pixel( data , largeur , hauteur , NC , 0 , 0 ) ;
	int Solmaxi=first_pixel->R+first_pixel->G+first_pixel->B ;
    for(Y=0;Y<hauteur;Y++){
		
        for( X=0 ; X<largeur ; X++ ){
            pixelRGB*pixel=get_pixel( data , largeur , hauteur , NC , X , Y ) ;
            Sol=pixel->R+pixel->G+pixel->B ;
			
            if(Sol>Solmaxi){
                Solmaxi=Sol; 
                max_pixel=pixel;
			    Ymaxi=Y;
				Xmaxi=X;               
            }
        }
    }
	
    printf( "max_pixel ( %d %d ) : %d , %d , %d \n" , Xmaxi , Ymaxi , max_pixel->R , max_pixel->G , max_pixel->B ) ;
    char* resultat=malloc(100) ;
    sprintf(resultat , "max_pixel( %d %d ) : %d , %d , %d \n" , Xmaxi , Ymaxi , max_pixel->R , max_pixel->G , max_pixel->B ) ;
    return resultat ;  
}

