#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
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
    S8,//여기부턴 키입력에 의한 state
    S9,
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
    { RED,    YELLOW, RED,    YELLOW },
    { YELLOW, YELLOW, YELLOW, YELLOW },
	{ RED,    RED,    RED,    RED    }
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
    
    ULONGLONG wait_time = 4000;
    Intersection ints;
    set_light_state(&ints, cur_state);
    refresh_intersection(&ints);

    //키 입력을 위한 부분
    state_t last_state = S0;
    char input = 0;

    //키 입력에 따라 state를 바꾸고 기존 state를 저장 
    //키를 다시 누르면 해제 
    //state가 너무 많다 싶으면 비상 state를 따로 만들어서 else if
    
	//루프
	while (1)
	{
		bool flag = false;
        ULONGLONG current_tick = GetTickCount64();
        if (_kbhit()) 
            input = _getch();

        if (input == 'b' || input == 'e' || input == 's')
        {
            switch (input)
            {
            case 'b': //비상, 전체 RED 점멸 
                cur_state = S8;     
                flag = true;
                input = 0;
                break;
             
            case 's': //끝
				cur_state = last_state;
                wait_time = 0;
                input = 0;
                break;
            }
        }


        // 2. 시간 비교 (현재시간 - 마지막변경시간 >= 대기시간)
        if (current_tick - last_tick >= wait_time || flag)
        {
            // 기준 시간(last_tick)을 현재로 갱신 (타이머 리셋 효과)
            last_tick = current_tick;

            // 상태 전이 로직
            switch (cur_state)
            {
            case S0:
                last_state = cur_state;
                cur_state = S1;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S1:
                last_state = cur_state;
                cur_state = S2;
                wait_time = 6000; // 60s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S2:
                last_state = cur_state;
                cur_state = S3;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S3:
                last_state = cur_state;
                cur_state = S4;
                wait_time = 4000; // 40s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S4:
                last_state = cur_state;
                cur_state = S5;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S5:
                last_state = cur_state;
                cur_state = S6;
                wait_time = 6000; // 60s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S6:
                last_state = cur_state;
                cur_state = S7;
                wait_time = 600; // 6s
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            case S7:
                last_state = cur_state;
                cur_state = S0;
                wait_time = 4000; // 40s (처음 S0 시간으로 돌아감)
                
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;

            //예외 케이스
            case S8:
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);

                cur_state = S9;
                wait_time = 600; //6s           
                break;

            case S9:
                wait_time = 1000000000;// 무한대기
                // [호출]
                set_light_state(&ints, cur_state);
                refresh_intersection(&ints);
                break;
            }
        }
	}
	return 0;
}