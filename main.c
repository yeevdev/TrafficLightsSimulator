#include <stdio.h>
#include <windows.h>


//상태가 n개
typedef enum
{
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7
}state_t;

//각 상태에 맞는 신호등 상태


int main(void)
{
	//초기화
    ULONGLONG last_tick = GetTickCount64();
    state_t cur_state = S0;
    unsigned long long wait_time = 4000;
    printf("0");
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

