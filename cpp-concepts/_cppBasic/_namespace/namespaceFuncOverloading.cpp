#include <iostream>

using namespace std;

void myNamespaceFunc(void){
    cout << "::myNamespaceFunc()" << endl;
}

namespace TEST{
    void myNamespaceFunc(void){
        cout << "TEST::myNamespaceFunc()" << endl;
}

namespace MYTEST {

    void myNamespaceFunc(){
        cout << "MYTEST::myNamespaceFunc()" << endl;
    }
}

int main(){
    myNamespaceFunc();
    ::myNamespaceFunc();
    TEST::myNamespaceFunc();
    MYTEST::myNamespaceFunc();

    return 0;
}
