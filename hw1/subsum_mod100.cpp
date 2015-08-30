#include <iostream>
using namespace std;

// subsum calculates if sum is possible and returns true if it is
// value array already has values and last array is created
bool subsum(long int value[], long int size, long int last[]) {
  long int index;
  long int cur_remainder;
  long int next_remainder;

  for (cur_remainder = 1; cur_remainder <= 100; cur_remainder++) {
    last[cur_remainder] = 0;
  }

  for (index = 1; index <= size; index++) {
    for (cur_remainder = 0; cur_remainder <= 100; cur_remainder++) {
      if (cur_remainder == (value[index] % 100)) // can get sum with one value
      {
        last[cur_remainder] = index;
      } else {
        next_remainder = (cur_remainder + value[index]) % 100;
        if (last[cur_remainder] != 0 // current remainder has been reached
            && last[cur_remainder] != index // don't add this number twice
            && last[next_remainder] == 0)   // new remainder not reached yet
        {
          last[next_remainder] = index; // last value used to get this sum
        }
      }
    }
  }

  if (last[0] != 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  long int *value; // dynamic array for given numbers
  long int *last;  // dynamic array
                   // zero value means that total is not reachable yet
                   // nonzero gives index of last value used to reach total
  long int size;   // size of array containing given numbers
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

  last = new long int[100 + 1];
  for (int i = 0; i < 101; i++) {
    last[i] = 0;
  }

  success = subsum(value, size, last);

  if (success) // sum is reachable
  {
    cout << "You can reach a multiple of 100 with these numbers" << endl;
  } else {
    cout << "You cannot reach a multiple of 100 with these numbers" << endl;
  }

  delete[] value;
  delete[] last;
  return 0;
}
