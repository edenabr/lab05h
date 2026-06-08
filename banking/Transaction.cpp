#include "Transaction.h"

#include <stdexcept>

Transaction::Transaction()
    : fee_(1)
{
}

void Transaction::set_fee(int fee)
{
  if (fee < 0) {
    throw std::invalid_argument("negative fee");
  }

  fee_ = fee;
}

bool Transaction::Make(Account& from, Account& to, int sum)
{
  if (sum <= 0) {
    throw std::invalid_argument("sum must be positive");
  }

  if (sum < fee_) {
    throw std::invalid_argument("sum is less than fee");
  }

  from.Lock();
  to.Lock();

  if (from.GetBalance() < sum + fee_) {
    from.Unlock();
    to.Unlock();
    return false;
  }

  from.ChangeBalance(-sum - fee_);
  to.ChangeBalance(sum);

  from.Unlock();
  to.Unlock();

  return true;
}
