#include <iostream>
#include <cstdint>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::min;

template <typename T>
void bsearch(const T *const values, size_t length, const T &value, bool *found,
             size_t *location) {
  size_t low = 0, high = length - 1;
  while (low <= high) {
    size_t mid = low + ((high - low) / 2);
    if (values[mid] < value) {
      low = mid + 1;
    } else if (values[mid] > value) {
      high = mid - 1;
    } else {
      *found = true;
      *location = mid;
    }
  }
  *found = false;
  *location = low;
}

template <typename T>
void ss2(T values[], size_t size, T sum, bool *success, size_t *first,
         size_t *second) {
  *success = false;
  size_t loc;
  bool found;
  bsearch(values, size, sum, &found, &loc);
  size_t a = 0, b = min(size - 1, loc);
  if (values[a] + values[b] == sum && a != b) {
    *success = true;
    *first = a;
    *second = b;
    return;
  }
  while (b > 0 && a < size) {
    T tmp = values[a] + values[b];
    if (tmp > sum) {
      b--;
    } else if (tmp < sum) {
      a++;
    } else if (a == b) {
      return;
    } else {
      *success = true;
      *first = a;
      *second = b;
      return;
    }
  }
}

int main() {
  long int *value; // dynamic array of given values
  long int size;   // size of array of given values
  long int sum;    // sum we want to reach

  cin >> size;
  value = new long int[size];

  for (long int i = 0; i < size; i++) {
    cin >> value[i];
  }

  cin >> sum;

  bool success;
  size_t first, second;
  ss2(value, size, sum, &success, &first, &second);

  if (success) {
    cout << value[first] << " + " << value[second] << " = " << sum << endl;
  } else {
    cout << "You cannot reach " << sum << " with these numbers" << endl;
  }

  delete[] value;

  return 0;
}
