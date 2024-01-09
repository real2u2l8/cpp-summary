#include <iostream>

// 함수 원형 선언에서 매개변수 이름을 생략
void printNumbers(int = 1, int = 2);

int main() {
    // 함수 호출 시에는 매개변수의 이름을 제공해야 함
    printNumbers(5, 10);

    return 0;
}

// 함수 정의에서는 매개변수의 이름을 제공
void printNumbers(int a, int b) {
    std::cout << "First number: " << a << std::endl;
    std::cout << "Second number: " << b << std::endl;
}
 //강조되는 부분은 디폴트 매개변수는 반드시 함수 원형 선언 부분에 기술해야 함.