#include <iostream>

// 함수 다중 정의: 정수형 두 수를 더하는 함수
int add(int a, int b) {
    return a + b;
}

// 함수 다중 정의: 실수형 두 수를 더하는 함수
double add(double a, double b) {
    return a + b;
}

int main() {
    // 정수형 두 수를 더하는 함수 호출
    int resultInt = add(5, 3);
    std::cout << "Result (Int): " << resultInt << std::endl;

    // 실수형 두 수를 더하는 함수 호출
    double resultDouble = add(2.5, 3.7);
    std::cout << "Result (Double): " << resultDouble << std::endl;

    return 0;
}
