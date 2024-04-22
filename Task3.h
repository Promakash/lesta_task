#include <vector>
#include "random"

int partition(std::vector <int>& arr, int x, int l, int r) {
    int e = l, n = l, g = l;
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

void quicksort(std::vector<int>& arr, int l, int r) {
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