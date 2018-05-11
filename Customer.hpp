//
//  Customer.hpp
//  HW5
//
//  Created by Nate Esrey on 3/19/18.
//  Copyright © 2018 Nate Esrey. All rights reserved.
//
#ifndef Customer_hpp
#define Customer_hpp
#include <string>
using std::string;
/**
 The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
 Additionally, there are specialized types of Customers: Adult, Senior, and Student.
 Each type of Customer has its own checking and savings interest rates,
 as well as its own checking and overdraft fees.
 @author: Ed Walker
 */
class Customer // FIXME: Complete the implementation!
{
protected:
    //to store customer data that relates to the cooresponding account
    
    string name;
    string address;
    short int age;
    string telephone_number;
    int customer_number;
    
    //below will be different for each type of customer
    
    double SAVINGS_INTEREST; //%
    double CHECK_INTEREST;  //%
    double CHECK_CHARGE; //%
    double OVERDRAFT_PENALTY;  //$

public:
    //constructor will set values passed into constructor
    Customer (string n, string a, short int ag, string tn, int cn)
    {
        name = n; //name of customer
        address = a; //customer address
        age = ag; //age of customer
        telephone_number = tn; //customer's telephone number
        customer_number = cn; //customer's cell phone number
    }
    //customer data getters
    const string get_name() {
        return name;
    }
    
    const string get_address() {
        return address;
    }
    
    const short int get_age() {
        return age;
    }
    
    const string get_telephone_number() {
        return telephone_number;
    }
    
    const int get_customer_number() {
        return customer_number;
    }
    
    const double get_SAVINGS_INTEREST()
    {
        return SAVINGS_INTEREST;
    }
    
    const double get_CHECK_INTEREST()
    {
        return CHECK_INTEREST;
    }
    
    const double get_CHECK_CHARGE()
    {
        return CHECK_CHARGE;
    }
    
    const double get_OVERDRAFT_PENALTY()
    {
        return OVERDRAFT_PENALTY;
    }
    
protected:
    //protected setters for customer data, protected in order to protect customer data
    void set_name(string n) {
        name = n;
    }
    
    void set_address(string a) {
        address = a;
    }
    
    void set_age(short int a) {
        age = a;
    }
    
    void set_telephone_number(string n) {
        telephone_number = n;
    }
    
    void set_customer_number(int n) {
        customer_number = n;
    }
};

//definition of Customer that is a Senior
class Senior : public Customer {
public:
    Senior(string name, string address, int age, string telephone, int customer_number) : Customer(name, address, age, telephone, customer_number)
    {
        //pertinent numbers to a Senior's account
        SAVINGS_INTEREST = 7.65; //% gained from interest
        CHECK_INTEREST = 1.86;  //%
        CHECK_CHARGE = 0.35; //%
        OVERDRAFT_PENALTY = 28.50;  // Penalty for overdraft in dollar amount
    }
};

//definition of Customer that is a Student
class Student : public Customer {
public:
    Student(string name, string address, int age, string telephone, int customer_number) : Customer(name, address, age, telephone, customer_number)
    {
        //pertinent numbers to a Student's account
        SAVINGS_INTEREST = 10.01; // % gained from interest
        CHECK_INTEREST = 0.86;  //%
        CHECK_CHARGE = 0.35; //%
        OVERDRAFT_PENALTY = 20.00;  //Penalty for overdraft in dollar amount
    }
};

//definition of Customer that is an Adult
class Adult : public Customer {
public:
    Adult(string name, string address, int age, string telephone, int customer_number) : Customer(name, address, age, telephone, customer_number)
    {
        //pertinent numbers to a Adult's account
        SAVINGS_INTEREST = 6.65; //% gained from interest
        CHECK_INTEREST = 1.3;  //%
        CHECK_CHARGE = 1.35; //%
        OVERDRAFT_PENALTY = 25.00;  //Penalty for overdraft in dollar amount
    }
};


#endif
