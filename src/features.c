#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"
#include <stdlib.h>


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


void second_line(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }
 
    if (height < 2) {
        fprintf(stderr, "L'image doit avoir au moins 2 lignes.\n");
        return;
    }
 

    int index = width * channel_count;  
 
    int R = data[index];
    int G = data[index + 1];
    int B = data[index + 2];
 
    printf("second_line: %d, %d, %d\n", R, G, B);
 
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
    unsigned char *data;
    int width, height, channel_count;

    int pixel = 10;
    pixel -= 1;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    unsigned char r = data[(pixel) * channel_count];
    unsigned char g = data[(pixel) * channel_count + 1];
    unsigned char b = data[(pixel) * channel_count + 2];

    printf("tenth_pixel: %d, %d, %d\n", r, g, b);
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

void color_blue(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int pixel_count = width * height;

    // Pour chaque pixel, mettre R et G à 0 (on garde B)
    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count;
        data[index] = 0;       // R
        data[index + 1] = 0;   // G
        // B est à index + 2
    }

    // Écriture de l'image modifiée
    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void color_gray(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int pixel_count = width * height;

    // Pour chaque pixel, on calcule la moyenne R, G, B
    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count;

        unsigned char R = data[index];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 2];

        unsigned char gray = (R + G + B) / 3;

        data[index]     = gray;
        data[index + 1] = gray;
        data[index + 2] = gray;
        // Si canal alpha présent, on ne le touche pas
    }

    // Écriture du fichier de sortie
    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void color_gray_luminance(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int pixel_count = width * height;

    // Appliquer la formule de luminance pour chaque pixel
    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count;

        unsigned char R = data[index];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 2];

        unsigned char gray = (unsigned char)(0.21 * R + 0.72 * G + 0.07 * B);

        data[index]     = gray;
        data[index + 1] = gray;
        data[index + 2] = gray;
    }

    // Sauvegarder l'image modifiée
    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void color_invert(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int pixel_count = width * height;

    // Inversion des couleurs
    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count;
        data[index]     = 255 - data[index];     // R
        data[index + 1] = 255 - data[index + 1]; // G
        data[index + 2] = 255 - data[index + 2]; // B
        // Ne pas toucher au canal alpha s'il existe
    }

    // Sauvegarder l'image modifiée
    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void color_desaturate(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lire l'image
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int pixel_count = width * height;

    // Désaturation de chaque pixel
    for (int i = 0; i < pixel_count; i++) {
        int index = i * channel_count;

        unsigned char R = data[index];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 2];

        unsigned char min_val = R;
        if (G < min_val) min_val = G;
        if (B < min_val) min_val = B;

        unsigned char max_val = R;
        if (G > max_val) max_val = G;
        if (B > max_val) max_val = B;

        unsigned char desaturated = (min_val + max_val) / 2;

        data[index]     = desaturated;
        data[index + 1] = desaturated;
        data[index + 2] = desaturated;
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void mirror_total(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lecture de l'image
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int pixel_count = width * height;
    int image_size = pixel_count * channel_count;

    // Allouer de la mémoire pour l'image retournée
    unsigned char *mirrored = malloc(image_size * sizeof(unsigned char));
    if (mirrored == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * channel_count;
            int dest_index = ((height - 1 - y) * width + (width - 1 - x)) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                mirrored[dest_index + c] = data[src_index + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", mirrored, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image miroir\n");
    }

}

void mirror_vertical(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lecture de l'image
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int image_size = width * height * channel_count;
    unsigned char *mirrored = malloc(image_size);
    if (mirrored == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    // Pour chaque ligne
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * channel_count;
            int dst_index = (y * width + (width - 1 - x)) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                mirrored[dst_index + c] = data[src_index + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", mirrored, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void mirror_horizontal(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lire l'image
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int image_size = width * height * channel_count;
    unsigned char *mirrored = malloc(image_size);
    if (mirrored == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    // Appliquer la symétrie verticale (haut ↔ bas)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * channel_count;
            int dst_index = ((height - 1 - y) * width + x) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                mirrored[dst_index + c] = data[src_index + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", mirrored, width, height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void rotate_cw(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lire l'image d'entrée
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int new_width = height;
    int new_height = width;
    int image_size = new_width * new_height * channel_count;

    unsigned char *rotated = malloc(image_size);
    if (rotated == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    // Appliquer la rotation 90° sens horaire
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * channel_count;
            int dst_x = height - 1 - y;
            int dst_y = x;
            int dst_index = (dst_y * new_width + dst_x) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                rotated[dst_index + c] = data[src_index + c];
            }
        }
    }

    // Sauvegarde dans un nouveau fichier
    if (write_image_data("image_out.bmp", rotated, new_width, new_height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void rotate_acw(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lire l'image d'entrée
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image\n");
        return;
    }

    int new_width = height;
    int new_height = width;
    int image_size = new_width * new_height * channel_count;

    unsigned char *rotated = malloc(image_size);
    if (rotated == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(data);
        return;
    }

    // Appliquer la rotation 90° anti-horaire
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * channel_count;
            int dst_x = y;
            int dst_y = width - 1 - x;
            int dst_index = (dst_y * new_width + dst_x) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                rotated[dst_index + c] = data[src_index + c];
            }
        }
    }

    // Écriture de l'image tournée
    if (write_image_data("image_out.bmp", rotated, new_width, new_height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }

}

void scale_bilinear(char *source_path, float scale) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }

    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);

    unsigned char *scaled = malloc(new_width * new_height * channel_count);
    if (scaled == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return;
    }

    for (int y = 0; y < new_height; y++) {
        float gy = ((float)y) / scale;
        int y0 = (int)gy;
        int y1 = y0 + 1;
        float dy = gy - y0;

        if (y1 >= height) y1 = height - 1;

        for (int x = 0; x < new_width; x++) {
            float gx = ((float)x) / scale;
            int x0 = (int)gx;
            int x1 = x0 + 1;
            float dx = gx - x0;

            if (x1 >= width) x1 = width - 1;

            for (int c = 0; c < channel_count; c++) {
                // Pixels Q11, Q12, Q21, Q22
                float Q11 = data[(y0 * width + x0) * channel_count + c];
                float Q21 = data[(y0 * width + x1) * channel_count + c];
                float Q12 = data[(y1 * width + x0) * channel_count + c];
                float Q22 = data[(y1 * width + x1) * channel_count + c];

                // Interpolation horizontale
                float R1 = Q11 * (1 - dx) + Q21 * dx;
                float R2 = Q12 * (1 - dx) + Q22 * dx;

                // Interpolation verticale
                float P = R1 * (1 - dy) + R2 * dy;

                // Affecter au pixel final
                scaled[(y * new_width + x) * channel_count + c] = (unsigned char)(P);
            }
        }
    }

    if (write_image_data("image_out.bmp", scaled, new_width, new_height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image\n");
    }


}

void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lecture de l'image
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }

    // Calcul des coins du rectangle de découpe
    int x0 = center_x - crop_width / 2;
    int y0 = center_y - crop_height / 2;

    // Sécuriser les bords
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x0 + crop_width > width)  x0 = width - crop_width;
    if (y0 + crop_height > height) y0 = height - crop_height;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;

    unsigned char *cropped = malloc(crop_width * crop_height * channel_count);
    if (cropped == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return;
    }

    // Copie des pixels
    for (int y = 0; y < crop_height; y++) {
        for (int x = 0; x < crop_width; x++) {
            int src_index = ((y0 + y) * width + (x0 + x)) * channel_count;
            int dst_index = (y * crop_width + x) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                cropped[dst_index + c] = data[src_index + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", cropped, crop_width, crop_height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image cropée.\n");
    }

}

void scale_nearest(char *source_path, float scale) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    // Lire l'image source
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }

    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);

    unsigned char *resized = malloc(new_width * new_height * channel_count);
    if (resized == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return;
    }

    // Redimensionnement
    for (int y = 0; y < new_height; y++) {
        int src_y = (int)(y / scale);
        if (src_y >= height) src_y = height - 1;

        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale);
            if (src_x >= width) src_x = width - 1;

            int src_index = (src_y * width + src_x) * channel_count;
            int dst_index = (y * new_width + x) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                resized[dst_index + c] = data[src_index + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", resized, new_width, new_height) == 0) {
        fprintf(stderr, "Erreur lors de l'écriture de l'image redimensionnée.\n");
    }

}

void print_pixel(char *filename, int x, int y) {
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }
 
    pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
 
    if (pixel == NULL) {
        fprintf(stderr, "Pixel (%d, %d) hors de l'image.\n", x, y);
        return;
    }
 
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->r, pixel->g, pixel->b);
}

void max_component(char *filename, char component) {
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }
 
    int max_value = -1;
    int max_x = -1, max_y = -1;
 
    int c_index = 0; // 0: R, 1: G, 2: B
    if (component == 'R') c_index = 0;
    else if (component == 'G') c_index = 1;
    else if (component == 'B') c_index = 2;
    else {
        fprintf(stderr, "Composante invalide : %c (utiliser R, G ou B)\n", component);
        return;
    }
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;
            if (channel_count < 3) continue;  // sécurité
 
            int value = data[index + c_index];
            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }
 
    if (max_value >= 0)
        printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);
    else
        printf("Aucune valeur maximale trouvée.\n");
 
}


void min_component(char *filename, char component) {
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }
 
    int min_value = 256;  // car max d'un channel est 255
    int min_x = -1, min_y = -1;
 
    int c_index = 0;
    if (component == 'R') c_index = 0;
    else if (component == 'G') c_index = 1;
    else if (component == 'B') c_index = 2;
    else {
        fprintf(stderr, "Composante invalide : %c (utiliser R, G ou B)\n", component);
        return;
    }
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;
 
            if (channel_count < 3) continue;
 
            int value = data[index + c_index];
            if (value < min_value) {
                min_value = value;
                min_x = x;
                min_y = y;
 
                // optimisation : si 0 trouvé, pas besoin de continuer
                if (min_value == 0) break;
            }
        }
        if (min_value == 0) break;
    }
 
    if (min_value < 256)
        printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
    else
        printf("Aucune valeur minimale trouvée.\n");
 
}


void stat_report(char *filename) {
    unsigned char *data = NULL;
    int width, height, n;
 
    if (read_image_data(filename, &data, &width, &height, &n) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image.\n");
        return;
    }
 
    FILE *f = fopen("stat_report.txt", "w");
    if (!f) {
        fprintf(stderr, "Impossible de créer stat_report.txt\n");

        return;
    }
 
    int max_pixel_sum = -1, min_pixel_sum = 256 * 3 + 1;
    int max_px_x = 0, max_px_y = 0;
    int min_px_x = 0, min_px_y = 0;
 
    int max_r = -1, max_g = -1, max_b = -1;
    int min_r = 256, min_g = 256, min_b = 256;
    int max_rx = 0, max_ry = 0, max_gx = 0, max_gy = 0, max_bx = 0, max_by = 0;
    int min_rx = 0, min_ry = 0, min_gx = 0, min_gy = 0, min_bx = 0, min_by = 0;
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = (y * width + x) * n;
            unsigned char R = data[idx];
            unsigned char G = data[idx + 1];
            unsigned char B = data[idx + 2];
 
            int sum = R + G + B;
 
            if (sum > max_pixel_sum) {
                max_pixel_sum = sum;
                max_px_x = x; max_px_y = y;
            }
 
            if (sum < min_pixel_sum) {
                min_pixel_sum = sum;
                min_px_x = x; min_px_y = y;
            }
 
            if (R > max_r) { max_r = R; max_rx = x; max_ry = y; }
            if (G > max_g) { max_g = G; max_gx = x; max_gy = y; }
            if (B > max_b) { max_b = B; max_bx = x; max_by = y; }
 
            if (R < min_r) { min_r = R; min_rx = x; min_ry = y; }
            if (G < min_g) { min_g = G; min_gx = x; min_gy = y; }
            if (B < min_b) { min_b = B; min_bx = x; min_by = y; }
        }
    }
 
    fprintf(f, "max_pixel (%d, %d): %d\n", max_px_x, max_px_y, max_pixel_sum);
    fprintf(f, "\n");
    fprintf(f, "min_pixel (%d, %d): %d\n", min_px_x, min_px_y, min_pixel_sum);
    fprintf(f, "\n");
    fprintf(f, "max_component R (%d, %d): %d\n", max_rx, max_ry, max_r);
    fprintf(f, "\n");
    fprintf(f, "max_component G (%d, %d): %d\n", max_gx, max_gy, max_g);
    fprintf(f, "\n");
    fprintf(f, "max_component B (%d, %d): %d\n", max_bx, max_by, max_b);
    fprintf(f, "\n");
    fprintf(f, "min_component R (%d, %d): %d\n", min_rx, min_ry, min_r);
    fprintf(f, "\n");
    fprintf(f, "min_component G (%d, %d): %d\n", min_gx, min_gy, min_g);
    fprintf(f, "\n");
    fprintf(f, "min_component B (%d, %d): %d\n", min_bx, min_by, min_b);
    fprintf(f, "\n");
 
    fclose(f);
    
}