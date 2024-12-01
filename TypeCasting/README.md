# Type casting

C++의 명시적 캐스팅 종류는 다음과 같다.

1. [static_cast](#static-cast)
2. [dynamic_cast](#dynamic-cast)
3. [const_cast](#const-cast)
4. [reinterpret_cast](#reinterpret-cast)
  
## static cast
- 용도: 주로 명시적인 타입 변환에 사용된다.
  - 기본 데이터 타입 간 변환 (예: int &rarr; float)
  - 명시적 업캐스팅/다운캐스팅 (예: 부모 &rarr; 자식 클래스)
  - 포인터/레퍼런스 타입 변환
- 특징
  - 컴파일 타임에 검사
  - 안정성이 높고, 불필요한 타입 변환 방지
  - 런타임에 타입 정보를 확인하지 않음
- 예시
  ```cpp
  // 부모 자식 클래스 정의
  class Base {};
  class Derived : public Base {};
  ```
  ```cpp
  // 기본 타입 변환
  int a = 10;
  float b = static_cast<float>(a);
  cout << "Static cast int to float: " << b << endl;

  // 업캐스팅 (자식 → 부모)
  Derived derived;
  Base* base = static_cast<Base*>(&derived);
  cout << "Static cast Derived* to Base*" << endl;
  ```
  
## dynamic cast
- 용도: 주로 상속 계층에서 객체 타입의 안전환 변환에 사용된다.
  - 부모 클래스 포인터/레퍼런스를 자식 클래스 포인터/레퍼런스로 변환
- 특징
  - RTTI (Runtime Type Information)를 사용
  - 변환에 실패하면 포인터의 경우 nullptr 변환, 레퍼런스의 경우 예외 (std::bad_cast) 발생
  - 다형성(polymorphism) 클래스에서만 사용 가능 (즉, virtual 함수가 필요)
- 예시
  ```cpp
  // 클래스 정의
  class Base {
  public:
      virtual void show() {} // RTTI를 위한 가상 함수
  };
  
  class Derived : public Base {
  public:
      void show() { cout << "Derived class" << endl; }
  };

  class Unrelated {};
  ```
  ```cpp
  Base* base = new Derived;
  Base* base2 = new Base;

  // 안전한 다운캐스팅
  Derived* derived = dynamic_cast<Derived*>(base);
  if (derived) {
      cout << "Dynamic cast succeeded: ";
      derived->show();
  }

  // 실패하는 캐스팅
  Derived* invalidCast = dynamic_cast<Derived*>(base2);
  if (!invalidCast) {
      cout << "Dynamic cast failed" << endl;
  }

  delete base;
  delete base2;
  ```
  
## const cast
- 용도: const 또는 volatile 속성을 추가하거나 제거할 때 사용한다.
  - const 객체를 수정할 필요가 있을 때 사용 (비권장)
  - 예: const int* &rarr; int*
- 특징
  - 실제로 const 속성을 제거하면 정의되지 않은 동작 발생 가능하므로 주의
  - 주로 레거시 코드와의 호환성을 위해 사용
- 예시
  ```cpp
  // 클래스 정의
  void printValue(const int* value) {
    // const 제거
    int* nonConstValue = const_cast<int*>(value);
    *nonConstValue = 42;
  }
  ```
  ```cpp
  const int x = 10;
  cout << "Before const_cast: " << x << endl;

  // const 제거 후 수정 (권장하지 않음)
  printValue(&x);
  cout << "After const_cast: " << x << " (undefined behavior)" << endl;
  ```
  
## reinterpret cast
- 용도: 포인터 타입 간 변환이나 비관련 타입 간의 변환에 사용된다.
  - 예: int* &rarr; void*, 또는 포인터를 정수로 변환
- 특징
  - 안전성이 매우 낮음
  - 예측 불가능한 결과가 발생할 수 있음
  - 주로 하드웨어 접근이나 비트 연산 등과 같이 특수한 상황에서 사용
- 예시
  ```cpp
  int x = 65;
  // 정수를 포인터로 변환
  char* ptr = reinterpret_cast<char*>(&x);
  cout << "Reinterpreted int as char: " << *ptr << endl;

  // 포인터 타입 간 변환
  void* voidPtr = reinterpret_cast<void*>(&x);
  int* intPtr = reinterpret_cast<int*>(voidPtr);
  cout << "Reinterpreted back to int: " << *intPtr << endl;
  ```
