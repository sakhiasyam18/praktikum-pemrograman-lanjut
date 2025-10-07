#include "BankAccount.h"

// Inisialisasi static variable (harus dilakukan di luar class)
float BankAccount::interestRate = 0.05f; // 5% default

BankAccount::BankAccount(double initialBalance)
{
    if (initialBalance >= 0)
        balance = initialBalance;
    else
    {
        balance = 0;
        std::cout << "Invalid initial balance. Set to 0.\n";
    }
}

void BankAccount::deposit(double amount)
{
    if (amount > 0)
        balance += amount;
    else
        std::cout << "Deposit amount must be positive.\n";
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::setInterestRate(float rate)
{
    if (rate >= 0)
        interestRate = rate;
    else
        std::cout << "Interest rate must be non-negative.\n";
}

float BankAccount::getInterestRate()
{
    return interestRate;
}
