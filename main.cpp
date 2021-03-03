#include <iostream>
#include <vector>
#include <string>

//Creation of class to hold the type of bill, cost of bill, and total debt of the user

class billingSystem{
    public:
        void getBill();
        void payBill(double costToPay);
        std::string retrieveBillName(int i);
        double outstandingBalance();
        void getName();
        void simulateMonth();
        int totalNumberofBills();
    
    private:
        std::vector<std::string> typeOfBill; //Vector to hold the types of bill the user wishes to have
        std::vector<double> monthlyBillCost; // Vector to hold the cost of each bill, the position will directly relate to position of type
        double totalDebt; // Holds the total amount of money the user owes, which has yet to be paid off
        std::string userName;
        int numberOfBills = 0;

};

void billingSystem:: getName(){

    std::cout << "What is your name? ";

    //Allows getline to function multiple times in a row
    std::cin.ignore();

    getline(std::cin, userName); //Gets the name of the user

    std::cout << "Hello " << userName << ", thank you for using our billing system \n";

}

void billingSystem:: getBill(){
    std::string enteredBill; //Holds the type of bill the user would like to enter into the system, to be pushed into the vector typeOfBill
    double enteredCost; //Holds the entered cost of the bill the user would like to enter into the system

    //Retrieves the bill from the user, stores it into enteredBill,and then pushes it into the vector typeOfBill
    std::cout << "Hello " << userName << ", which bill would you like to enter into the system? ";

    //Allows getline to function multiple times in a row
    std::cin.ignore();

    getline(std::cin, enteredBill);

    typeOfBill.push_back(enteredBill);

    //Retrieves the cost of the bill from the user, stores it in enteredCost, and then pushes it into the vector monthlyBillCost

    std::cout << "What is the cost of the bill you just entered? ";
    std::cin >> enteredCost;

    monthlyBillCost.push_back(enteredCost);

    //Increases the number of bills that the user has entered into the system
    numberOfBills++;
    
}

//Simulates that a month has passed since the user has last paid their bill, meaning that the associated cost is added to their total debt(balance)

void billingSystem:: simulateMonth(){
    //Adds the cost of every bill the user has entered to their total debt
    for(int i = 0; i < numberOfBills; i++){
        totalDebt += monthlyBillCost[i];
    }
}

//Subtracts the amount being paid from the total outstanding balance of the user
//It then outputs how much the user has left
void billingSystem:: payBill(double costToPay){
    totalDebt -= costToPay;
    
    //Acknowledges that the system has received the payment
    std::cout << "Hello " << userName <<", we have received your payment \n";

    //Tells the user their new outstanding balance after the payment has been processed
    std::cout << "Your remaining balance after your payment of: $" << costToPay << " is: $" << totalDebt; 
}

//Returns the name of the bill being indexed
std::string billingSystem:: retrieveBillName(int i){
    //return the value of the vector at which it's being indexed

    return typeOfBill[i];

}

//Returns the outstanding balance(debt) of the user
double billingSystem:: outstandingBalance(){
    return totalDebt;
}

//Returns the amount of bills the specific user has entered into the system
int billingSystem:: totalNumberofBills(){
    return numberOfBills;
}

int main(){
    int numberOfUsers, billsToAdd;
    double amountToPay;
    billingSystem *billing;

    //Tells the program how many users to be created
    std::cout << "How many users would you like to add to the system? ";
    std::cin >> numberOfUsers;

    //Creation of pointer to hold the amount of users the program should be able to create
    billing = new billingSystem[numberOfUsers];

    //Loops over the number of users created and fills in information for them
    for(int i = 0; i < numberOfUsers; i++){
        billing[i].getName(); //Stores the name of an individual into the object
        std::cout << "How many bills would you like to add? "; //Tells the program how many bills the user would like to add for X person
        std::cin >> billsToAdd;

        //Loops over the number of bills to add and continually add them to the program, along with their associated cost
        for(int k = 0; k < billsToAdd; k++){
            billing[i].getBill();
        }
    }

    //Simulates the passage of 2 months

    for(int i = 0; i < numberOfUsers; i++){
        billing[i].simulateMonth();
        billing[i].simulateMonth();
    }

    //Simulates the user deciding to pay X amount
    for(int i = 0; i < numberOfUsers; i++){
        std:: cout << "These are the bills that you have with us: \n ";
        
        for(int k = 0; k <billing[i].totalNumberofBills(); k++){

            std::cout << billing[i].retrieveBillName(k) << std::endl;
        }

        //Stores the amount the user wishes to pay, for their current balance, into amountToPay
        std::cout << "How much of your outstanding balance would you like to pay off? \n"
                  << "Your current outstanding balance is: " << billing[i].outstandingBalance() << std::endl;
        
        std::cout << "I would like to pay: $";
        std::cin >> amountToPay;

        billing[i].payBill(amountToPay);

    }

    //Deletion of pointers to return memory to space
    delete[] billing;
}
