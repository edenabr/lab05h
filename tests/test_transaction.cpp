#include <Transaction.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;

class MockAccount : public Account {
public:
  MockAccount() : Account(0, 0) {}

  MOCK_CONST_METHOD0(GetBalance, int());
  MOCK_METHOD0(Lock, void());
  MOCK_METHOD0(Unlock, void());
  MOCK_METHOD1(ChangeBalance, void(int));
};

TEST(Transaction, NegativeFeeThrows)
{
  Transaction transaction;

  EXPECT_THROW(transaction.set_fee(-1), std::invalid_argument);
}

TEST(Transaction, ZeroSumThrows)
{
  Transaction transaction;
  MockAccount from;
  MockAccount to;

  EXPECT_THROW(transaction.Make(from, to, 0), std::invalid_argument);
}

TEST(Transaction, SumLessThanFeeThrows)
{
  Transaction transaction;
  MockAccount from;
  MockAccount to;

  transaction.set_fee(10);

  EXPECT_THROW(transaction.Make(from, to, 5), std::invalid_argument);
}

TEST(Transaction, SuccessfulTransaction)
{
  Transaction transaction;
  MockAccount from;
  MockAccount to;

  transaction.set_fee(5);

  EXPECT_CALL(from, Lock());
  EXPECT_CALL(to, Lock());
  EXPECT_CALL(from, GetBalance()).WillOnce(Return(100));
  EXPECT_CALL(from, ChangeBalance(-15));
  EXPECT_CALL(to, ChangeBalance(10));
  EXPECT_CALL(from, Unlock());
  EXPECT_CALL(to, Unlock());
EXPECT_TRUE(transaction.Make(from, to, 10));
}

TEST(Transaction, NotEnoughMoney)
{
  Transaction transaction;
  MockAccount from;
  MockAccount to;

  transaction.set_fee(5);

  EXPECT_CALL(from, Lock());
  EXPECT_CALL(to, Lock());
  EXPECT_CALL(from, GetBalance()).WillOnce(Return(10));
  EXPECT_CALL(from, ChangeBalance(::testing::_)).Times(0);
  EXPECT_CALL(to, ChangeBalance(::testing::_)).Times(0);
  EXPECT_CALL(from, Unlock());
  EXPECT_CALL(to, Unlock());

  EXPECT_FALSE(transaction.Make(from, to, 10));
}
