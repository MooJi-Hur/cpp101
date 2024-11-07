#include <iostream>
#include "lecture_01_comparison/demonstrate_namespace.h"

using namespace std;

namespace AUser {
void myFunction(void) {
    cout << "I am in A." << endl;
}
}  // namespace AUser

namespace BUser {
void myFunction(void) {
    cout << "I am in B." << endl;
}
}  // namespace BUser

void demonstrateNamespace(void) {
    AUser::myFunction();
    BUser::myFunction();
}