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

#include <strings.h>

#define LENGTH(a) (sizeof(a) / sizeof(a[0])) ///< Array length

/** @struct Language
 * @brief Storage class for languages
 **/

struct language_t {
    char *name; ///< Language name
    char *world; ///< Language translation of the word 'world'
};

/** @typedef Language
 * @brief Convenience type definition for languages
 **/

typedef struct language_t Language;

static Language languages[] = {
    { .name = "EN", .world = "World" },
    { .name = "DE", .world = "Welt" },
    { .name = "NL", .world = "Wereld" }
};

/** @fn get_lang
 * @brief Helper to fetch given language
 * @param[in]  name  Name of the language
 * @return Returns either found translation in given language or default for \p EN
 **/

char *get_lang(const char *name) {
    char *retval = languages[0].world;

    if (name) {
        for (int i = 0; i < LENGTH(languages); i++) {
            if (!strncasecmp(languages[i].name, name, 2)) {
                retval = languages[i].world;

                break;
            }
        }
    }

    return retval;
}
