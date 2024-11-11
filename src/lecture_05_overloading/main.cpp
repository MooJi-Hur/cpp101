#include <iostream>
#include <string>

using namespace std;

class Order {
  private:
    string menuName;
    int    price = 3000;

  public:
    Order(string menuName, int price) : menuName(menuName), price(price) {};

    // 함수 오버로딩 : 함수 또 쓰기
    // 같은 함수의 이름을 이용해 함수를 재정의
    // 정의가 다르므로, 기존 함수와 또 쓴 함수를 모두 하나의 클래스에서 불러볼 수 있음
    // 기존 함수와 매개 변수의 타입이나 갯수가 달라야 함
    Order(string menuName) : menuName(menuName) {};

    // 생성자 오버로딩 : 연산자를 재정의
    // 피연산자의 기본적인 틀은 같아야 하며, 하나 이상의 피연산자는 직접 정의한 자료형이어야 함
    // 멤버 연산자 . 나 범위 연산자 :: 등은 재정의할 수 없음
    // 계산 연산자를 재정의하여 코드 양을 줄이는데 많이 활용됨
    Order operator+(const Order& other) {
        return Order(menuName + " & " + other.menuName, price + other.price);
    }

    void showOrder() { cout << "Menu : " << menuName << "\nPrice : " << price << endl; }
};

int main(void) {
    // 함수 오버로딩 : 재정의한 생성자 (생성자도 함수)를 사용
    Order firstOrder = Order("coffee");

    firstOrder.showOrder();  // Menu : coffee //Price : 3000

    Order secondOrder = Order("blackTea", 5000);

    secondOrder.showOrder();  // Menu : blackTea // Price : 5000

    // 생성자 오버로딩 : 재정의한 연산자를 사용
    Order allMenu = firstOrder + secondOrder;

    allMenu.showOrder();  // Menu : coffee & blackTea // Price : 8000

    return 0;
}
