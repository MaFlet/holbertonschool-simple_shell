#include <stddef.h>
#include "shell.h"

size_t _strcspn(const char *s, const char *reject) {
    const char *p;
    const char *r;

    for (p = s; *p; p++) {
        for (r = reject; *r; r++) {
            if (*p == *r) {
                return p - s;
            }
        }
    }

    return p - s;
}
