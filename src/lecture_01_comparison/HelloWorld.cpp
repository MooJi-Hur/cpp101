#include <iostream>  // 표준 입출력 라이브러리. 최근에는 .h 확장자를 붙이지 않아도 됨

// 여러 사람이 함께 작업하여 중복된 함수명을 가져와 쓰더라도 이름 영역 (namespace)로 구분
// std는 c++는 iostream에 있는 함수를 사용하기 위한 네임스페이스
// using namespace 키워드를 사용하지 않을 경우, std::cout으로 매번 범위 지정 연산자를 사용해야 함
using namespace std;

int main(void) {
    // 형식 지정자를 사용하지 않아도 됨
    // endl은 \n을 추가하면서 출력을 종료한 것
    cout << "Hello, World!" << endl;

    return 0;
}