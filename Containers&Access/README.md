# STL Containers and Access Methods

| Access Method           | std::vector | std::array | std::string | std::deque | std::list | std::set / std::map |
|--------------------------|-------------|------------|-------------|------------|-----------|---------------------|
| Pointer (`data()`)       | ✅          | ✅         | ✅          | ❌         | ❌        | ❌                  |
| Iterator                | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |
| `std::next`             | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |
| Range-based for loop    | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |
| Index-based (`[]`)      | ✅          | ✅         | ✅          | ❌         | ❌        | ❌                  |
| `at()` method           | ✅          | ✅         | ✅          | ❌         | ❌        | ❌                  |
| `std::for_each`         | ✅          | ✅         | ✅          | ✅         | ✅        | ✅                  |
