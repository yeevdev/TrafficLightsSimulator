#include <stdio.h>
#include <windows.h>
#include "light.h"

#define LIGHT_NUM 4
//상태가 n개
typedef enum
{
	S0 = 0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7,
    STATE_COUNT
}state_t;



//각 상태에 맞는 신호등 상태
STATE light_state[STATE_COUNT][LIGHT_NUM] =
{
    //    A        B        C         D
       { GO_LEFT, STOP,    GO_LEFT, STOP    },
       { WAIT,    STOP,    WAIT,    STOP    },
       { GO_ST,   STOP,    GO_ST,   STOP    },
       { WAIT,    STOP,    WAIT,    STOP    },
       { STOP,    GO_LEFT, STOP,    GO_LEFT },
       { STOP,    WAIT,    STOP,    WAIT    },
       { STOP,    GO_ST,   STOP,    GO_ST   },
       { STOP,    WAIT,    STOP,    WAIT    }
};


int main(void)
{
	//초기화
    ULONGLONG last_tick = GetTickCount64();
    state_t cur_state = S0;
    state_t last_state = S0;
    unsigned long long wait_time = 4000;
    char input = 0;
    printf("0");
	//루프
	while (1)
	{
        ULONGLONG current_tick = GetTickCount64();
        
        
        //키 입력에 따라 state를 바꾸고 기존 state를 저장
        //키를 다시 누르면 해제
        //state가 너무 많다 싶으면 비상 state를 따로 만들어서 else if

        
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
                printf("1");
                // [호출]
                break;

            case S1:
                cur_state = S2;
                wait_time = 6000; // 60s
                printf("2");
                // [호출]
                break;

            case S2:
                cur_state = S3;
                wait_time = 600; // 6s
                printf("3");
                // [호출]
                break;

            case S3:
                cur_state = S4;
                wait_time = 4000; // 40s
                printf("4");
                // [호출]
                break;

            case S4:
                cur_state = S5;
                wait_time = 600; // 6s
                printf("5");
                // [호출]
                break;

            case S5:
                cur_state = S6;
                wait_time = 6000; // 60s
                printf("6");
                // [호출]
                break;

            case S6:
                cur_state = S7;
                wait_time = 600; // 6s
                printf("7");
                // [호출]
                break;

            case S7:
                cur_state = S0;
                wait_time = 4000; // 40s (처음 S0 시간으로 돌아감)
                printf("0");
                // [호출]
                break;
            }
        }
	}
	return 0;
}