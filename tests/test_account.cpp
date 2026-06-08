#include <Account.h>

#include <gtest/gtest.h>

TEST(Account, Constructor)
{
  Account account(1, 100);

  EXPECT_EQ(account.id(), 1);
  EXPECT_EQ(account.GetBalance(), 100);
}

TEST(Account, ChangeBalanceWithoutLockThrows)
{
  Account account(1, 100);

  EXPECT_THROW(account.ChangeBalance(50), std::runtime_error);
}

TEST(Account, ChangeBalanceWithLock)
{
  Account account(1, 100);

  account.Lock();
  account.ChangeBalance(50);

  EXPECT_EQ(account.GetBalance(), 150);

  account.Unlock();
  EXPECT_THROW(account.ChangeBalance(10), std::runtime_error);
}
