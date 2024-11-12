#include <iostream>

using namespace std;

int main(void) {
    // unique pointer
    // 스마트 포인터 하나와 객체 하나를 연결
    // 소유권 이전 및 할당 해제 가능
    cout << "Unique Pointer" << endl;
    unique_ptr<int> firstPointer(new int(10));
    unique_ptr<int> secondPointer;

    cout << "Current first pointer : " << firstPointer << endl;  // Current first pointer : 0x7...80
    cout << "Current second pointer : " << secondPointer << endl;  // Current second pointer : 0x0

    cout << "\nmove" << endl;

    secondPointer = std::move(firstPointer);

    cout << "Current first pointer : " << firstPointer << endl;  // Current first pointer : 0x0
    cout << "Current second pointer : " << secondPointer
         << endl;  // Current second pointer : 0x7...80

    cout << "Current Value : " << *secondPointer << endl;  // Current Value : 10

    cout << "\nreset" << endl;

    secondPointer.reset();

    cout << "Current first pointer : " << firstPointer << endl;    // Current first pointer : 0x0
    cout << "Current second pointer : " << secondPointer << endl;  // Current second pointer : 0x0

    // shared pointer
    cout << "\nShared Pointer" << endl;
    int* firstArray = new int[10];

    shared_ptr<int> thirdPointer(firstArray);
    cout << "Count Pointer : " << thirdPointer.use_count() << endl;  // Count Pointer : 1

    shared_ptr<int> fourthPointer(thirdPointer);
    cout << "Count Pointer : " << thirdPointer.use_count() << endl;  // Count Pointer : 2

    shared_ptr<int> fifthPointer = fourthPointer;
    cout << "Count Pointer : " << thirdPointer.use_count() << endl;  // Count Pointer : 3

    thirdPointer.reset();
    fourthPointer.reset();
    fifthPointer.reset();

    cout << "\nreset" << endl;

    cout << "After reset : " << thirdPointer.use_count() << endl;  // After reset : 0

    // weak pointer
    // 참조로 객체에 접근할 수 있지만 소유권이 없으므로 shared pointer가 세지는 않음
    cout << "\nWeak Pointer" << endl;

    int* secondArray = new int[3];

    shared_ptr<int> mainSharedPointer(secondArray);
    weak_ptr<int>   noRefferCountWeakPointer = mainSharedPointer;

    cout << "Count Pointer : " << mainSharedPointer.use_count() << endl;
    cout << "Count Pointer : " << noRefferCountWeakPointer.use_count() << endl;

    if (true) {  // scope 범위 내에서 동작
        // 참조 횟수를 증가시키기 위해 사용한 코드
        // lock() 함수는 weak pointer가 바라보는 객체가 유효한지 검증
        // 유효하면 shared pointer 반환, 유효하지 않으면 null pointer 반환
        shared_ptr<int> addSharedPointer = noRefferCountWeakPointer.lock();

        cout << "Count Pointer : " << mainSharedPointer.use_count() << endl;
        cout << "Count Pointer : " << noRefferCountWeakPointer.use_count() << endl;

        // scope 범위를 벗어나면 메모리가 해제될 예정
        // addSharedPointer.reset();
    }

    // scope 범위를 벗어났으므로 해제
    cout << "Count Pointer : " << mainSharedPointer.use_count() << endl;
    cout << "Count Pointer : " << noRefferCountWeakPointer.use_count() << endl;

    mainSharedPointer.reset();
    noRefferCountWeakPointer.reset();

    return 0;
}