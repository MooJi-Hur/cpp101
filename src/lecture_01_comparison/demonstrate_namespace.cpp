#include <iostream>
#include "lecture_01_comparison/demonstrate_namespace.h"

using namespace std;

// 각각의 네임스페이스에 동일한 이름의 함수가 있는 경우
namespace AUser {
void myFunction(void) {
    cout << "I am in A." << endl;
}
}  // namespace AUser

namespace BUser {
void myFunction(void) {
    cout << "I am in B." << endl;
}
}  // namespace BUser

void demonstrateNamespace(void) {
    // 영역 구분자 ::를 이용해 어느 네임 스페이스에서 가져온 함수인지 표시
    AUser::myFunction();
    BUser::myFunction();
}