#include "template_qsort.h"

void qsort_test() {
    std::array<uint32_t, 10> arr{ 14, 1, 5, 16, 2, 16, 2, 2, 14, 10 };
	qsort_v1<arr.size()>(arr, 0, arr.size()-1);
}
