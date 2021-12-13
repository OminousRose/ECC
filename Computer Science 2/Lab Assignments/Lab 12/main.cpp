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