me: bank_account.cpp
 *
 *  Created on: Sep 7, 2015
 *  Author: Ian Wilhelm, Q789F653
 *  Assignment: 1
 */

#include "bank_account.h"
#include <iostream>
#include <string>
// Constructor
BankAccount::BankAccount(AccountType type, std::string holder_name)
{
	m_holder_name = holder_name;
	m_type = type;
	m_balance = 0;
	m_interest_rate = 0.0;
	m_monthly_fee = 0;
}
// Deconstructor
BankAccount::~BankAccount()
{

}
// Transactions
// This takes the amount entered and subtracts it from the balance. It will not work if it would make the balance a negative number.
bool BankAccount::withdraw(long amount)
{
	long bal = new long;
	bool balance_change;

	bal = Balance;

	bal = bal - amount;
	balance_change = Change_Balance(bal);

	return balance_change;

}
// This takes the amount entered and adds it to the balance.
bool BankAccount::deposit(long amount)
{
	long balan = Balance;
	bool bal_change;

	balan = balan + amount;

	bal_change = Change_Balance(balan);

	return bal_change;

}
//This calculates the interest rates and adds it to the balance. Then checks if the balance can pay the monthly fee. If the balance can pay the monthly fee it is taken out the balance.
bool BankAccount::month_end_process(void)
{
	long bal = Balance;
	long interest;
	bool month_check;
	double rate;
	long fee;

	rate = Interest_Rate;
	interest = bal*rate;

	bal = bal + interest;
	bal = bal - fee;

	month_check = Change_Balance(bal);

	if (!month_check)
	{
		std::cout << "Could not pay monthly fee.\n";
	}
	return month_check;
}
//Accessors
// Gives the balance from the account
long BankAccount::Balance()
{
	return m_balance;
}
// Give the decimal version of the interest rate.
double BankAccount::Interest_Rate()
{
	return m_interest_rate;
}
// Give the monthly fee on that account;
long BankAccount::Monthly_Fee()
{
	return m_monthly_fee;
}
// Give the name of the account holder/
std::string BankAccount::Holder_Name()
{
	return m_holder_name;
}
// Give the type of the account
AccountType BankAccount::Type()
{
	return m_type;
}

// Mutators
// Takes a new interest rate and if valid then changes the interest rate.
bool BankAccount::Change_Interest_Rate(double rate)
{
	bool change;

	change = valid_interest_rate(rate);

	if (change == true)
	{
		m_interest_rate = rate;
	}

	return change;
}
// Takes a new monthly fee and if valid then changes the monthly fee.
bool BankAccount::Change_Monthly_Fee(long fee)
{
	bool change;

	change = valid_monthly_fee(fee);

	if (change)
	{
		m_monthly_fee = fee;
	}

	return change;
}
// Takes the new balance and if valid then the balance changes to the new balance.
bool BankAccount::Change_Balance(long amount)
{
	bool change;

	change = valid_balance(amount);

	if (change)
	{
		m_balance = amount;
	}

	return change;
}
// Changes the type of the account
void BankAccount::Change_AccountType()
{
	if (m_type == AccountType[0])
	{
		m_type = AccountType[1];
	}
	else
	{
		m_type = AccountType[0];
	}
}

//Private Methods
// Checks if the entered interest rate is vaild or invaild.
bool BankAccount::valid_interest_rate(double rate_change)
{
	bool check;

	if (rate_change > 0.0 && rate_change < .15)
	{
		check = true;
	}
	else
	{
		check = false;
	}

	return check;
}
// Checks if the monthly fee is valid or invalid.
bool BankAccount::valid_monthly_fee(long fee_change)
{
	bool check;

	if (fee_change >= 0 && fee_change <= 5000)
	{
		check = true;
	}
	else
	{
		check = false;
	}

	return check;
}
// Check to make sure that the balance is not negative
bool BankAccount::valid_balance(long bal)
{
	bool check;

	if (bal < 0)
	{
		check = false;
	}
	else
	{
		check = true;
	}

	return check;
}
