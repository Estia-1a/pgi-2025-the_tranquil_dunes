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

    // Libération de la mémoire si nécessaire (selon l'implémentation de read_image_data)
    free(data);
}

/*void second_line(char *source_path) {
    unsigned char *data;
    int width, height, channels;

    // Lecture de l'image
    if (read_image_data(source_path, &data, &width, &height, &channels) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }

    // Vérifie que l'image a au moins 2 lignes
    if (height < 2) {
        fprintf(stderr, "L'image doit avoir au moins 2 lignes.\n");
        return;
    }

    // Calcul de l'index du 1er pixel de la 2e ligne
    int index = 3 * width;
    int r = data[index];
    int g = data[index + 1];
    int b = data[index + 2];

    // Affichage du résultat
    printf("second_line: %d, %d, %d\n", r, g, b);
}*/