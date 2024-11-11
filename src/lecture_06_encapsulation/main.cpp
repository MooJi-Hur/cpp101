#include <iostream>
#include <string>

using namespace std;

class Tea {
    // friend class 키워드로 BlackTea 클래스는 Tea의 private 멤버에도 접근할 수 있음
    friend class BlackTea;

  private:
    // id를 const 키워드를 이용해 상수로 선언
    // 생성자로 값을 초기화 한 후에는 setter 설정이 불가능
    const int id;
    int       water;
    int       price = 3000;

  public:
    // 정적 멤버 선언
    // 하나의 메모리에서 값을 관리
    static int orderCount;

    // orderCount++를 삽입하여, Tea 생성자가 호출 될 때마다 값이 1씩 증가
    Tea(int id, int water) : id(id), water(water) { orderCount++; };

    // 생성자 overloading
    Tea(int id, int water, int price) : id(id), water(water), price(price) { orderCount++; };

    void showPrice() { cout << "The price : " << price << endl; };
};

class BlackTea : public Tea {
  private:
    int sugarLevel;

  public:
    BlackTea(int id, int water, int sugarLevel) : sugarLevel(sugarLevel), Tea(id, water) {};

    // 생성자 overloading
    BlackTea(int id, int water, int price, int sugarLevel)
        : sugarLevel(sugarLevel), Tea(id, water, price) {};

    void showSugarLevel() { cout << "The sugar level : " << sugarLevel << endl; };

    // Tea 클래스 내 friend class로 BlackTea를 설정했으므로
    // 별도의 getter를 설정하지 않고도 Tea의 private 멤버를 가져와 사용
    void showUnitPrice() { cout << "The unit price : " << price << endl; };
};

class EarlGrayTea : public Tea {
  private:
    int coupon;

  public:
    EarlGrayTea(int id, int water, int coupon) : coupon(coupon), Tea(id, water) {};

    // friend 키워드를 멤버 함수에 적용한 경우
    // 다른 객체의 private 멤버 변수를 바로 가져와서 사용
    friend void mergeCoupon(EarlGrayTea myEarlGrayTea, EarlGrayTea yourEarlGrayTea) {
        cout << "Total coupon : " << myEarlGrayTea.coupon + yourEarlGrayTea.coupon << endl;
    };

    void showOrderCount() { cout << "Current order count: " << orderCount << endl; };
};

// 정적 멤버인 orderCount를 클래스 외부에서 초기화
// 새로운 인스턴스가 생성되더라도 초기화 되지 않고, 프로그램을 실행할 때 한 번만 초기화 됨
int Tea::orderCount = 0;

int main(void) {
    BlackTea firstOrder = BlackTea(1, 2, 3);

    cout << "The order count : " << firstOrder.orderCount << endl;  // The order count : 1

    firstOrder.showPrice();      // The price : 3000
    firstOrder.showUnitPrice();  // The price : 3000

    BlackTea secondOrder = BlackTea(2, 3, 5000, 0);

    cout << "Current order count on first order : " << firstOrder.orderCount
         << endl;  // Current order count on first order : 2
    cout << "Current order count on second order : " << secondOrder.orderCount
         << endl;  // Current order count on second order : 2

    firstOrder.showUnitPrice();   // The price : 3000
    secondOrder.showUnitPrice();  // The price : 5000

    EarlGrayTea thirdOrder = EarlGrayTea(3, 5, 1);

    // Tea 클래스 생성자가 총 3번 호출됨
    thirdOrder.showOrderCount();  // Current order count: 3

    // Tea::showPrice()
    thirdOrder.showPrice();  // The price : 3000

    EarlGrayTea fourthOrder = EarlGrayTea(4, 3, 2);

    // 멤버 함수는 this 포인터를 통해서 접근
    fourthOrder.showOrderCount();  // Current order count: 4

    fourthOrder.showPrice();  // The price : 3000

    // 코드 영역의 일반 함수에 할당, this 포인터가 없음
    // 클래스 외부에 정의되어 private에 정의된 thirdOder.coupon, fourthOrder.coupon에 접근 가능
    mergeCoupon(thirdOrder, fourthOrder);  // Total coupon : 3

    return 0;
}