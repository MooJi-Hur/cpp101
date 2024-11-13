#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void) {
    // deque
    // 시작과 끝점에서 데이터를 다룰 수 있음
    // iterator를 이용해 index를 지정하여 데이터를 다룰 수 있음
    deque<int> myDeque;

    //  1
    myDeque.push_front(1);

    // 1 3
    myDeque.push_back(3);

    // 3
    myDeque.pop_front();

    // 5 3
    myDeque.push_front(5);

    cout << "Current my deque" << endl;

    // 5 3
    for (int i = 0; i < myDeque.size(); i++) {
        cout << myDeque[i] << endl;
    }

    // deque를 조회하는 객체
    deque<int>::iterator myDequeIterator;

    // index 0에서 순회 시작
    myDequeIterator = myDeque.begin();

    // myDeque 시작점 + 1인 곳 (index 1)에 3개의 7을 넣어라
    // 5 3 => 5 '7 7 7' 3
    myDeque.insert(myDequeIterator + 1, 3, 7);

    cout << "after insert using iterator" << endl;
    // 5 7 7 7 3
    for (int i = 0; i < myDeque.size(); i++) {
        cout << myDeque[i] << endl;
    }

    // 내용 비우기
    myDeque.clear();

    // 비어있음이 참이므로 1을 출력
    cout << "is empty? " << myDeque.empty() << endl;  // 1

    // vector
    vector<int> myVector;

    // 1
    myVector.push_back(1);

    // 1 3
    myVector.push_back(3);

    // 1 3 5
    myVector.push_back(5);

    // 1 3
    myVector.pop_back();

    // 1 3 7
    myVector.push_back(7);

    cout << "\nCurrent my vector" << endl;

    // 1 3 7
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << endl;
    }

    // vector를 조회할 수 있는 객체
    vector<int>::iterator myVectorIterator;

    // vector의 시작점부터 순회
    myVectorIterator = myVector.begin();

    // myVector 시작점 + 2인 곳 (index 2)에 4개의 6을 넣어라
    // 1 3 7 => 1 3 '6 6 6 6' 7
    myVector.insert(myVectorIterator + 2, 4, 6);

    cout << "after insert using iterator" << endl;

    // 1 3 6 6 6 6 7
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << endl;
    }

    // 내용 비우기
    myVector.clear();

    // 비어있음이 참이므로 1을 출력
    cout << "is empty? " << myVector.empty() << endl;  // 1

    return 0;
}