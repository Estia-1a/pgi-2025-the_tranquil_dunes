#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }

  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    dimension(configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    first_pixel(configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "second_line", 11) == 0) {
    second_line(configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "max_pixel", 9) == 0) {
    max_pixel(configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "min_pixel", 9) == 0) {
  min_pixel(configuration.filenames[0]);
  }

  else if (strcmp(configuration.command, "print_pixel") == 0) {
    if (argc < 7) {
        fprintf(stderr, "Usage: -c print_pixel <x> <y>\n");
        return 1;
    }
 
    int x = atoi(argv[5]);
    int y = atoi(argv[6]);
 
    print_pixel(configuration.filenames[0], x, y);
  }

if (strncmp(configuration.command, "tenth_pixel", 9) == 0) {
  tenth_pixel(configuration.filenames[0]);
}

if (strncmp(configuration.command, "color_red", 9) == 0) {
  color_red(configuration.filenames[0]);
}

if (strncmp(configuration.command, "color_green", 9) == 0) {
  color_green(configuration.filenames[0]);
}

if (strncmp(configuration.command, "color_blue", 9) == 0) {
  color_blue(configuration.filenames[0]);
}

if (strncmp(configuration.command, "color_gray", 9) == 0) {
  color_gray(configuration.filenames[0]);
}

if (strncmp(configuration.command, "color_gray_luminance", 9) == 0) {
  color_gray_luminance(configuration.filenames[0]);
}

if (strncmp(configuration.command, "color_invert", 9) == 0) {
  color_invert(configuration.filenames[0]);
}

if (strncmp(configuration.command, "color_desaturate", 9) == 0) {
  color_desaturate(configuration.filenames[0]);
}

if (strcmp(configuration.command, "mirror_total") == 0) {
    mirror_total(configuration.filenames[0]);
}

if (strcmp(configuration.command, "mirror_vertical") == 0) {
    mirror_vertical(configuration.filenames[0]);
}

if (strcmp(configuration.command, "mirror_horizontal") == 0) {
    mirror_horizontal(configuration.filenames[0]);
}

if (strcmp(configuration.command, "rotate_cw") == 0) {
    rotate_cw(configuration.filenames[0]);
}

if (strcmp(configuration.command, "rotate_acw") == 0) {
    rotate_acw(configuration.filenames[0]);
}

else if (strcmp(configuration.command, "scale_bilinear") == 0) {
    if (argc < 6) {
        fprintf(stderr, "Usage: ./freud.exe -f <image> -c scale_bilinear <scale>\n");
        return 1;
    }

    float scale = atof(argv[5]);
    if (scale <= 0) {
        fprintf(stderr, "Erreur : le facteur d'échelle doit être > 0\n");
        return 1;
    }

    scale_bilinear(configuration.filenames[0], scale);
}

else if (strcmp(configuration.command, "scale_crop") == 0) {
    if (argc < 9) {
        fprintf(stderr, "Usage: ./freud.exe -f <image> -c scale_crop <center_x> <center_y> <width> <height>\n");
        return 1;
    }

    int center_x = atoi(argv[5]);
    int center_y = atoi(argv[6]);
    int crop_width = atoi(argv[7]);
    int crop_height = atoi(argv[8]);

    scale_crop(configuration.filenames[0], center_x, center_y, crop_width, crop_height);
}

else if (strcmp(configuration.command, "scale_nearest") == 0) {
    if (argc < 6) {
        fprintf(stderr, "Usage: ./freud.exe -f <image> -c scale_nearest <scale>\n");
        return 1;
    }

    float scale = atof(argv[5]);
    if (scale <= 0) {
        fprintf(stderr, "Erreur : le facteur d'échelle doit être > 0\n");
        return 1;
    }

    scale_nearest(configuration.filenames[0], scale);
}

else if (strcmp(configuration.command, "max_component") == 0) {
    if (argc < 6) {
        fprintf(stderr, "Usage: -c max_component <R|G|B>\n");
        return 1;
    }
 
    char comp = argv[5][0];
    max_component(configuration.filenames[0], comp);
}

else if (strcmp(configuration.command, "min_component") == 0) {
    if (argc < 6) {
        fprintf(stderr, "Usage: -c min_component <R|G|B>\n");
        return 1;
    }
 
    char comp = argv[5][0];
    min_component(configuration.filenames[0], comp);
}

else if (strcmp(configuration.command, "stat_report") == 0) {
    stat_report(configuration.filenames[0]);
}
 if (strncmp(configuration.command, "min_component", 13) == 0) {
    max_component(configuration.filenames[0], (configuration.arguments[0][0]));
  } 
  return 0;
}

