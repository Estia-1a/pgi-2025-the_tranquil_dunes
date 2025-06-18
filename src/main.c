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
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel(configuration.filenames[0]);
  }

if (strncmp(configuration.command, "max_pixel", 9) == 0) {
    max_pixel(configuration.filenames[0]);
}

if (strncmp(configuration.command, "min_pixel", 9) == 0) {
  min_pixel(configuration.filenames[0]);
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








  return 0;
}

