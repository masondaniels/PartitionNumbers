#include <iostream>
#include <vector>
#include <gmpxx.h>
using namespace std;


// Get lowest list offset index ... 1, 3, 2, 5, 3 ...
// i starts at 0 in this instance
int getOffsetIndex(int i) {
    return (i % 2 == 0 ? i/2 + 1 : i + 2);
}

/*
 * The partition number is the number of unique
 * ways to add the number n.
 * 
 * For example:
 * 
 * n = 1
 * 1
 * There is only one way to add 1
 * 
 * n = 2
 * 2
 * 1 + 1
 * 
 * There are two unique ways to add two
 * 
 * n = 3
 * 3
 * 2 + 1
 * 1 + 1 + 1
 * 
 * There are three unique ways to add three
 * 
 * Unique means the addition can't repeat itself
 * so you can't count, say, 2 + 3 + 1, and 3 + 2 + 1
 * as two -- only one.
 * 
 * 
 * This pattern is tricky to follow.
 * Don't be fooled. For example,
 * the partition number for 7 is 22.
 * 
 */
mpz_class getPartition(int n) {

    vector<int> offsetIndex; // Indexes which must be either added or subtracted

    for (int i = 0; i < n; ++i) {
        int index = getOffsetIndex(i);
        offsetIndex.push_back(index);
        if (index > n) {
            break;
        }
    }


    vector<int> listOfOffsets;
    listOfOffsets.push_back(1);
    int b = 0;
    while (true) {
        listOfOffsets.push_back(listOfOffsets[b] + getOffsetIndex(b));
        if (listOfOffsets[b] > n) {
            break;
        }
        ++b;
    }

    vector<bool> perform; // vector to see if left side needs to perform addition/subtraction

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (k > listOfOffsets.size()) {
            break;
        }
        if (i == listOfOffsets[k]) {
            perform.push_back(true);
            ++k;
        } else {
            perform.push_back(false);
        }
    }

    // Generate lists which will be used for pattern up to n

    vector<mpz_class> partitions; // This is the offset for ++ -- ++ ... 1, 2, 5, 7, 12, 15, 22 ...
    partitions.push_back(1);

    for (int i = 1; i < n; ++i) {
        
        int performed = 0; // swaps signs from + to - after two iterations
        mpz_class total = 0;
        int a = 0;
        for (int j = i; j >= 0; --j) {
            if (perform[a]) {
                int sign = (performed/2) % 2 == 0 ? 1 : -1;
                total += sign * partitions[j];
                
                ++performed;
            }
            ++a;
        }
        partitions.push_back(total);
    }

    if (n >= 0) {
        return partitions[n-1];
    } else {
        return -1;
    }
}

int main() {
    // Mathologer wanted the 666th partition number
    // Odd choice of a number...

    // n must be greater than or equal to 1

    cout << "Enter the integer you want for the partition number." << endl;

    while (true) {
        int n = 666;
        cin >> n;
        mpz_class a = getPartition(n);
        cout << "The " << n << "th partition number was " << a << endl;
    }

}