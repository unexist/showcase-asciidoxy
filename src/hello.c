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

#include "lang.h"

 /** main
  * @brief Main function
  *
  * @details
  * @startuml
  * main.c -> lang.c : get_lang()
  * @enduml
  *
  * @param[in]  argc  Number of arguments
  * @param[in]  argv  Array with passed commandline arguments
  * @retval  0  Default return value
  **/

 int main(int argc, char *argv[]) {

    printf("Hello, %s", get_lang("NL"));

    return 0;
 }
