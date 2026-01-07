#include <stdio.h>

typedef enum {
    GO_ST = 1, // green
    WAIT,      // yelow
    STOP,      // red
    GO_LEFT    // arrow
} STATE;

const char st_chr[5][30] = { // state to string function
    "",
    " ¡Ü ¡Ü ¡ç \033[32m ¡Ü \033[0m",
    " ¡Ü \033[33m ¡Ü \033[0m ¡ç ¡Ü",
    "\033[31m ¡Ü \033[0m ¡Ü ¡ç ¡Ü",
    " ¡Ü ¡Ü \033[32m ¡ç \033[0m ¡Ü"
};

// main light struct
typedef struct {
    int id;
    char name[10];
    STATE state;

} Light;

void print_light(const Light* light); // print light state
void change_light(Light* light, const STATE* state); // change light state