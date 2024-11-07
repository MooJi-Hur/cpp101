#include <iostream>
#include <string>

using namespace std;

class Order {
  private:
    string name;
    int    countCoupon;
    int    countCoffee;
    int    countBlacktea;

    int getSumPrice() { return countCoffee * 2000 + countBlacktea * 3000; }

  public:
    // constructor
    // 생성자, 따로 설정하지 않을 경우 기본 생성자가 호출됨
    // 기본 생성자는 자료 반환형이 없으며, 매개 변수 없이 각 멤버 변수를 0, NULL 등으로 초기화
    // 아래 생성자에서 this->name = name과 name(name)은 동일한 표현 방식
    Order(string name, int countCoffee, int countBlacktea)
        : name(name), countCoupon(0), countCoffee(countCoffee), countBlacktea(countBlacktea) {};

    // copy constructor
    // 깊은 복사. 별도의 메모리 공간에 멤버 변수 값을 복사
    // 호출 방식 Order moojiTomorrow(moojiToday);
    // const 상수화, 복사 대상을 수정하지 않음, 복사 생성자 내에서 원본 객체가 수정되지 않도록 보장
    // Order& 참조자, 원본 Order주소를 통해 원본 객체에 접근
    Order(const Order& origin) {
        name          = origin.name;
        countCoupon   = origin.countCoupon;
        countCoffee   = origin.countCoffee;
        countBlacktea = origin.countBlacktea;
    }

    // destructor
    ~Order() { cout << "Order " << name << " completed!" << endl; };

    void takeCoupon() { countCoupon++; }

    void show() {
        cout << "Name : " << name << "\nTotal : " << getSumPrice()
             << "\nCurrent Coupon : " << countCoupon << endl;
    }
};

int main(void) {
    // 생성자를 호출하여 새 인스터스 생성
    Order moojiToday = Order("MooJi", 3, 2);

    moojiToday.takeCoupon();

    moojiToday.show();  // 1

    // 깊은 복사의 방식으로 새 인스턴스 생성
    Order moojiTomorrow(moojiToday);

    moojiTomorrow.show();  // 1

    moojiTomorrow.takeCoupon();

    moojiTomorrow.show();  // 2

    // 깊은 복사이므로 moojiTomorrow에서 복사 이후에 실행한 쿠폰 정보 업데이트는 반영되지 않음
    moojiToday.show();  // 1

    // 동적 할당을 통한 인스턴스 생성
    Order* minjiToday = new Order("MinJi", 1, 1);

    minjiToday->takeCoupon();

    minjiToday->show();  // 1

    Order minjiTomorow(*minjiToday);

    minjiTomorow.takeCoupon();

    minjiTomorow.show();  // 2

    minjiToday->show();  // 1

    // 동적 할당을 통해 인스턴스를 만든 경우에는 delete 키워드를 이용해 할당 해제를 해야 함
    // 얕은 복사를 수행했었을 경우, 해당 할당해제로 인해 dangling pointer 문제 발생하지 않는지
    // 확인해야 함
    delete minjiToday;

    // main 함수가 종료될 때 소멸자 ~Order이 호출됨

    return 0;
}