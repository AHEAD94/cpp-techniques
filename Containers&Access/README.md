# STL Containers and Access Methods

| Access Method           | std::vector | std::array | std::string | std::deque | std::list | std::set / std::map |
|-------------------------|-------------|------------|-------------|------------|-----------|---------------------|
| Pointer (`data()`)      | ✅          | ✅         | ✅          | ❌         | ❌        | ❌                  |
| Iterator                | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |
| `std::next`             | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |
| Range-based for loop    | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |
| Index-based (`[]`)      | ✅          | ✅         | ✅          | ❌         | ❌        | ❌                  |
| `at()` method           | ✅          | ✅         | ✅          | ❌         | ❌        | ❌                  |
| `std::for_each`         | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |

## Examples
  
```cpp
// Pointer( data() )
int* ptr = vector_test.data(); // referencing 1st element of vector
for (size_t i = 0; i < vector_test.size(); i++) {
    cout << *(ptr + i) << endl;
}

// Iterator
for (auto iter = vector_test.begin(); iter != vector_test.end(); iter++) {
    cout << *iter << endl;
}

// std::next
for (size_t i = 0; i < vector_test.size(); i++) {
    cout << *(next(vector_test.begin(), i)) << endl;
}

// Range-based for loop
for (int value : vector_test) {
    cout << value << endl;
}

// Index-based ( [] )
for (size_t i = 0; i < vector_test.size(); i++) {
    cout << vector_test[i] << endl;
}

// at() method
for (size_t i = 0; i < vector_test.size(); i++) {
    cout << vector_test.at(i) << endl;
}

// std::for_each & lambda
for_each(vector_test.begin(), vector_test.end(), [](int value) {
    cout << value << endl;
});
```
