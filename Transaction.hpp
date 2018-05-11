//
//  Transaction.hpp
//  HW5
//
//  Created by Nate Esrey on 3/19/18.
//  Copyright © 2018 Nate Esrey. All rights reserved.
//

#ifndef Transaction_hpp
#define Transaction_hpp
#include <string>
#include <sstream>

/**
 Keeps a record for each transaction performed
 */
class Transaction
{
private:
    std::string customer_number;
    std::string transaction_type;
    double amount;
    std::string fees;
public:
    
    Transaction(int customer_number, std::string type, double amt, std::string fees)
    {
        this->customer_number = customer_number;
        this->transaction_type = type;
        this->amount = amt;
        this->fees = fees;
    }
    
    std::string process_tran()
    {
        std::stringstream ss;
        ss << "Transaction: " << transaction_type << " Amount: " << amount << " " << fees;
        return ss.str();
    }
};
#endif
