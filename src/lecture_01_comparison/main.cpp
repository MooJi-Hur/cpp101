#include <iostream>
#include "lecture_01_comparison/hello_world.h"
#include "lecture_01_comparison/demonstrate_namespace.h"

int main() {
    // 각 강의의 예제를 실행
    std::cout << "Comparison between C and C++" << std::endl;
    helloWorld();

    std::cout << "Namespace Demonstration" << std::endl;
    demonstrateNamespace();

    return 0;
}
