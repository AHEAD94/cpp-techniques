# Template

C++의 템플릿은 일반화된 코드 작성을 가능하게 하는 기능으로, 타입에 의존하지 않는 함수나 클래스를 구현할 수 있다. 이를 통해 코드 재사용성을 높이고 다양한 데이터 타입에 대해 동일한 로직을 적용할 수 있다.

## 함수 템플릿

함수 템플릿은 동일한 코드 로직을 다양한 데이터 타입에 적용하기 위해 사용된다.  

### 특징

- 템플릿 매개변수는 컴파일 시점에 실제 데이터 타입으로 대체됨
- 함수 템플릿은 컴파일 과정에서 인스턴스화됨
- 템플릿을 많이 사용하면 컴파일 시간이 길어지고 실행 파일의 크기가 커질 수 있음

### 기존 함수와의 비교

`vector<int>` 컨테이너의 요소를 출력하는 함수는 다음과 같다.

```cpp
void print_container(const vector<int>& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}
```

위 함수는 `vector<int>` 타입에만 동작하므로 다른 타입을 전달하면 컴파일 에러가 발생한다. 이를 일반화하기 위해 함수 템플릿을 사용한다.

### 함수 템플릿 작성

`template` 키워드와 `<typename T>`를 사용하여 다음과 같이 일반화된 함수를 작성할 수 있다.

```cpp
// 함수 템플릿을 활용한 컨테이너 출력 함수
template <typename T>
void print_container(const T& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}
```

-	`T`는 템플릿 매개변수로, 함수가 호출될 때 인자의 타입으로 대체된다.  
-	작성된 함수 템플릿은 타입에 의존하지 않으므로 다양한 타입의 컨테이너를 처리할 수 있다.  

## 템플릿의 명시적 특수화

명시적 특수화는 특정 데이터 타입에 대해 다른 로직을 적용할 때 사용된다.

예를 들어, `string` 타입을 출력할 때 요소마다 공백을 출력하는 기본 템플릿을 사용하면 문자열이 문자 단위로 공백과 함께 출력된다. 이를 해결하기 위해 템플릿을 `string` 타입에 대해 특수화할 수 있다.  

```cpp
// 템플릿 명시적 특수화 (explicit specialization)
template <>
void print_container(const string& container) {
    for (const auto& element : container) {
        cout << element; // 공백 출력 제외
    }
    cout << endl;
}
```

-	`template<>`를 사용하여 템플릿 매개변수를 생략하고 `string` 타입에 대한 특수화된 함수를 정의한다.
-	문자열에 대해 특수화된 `print_container` 함수에 `string` 타입을 전달하면 문자 사이에 공백이 없이 출력된다.

## 템플릿과 오버로딩

템플릿 함수는 오버로딩을 통해서도 특정 타입에 대해 다른 동작을 정의할 수 있다.  
예를 들어, `map` 컨테이너의 요소들을 출력할 때는 키와 값을 동시에 출력해야 한다. 이를 위해 템플릿 함수 오버로딩을 사용한다.  

```cpp
// 템플릿 함수의 Overloading -> map 컨테이너를 사용하기 위함
template <typename T1, typename T2>
void print_container(const map<T1, T2>& container) { // 어떤 타입의 key-value 쌍이라도 처리 가능
    for (const auto& element : container) {
        cout << element.first << ":" << element.second << " ";
    }
    cout << endl;
}
```

- `map` 컨테이너는 key-value 쌍을 저장하므로 두 개의 템플릿 매개변수 `T1`, `T2`를 사용하여 키와 값의 타입을 처리한다.
- 오버로딩된 함수를 사용하면 `map` 타입의 컨테이너의 키와 값을 동시에 출력할 수 있다.

## 전체 코드

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>

using namespace std;

// 함수 템플릿을 활용한 컨테이너 출력 함수
template <typename T>
void print_container(const T& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}

// 템플릿 명시적 특수화 (explicit specialization)
template <>
void print_container(const string& container) {
    for (const auto& element : container) {
        cout << element; // 공백 출력 제외
    }
    cout << endl;
}

// 템플릿 함수의 Overloading
template <typename T1, typename T2>
void print_container(const map<T1, T2>& container) { // 어떤 타입의 key-value 쌍이라도 처리 가능
    for (const auto& element : container) {
        cout << element.first << ":" << element.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vector_test(10, 1);
    
    list<int> list_test(10, 2);
    
    string string_test("string test");
    
    set<int> set_test{6, 3, 9, 1, 5};
    
    map<int, string> map_test{make_pair(1, "one"), make_pair(2, "two"), make_pair(9, "nine")};
    
    // 함수 템플릿 사용
    print_container(vector_test);
    print_container(list_test);
    print_container(set_test);
    
    // 템플릿 명시적 특수화
    print_container(string_test);
    
    // 템플릿 함수 오버로딩
    print_container(map_test);
    
    return 0;
}
```
