#include "vect_add_one.h"
#include <vector>
using std::vector;

void AddOneToEach(vector<int> &v) {
    for (auto& i: v) {
        i++;
    }
}