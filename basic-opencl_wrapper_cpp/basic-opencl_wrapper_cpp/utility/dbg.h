/*
 * Author: the hard way to learn c
 */

#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define RED          "\033[1;31m"
#define GREEN        "\033[1;32m"
#define BLUE         "\033[1;34m"
#define YELLOW       "\033[1;33m"
#define DARK_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define PURPPLE      "\033[0;35m"
#define BROWN        "\033[0;33m"
#define LIEGHT_BLACK "\033[0;30m"
#define CLOSE        "\033[0m"

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, GREEN "DEBUG %s:%d: " M "\n" CLOSE,\
    __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, RED "[ERROR](%s:%d: errno: %s) " M "\n" CLOSE,\
    __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, YELLOW "[WARN] (%s:%d: errno: %s) " M "\n" CLOSE,\
    __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, CYAN "[INFO] (%s:%d) " M "\n" CLOSE,\
    __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
