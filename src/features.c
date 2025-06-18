#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
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

void first_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (read_image_data(source_path, &data, &width, &height, &channels) != 0) {
        fprintf(stderr, "Erreur : impossible de lire l'image '%s'\n", source_path);
        return;
    }

    // Premier pixel = 3 premières valeurs du tableau data[]
    unsigned char R = data[0];
    unsigned char G = data[1];
    unsigned char B = data[2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);

    
    free(data);
}

void second_line(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (read_image_data(source_path, &data, &width, &height, &channels) != 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image : %s\n", source_path);
        return;
    }

    // Vérification minimale
    if (height < 2 || channels < 3) {
        fprintf(stderr, "Image invalide (hauteur < 2 ou < 3 canaux).\n");
        free(data);
        return;
    }

    int x = 1;  // colonne
    int y = 1;  // ligne (seconde ligne)
    int index = (y * width + x) * channels;

    unsigned char r = data[index];
    unsigned char g = data[index + 1];
    unsigned char b = data[index + 2];

    printf("second_line: %d, %d, %d\n", r, g, b);
    free(data);
}