#include <stdio.h>
#include <windows.h>
#include "light.h"

//상태가 n개 
enum state_t {
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7
};

int main(void) {
	Light light = { 1, "test", GO_ST };
	print_light(&light);
	change_light(&light, WAIT); print_light(&light);
	change_light(&light, STOP); print_light(&light);
	change_light(&light, GO_LEFT); print_light(&light);
	
	return 0;
}