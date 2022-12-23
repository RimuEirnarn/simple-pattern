#pragma once
#include <locale.h>
#include "simplify.h"

// Set all locale possibility to locale
int set_locale(str locale) {
    setlocale(LC_ALL, locale);
    setlocale(LC_ADDRESS, locale);
    setlocale(LC_IDENTIFICATION, locale);
    setlocale(LC_MEASUREMENT, locale);
    setlocale(LC_MESSAGES, locale);
    setlocale(LC_MONETARY, locale);
    setlocale(LC_NAME, locale);
    setlocale(LC_NUMERIC, locale);
    setlocale(LC_PAPER, locale);
    setlocale(LC_TELEPHONE, locale);
    setlocale(LC_TIME, locale);
    return true;
}