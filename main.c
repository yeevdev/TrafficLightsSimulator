#include <stdio.h>
#include <windows.h>
#include ""

//상태가 n개 
enum state_t
{
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7
};

//각 상태에 맞는 신호등 상태


int main(void)
{
	//초기화

	//루프
	while (1)
	{
		state_t cur_state = S0;
		//호출
		Sleep(40000);//40s
		cur_state = S1;
		//호출
		Sleep(6000);//6s
		cur_state = S2;
		//호출
		Sleep(60000);//60s
		cur_state = S3;
		//호출
		Sleep(6000);//6s
		cur_state = S4;
		//호출
		Sleep(40000);//40s
		cur_state = S5;
		//호출
		Sleep(6000);//6s
		cur_state = S6;
		//호출
		Sleep(60000);//60s
		cur_state = S7;
		//호출
		Sleep(6000);//6s
	}
	return 0;
}

