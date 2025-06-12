/**
 * @file Thread-Callback-Win32.cpp
 * @brief Windows API를 사용한 쓰레드와 콜백 함수 예제 프로그램
 * @details 사용자가 입력한 시간 후에 알람이 울리는 프로그램으로,
 *          쓰레드와 콜백 함수의 기본적인 사용법을 보여줍니다.
 * @author real2u2l8
 * @date 2025-06-12
 */

#include "pch.h"

/**
 * @brief 알람 콜백 함수의 타입 정의
 * @details CALLBACK은 Windows API에서 사용하는 호출 규약을 지정하는 매크로입니다.
 */
typedef void (CALLBACK *ALARM_CALLBACK)();

/** @brief 전역 콜백 함수 포인터 */
ALARM_CALLBACK g_AlarmCallback = nullptr;

/**
 * @brief 알람 콜백 함수를 설정하는 함수
 * @param cb 설정할 콜백 함수 포인터
 */
void SetAlarmCallback(ALARM_CALLBACK cb) {
    g_AlarmCallback = cb;
}

/**
 * @brief 알람 타이머 쓰레드 함수
 * @param lpParam 대기할 시간(초)을 담은 포인터
 * @return 쓰레드 종료 코드
 * @details 지정된 시간동안 1초씩 카운트다운하며 대기한 후 콜백 함수를 호출합니다.
 */
DWORD WINAPI AlarmThread(LPVOID lpParam) {
    int seconds = *(int*)lpParam;  // void 포인터를 int로 변환
    std::cout << "[AlarmThread] " << seconds << "초 후 알람 예정...\n";

    // 초 단위로 카운트다운
    while (seconds > 0) {
        std::cout << seconds << "초 남았습니다...\n";
        Sleep(1000);  // 1초(1000밀리초) 대기
        seconds--;
    }

    // 설정된 콜백 함수가 있다면 호출
    if (g_AlarmCallback) {
        g_AlarmCallback();  // 알람 울림 콜백 호출
    }

    return 0;
}

/**
 * @brief 실제 알람 동작을 수행하는 콜백 함수
 * @details 시스템 비프음을 발생시키고 알람 메시지를 출력합니다.
 */
void CALLBACK MyAlarmRings() {
    std::cout << "\a[ALARM]  알람이 울립니다! \n";  // \a는 시스템 비프음
    Sleep(1000);  // 1초 대기
}

/**
 * @brief 메인 함수
 * @return 프로그램 종료 코드
 * @details 사용자로부터 알람 시간을 입력받아 알람 쓰레드를 생성하고 관리합니다.
 */
int main() {
    while (true) {
        std::cout << "알람을 설정할 시간(초)을 입력하세요 (종료: 0): ";
        int delaySeconds;
        std::cin >> delaySeconds;

        // 종료 조건 검사
        if (delaySeconds == 0) {
            break;
        }

        // 입력값 유효성 검사
        if (delaySeconds < 0) {
            std::cout << "올바른 시간을 입력해주세요.\n";
            continue;
        }

        std::cout << "[Main] 알람 콜백 등록\n";
        SetAlarmCallback(MyAlarmRings);

        // 알람 쓰레드 생성 및 실행
        HANDLE hThread = CreateThread(NULL, 0, AlarmThread, &delaySeconds, 0, NULL);
        WaitForSingleObject(hThread, INFINITE);  // 쓰레드가 종료될 때까지 대기
        CloseHandle(hThread);  // 쓰레드 핸들 해제

        // 다음 입력을 위한 대기
        std::cout << "다음 알람 설정을 위해 Enter를 누르세요...";
        std::cin.ignore(INT_MAX, '\n');  // 입력 버퍼 비우기
        std::cin.get();  // Enter 키 대기
    }

    std::cout << "[Main] 프로그램 종료\n";
    return 0;
}
