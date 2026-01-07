#include <stdio.h>
#include <windows.h>
#include "light.h"

#define LIGHT_NUM 4
//상태가 n개
typedef enum {
	S0 = 0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7,
    STATE_COUNT
} state_t;



//각 상태에 맞는 4차선 신호등 상태
LightState light_state[STATE_COUNT][LIGHT_NUM] = {
	//  A      B       C       D
    { LEFT,   RED,    LEFT,   RED    },
    { YELLOW, RED,    YELLOW, RED    },
    { GREEN,  RED,    GREEN,  RED    },
    { YELLOW, RED,    YELLOW, RED    },
    { RED,    LEFT,   RED,    LEFT   },
    { RED,    YELLOW, RED,    YELLOW },
    { RED,    GREEN,  RED,    GREEN  },
    { RED,    YELLOW, RED,    YELLOW }
};

//4차선 신호 변경
void set_light_state(Intersection *ints, state_t state) {
	ints->north.state = light_state[state][0];
	ints->west.state = light_state[state][1];
	ints->south.state = light_state[state][2];
	ints->east.state = light_state[state][3];
}

int main(void) {
	//초기화


    ULONGLONG last_tick = GetTickCount64();
    state_t cur_state = S0;
    
    unsigned long long wait_time = 4000;
    Intersection ints;
    set_light_state(&ints, cur_state);
    refresh_intersection(&ints);


    //키 입력을 위한 부분
    state_t last_state = S0;
    char input = 0;

    
	//루프
	while (1)
	{
        ULONGLONG current_tick = GetTickCount64();

        // 2. 시간 비교 (현재시간 - 마지막변경시간 >= 대기시간)
        if (current_tick - last_tick >= wait_time)
        {
            // 기준 시간(last_tick)을 현재로 갱신 (타이머 리셋 효과)
            last_tick = current_tick;

            // 상태 전이 로직
            switch (cur_state)
            {
            case S0:
                cur_state = S1;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S1:
                cur_state = S2;
                wait_time = 6000; // 60s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S2:
                cur_state = S3;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S3:
                cur_state = S4;
                wait_time = 4000; // 40s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S4:
                cur_state = S5;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S5:
                cur_state = S6;
                wait_time = 6000; // 60s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S6:
                cur_state = S7;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S7:
                cur_state = S0;
                wait_time = 4000; // 40s (처음 S0 시간으로 돌아감)
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;
            }
        }
	}
	return 0;
}