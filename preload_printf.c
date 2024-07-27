/* preload_printf.c */

#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <stdarg.h>

/* Globals. */
int (*real_printf)(const char *__restrict format, ...) = NULL;


int puts(const char *s) {
  if (real_printf == NULL) {
    real_printf = dlsym(RTLD_NEXT, "printf");
    if (real_printf == NULL) {
      fprintf(stderr, "Error in dlsym for printf: %s\n", dlerror());
      return -1;
    }
  }

  return real_printf("Er, %s\n", s);
}


int printf(const char *__restrict format, ...) {
  int result;
  va_list args;

  if (real_printf == NULL) {
    real_printf = dlsym(RTLD_NEXT, "printf");
    if (real_printf == NULL) {
      fprintf(stderr, "Error in dlsym for printf: %s\n", dlerror());
      return -1;
    }
  }

  real_printf("Um, ");

  va_start(args, format);
  result = vprintf(format, args);
  va_end(args);

  return result;
}


__attribute__((constructor)) static void setup(void) {
  /* Not used in this example.  This will be called before main() starts
   * running.  But beware, functions might get called *before* this is called,
   * for example by the loader. That's why the "real_..." variables are
   * initialized on first call, not here. See:
   * https://www.apriorit.com/dev-blog/537-using-constructor-attribute-with-ld-preload */
}
