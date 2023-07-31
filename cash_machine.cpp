#include <iostream>
#include <cmath>
using namespace std;


void cashMachine(double inputValue)
{   
    // Check user input to ensure there is no double overflow with inputValue
    if (inputValue > 9999999999999.99)
    {
        printf("Input value exceeds hardware limitations.");
        return;
    }

    unsigned long long total = round(inputValue*100.0); //mutliply by 100 to get around floating point rounding error 
    unsigned long long billValueArray[10] = {10000, 5000, 2000, 1000, 500, 100, 25, 10, 5, 1}; //Array with all bill and coin values
    const char billNameArray[10][11] = {"$100 Bills", "$50 Bills", "$20 Bills", "$10 Bills", "$5 Bills", "$1 Bills", "Quarters", "Dimes", "Nickles", "Pennies"};//Array will all bill and coin names
    unsigned long long billQuantityArray[10] = {0}; //Initialize array for return bill quantity
    unsigned long long numBills; //Variable to hold 

    printf("\nTotal: %.2Lf", inputValue);
    //loop through bill values, calculate quantity of each bill, and recalculate total 
    for (int i = 0; i <sizeof(billValueArray)/sizeof(billValueArray[0]); i++)
    {
        numBills = floor(total/billValueArray[i]);
        billQuantityArray[i] = numBills;
        total = total - billValueArray[i]*numBills;
        printf("\n%s: ", billNameArray[i]);
        printf("%llu", numBills);
    }
    printf("\n");
    return;
}

int main()
{   
    double cashInput = 9999999999999.99;//works
    cashMachine(cashInput);
    //cashMachine(91474836);
    return 0;
}






