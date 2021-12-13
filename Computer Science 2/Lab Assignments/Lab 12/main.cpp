//    Name: Eric Flores
//    Assignment: Lab 12
//    Title:      Bank Account
//    Date: 12/13/2021
//
//    Description: This short program assumes the existence of a "BankAccount" class to derive a class "SavingsAccount"
//                 It contains two instance variables: a double declared as "interestRate" and an int declared as "interestType"
//                 interestType can have two values 1 or 2, which are labeled "Simple" or "Compound" respectively.
//                 The interestType variable is initialized by a strings "Simple" or "Compound"
//                 In the end, two pairs of functions "getInterestRate" and "getInterestType" return the values
//                 of the correspondingh data members as double and int respectively.
class SavingsAccount : public BankAccount
{

private:
    double interestRate;

    int interestType;

public:
    SavingsAccount(double interest, string type)
    {

        interestRate = interest;

        if (type == "Simple")
            interestType = 1;

        else if (type == "Compound")
            interestType = 2;
    }

    double getInterestRate()
    {
        return interestRate;
    }

    int getInterestType()
    {
        return interestType;
    }
};