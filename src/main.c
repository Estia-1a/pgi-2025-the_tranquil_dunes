#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include <string.h>

#include "utils.h"
#include "argsparse.h"


  //SECOND LINE
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

if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
  second_line(configuration.filenames[0]); 
}

  /*
   * TO COMPLETE
   */

return 0;

  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel(configuration.source_path);
  }

  /* else if (strncmp(configuration.command, "second_line", 11) == 0) {
    second_line(configuration.filenames[0]);
  }*/

}

  