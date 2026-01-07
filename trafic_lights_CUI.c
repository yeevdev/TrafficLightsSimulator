#include "trafic_lights_CUI.h"
#include <stdio.h>


void clear_CUI(void) {
    printf("\033[2J\033[H");
}

const char* get_light_state_str(Light* light) {
    switch(light->state) {
    case RED:
        return SIGNAL_RED;
    case YELLOW:
        return SIGNAL_YELLOW;
    case GREEN:
        return SIGNAL_GREEN;
    case LEFT:
        return SIGNAL_LEFT;
    default:
        break;
    }
}

void display_intersection(Intersection* intersection) {
    printf("                 │             │\n");
    printf("                 │             │\n");
    printf("                 │             │\n");
    printf("                 │             │\n");
    printf("                 │   %-8s   │\n", get_light_state_str(&(intersection->north)));
    printf("                 │             │\n");
    printf("─────────────────┘             └─────────────────\n");
    printf("                                                 \n");
    printf("                                                 \n");
    printf("                                                 \n");

    // 좌우 도로 (West, East)
    printf("    %-8s                         %-8s\n",
        get_light_state_str(&(intersection->west)),
        get_light_state_str(&(intersection->east)));

    printf("                                                 \n");
    printf("                                                 \n");
    printf("                                                 \n");

    printf("─────────────────┐             ┌─────────────────\n");
    printf("                 │             │\n");
    printf("                 │             │\n");
    printf("                 │   %-8s   │\n", get_light_state_str(&(intersection->south)));
    printf("                 │             │\n");
    printf("                 │             │\n");
    printf("                 │             │\n");
    printf("                 │             │\n");
}

void refresh_intersection(Intersection* intersection) {
    clear_CUI();
    display_intersection(intersection);
}

