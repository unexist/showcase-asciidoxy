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

#ifndef LANG_H
#define LANG_H 1

/* Forward declarations */

/**
 * @brief Helper to fetch given language
 * @param[in]  name  Name of the language
 * @retval  Default   EN is the default is the couldn't be found
 * @retval  Anything  Found translation in given language
 **/

char *get_lang(const char *name);

#endif /* LANG_H */