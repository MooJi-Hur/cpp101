#include <iostream>
#include <string>

using namespace std;

// template 키워드를 사용해 여러 데이터 타입을 처리
// 값을 교환하는 예제
template <typename MyParameterType>
void change(MyParameterType& sourceValue, MyParameterType& targetValue) {
    MyParameterType roomForCopy;

    roomForCopy = sourceValue;
    sourceValue = targetValue;
    targetValue = roomForCopy;

    cout << sourceValue << targetValue << endl;
}

// 명시적 특수화
// 지정한 타입에 대해서는 다른 로직을 추가할 때 사용
template <>
void change<int>(int& sourceValue, int& targetValue) {
    int roomForCopy;

    roomForCopy = sourceValue;
    sourceValue = targetValue;
    targetValue = roomForCopy;

    cout << "It's a int type. " << sourceValue << " " << targetValue << endl;
}

// 클래스에도 template 키워드를 적용할 수 있음
// 아무 자료형을 입력하지 않은 경우, int를 기본 값으로 다루도록 할당
template <typename MyType = int>
class SetterGetter {
  private:
    MyType myVariable;

  public:
    SetterGetter(MyType myVariable) : myVariable(myVariable) {}

    void setMyVariable(MyType myVariable) { this->myVariable = myVariable; }

    MyType getMyVariable() { return myVariable; }
};

int main(void) {
    // 함수 파라미터에 템플릿을 적용한 경우
    string firstString  = "world!";
    string secondString = "Hello, ";

    change(firstString, secondString);  // Hello, world!

    // 함수 파라미터에 템플릿을 적용할 때
    // 특정한 타입에는 다른 로직을 추가한 경우
    int firstInt  = 33;
    int secondInt = 66;

    change(firstInt, secondInt);  // It's a int type. 66 33

    // 직접 초기화 방식 - 매개 변수를 생성자에 직접 전달
    SetterGetter<> intVariable(1);

    // 복사 초기화 방식 - 컴파일 방식에 따라서는 임시 객체 생성 후 대입할 수도 있음
    // SetterGetter<> intVariable = SetterGetter(1);
    // 컴파일을 할 때, 코드에 명기된 자료형 (int, string)에 해당하는 템플릿 인스턴스를 각각 만들게
    // 됨
    SetterGetter<string> stringVariable("Hi!");

    // 복사 초기화 방식 - SetterGetter<string> 자료형과 데이터 타입을 모두 작성한 점 봐두기
    // SetterGetter<string> stringVariable = SetterGetter<string>("Hello");

    cout << "int variable : " << intVariable.getMyVariable()
         << "\nstring variable : " << stringVariable.getMyVariable()
         << endl;  // int variable : 1 // string variable : Hi!

    return 0;
}