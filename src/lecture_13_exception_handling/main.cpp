#include <iostream>

using namespace std;

int main(void) {
    int myNumerator   = 7;
    int myDenominator = 0;

    try {
        if (myDenominator == 0) {
            throw 0;  // throw는 클래스 내 코드에서도 쓸 수 있음
        }

        int myQuotient = myNumerator / myDenominator;

        cout << myQuotient << endl;
    } catch (int error) {
        if (error == 0) {
            cerr << "Your denominator is zero (Error code: " << error << ")"
                 << endl;  // Your denominator is zero (Error code: 0)
        } else {
            cerr << "Unknown Error (Error code: " << error << ")" << endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << endl;
    }

    return 0;
}