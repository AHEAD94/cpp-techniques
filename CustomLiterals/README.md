# Custom literals

c++11부터 기본 제공 리터럴 외에 개발자가 리터럴을 정의할 수있다.
  
## 사용자 정의 리터럴 연산자

```cpp
operator""
```

## 정의 예시

```cpp
long double operator"" _mi(long double val) {
  return val * km_per_mile;
}
```

## 사용 예시

```cpp
long double distance = 1.0_mi;
```
