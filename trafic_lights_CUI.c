#include "trafic_lights_CUI.h"

// 현재 화면을 클리어하는 함수
void clear_CUI() {
	for(int i = 0; i < 100; i++) {
		printf("\n\r");
	}
}

const char* get_light_state_str(Light* light) {
	switch(light->state) {
		case GO_LEFT:
			return "\033[32m←\033[0m\n";
		case WAIT:
			return "\033[33m●\033[0m\n";
		case STOP:
			return "\033[31m●\033[0m\n";
		case GO_ST:
			return "\033[32m●\033[0m\n";
	}
}

