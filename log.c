#include <stdarg.h>
#include <stdint.h>
#include <time.h>

#include <json-c/json.h>

#include "log.h"

int reallog(char *l, ...)  {
    va_list ap;
    int rc = 0;

    unsigned long now = (unsigned long)time(NULL);
    struct json_object *root =json_object_new_object();;
    json_object_object_add(root, "timestamp", json_object_new_int64(now));

    va_start(ap, l);
    for (int i = 1; ; i+2) {
        char *arg1 = va_arg(ap, char *);
        if (arg1 == NULL) {
            break;
        }
        if (i % 2 != 0) {
            char *arg2 = va_arg(ap, char *);
            if (arg2 == NULL) {
                break;
            }
            json_object_object_add(root, arg1, json_object_new_string(arg2));
            continue;
        }
    }
    va_end(ap);

    printf("%s\n", json_object_to_json_string(root));
    json_object_put(root);

    return  rc;
}
