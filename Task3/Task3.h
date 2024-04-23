#include <vector>
#include "random"
#include <type_traits>

template<typename T>
size_t partition(std::vector <T>& arr, T x, size_t l, size_t r) {
    size_t e = l, n = l, g = l;
    while (n < r) {
        if (arr[n] < x) {
            std::swap(arr[g], arr[n]);
            std::swap(arr[g], arr[e]);
            g++;
            e++;
        }
        else if (arr[n] == x) {
            std::swap(arr[g], arr[n]);
            g++;
        }
        n++;
    }
    return e;
}

template<typename T>
void quicksort(std::vector<T>& arr, size_t l, size_t r) {
    if (l == r) return;
    int pivot = arr[l + std::rand() % (r - l)];
    int p = partition(arr, pivot, l, r);
    int rp = p;
    while (rp < r - 1) {
        if (arr[rp] == arr[rp + 1]) rp++;
        else break;
    }
    quicksort(arr, l, p);
    quicksort(arr, rp + 1, r);
}

template<typename T>
void quicksort_handler(std::vector<T>& arr) {
    static_assert(std::is_arithmetic<T>::value, "Must be number type!");
    quicksort(arr, 0, arr.size());
}