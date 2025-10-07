#include "BankAccount.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Interest rate (default): " << BankAccount::getInterestRate() * 100 << "%\n\n";

    BankAccount acc1(1000.0);
    BankAccount acc2(500.0);

    cout << "Account 1 balance: $" << acc1.getBalance() << endl;
    cout << "Account 2 balance: $" << acc2.getBalance() << endl;

    cout << "\nUpdating interest rate...\n";
    BankAccount::setInterestRate(0.07f); // ubah jadi 7%

    cout << "New interest rate: " << BankAccount::getInterestRate() * 100 << "%\n\n";

    // Kedua akun berbagi interest rate yang sama
    cout << "Account 1 (after rate change): $" << acc1.getBalance()
         << " | Rate: " << BankAccount::getInterestRate() * 100 << "%\n";
    cout << "Account 2 (after rate change): $" << acc2.getBalance()
         << " | Rate: " << BankAccount::getInterestRate() * 100 << "%\n";

    system("pause"); // <- tambahkan ini sebelum return 0;

    return 0;
}
