#include <vector>
#include "random"
#include <type_traits>

//comparison - элемент для сравнения
//l - левая граница сортируемого подмассива
//r - правая граница сортируемого подмассива
//dec - флаг сортировки по убыванию
template<typename T>
size_t partition(std::vector <T>& arr, const T& comparison, const size_t& l, const size_t& r, const bool &dec) {
    size_t first_equal = l, cur = l, greater_or_lower = l;
    while (cur < r) {
        if ((arr[cur] < comparison && !dec) || (arr[cur] > comparison && dec)) {
            std::swap(arr[greater_or_lower], arr[cur]);
            std::swap(arr[greater_or_lower], arr[first_equal]);
            greater_or_lower++;
            first_equal++;
        }
        else if (arr[cur] == comparison) {
            std::swap(arr[greater_or_lower], arr[cur]);
            greater_or_lower++;
        }
        cur++;
    }
    return first_equal;
}

//l - левая граница массива
//r - правая граница массива
//dec - флаг сортировки по убыванию
template<typename T>
void quicksort(std::vector<T>& arr, size_t l, size_t r, const bool &dec) {
    if (l == r) return;
    T pivot = arr[l + std::rand() % (r - l)];
    size_t p = partition(arr, pivot, l, r, dec);
    size_t rp = p;
    while (rp < r - 1) {
        if (arr[rp] == arr[rp + 1]) rp++;
        else break;
    }
    quicksort(arr, l, p, dec);
    quicksort(arr, rp + 1, r, dec);
}

//dec - флаг сортировки по убыванию
template<typename T>
void quicksort_handler(std::vector<T>& arr, const bool &dec = false) {
    static_assert(std::is_arithmetic<T>::value, "Must be number type!");
    quicksort(arr, 0, arr.size(), dec);
}