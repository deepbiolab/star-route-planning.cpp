#include "vect_add_one.h"
#include "increment_and_sum.h"

#include <vector>
using std::vector;

int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;
    AddOneToEach(v);

    for (auto i: v) {
        total += i;
    }
    return total;
}