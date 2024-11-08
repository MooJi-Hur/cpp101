## 다중 상속

### 인스턴스 생성 과정

1. 지역 변수 firstOrder 공간 할당
- main() 함수 실행 시 스택 프레임 생성
- 스택 프레임 내 지역 변수인 firstOrder 생성
- 자료 구조에 맞는 공간 할당

- Call Stack
    -  67   main    `BlackTea firstOrder ...`
    -  0    start

- `main()` Stack Frame
    ```
    > firstOrder
        > Tea
            - water
            - count
            - price
        > IngredientUnit
            - unitWater
            - unitSugar
        - sugarLevel
    ```

2. BlackTea 클래스 생성자 호출
- BlackTea 생성자 스택 프레임 생성
- this 포인터는 지역변수 firstOrder의 시작점 주소를 담음
- 스택 영역 내 입력받은 파라미터 water = 2, count = 3, sugarLevel = 2 할당

- Call Stack
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `BlackTea(int ...)` Stack Frame
    ```
    > this = 0x...f324
        > Tea
            - water
            - count
            - price
        > IngredientUnit
            - unitWater
            - unitSugar
        - sugarLevel
    - water = 2
    - count = 3
    - sugarLevel = 2
    ```

3. 부모 클래스에 있는 멤버 변수를 순서대로 채우도록 상속 시작
- `class BlackTea : public Tea, private IngredientUnit` 상속 순서에 따라 부모 클래스 생성자 참조를 위한 스택 프레임 생성 

- Call Stack
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start


4. Tea 클래스 내 생성자 호출
- Tea 클래스의 멤버 변수에 해당하는 공간을 참조하며, 초기에는 쓰레기 값임
- this = ((Tea *)0x...f324)
- `Tea(int, int)` Stack Frame에서 만들어진 this는 타입이 (Tea *)


- Call Stack
    - 29    Tea(int, int)   `Tea(int water, int count) : ...`
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `Tea(int, int)` Stack Frame
    ```
    > this = 0x...f324
        - water
        - count
        - price
    - water = 2
    - count = 3
    ```

5. Tea 클래스 멤버 변수에 파라미터에서 받은 값 할당
- 파라미터로 받은 water, count의 값을 firstOrder의 해당 멤버에 할당
- water = 2, count = 3
- this -> water = 2

- Call Stack
    - 24    Tea(int, int)   `int price = 3000;`
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `Tea(int, int)` Stack Frame
    ```
    > this = 0x...f324
        - water = 2
        - count = 3
        - price
    - water = 2
    - count = 3
    ```

- 참고
    ```
    ((Tea *)0x...f324)->water = 2
    ((Tea *)0x...f324)->count = 3
    ```

6. Tea 클래스 멤버 변수에 해당하는 값 초기화
- 클래스 설계 내 초기화 값으로 있는 price를 firstOrder의 해당 멤버에 할당
- this -> price = 3000

- Call Stack
    - 29    Tea(int, int)   ` ... : water(water), count(count) {}`
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `Tea(int, int)` Stack Frame
    ```
    > this = 0x...f324
        - water = 2
        - count = 3
        - price = 3000
    - water = 2
    - count = 3
    ```

- 참고
    ```
    ((Tea *)0x...f324)->price = 3000
    ```

7. Tea 클래스 멤버 변수 할당 종료
- Tea 클래스 생성자 호출이 완료되었으므로 `Tea(int,int)` Stack Frame 소멸

- Call Stack
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `BlackTea(int, int, int)` Stack Frame
    ```
    > this = 0x...f324
        > Tea
            - water = 2
            - count = 3
            - price = 3000
        > IngredientUnit
            - unitWater
            - unitSugar
        - sugarLevel
    - water = 2
    - count = 3
    - sugarLevel = 2
    ```

8. IngredientUnit 클래스 default 생성자 동작
- IngredientUnit 클래스 생성자는 별도의 파라미터는 없음
- this의 자료형은 IngredientUnit *
- this = ((IngredientUnit *)0x...f330)

- Call Stack
    - 9 IngredientUnit()    `int unitWater = 100;`
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `IngredientUnit()` Stack Frame
    ```
    > this = 0x...f330
        - unitWater
        - unitSugar
    ```

9. IngredientUnit 멤버 변수에 해당하는 unitWater 값 초기화
- this 포인터를 통해 unitWater = 100 할당
- this -> unitWater = 100

- Call Stack
    - 10 IngredientUnit()    `int unitSugar = 10;`
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `IngredientUnit()` Stack Frame
    ```
    > this = 0x...f330
        - unitWater = 100
        - unitSugar
    ```

- 참고
    ```
    ((IngredientUnit *)0x...f330)->unitWater = 100
    ```


10. IngredientUnit 멤버 변수에 해당하는 unitSugar 값 초기화
- this 포인터를 통해 unitSugar = 10 할당
- this -> unitSugar = 10

- Call Stack
    - 7 IngredientUnit()    `class IngredientUnit {`
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `IngredientUnit()` Stack Frame
    ```
    > this = 0x...f330
        - unitWater = 100
        - unitSugar = 10
    ```

- 참고
    ```
    ((IngredientUnit *)0x...f330)->unitSugar = 10
    ```

11. IngredientUnit 클래스 멤버 변수 할당 종료
- IngredientUnit 클래스 생성자 호출이 완료되었으므로 `IngredientUnit()` Stack Frame 소멸

- Call Stack
    - 50    BlackTea(int, int, int) `...: ..., Tea(water, count)`
    - 50    BlackTea(int, int, int) `BlackTea(int water, int count, int sugarLevel) : ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `BlackTea(int, int, int)` Stack Frame
    ```
    > this = 0x...f324
        > Tea
            - water = 2
            - count = 3
            - price = 3000
        > IngredientUnit
            - unitWater = 100
            - unitSugar = 10
        - sugarLevel
    - water = 2
    - count = 3
    - sugarLevel = 2
    ```

12. BlackTea 클래스 멤버 변수 값 할당
- 파라미터로 입력받은 sugarLevel 값을 업데이트
- this = ((BlackTea *)0x...f324)
- this -> sugarLevel = 2

- Call Stack
    - 50    BlackTea(int, int, int) `...: sugarLevel(sugarLevel), ...`
    - 67    main    `BlackTea(2, 3, 2);`
    - 0 start

- `BlackTea(int, int, int)` Stack Frame
    ```
    > this = 0x...f324
        > Tea
            - water = 2
            - count = 3
            - price = 3000
        > IngredientUnit
            - unitWater = 100
            - unitSugar = 10
        - sugarLevel = 2
    - water = 2
    - count = 3
    - sugarLevel = 2
    ```

- 참고
    ```
    ((BlackTea *)0x...f324)->sugarLevel = 2
    ```

13. BlackTea 클래스 인스턴스 생성 완료
- BlackTea 클래스 생성자 호출이 완료되었으므로 `BlackTea(int, int, int)` Stack Frame 소멸
- 지역변수 firstOrder의 값이 업데이트 되어 있음을 확인 가능

- Call Stack
    - 69    main    `firstOrder.showPrice();`
    - 0 start

- `main()` Stack Frame
    ```
    > firstOrder
        > Tea
            - water = 2
            - count = 3
            - price = 3000
        > IngredientUnit
            - unitWater = 100
            - unitSugar = 10
        - sugarLevel = 2
    - water = 2
    - count = 3
    - sugarLevel = 2
    ```