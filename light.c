#include "light.h"

void print_light(const Light* light) {
    printf("[%d] %s - [%s]", light->id, light->name, st_chr[light->state]);
}

void change_light(Light* light, const STATE* state) {
    light->state = *state;
}