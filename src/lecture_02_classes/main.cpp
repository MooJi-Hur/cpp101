#include <iostream>
#include <string>

// string 자료형을 사용하기 위한 네임스페이스 설정
using namespace std;

// 클래스
// c의 struct와 다르게 함수도 멤버에 포함할 수 있음
// 멤버의 기본 접근 한정자가 c와는 반대로 private임
class Order {
    // 접근 한정자
  private:
    // 인스턴스를 생성하면, 변수는 각 인스턴스마다 다른 메모리 영역에 저장
    string name;
    int    coffee;
    int    blacktea;

    // 멤버 함수를 Method라고도 함
    // private에 작성했으므로 클래스 내에서만 접근 가능한 함수
    // 각 인스턴스를 생성하더라도 하나의 함수를 참조
    int sumPrice() { return coffee * 2000 + blacktea * 3000; };

  public:
    // 생성자, 클래스 이름과 같은 함수
    // 파라미터의 이름을 멤버의 이름과 동일하게 맞춘 상태
    // 멤버 변수의 name과 생성자 파라미터의 name을 구분할 방법이 필요
    // this를 포인터로 사용할 경우 멤버 변수의 name을 지칭
    Order(string name, int coffee, int blacktea) {
        this->name     = name;
        this->coffee   = coffee;
        this->blacktea = blacktea;
    };

    // public에 작성했으므로 외부에서 접근 가능한 함수
    void show() { cout << "Total : " << sumPrice() << endl; }
};

int main(void) {
    // 인스턴스 생성
    Order myOrder = Order("MooJi", 2, 3);

    // Total : 13000 출력
    myOrder.show();

    return 0;
}