#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "simplify.h"
#include <string.h>

// Throw error, this cannot be caught
#define throw(stuff) stuff._raise(&stuff, __LINE__, __FILE__)
// Throw error, now with dynamic reasoning.
#define throw2(stuff, reason) stuff._raise2(&stuff, reason, __LINE__, __FILE__)
// Throw error, pointer only?
#define throw_(stuff) stuff->_raise(stuff, __LINE__, __FILE__)
// Throw error, pointer only, with dynamic reasoning
#define throw2_(stuff, reason) stuff->_raise2(stuff, __LINE__, __FILE__)
// Throw error at default but with configurable reason.
#define raise(reason) Exception exc = Exception_init(""); throw2(exc, reason)
// String-fy something.
#define strfy(...) #__VA_ARGS__

// Exception class, use throw() macro to throw an error.
class Exception {
    str name;
    int code;
    str reason;
    // Bare raise function
    void (*_raise)(struct Exception *self, int lineno, str filename);
    // Bare raise function but reason may be changed.
    void (*_raise2)(struct Exception *self, str reason, int lineno, str filename);
    // Rename current name object
    void (*rename)(struct Exception *self, str name);
} Exception;

// It's best to use with throw(exc) than directly using .raise method.
void Exception_raise(struct Exception *self, int lineno, str filename)
{
    printf("%s(%d) -> %s: %s\n", self->name, lineno, filename, self->reason);
    exit(self->code);
}

// Rename current exception name.
void Exception_rename(struct Exception *self, str name) {
    self->name = name;
}

// Raise with different reason
void Exception_raise2(struct Exception *self, str reason, int lineno, str filename) {
    str _reason = self->reason;
    self->reason = reason;
    self->_raise(self, lineno, filename);
    self->reason = _reason;
}

// Initialise Exception object
Exception Exception_init(str reason) {
    Exception self;
    self.name = "Exception";
    self.code = EXIT_FAILURE;
    self.reason = reason;
    self._raise = Exception_raise;
    self._raise2 = Exception_raise2;
    self.rename = Exception_rename;
    return self;
}

// Customizable Excepion object initializator
Exception Error_init(str name, str reason, int code) {
    Exception self = Exception_init(reason);
    self.name = name;
    self.code = code;
    return self;
}

int copy_times(char out[], str src, int times) {
    if (strlen(out) < strlen(src)*times) return 0;
    frange(times) {
        out[i] = src[0];
    }
    return 1;
}

int fill(char out[], str src) {
    if (strlen(src) != 0) return 0;
    for_range(strlen(out)) {
        out[current] = src[0];
    }
}