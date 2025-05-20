#include "pch.h"

DWORD WINAPI AlaramThread(LPVOID lpParam)
{
	int		seconds =	*(int*)lpParam;
	
	Sleep(seconds * 1000);
	printf("%d초 알람 (Thread ID:	%lu)\n", seconds, GetCurrentThreadId());

	return	0;

}

int main()
{
	int		alarmTimes[] = { 2, 5, 7 };
	HANDLE	threads[3];

	for (int i = 0; i < 3; i++)
	{
		threads[i] = CreateThread(
			NULL,
			0,
			AlaramThread,
			&alarmTimes[i],
			0,
			NULL
		);

		if ( threads[i] == NULL )
		{
			printf("쓰레드 생성 실패\n");
			return	1;
		}
	}
	
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);

	for ( int i = 0; i < 3; i++) 
	{
		CloseHandle(threads[i]);
	}

	printf("모든 알람 종료.\n");
	
}
