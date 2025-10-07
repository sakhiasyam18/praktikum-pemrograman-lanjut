#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

class BankAccount
{
private:
    double balance;            // Private: melindungi data saldo
    static float interestRate; // Static: sama untuk semua akun

public:
    // Constructor untuk inisialisasi saldo awal
    BankAccount(double initialBalance = 0.0);

    // Menambah saldo
    void deposit(double amount);

    // Mengambil saldo (tidak boleh ubah data, jadi const)
    double getBalance() const;

    // Mengatur bunga bersama untuk semua akun
    static void setInterestRate(float rate);

    // Mengambil bunga bersama
    static float getInterestRate();
};

#endif
