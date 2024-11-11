#include <iostream>
#include <string>

using namespace std;

// 추상 클래스 Abstract Class
// 하나 이상의 순수 가상 클래스를 포함하는 클래스
// 순수 가상 함수는 본문을 정의하지 않고 =0을 표기
class Drink {
  public:
    virtual void showPureVirtualFunction() = 0;
};

class Tea {
  public:
    // Tea* 로 인스턴스를 만들 경우, 메모리에 주소를 찾아가는 바인딩 주소가 고정됨
    // 컴파일 시에는 객체를 특정할 수 없음
    // 리소스를 절약하기 위해 정적 바인딩을 기본값으로 사용
    void showStaticBinding() { cout << "This is static Binding of Tea." << endl; };

    virtual void showDynamicBinding() {
        cout << "This is dynamic Binding of Tea on virtual Function table." << endl;
    };
};

class BlackTea : public Tea, public Drink {
  public:
    // Tea 클래스의 멤버 함수를 overriding
    // 포인터로 객체에 접근할 경우, 포인터를 정의한 타입을 기준으로 함수에 접근
    // 정적으로 오버라이드 한 함수는 Tea*로 정의한 포인터에서는 호출되지 않음
    void showStaticBinding() { cout << "This is static Binding of Tea." << endl; };

    // virtual 키워드를 사용하면 가상 함수 테이블에 멤버 함수의 주소가 저장됨
    virtual void showDynamicBinding() {
        cout << "This is dynamic Binding of BlackTea on virtual Function table." << endl;
    };

    // 순수 가상 함수를 사용하기 위해서는 본문을 정의해야 함
    virtual void showPureVirtualFunction() {
        cout << "This is dynamic Binding of BlackTea on pure virtual table." << endl;
    };
};

int main(void) {
    // Tea 클래스 포인터 인스턴스
    Tea* defaultOrder;

    Tea firstOrder;

    BlackTea secondOrder;

    defaultOrder = &firstOrder;

    // Tea 클래스의 멤버 함수가 실행됨
    defaultOrder->showStaticBinding();  // This is static Binding of Tea.

    defaultOrder->showDynamicBinding();  // This is dynamic Binding of Tea on virtual Binding table.

    // 포인터를 BlackTea 인스턴스인 secondOrder의 주소로 변경
    defaultOrder = &secondOrder;

    // 정적 바인딩. Tea 클래스의 멤버 함수가 실행됨
    defaultOrder->showStaticBinding();  // This is static Binding of Tea.

    // 동적 바인딩. BlackTea 클래스의 멤버 함수가 실행됨
    defaultOrder
        ->showDynamicBinding();  // This is dynamic Binding of BlackTea on virtual Binding table.

    // 추상 클래스 및 순수 가상 함수
    BlackTea fourthOrder;

    // BlackTea의 순수 가상 함수 호출
    fourthOrder
        .showPureVirtualFunction();  // This is dynamic Binding of BlackTea on pure virtual table.

    // 추상 클래스는 직접 인스턴스를 만들 수 없음
    // Drink thirdOrder;

    // 추상 클래스 포인터 인스턴스
    Drink* drinkPointer = &fourthOrder;

    // BlackTea에 정의된 가상 함수를 바라봄
    drinkPointer
        ->showPureVirtualFunction();  // This is dynamic Binding of BlackTea on pure virtual table.

    return 0;
}