#pragma once
/*
 *
 * Qsort Avrora implementation according to cormen description with
 * little comparation changes
 *
 */
#include <array>
#include <cstdint>

void swap_v1(uint32_t& x, uint32_t& y) {
	uint32_t tmp = y;
	y = x;
	x = tmp;
}

template<std::size_t SIZE>
unsigned int partition_v1(
    std::array<uint32_t, SIZE>& arr, unsigned int p, unsigned int r) {
    auto x = arr[p];
    auto i = p;
    auto j = r;
    while(true) {
        while(arr[i] < x)
            i++;
        while(arr[j] > x)
            j--;
        if(i <= j) {
            swap_v1(arr[i], arr[j]);
            i++;
            j--;
        }
        else
            return j;
    }
}

template<std::size_t SIZE>
void qsort_v1(std::array<uint32_t, SIZE>& arr, unsigned int p, unsigned int r) {
    if(p < r) {
        auto q = partition_v1<SIZE>(arr, p, r);
        qsort_v1<SIZE>(arr, p, q);
        qsort_v1<SIZE>(arr, q + 1, r);
    }
}
