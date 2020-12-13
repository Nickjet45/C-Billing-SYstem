#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//Creation of class to hold the type of bill, cost of bill, and total debt of the user

class billingSystem{
    public:
        void getBill();
        void payBill(double costToPay);
        std::string retrieveBillName(int indexedElement);
        double retrieveBillCost(int indexedElement);
    
    private:
        std::vector<std::string> typeOfBill; //Vector to hold the types of bill the user wishes to have
        std::vector<double> monthlyBillCost; // Vector to hold the cost of each bill, the position will directly relate to position of type
        double totalDebt; // Holds the total amount of money the user owes, which has yet to be paid off

};

void billingSystem:: getBill(){
    std::string enteredBill; //Holds the type of bill the user would like to enter into the system, to be pushed into the vector typeOfBill
    double enteredCost; //Holds the entered cost of the bill the user would like to enter into the system

    //Retrieves the bill from the user, stores it into enteredBill,and then pushes it into the vector typeOfBill
    std::cout << "Which bill would you like to enter into the system? ";

    getline(std::cin, enteredBill);

    typeOfBill.push_back(enteredBill);

    //Retrieves the cost of the bill from the user, stores it in enteredCost, and then pushes it into the vector monthlyBillCost

    std::cout << "What is the cost of the bill you just entered? ";
    std::cin >> enteredCost;

    monthlyBillCost.push_back(enteredCost);
    
}

//Subtracts the amount being paid from the total outstanding balance of the user
//It then outputs how much the user has left
void billingSystem:: payBill(double costToPay){
    totalDebt -= costToPay;

    std::cout << "Your remaining balance after your payment of: $" << costToPay << " is: $" << totalDebt; 
}

//Returns the name of the bill being indexed
std::string billingSystem:: retrieveBillName(int indexedElement){
    return typeOfBill[indexedElement];
}

//Returns the cost of the bill being indexed
double billingSystem:: retrieveBillCost(int indexedElement){
    return monthlyBillCost[indexedElement];
}


int main(){
    int numberOfRuns;
}