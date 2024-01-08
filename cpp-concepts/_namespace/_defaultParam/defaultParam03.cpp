#include <iostream>

// 두 개의 매개변수 중 하나만 디폴트 값으로 설정
void printNumbers(int a, int b = 10);

int main() {
    printNumbers(5); // 두 번째 매개변수에는 디폴트 값이 사용됨
    printNumbers(7, 20); // 두 번째 매개변수에 전달된 값이 사용됨

    return 0;
}

// 함수 정의에서는 디폴트 값을 설정한 매개변수에 대해 다시 기술하지 않음
void printNumbers(int a, int b) {
    std::cout << "First number: " << a << std::endl;
    std::cout << "Second number: " << b << std::endl;
}
