#include <iostream>
using namespace std;

int main() {
    // Given Probabilities
    double P_Fault = 0.02;
    double P_NoFault = 1.0 - P_Fault;
    double P_Alert_given_Fault = 0.98;
    double P_Alert_given_NoFault = 0.03;

    // Calculate P(Alert)
    double P_Alert = (P_Alert_given_Fault * P_Fault) + (P_Alert_given_NoFault * P_NoFault);

    // Apply Bayes' Theorem to find P(Fault | Alert)
    double P_Fault_given_Alert = (P_Alert_given_Fault * P_Fault) / P_Alert;

    // Display the result
    cout << "Probability that machine actually has a fault given an alert: ";
    cout << P_Fault_given_Alert * 100 << "%" << endl; // Convert to percentage

    return 0;
}
