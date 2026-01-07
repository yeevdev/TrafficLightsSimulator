#include "light.h"

const char state_to_st[5][30] = { // state to string function
    "NONE",
    " ● ● ← \033[32m ● \033[0m",
    " ● \033[33m ● \033[0m ← ●",
    "\033[31m ● \033[0m ● ← ●",
    " ● ● \033[32m ← \033[0m ●"
};

void print_light(const Light* light) {
    printf("[%d] %s - [%s]", light->id, light->name, state_to_st[light->state]);
}

void change_light(Light* light, const STATE* state) {
    light->state = *state;
}