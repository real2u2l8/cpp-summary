#include <iostream>

// 인라인 함수: 두 수를 더하는 함수
inline int addInline(int a, int b) {
    return a + b;
}

// 매크로: 두 수를 더하는 매크로
#define ADD_MACRO(a, b) ((a) + (b))

int main() {
    int x = 5, y = 3;

    // 인라인 함수 호출
    int resultInline = addInline(x, y);
    std::cout << "Result using inline function: " << resultInline << std::endl;

    // 매크로 사용
    int resultMacro = ADD_MACRO(x, y);
    std::cout << "Result using macro: " << resultMacro << std::endl;

    return 0;
}