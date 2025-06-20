# Windows Thread Practice Project

이 프로젝트는 Windows API를 사용한 스레드 프로그래밍 실습 프로젝트입니다.

## 프로그램 설명

이 프로그램은 여러 개의 알람을 동시에 실행하는 멀티스레드 예제입니다.

### 주요 기능
1. 여러 개의 알람 동시 실행
   - 각 알람은 별도의 스레드에서 실행
   - 서로 다른 시간(2초, 5초, 7초)의 알람을 동시에 처리

2. 스레드 관리
   - CreateThread() 함수를 사용한 스레드 생성
   - WaitForMultipleObjects()를 통한 스레드 동기화
   - 스레드 핸들 관리 및 정리

### 실행 예시
```
2초 알람 (Thread ID: 1234)
5초 알람 (Thread ID: 1235)
7초 알람 (Thread ID: 1236)
모든 알람 종료.
```

## 프로젝트 개요

- Windows API의 스레드 관련 기능들을 학습하고 실습
- 멀티스레드 프로그래밍의 기본 개념 이해
- 스레드 동기화 기법 학습

## 주요 학습 내용

1. 스레드 생성 및 관리
   - CreateThread() 함수 사용
   - 스레드 핸들 관리
   - 스레드 종료 처리

2. 스레드 동기화
   - Critical Section
   - Mutex
   - Semaphore
   - Event Object

3. 스레드 간 통신
   - 공유 메모리
   - 메시지 큐


## 참고 자료

- [Microsoft Windows Thread Documentation](https://learn.microsoft.com/ko-kr/windows/win32/procthread/processes-and-threads)
- [Windows API Programming](https://learn.microsoft.com/ko-kr/windows/win32/api/)