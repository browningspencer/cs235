#include "QSInterface.h"
#include <sstream>

#pragma once

using namespace std;

class QS : public QSInterface {

public:
  QS();
  ~QS();

  virtual void sort(int left, int right);
  virtual void sortAll();
  virtual int medianOfThree(int left, int right);
  virtual int partition(int left, int right, int pivotIndex);
  virtual string getArray();
  virtual int getSize();
  virtual void addToArray(int value);
  virtual bool createArray(int capacity);
  virtual void clear();
};
