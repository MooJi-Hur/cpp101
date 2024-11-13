#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    // stack
    stack<int> myStack;

    /**
     * 1
     */
    myStack.push(1);

    /**
     * 3
     * 1
     */
    myStack.push(3);

    /**
     * 5
     * 3
     * 1
     */
    myStack.push(5);

    /**
     * 3
     * 1
     */
    myStack.pop();

    /**
     * 7
     * 3
     * 1
     */
    myStack.push(7);

    /**
     * 3
     * 1
     */
    myStack.pop();

    /**
     * 3
     * 1
     */

    /**
     * 1
     */

    /**
     */

    cout << "Current my stack" << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << endl;  // 3    // 1

        myStack.pop();
    }

    // queue
    queue<int> myQueue;

    // 1
    myQueue.push(1);

    // 1 3
    myQueue.push(3);

    // 1 3 5
    myQueue.push(5);

    // 3 5
    myQueue.pop();

    // 3 5 7
    myQueue.push(7);

    // 5 7
    myQueue.pop();

    cout << "\nCurrent my queue" << endl;

    // 5 7
    // 7
    // empty
    while ((!myQueue.empty())) {
        cout << myQueue.front() << endl;  // 5    // 7

        myQueue.pop();
    }

    return 0;
}