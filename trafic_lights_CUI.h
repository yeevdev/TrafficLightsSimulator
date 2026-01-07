#ifndef __TRAFIC_LIGHTS_CUI_H__
#define __TRAFIC_LIGHTS_CUI_H__

#include "light.h"

#define RED_LIGHT "\033[31m●\033[0m"
#define YELLOW_LIGHT "\033[33m●\033[0m"
#define GREEN_LIGHT "\033[32m●\033[0m"
#define GREEN_ARROW "\033[32m←\033[0m"
#define OFF_LIGHT     "\033[90m○\033[0m"

// [RED][YELLOW][GREEN][LEFT]
#define SIGNAL_RED		RED_LIGHT    " " OFF_LIGHT   " " OFF_LIGHT   " " OFF_LIGHT
#define SIGNAL_YELLOW	OFF_LIGHT    " " YELLOW_LIGHT" " OFF_LIGHT   " " OFF_LIGHT
#define SIGNAL_GREEN	OFF_LIGHT    " " OFF_LIGHT   " " OFF_LIGHT	" " GREEN_LIGHT
#define SIGNAL_LEFT		OFF_LIGHT    " " OFF_LIGHT	" " GREEN_ARROW	" " OFF_LIGHT


void clear_CUI(void);
const char* get_light_state_str(Light* light);
void display_intersection(Intersection* intersection);

#endif // !__TRAFIC_LIGHTS_CUI_H__
