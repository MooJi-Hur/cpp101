#include <iostream>
#include <string>

using namespace std;

// 부모 클래스 1
class IngredientUnit {
  private:
    int unitWater = 100;
    int unitSugar = 10;

  public:
    // 별도의 생성자를 명시하지 않고, 기본 생성자를 사용할 예정
    // 함수 이름을 unitWater로 하면 private의 변수명과 같아서 접근할 수 없다고 나옴
    int getUnitWater() { return unitWater; }
    int getUnitSugar() { return unitSugar; }
};

// 부모 클래스 2
class Tea {
  private:
    int water;
    int count;
    int price = 3000;

  public:
    // price는 생성자를 통해 값을 입력하지 않고 기본 값을 그대로 사용
    // water(water) 멤버 변수(파라미터 값), this->water=water
    Tea(int water, int count) : water(water), count(count) {}

    int getCount() { return count; }
    int getWater() { return water; }

    void showPrice() { cout << "The total price : " << price * count << endl; }
};

// c++은 다중 상속이 가능함
// 다만, 멤버 변수가 중복되거나, 상속받을 클래스의 포인터가 해제 될 때의 관리 위험이 있음

// 접근 제한자 private, protected, public
// 기존 클래스 내의 접근 제한자와 별개로, 최대 권한을 재기술
// 상속 시 struct는 public, class는 private 가 기본 접근 제한자
class BlackTea : public Tea, private IngredientUnit {
  private:
    int sugarLevel;

  public:
    // 상속을 받았을 때 생성자 표현
    // Tea(water, count) 는 inline Tea::Tea(int water, int count)를 실행한 것
    BlackTea(int water, int count, int sugarLevel) : sugarLevel(sugarLevel), Tea(water, count) {}

    void showSugarLevel() { cout << "Current sugar level : " << sugarLevel << endl; }

    void showIngredients() {
        // IngredientUnit을 private로 상속받았음
        // IngredientUnit에 있는 public 함수는 main에서 firstOrder.getUnitWater로 불러오지 못함
        cout << "The total sugar : " << getCount() * getUnitSugar() * sugarLevel << endl;
        cout << "The total water : " << getCount() * getUnitWater() * getWater() << endl;
    }
};

int main(void) {
    // BlackTea의 인스턴스인 firstOrder 생성
    // 클래스 자체는 힙이나 스택에 할당되지 않으며 인스턴스를 생성해야 객체의 멤버가 메모리에 할당됨
    // water = 2, count = 3, sugarLevel = 2;
    // 인스턴스 생성 과정은 src/lecture_04_inheritance/README.md 참조
    BlackTea firstOrder = BlackTea(2, 3, 2);

    firstOrder.showPrice();  // The total price : 9000

    cout << "Current value of water : " << firstOrder.getWater()
         << endl;  // Current value of water : 2

    firstOrder.showSugarLevel();   // Current sugar level : 2
    firstOrder.showIngredients();  // The total sugar : 60 // The total water : 600

    return 0;
}