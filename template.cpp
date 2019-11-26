
template <typename T>
T max(T a) {
    return a;
}

template <typename T, typename... Args>
T max(T a, Args... args) {
    T b = max(args...);
    return a > b ? a : b;
}

template <typename T>
T min(T a) {
    return a;
}

template <typename T, typename... Args>
T min(T a, Args... args) {
    T b = min(args...);
    return a > b ? b : a;
}
