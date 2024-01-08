#include <iostream>

// 함수 선언에서 디폴트 매개변수 사용
void printMessage(std::string message = "Hello, World!");

int main() {
    // 디폴트 매개변수를 사용하여 함수 호출
    printMessage(); // "Hello, World!" 출력
    printMessage("Custom Message"); // "Custom Message" 출력

    return 0;
}

// 함수 정의에서 디폴트 매개변수 사용
void printMessage(std::string message) {
    std::cout << message << std::endl;
}
