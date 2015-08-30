#include <iostream>
using namespace std;

// subsum calculates if sum is possible and returns true if it is
// value array already has values and last array is created
bool subsum(long int value[], long int size, long int sum, long int last[]);
// print_solution assumes sum is reachable and prints out values used
// subsum must be called first to put values in last array
void print_solution(long int value[], long int size, long int sum,
                    long int last[]);

int main() {
  long int *value; // dynamic array for given numbers
  long int *last;  // dynamic array
                   // zero value means that total is not reachable yet
                   // nonzero gives index of last value used to reach total
  long int size;   // size of array containing given numbers
  long int sum;    // sum to be reached
  bool success;    // true if the sum is reachable

  cin >> size;
  value = new long int[size + 1]; // first element of array not used
                                  // so we can start with index 1

  for (long int i = 1; i <= size; i++) // read in given numbers
  {
    cin >> value[i];
  }

  cout << "Here are the numbers I read in:" << endl;

  for (long int i = 1; i <= size; i++) // read in given numbers
  {
    cout << value[i] << " ";
  }
  cout << endl;

  cin >> sum;
  last = new long int[sum + 1]; // first element not used since sums are nonzero

  success = subsum(value, size, sum, last);

  if (success) // sum is reachable
  {
    cout << "Here are the numbers used to reach " << sum << endl;
    print_solution(value, size, sum, last);
  } else {
    cout << "You cannot reach " << sum << " with these numbers" << endl;
  }

  delete[] value;
  delete[] last;
  return 0;
}

bool subsum(long int value[], long int size, long int sum, long int last[]) {
  long int index;
  long int cur_total;
  long int next_total;

  for (cur_total = 1; cur_total <= sum; cur_total++) {
    last[cur_total] = 0;
  }

  for (index = 1; index <= size; index++) {
    for (cur_total = 1; cur_total <= sum; cur_total++) {
      if (cur_total == value[index]) // can get sum with one value
      {
        last[cur_total] = index;
      } else {
        next_total = cur_total + value[index];
        if (next_total <= sum           // don't allow total to be more than sum
            && last[cur_total] != 0     // current total has been reached
            && last[cur_total] != index // don't add this number twice
            && last[next_total] == 0)   // new total not reached yet
        {
          last[next_total] = index; // last value used to get this sum
        }
      }
    }
  }

  if (last[sum] != 0) {
    return true;
  } else {
    return false;
  }
}

void print_solution(long int value[], long int size, long int sum,
                    long int last[]) {
  while (sum != 0) {
    cout << value[last[sum]] << endl;
    sum -= value[last[sum]];
  }
}
