#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"

class Transaction {
public:
  Transaction();

  void set_fee(int fee);
  bool Make(Account& from, Account& to, int sum);

private:
  int fee_;
};

#endif
