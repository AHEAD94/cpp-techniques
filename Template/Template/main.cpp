//
//  main.cpp
//  Template
//
//  Created by Ryu Dae-ha on 12/19/24.
//

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
