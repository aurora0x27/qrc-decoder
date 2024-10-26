#include <utils/ulog.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void ulog(msg_type type, const char* format, ...) {
#define COLOR_NONE "\033[0m"
#define RED        "\033[1;31m"
#define BLUE       "\033[1;34m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[1;33m"

    char* msg_content = NULL;
    va_list arg_list_raw;
    va_start(arg_list_raw, format);
    va_list arg_list;
    va_copy(arg_list, arg_list_raw);

    // calculate required memory size
    int len = vsnprintf(NULL, 0, format, arg_list);
    if (len < 0) {
        fprintf(stderr, "[ulog]: mem alloc error!\n");
        return;
    }

    // alloc memory for messafe content
    msg_content = (char*)malloc(len + 1);
    if (msg_content == NULL) {
        fprintf(stderr, "[ulog]: mem alloc error!\n");
        return;
    }

    // use vsprintf to fill msg_content
    va_copy(arg_list, arg_list_raw);
    vsnprintf(msg_content, len + 1, format, arg_list);

    va_end(arg_list_raw);
    va_end(arg_list);

    // print message
    switch(type) {
        case MSG_INFO:
            printf(GREEN "[INFO]: %s\n" COLOR_NONE, msg_content);
            break;
        case MSG_DEBUG:
            printf(BLUE "[DEBUG]: %s\n" COLOR_NONE, msg_content);
            break;
        case MSG_WARN:
            printf(YELLOW "[WARN]: %s\n" COLOR_NONE, msg_content);
            break;
        case MSG_ERROR:
            printf(RED "[ERROR]: %s\n" COLOR_NONE, msg_content);
            break;               
        default:                 
            printf("[ERROR_LOG]: Please choose a correct log type");
    }

    free(msg_content);

#undef COLOR_NONE
#undef RED       
#undef BLUE      
#undef GREEN     
#undef YELLOW    
}
