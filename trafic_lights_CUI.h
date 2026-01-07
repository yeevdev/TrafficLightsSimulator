#ifndef __TRAFFIC_LIGHTS_CUI_H__
#define __TRAFFIC_LIGHTS_CUI_H__

#include <stdio.h>
#include "light.h"


// 현재 화면을 클리어하는 함수
void clear_CUI();

// 신호등의 상태를 참조해서 문자열으로 반환하는 함수
const char* get_light_state_str(Light* light);

#endif