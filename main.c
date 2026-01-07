#include "trafic_lights_CUI.h"


int main(void) {
	Light light1 = { 1, "Main St.", GO_ST };
	Light light2 = { 2, "1st Ave.", STOP };
	Light light3 = { 3, "2nd Ave.", GO_LEFT };
	Light light4 = { 4, "3rd Ave.", WAIT };

	printf("%s\n", get_light_state_str(&light1));

	return 0;
}