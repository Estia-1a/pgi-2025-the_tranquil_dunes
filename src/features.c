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
    int width;
    int height;
    int channel_count;

    int chiffreRetour = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (chiffreRetour == 0){
        printf("il y a un problème avec read_image_data");
    }
    else {
        printf("dimension: %d, %d", width, height);
    }
 
}

void first_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];

     int chiffreRetour = read_image_data(source_path, &data, &width, &height, &channel_count);
     
    if (chiffreRetour == 0){
        printf("il y a un problème avec read_image_data");
    }
    else {
        printf("first_pixel: %d, %d, %d\n", r, g, b);
    }
    
};
