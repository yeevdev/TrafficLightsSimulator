    #include "trafic_lights_CUI.h"
    #include <stdio.h>


    void clear_CUI(void) {
        printf("\033[\033[H");
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
        case OFF:
            return SIGNAL_OFF;
        default:
            break;
        }
    }

    void display_intersection(Intersection* intersection)
    {
        const char* N = get_light_state_str(&intersection->north);
        const char* S = get_light_state_str(&intersection->south);
        const char* W = get_light_state_str(&intersection->west);
        const char* E = get_light_state_str(&intersection->east);

        printf("\n");
        printf("                       │               │\n");
        printf("                       │               │\n");
        printf("                       │               │\n");
        printf("                       │               │\n");
        printf("                       │===============│\n");
        printf("                       │===============│\n");
        printf("                       │    %s    │\n", N);
        printf("───────────────────────┘               └───────────────────────\n");

        // 가운데 (너 간격 그대로)
        printf("                 ││ ││                   ││ ││                       \n");
        printf("                 ││ ││                   ││ ││                       \n");
        printf("                 ││ ││                   ││ ││                       \n");
        printf("                %s                 %s                          \n", W, E);
        printf("                 ││ ││                   ││ ││                       \n");
        printf("                 ││ ││                   ││ ││                       \n");
        printf("                 ││ ││                   ││ ││                       \n");
        printf("───────────────────────┐               ┌───────────────────────\n");
        printf("                       │    %s    │\n", S);
        printf("                       │===============│\n");
        printf("                       │===============│\n");
        printf("                       │               │\n");
        printf("                       │               │\n");
        printf("                       │               │\n");
        printf("                       │               │\n");
        printf("                       │               │\n");

        printf("\n");
    }

    void refresh_intersection(Intersection* intersection) {
        clear_CUI();
        display_intersection(intersection);
    }

