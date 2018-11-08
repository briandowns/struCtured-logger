#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <json-c/json.h>

#include "slog.h"

void slog_init(FILE *out) {
    slog_output = out;
}

static slog_field_t *slog_field_new() {
    slog_field_t *field = malloc(sizeof(slog_field_t));
    if (field == NULL) {
        perror("unable to allocation memory for new field");
        return NULL;
    }
    memset(field, 0, sizeof(field));
    return field;
}

/**
 * slog_field_free frees the memory used by the slog_field_t.
 * struct.
 */
static void slog_field_free(slog_field_t *sf) {
    if (sf != NULL) {
        free(sf);
    }
}

/**
 * slog_field_string_free frees the memory used by the string 
 * field and then frees the memory used by the slog_field_t struct.
 */
static void slog_field_string_free(slog_field_t *sf) {
    if (sf != NULL) {
        if (sf->char_value != NULL) {
            free(sf->char_value);
        }
        slog_field_free(sf);
    }
}

slog_field_t *slog_int(const int value) {
    slog_field_t *field = slog_field_new();
    field->type = SLOG_INT;                                    
    field->int_value = value;      
    return field;             
}      

slog_field_t *slog_int64(const int64_t value) {
    slog_field_t *field = slog_field_new(); 
    field->type = SLOG_INT64;                                    
    field->int64_value = value;      
    return field;             
}  

slog_field_t *slog_double(const double value) {
    slog_field_t *field = slog_field_new(); 
    field->type = SLOG_DOUBLE;                                    
    field->double_value = value;      
    return field;             
}  

slog_field_t *slog_string(const char *value) {
    slog_field_t *field = slog_field_new(); 
    field->type = SLOG_STRING; 
    field->char_value = malloc(strlen(value)+1);                                   
    strcpy(field->char_value, value);
    return field;             
} 

int reallog(char *l, ...)  {
    va_list ap;

    unsigned long now = (unsigned long)time(NULL); // UNIX timestamp format
    struct json_object *root = json_object_new_object(); 
    json_object_object_add(root, "timestamp", json_object_new_int64(now));
    json_object_object_add(root, "level", json_object_new_string(l));

    va_start(ap, l);
    for (int i = 1; ; i+2) {
        char *arg1 = va_arg(ap, char *);
        if (arg1 == NULL) { 
            break;
        }

        if (i % 2 != 0) {
            slog_field_t *sf = va_arg(ap, slog_field_t *);
            if (sf == NULL) {
                break;
            }
            switch (sf->type) {
                case SLOG_INT:
                    json_object_object_add(root, arg1, json_object_new_int(sf->int_value));
                    slog_field_free(sf);
                    break;
                case SLOG_INT64:
                    json_object_object_add(root, arg1, json_object_new_int64(sf->int64_value));
                    slog_field_free(sf);
                    break;
                case SLOG_DOUBLE:
                    json_object_object_add(root, arg1, json_object_new_double(sf->double_value));
                    slog_field_free(sf);
                    break;
                case SLOG_STRING:
                    json_object_object_add(root, arg1, json_object_new_string(sf->char_value));
                    slog_field_string_free(sf);
            }
            continue;
        }
    }
    va_end(ap);

    int wc = fprintf(slog_output, "%s\n", json_object_to_json_string(root));
    json_object_put(root); // decrement the count on the JSON object

    return  wc;
}
