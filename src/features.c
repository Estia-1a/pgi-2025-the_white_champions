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

char* max_pixel(char* source_path){
    unsigned char* data=NULL ;
    int hauteur , largeur , NC , X , Y ;
    int Sol=0 ;
    int Ymaxi=0 ;
    int Xmaxi=0 ;
    
    read_image_data( source_path , &data , &largeur , &hauteur , &NC ) ;
    pixelRGB*max_pixel=get_pixel( data , largeur , hauteur , NC , 0 , 0 ) ;
	pixelRGB*first_pixel=get_pixel( data , largeur , hauteur , NC , 0 , 0 ) ;
	int Solmaxi=first_pixel->R+first_pixel->G+first_pixel->B ;

    for( Y=0 ; Y<hauteur ; Y++ ){
		
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

char* min_pixel(char* source_path){
    unsigned char* data=NULL ;
    int largeur , hauteur , NC , X , Y ;
    int Sol ;
    int Ymini=0 ;
	int Xmini=0 ;
 
    read_image_data( source_path , &data , &largeur , &hauteur , &NC ) ; 
    pixelRGB*min_pixel=get_pixel( data , largeur , hauteur , NC , 0 , 0 ) ;
    pixelRGB*first_pixel=get_pixel( data , largeur , hauteur , NC , 0 , 0 ) ;
    int Solmini=first_pixel->R+first_pixel->G+first_pixel->B ;

    for( Y=0 ; Y<hauteur ; Y++ ){
		
        for( X=0 ; X<largeur ; X++ ){
            pixelRGB*pixel=get_pixel( data , largeur , hauteur , NC , X , Y ) ;
            Sol=pixel->R+pixel->G+pixel->B ;
			
            if(Sol<Solmini){
                Solmini=Sol ;
                min_pixel=pixel ;
                Xmini=X ;
                Ymini=Y ;
            }
        }
    }
    printf("min_pixel( %d %d ) : %d , %d , %d \n" , Xmini , Ymini , min_pixel->R , min_pixel->G , min_pixel->B ) ;
    char* resultat=malloc(100) ;
    sprintf( resultat ,"min_pixel( %d %d ) : %d , %d , %d \n" , Xmini , Ymini , min_pixel->R , min_pixel->G , min_pixel->B ) ;
    return resultat ;
}

int crop_image(int argc, char*argy[]){
    if(argc != 7){
        printf("Usage : %s<input_file> <outpu_file> <center_x> <center_y> <width>
        <height>\n", argv[0]);
        return 1;
    }
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int center_x = atoi(argv[3]);
    int center_y = atoi(argv[4]);
    int width = atoi(argv[5]);
    int height = atoi(argv[6]);

    crop_image(input_file, output_file, center_x, center_y, width, height);

    return 0;
}

char* max_component(char *source_path,char color_pixel){
    unsigned char* data=NULL ;
    int largeur , hauteur , NC , X , Y ;
    int color_pixel_maxi=0 ;
    int color_pixel_val=0 ;
    int Ymaxi=0 ;
    int Xmaxi=0 ;
   
    read_image_data( source_path , &data , &largeur , &hauteur , &NC ) ;
    for( Y=0 ; Y<hauteur ; Y++ ){
	
        for( X=0 ; X<largeur ; X++ ){
		
            pixelRGB*pixel=get_pixel( data, largeur , hauteur , NC , X , Y ) ;
            if (color_pixel=='B'){
                color_pixel_val=pixel->B ;
            }
			
            else if (color_pixel=='R'){
                color_pixel_val=pixel->R ;
            }
			
            else if (color_pixel=='G'){
                color_pixel_val=pixel->G ;
            }
			
            if(color_pixel_val>color_pixel_maxi){
                color_pixel_maxi=color_pixel_val ;
                Ymaxi=Y ;
                Xmaxi=X ;
            } 
        }
    }
	
    printf("max_component %c ( %d %d ) : %d \n" , color_pixel , Xmaxi , Ymaxi , color_pixel_maxi);
    char* resultat=malloc(100) ;
    sprintf( resultat , "max_component %c ( %d %d ) : %d \n" , color_pixel , Xmaxi , Ymaxi , color_pixel_maxi ) ;
    return resultat ;
}

typedef struct{
    unsigned char R;
    unsigned char G;
    unsigned char B;
} pixelRGB

pixelRGB* get_pixel(unsigned char* data, unsigned int width, unsigned int height, unsigned int n, int x, int y){
    if(x<0 || x>=width || y<0 ||y>=height) return NULL;
    return (pixelRGB*)&data[(y*width + x) * n];
}

void print_pixel(char*filename, int x, int y){
    unsigned char* data;
    unsigned int width, height, n;
    data = read_image_data(filename, &data, &width, height, n,, x, y);
    if(pixel){
        printf("%s, %d, %d\n", pixel->G, pixel->G, pixel->B);
    }
}

typdef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

uint8_t min(uint8_t a, uint8_t b, uint8_t c){
    uint8_t m = a;
    if (b < c) m = b;
    if (c < m) m = c;
    return m;
}

uint8_t max(uint8_t a, uint8_t b, uint8_t c);{
    uint8_t m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

void desaturate_image(Pixel* image_data, int width, int height){
    for (int i = 0; i < width * height; i++){
        uint8_t r = image_data[i].red;
        uint8_t g = image_data[i].green;
        uint8_t b = image_data[i].blue;

        uint8_t min_val = min(r, g, b);
        uint8_t max_val = max(r, g, b);

        uint8_t new_val = (min_val + max_val) / 2;
        
        image_data[i]. red = new_val;
        image_data[i]. green = new_val;
        image_data[i]. blue = new_val;
    }
}

desaturate_image(){
    int width = 2;
    int height = 2;

    Pixel* my_image_pixels = (Pixel*)malloc(width * height * sizeof(Pixel));
    if (my_image_pixels == NULL){
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return 1;
    }

    my_image_pixels[0].red = 255;
    my_image_pixels[0].green = 0;
    my_image_pixels[0].blue = 0;

    my_image_pixels[1].red = 0;
    my_image_pixels[1].green = 255;
    my_image_pixels[1].blue = 0;

    my_image_pixels[2].red = 0;
    my_image_pixels[2].green = 0;
    my_image_pixels[2].blue = 255;

    my_image_pixels[3].red = 255;
    my_image_pixels[3].green = 255;
    my_image_pixels[3].blue = 0;

    printf("--- Après désaturation ---\n");
    for(int i = 0; i < width * height; i++){
        printf("Pixel %d: R=%d, G=%d, B=%d\n", i,
                my_image_pixels[i].red, my_image_pixels[i].green, my_image_pixels[i].blue);
    }

    free(my_image_pixels);
    my_image_pixels = NULL;

    return 0;
}

char* min_component(char *source_path,char t ){
    unsigned char* data=NULL;
    int color_pixel_min;
    int largeur , hauteur , NC , X , Y ;
    int color_pixel_val=0 ;
    int Ymini=0 ;
    int Xmini=0 ;
    
    read_image_data( source_path , &data , &largeur , &hauteur , &NC ) ;
    pixelRGB*first_pixel=get_pixel( data , largeur , hauteur , NC , 0 , 0 ) ;
	
    if (t=='B'){
        color_pixel_mini=first_pixel->B ;
    }
    else if (t=='R'){
        color_pixel_mini=first_pixel->R ;
    }
    else if (t=='G'){
        color_pixel_mini=first_pixel->G ;
    }
    
    for( Y=0 ; Y<hauteur ; Y++ ){
        for( X=0 ; X<largeur ; X++ ){
            pixelRGB*pixel=get_pixel(data , largeur , hauteur , NC , X , Y ) ;
            if (t=='B'){
                color_pixel_val=pixel->B ;
            }
            else if (t=='R'){
                color_pixel_val=pixel->R ;
            }
            else if (t=='G'){
                color_pixel_val=pixel->G ;
            }
            if(color_pixel_val<color_pixel_mini){
                color_pixel_mini = color_pixel_val ;
                Ymin=Y ;
                Xmin=X ;
            }
        }
    }
    printf("min_component %c ( %d %d ) : %d \n" , t , Xmini , Ymini , color_pixel_mini) ;
    char* resultat=malloc(100);
    sprintf(resultat , "min_component %c ( %d %d ) : %d \n" , t , Xmini , Ymini , color_pixel_mini ) ;
    return resultat ;
}