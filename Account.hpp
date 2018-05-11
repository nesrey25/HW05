//
//  Account.hpp
//  HW5
//
//  Created by Nate Esrey on 3/19/18.
//  Copyright © 2018 Nate Esrey. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp
#include <string>
#include <vector>
#include <sstream>
#include "Customer.hpp"
#include "Transaction.hpp"

/**
 The Bank has Accounts and an Account belongs to a Customer.
 Additionally, there are specialized types of accounts: Checking_Account and Savings_Account.
 Checking_Account and Savings_Account have specialized ways of adding interest, and describing itself.
 @author: Ed Walker
 */

class Account {
protected:
    Customer *customer;		// The customer who owns this account
    double balance;			// The available balance in this account
    int account_number = 1;		// A unique number identifying this account
    std::vector<Transaction *> transactions;  // The record of transactions that have occured with this account
    
    /**
     Describe fees associated with the customer who owns this account.
     The fee will depend on the specific type of customer.
     @return string showing checking and overdraft fees
     */
    std::string get_fees()
    {
        double overdraft, charge;
        
        // Polymorphism: calls the correct virtual methods from the specific customer type
        // FIXME: Get the overdraft and check charge information from this accounts customer
        overdraft = this->get_customer()->get_CHECK_CHARGE();
        charge = this->get_customer()->get_CHECK_CHARGE();
        std::stringstream ss;
        ss << "Check Charge: " << charge << " Overdraft Fee: " << overdraft;
        return ss.str();
    }
    
protected:
    /**
     Add interest based on a specified interest rate to account
     @param interest	The interest rate
     */
    //created with the assumption that it will only be called when it should be
    void add_interest(double interest) {
        double amt = balance*interest;
        balance = balance + amt;
        std::string fees = get_fees();
        Transaction *tran = NULL;
        
        // FIXME: Create a Transaction object and assign it to the transaction vector.
        //create new transaction and add to vector
        tran = new Transaction(this->get_customer()->get_customer_number(), "interest", interest, fees);
        transactions.push_back(tran);
    }
    
public:
    /**
     Constructor requires a customer to create an account
     Balance always starts with 0 when account is created.
     */
    Account(Customer *cust, int id) : customer(cust), account_number(id), balance(0) {}
    
    //destructor
    ~Account() {}
    
    /**
     Generic accesser and setter methods for properties customer, balance, and account_number
     */
    
    Customer *get_customer() {
        return customer;
    }
    
    void set_customer(Customer *cust) {
        customer = cust;
    }
    
    int get_account() {
        return account_number;
    }
    
    void set_balance(double new_balance) {
        balance = new_balance;
    }
    
    void set_account(int account_number) {
        this->account_number = account_number;
    }
    
    double get_balance() {
        return balance;
    }
    
    int get_account_number()
    {
        return account_number;
    }
    
    /**
     Generic method describing the account information.
     Remember that you will need to indicate if an account is Savings or Checking in
     an overridden version of to_string() in the derived classes.
     @return string describing generic information about the account
     */
    virtual std::string to_string() {
        std::stringstream ss; // for composing the string that describes this account
        
        // FIXME: Add information about the customer who owns this account.
        
        ss << "  Balance: " << this->get_balance() << std::endl;
        ss << "  Account ID: " << this->get_account_number() << std::endl;
        return ss.str();
    }
    
    /**
     Deposits amount into account
     @param amt The deposit amount
     */
    virtual void deposit(double amt) {
        balance += amt;
        std::string fees = get_fees();
        Transaction *tran = NULL;
        
        // FIXME: Create a Transaction object and assign it to transaction vector.
        tran = new Transaction(this->get_customer()->get_customer_number(), "deposit", amt, fees);
        transactions.push_back(tran);
    }
    
    /**
     Withdraws amount from account
     @param amt The withdrawal amount
     */
    virtual void withdraw(double amt) {
        balance -= amt;
        std::string fees = get_fees();
        Transaction *tran = NULL;
        
        // FIXME: Create a Transaction object and assign it to tran.
        tran = new Transaction(this->get_customer()->get_customer_number(), "withdraw", amt, fees);
        transactions.push_back(tran);
    }
    
    // We want the Savings_Account and Checking_Account to implement this.
    virtual void add_interest() = 0;
    
};

//definition of Account that is a savings acount 
class Savings_Account : public Account
{
public:
    //constructor
    Savings_Account(Customer *cust, int id) : Account(cust, id)
    {
        customer = cust;
        account_number = account_number;
        balance = 0;
    }
    
    //adds appropriate interest rate
    void add_interest()
    {
        balance = balance*this->get_customer()->get_SAVINGS_INTEREST();
    }
};

//definition of Account that is a checking account
class Checking_Account : public Account
{
public:
    //constructor
    Checking_Account(Customer *cust, int id) : Account(cust, id)
    {
        customer = cust;
        account_number = account_number;
        balance = 0;
    }
    //adds appropriate interest rate
    void add_interest()
    {
        balance = balance*this->get_customer()->get_SAVINGS_INTEREST();
    }
};

#endif
