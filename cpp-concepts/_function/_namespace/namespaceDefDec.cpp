#include <iostream>

// 네임스페이스 선언
namespace myNamespace {
    // 정수형 변수 선언 및 정의
    int myVariable = 42;

    // 함수 선언 및 정의
    void myFunction() {
        std::cout << "Hello from myFunction!" << std::endl;
    }
}

int main() {
    // 네임스페이스의 변수와 함수 사용
    std::cout << "Value of myVariable: " << myNamespace::myVariable << std::endl;
    myNamespace::myFunction();

    return 0;
}
