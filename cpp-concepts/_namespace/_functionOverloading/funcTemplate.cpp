#include <iostream>

// 함수 템플릿: 두 수를 더하는 함수
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // 정수형 두 수를 더하는 함수 호출
    int resultInt = add(5, 3);
    std::cout << "Result (Int): " << resultInt << std::endl;

    // int로 캐스팅하여 사용한 다중정의 템플릿 사용
    std::cout << add<int>(5, 3) << std::endl;

    // 실수형 두 수를 더하는 함수 호출
    double resultDouble = add(2.5, 3.7);
    std::cout << "Result (Double): " << resultDouble << std::endl;

    return 0;
}
