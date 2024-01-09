#include <iostream>

// MyNamespace 네임스페이스 선언
namespace MyNamespace {
    int myVariable = 42;

    void myFunction() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}

int main() {
    // using을 사용하여 MyNamespace와 std 네임스페이스의 내용을 현재 스코프로 가져오기
    using namespace MyNamespace;
    using namespace std;

    // MyNamespace의 변수와 함수에 직접 접근
    cout << "Value of myVariable: " << myVariable << endl;
    myFunction();

    // std 네임스페이스의 내용에도 직접 접근
    cout << "Hello, using std namespace!" << endl;

    return 0;
}
