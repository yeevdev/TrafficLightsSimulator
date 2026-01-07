#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <stdio.h>

typedef enum {
    GO_ST = 1, // green
    WAIT,      // yelow
    STOP,      // red
    GO_LEFT    // arrow
} STATE;

extern const char state_to_st[5][30];

// main light struct
typedef struct {
    int id;
    char name[10];
    STATE state;

} Light;

void print_light(const Light* light); // print light state
void change_light(Light* light, STATE state); // change light state

#endif