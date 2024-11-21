/**
 * @package showcase-asciidoxy
 *
 * @file hello.c
 * @copyright 2024-present Christoph Kappel <christoph@unexist.dev>
 * @version $Id$
 *
 * This program can be distributed under the terms of the GNU GPLv2.
 * See the file COPYING for details.
 **/

 #include <stdio.h>

 /** @struct Language
  * @brief Storage class for languages
  **/

typedef struct {
    char *lang; ///< Language name
    char *world; ///< Translation of the word 'world'
} Language;

 /** main
  * @brief Main function
  * @param[in]  argc  Number of arguments
  * @param[in]  argv  Array with passed commandline arguments
  * @return Returns always \p zero
  **/

 int main(int argc, char *argv[]) {
    Language lang = { .lang = "NL", .world = "Wereld" };

    printf("Hello, %s", lang.world);

    return 0;
 }