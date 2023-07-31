#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


class CashMachine{
    private:
        double total = 0.0;
        const char billNameArray[10][11] = {"$100 Bills", "$50 Bills", "$20 Bills", "$10 Bills", "$5 Bills", "$1 Bills", "Quarters", "Dimes", "Nickles", "Pennies"};//Array will all bill and coin names    
        unsigned long long billQuantityArray[10] = {0}; //Initialize array for return bill quantity

    public:
        void calcBills(double inputValue){   
            // Check user input to ensure there is no double overflow with inputValue
            if (inputValue > 9999999999999.99)
            {
                printf("\nInput value exceeds hardware limitations, please input a quantity less than $10 trillion!");
                memset(billQuantityArray, 0, sizeof(billQuantityArray));
                total =  0.0; //update total attribute
                return;
            }

            total =  inputValue; //update total attribute
            unsigned long long totalRemainder = round(total*100.0); //mutliply by 100 to handle floating point rounding error
            unsigned long long numBills; //Variable to hold bill quantity result
            unsigned long long billValueArray[10] = {10000, 5000, 2000, 1000, 500, 100, 25, 10, 5, 1}; //Array with all bill and coin values *100

            //loop through bill values, calculate quantity of each bill, and recalculate total 
            for (int i = 0; i <sizeof(billValueArray)/sizeof(billValueArray[0]); i++)
            {
                numBills = floor(totalRemainder/billValueArray[i]);
                billQuantityArray[i] = numBills;
                totalRemainder = totalRemainder - billValueArray[i]*numBills;
            }
            return;
        }

        void printBills(){
            if (total == 0.0) {
            printf("\nNo bills to print.\n|");
            return;
        }   
            printf("\nTotal: $%.2f", total);
            for (int i = 0; i <sizeof(billQuantityArray)/sizeof(billQuantityArray[0]); i++)
            {
                printf("\n%s: ", billNameArray[i]);
                printf("%llu", billQuantityArray[i]);
            }
            printf("\n|");
            return;
        } 

        void returnBillQuantity(unsigned long long array[10])
        {
         memcpy(array, billQuantityArray, sizeof(billQuantityArray)); 
        }      
};

int main()
{   
    // Initialize Class
    CashMachine bills;

    // generic input
    double cashInput = 1024.08; // User Input
    bills.calcBills(cashInput);
    bills.printBills();

    unsigned long long billArray[10]; 
    bills.returnBillQuantity(billArray);    //get copy of bill quantity array

    // 1 of each bill
    cashInput = 186.41; // User Input
    bills.calcBills(cashInput);
    bills.printBills();

    //biggest possible user input for double input
    cashInput = 9999999999999.99; // User Input
    bills.calcBills(cashInput);
    bills.printBills();

    //too big error case
    cashInput = 99999999999999.99; // User Input
    bills.calcBills(cashInput);
    bills.printBills();

    return 0;
}






