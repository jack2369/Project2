#include <iostream>

class DynamicArray {
 public:

  explicit DynamicArray(int size = 1);

  DynamicArray(const DynamicArray& d);

  bool operator ==(DynamicArray& d) const;

  // version that allows one to use the operator in a non-constant setting
  // to update the values in the array
  int& operator[](int i) {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }

  // version that allows one to use the operator on a constant array
  // returning copies of a value in the array
  int operator[](int i) const {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }

  DynamicArray &operator=(const DynamicArray &d);

  void SetSize(int nSize, bool copy = true);

  int GetSize() const {return size_;}

  int RemoveAll(int target);

  void RemoveDuplicates();
  
  bool AllUnique() const;

  int FindAndReplace(int find, int replace);

  void Sort(bool descending = false);
    
  static void SetDelimiter(char delimeter);

  static char GetDelimiter() {return delimiter_;}

  int Operations(char op = '+');

  ~DynamicArray() {delete [] values_;} //destructor to avoid memleaks
  
 private:
  int size_;
  int * values_;
  static char delimiter_; // (for separator used by <<)
  
  friend std::ostream &operator<<(std::ostream &ostream, const DynamicArray &d);
};

std::ostream &operator<<(std::ostream &ostream, const DynamicArray &d);