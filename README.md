[![Coverage Status](https://coveralls.io/repos/github/edenabr/lab05h/badge.svg?branch=main)](https://coveralls.io/github/edenabr/lab05h?branch=main)

<pre>
Running main() from /home/vboxuser/Рабочий стол/project/projects/lab05h/third-party/gtest/googletest/src/gtest_main.cc
[==========] Running 8 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from Account
[ RUN      ] Account.Constructor
[       OK ] Account.Constructor (0 ms)
[ RUN      ] Account.ChangeBalanceWithoutLockThrows
[       OK ] Account.ChangeBalanceWithoutLockThrows (1 ms)
[ RUN      ] Account.ChangeBalanceWithLock
[       OK ] Account.ChangeBalanceWithLock (0 ms)
[----------] 3 tests from Account (1 ms total)

[----------] 5 tests from Transaction
[ RUN      ] Transaction.NegativeFeeThrows
[       OK ] Transaction.NegativeFeeThrows (0 ms)
[ RUN      ] Transaction.ZeroSumThrows
[       OK ] Transaction.ZeroSumThrows (0 ms)
[ RUN      ] Transaction.SumLessThanFeeThrows
[       OK ] Transaction.SumLessThanFeeThrows (0 ms)
[ RUN      ] Transaction.SuccessfulTransaction
[       OK ] Transaction.SuccessfulTransaction (0 ms)
[ RUN      ] Transaction.NotEnoughMoney
[       OK ] Transaction.NotEnoughMoney (0 ms)
[----------] 5 tests from Transaction (0 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 8 tests. </pre>
