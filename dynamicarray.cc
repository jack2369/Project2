#include "dynamicarray.h"
#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
// regular constuctor
DynamicArray::DynamicArray(int size = 1) {
    values_ = new int[size];
    for (int i = 0; i < size; i++) {
        values_[i] = 0;
    }
}

// copy constructor
DynamicArray::DynamicArray(const DynamicArray& d) {
    values_ = new int[size_];
    for(int i = 0; i < size_; ++i) {
        values_[i] = d.values_[i];
    }
}

bool DynamicArray::operator ==(DynamicArray& d) const {
    // if the sizes don't match
    if(d.size_ != size_) {
        return false;
    }
    // checks each value
    for(int i = 0; i < size_; ++i) {
        if(values_[i] != d.values_[i]) {
            return false;
        }
    }
    return true;
}

DynamicArray& DynamicArray::operator=(const DynamicArray &d) {
    if (this != &d) {
        int *temp = new int[d.size_];
        for (int i = 0; i < d.size_; i++) {
            temp[i] = d.values_[i];
        }
        delete[] values_;
        values_ = temp;
        size_ = d.size_;
    }
    return *this;
}

void DynamicArray::SetSize(int nSize, bool copy) {
    int *temp = new int[nSize];
    if(copy == false) {
        for(int i = 0; i < nSize; ++i) {
            temp[i] = 0;
        }
    } else {
        if(nSize > size_) {
            for(int i = 0; i < nSize; ++i) {
                if(i < size_) {
                    temp[i] = 0;                    
                } else {
                    temp[i] = values_[i];
                }
            }
        } else {
            for(int i = 0; i < nSize; ++i) {
                temp[i] = values_[i];                    
            }
        }
    }
    delete [] values_;
    values_ = temp;
    size_ = nSize;
}


int DynamicArray::RemoveAll(int target) {
    // counts every instance of the target int
    int count = 0;
    for(int i = 0; i < size_; ++i) {
        if(values_[i] == target) {
            ++count;
        }
    }
    // makes temporary pointer to hold new array
    int *temp = new int[size_-count];
    for(int i = 0, j = 0; i < (size_); ++i) {
        if(values_[i] != target) {
            temp[j] = values_[i];
            ++j;
        }
    }
    // swaps temp with the actual array and then updates size
    delete [] values_;
    values_ = temp;
    size_ -= count;
    return count;
}

void DynamicArray::RemoveDuplicates() {
    int count;
    int i = 0;
    do {
        count = 0;
        for(int j = i+1; j < size; ++j) {
            if(values_[j] == values_[i]) {
                ++count;
            }
        }
        int *temp = new int[size_-count];
        for(int j = 0, l = 0; j < (size_); ++i) {
            if(values_[j] != target) {
                temp[l] = values_[j];
                ++l;
            }
        }
        delete [] values_;
        values_ = temp;
        size_ -= count;
        ++i;
    } while(i < size)
}

void DynamicArray::SetDelimiter(char delimeter) {
    delimiter_ = delimeter;
}

std::ostream &operator<<(std::ostream &ostream, const DynamicArray &d) {
     
}

int DynamicArray::Operations(char op) {
    int end = values_[0];
    swtich(op) {
        case '+':
        for(int i = 1; i < size_ < ++i) {
            end += values_[i];
        }
        break;
        case '-':
        for(int i = 1; i < size_ < ++i) {
            end -= values_[i];
        }
        break;
        case '*':
        for(int i = 1; i < size_ < ++i) {
            end *= values_[i];
        }
        break;
        case '/':
        for(int i = 1; i < size_ < ++i) {
            if(values_[i] != 0) {
                end /= values_[i];
            } else {
                cout << "Division by 0 is not allowed." << endl;
                return 0;
            }
        }
        break;
    }
    return end;
}