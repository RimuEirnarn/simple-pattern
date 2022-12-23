#pragma once
#include "general.h"
#include <time.h>
#include <string.h>

// Timed function, the max byte is 1024. This paste the result to out char
void _timed(str out, const str __restrict__ __format) {
    Exception TimedError = Error_init("TimedError", "", EXIT_FAILURE);
    time_t time_ = time(NULL);
    char string[1024];
    struct tm *time__ = localtime(&time_);
    if (time__ == NULL) throw2(TimedError, "Localtime returned NULL");
    if (strftime(string, sizeof(string), __format, time__) == 0) {
        throw2(TimedError, "strftime returned 0");
    }
    strcpy(out, string);
}

// Paste your out with current time, max byte is 1024. With pre-determinted format
// format -> %A, %d %B %Y (%H:%M:%S)
void auto_timed(str out) {
    _timed(out, strfy(%A, %d %B %Y (%H:%M:%S)));
}