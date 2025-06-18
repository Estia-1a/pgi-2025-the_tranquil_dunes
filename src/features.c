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
    
}
void max_pixel(char *source_path) {
    unsigned char *data;
    int width;
    int height;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int max_s = -1;
    int max_x = 0, max_y = 0;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            if (pixel == NULL) {
                continue;
            }

            int sum = pixel->r + pixel->g + pixel->b;
            if (sum > max_s) {
                max_s = sum;
                max_x = x;
                max_y = y;
            }
        }
    }

    pixelRGB* max_pixel = get_pixel(data, width, height, channel_count, max_x, max_y);
    if (max_pixel != NULL) {
        printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel->r, max_pixel->g, max_pixel->b);
    }
}

void min_pixel(char *source_path) {
    unsigned char *data;
    int width;
    int height;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_s = 900;
    int min_x = 0, min_y = 0;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            if (pixel == NULL) {
                continue;
            }

            int sum = pixel->r + pixel->g + pixel->b;
            if (sum < min_s) {
                min_s = sum;
                min_x = x;
                min_y = y;
            }
        }
    }

    pixelRGB* min_pixel = get_pixel(data, width, height, channel_count, min_x, min_y);
    if (min_pixel != NULL) {
        printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel->r, min_pixel->g, min_pixel->b);
    }
}

void tenth_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lecture de l'image
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    if (width < 10) {
        fprintf(stderr, "L'image doit avoir une largeur d'au moins 10 pixels\n");
        return;
    }

    // Indice du dixième pixel (index 9 car on commence à 0)
    int index = 9 * channel_count;

    int R = data[index];
    int G = data[index + 1];
    int B = data[index + 2];

    printf("tenth_pixel: %d, %d, %d\n", R, G, B);

}

void color_red(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }

    int pixel_count = width * height;

    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count;
        // Garder R, mettre G et B à 0
        data[index + 1] = 0; // Green
        data[index + 2] = 0; // Blue
        // Si image avec alpha (4 canaux), ne pas toucher data[index + 3]
    }

    // Écrire dans un nouveau fichier
    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image.\n");
    }

}

void color_green(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int pixel_count = width * height;

    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count;
        data[index] = 0;       // R
        data[index + 2] = 0;   // B
        // On laisse G (index + 1)
    }

    // Sauvegarder dans une nouvelle image
    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}