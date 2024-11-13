#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(void) {
    int orders[6] = {3, 2, 5, 1, 4, 2};

    // set
    // 데이터의 각 요소를 키로 가짐
    // 중복된 키를 만들면 안되므로, array => set으로 변경할 때 고유한 값들만 남음
    // 내부에서 오름차순으로 정렬됨
    set<int> orderSet(orders, orders + 5);

    // iterator를 활용
    set<int>::iterator orderIterator = orderSet.begin();

    // iterator를 이용해 for문을 사용하는 방법
    // 1 2 3 4 5
    for (; orderIterator != orderSet.end(); orderIterator++) {
        // iterator가 가진 주소값이 담고있는 값을 출력
        cout << *orderIterator << endl;
    }

    orderSet.insert(10);
    orderSet.insert(9);
    orderSet.insert(8);

    // 중복된 값을 추가로 입력하더라도 실제 set의 요소 수가 늘어나지는 않음
    orderSet.insert(8);

    // iterator가 보는 주소의 위치를 재조정
    orderIterator = orderSet.begin();

    // 1 2 3 4 5 8 9 10
    for (; orderIterator != orderSet.end(); orderIterator++) {
        cout << *orderIterator << endl;
    }

    // map
    // key, value 형태, key를 기준으로 정렬해둠
    // 정렬은 검색 속도를 높이기 위한 것
    map<string, int> orderId;

    orderId["water"]    = 0;
    orderId["coffee"]   = 1;
    orderId["blacktea"] = 2;

    map<string, int>::iterator orderIdIter = orderId.begin();

    // blacktea:2 // coffee:1 // water:0
    for (; orderIdIter != orderId.end(); orderIdIter++) {
        cout << orderIdIter->first << ":" << orderIdIter->second << endl;
    }

    // 새로운 값으로 데자와 추가
    orderId["TEJAVA"] = 3;

    orderIdIter = orderId.begin();

    // 대문자를 먼저 세고 있음
    // TEJAVA:3 // blacktea:2 // coffee:1 // water:0
    for (; orderIdIter != orderId.end(); orderIdIter++) {
        cout << orderIdIter->first << ":" << orderIdIter->second << endl;
    }

    // orderId에 없는 key로 조회하려고 시도할 때, 0을 출력
    // 0
    cout << orderId["hello"] << endl;

    return 0;
}