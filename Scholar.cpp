#include <iostream>
using namespace std;

// Enum to represent social classes
enum SocialClass {
    POOR,
    LOW_INCOME,
    LOWER_MIDDLE_INCOME,
    MIDDLE_MIDDLE_INCOME,
    UPPER_MIDDLE_INCOME,
    UPPER_INCOME,
    RICH
};

// Function prototypes
SocialClass identifySocialClass(double monthlyIncome);
void checkScholarshipEligibility(SocialClass socialClass, double annualIncome, double gpa);

int main() {
    double monthlyIncome, gpa;

    // Input family monthly income and GPA
    cout << "Enter family monthly income: ";
    cin >> monthlyIncome;

    // Check for negative income
    if (monthlyIncome < 0) {
        cout << "Income cannot be negative." << endl;
        return 1;
    }

    cout << "Enter GPA: ";
    cin >> gpa;

    // Check for valid GPA range
    if (gpa < 0 || gpa > 4.0) {
        cout << "GPA must be between 0 and 4.0." << endl;
        return 1;
    }

    // Calculate annual income
    double annualIncome = monthlyIncome * 12;

    // Identify social class
    SocialClass socialClass = identifySocialClass(monthlyIncome);
    cout << "Social Class: ";
    switch (socialClass) {
        case POOR: cout << "Poor"; break;
        case LOW_INCOME: cout << "Low-income class"; break;
        case LOWER_MIDDLE_INCOME: cout << "Lower middle-income class"; break;
        case MIDDLE_MIDDLE_INCOME: cout << "Middle middle-income class"; break;
        case UPPER_MIDDLE_INCOME: cout << "Upper middle-income class"; break;
        case UPPER_INCOME: cout << "Upper-income class (but not rich)"; break;
        case RICH: cout << "Rich"; break;
    }
    cout << endl;

    // Check scholarship eligibility
    checkScholarshipEligibility(socialClass, annualIncome, gpa);

    return 0;
}

// Function to determine social class based on family income
SocialClass identifySocialClass(double monthlyIncome) {
    if (monthlyIncome < 12082) {
        return POOR;
    } else if (monthlyIncome >= 12082 && monthlyIncome < 24164) {
        return LOW_INCOME;
    } else if (monthlyIncome >= 24164 && monthlyIncome < 48328) {
        return LOWER_MIDDLE_INCOME;
    } else if (monthlyIncome >= 48328 && monthlyIncome < 84574) {
        return MIDDLE_MIDDLE_INCOME;
    } else if (monthlyIncome >= 84574 && monthlyIncome < 144984) {
        return UPPER_MIDDLE_INCOME;
    } else if (monthlyIncome >= 144984 && monthlyIncome < 241640) {
        return UPPER_INCOME;
    } else {
        return RICH;
    }
}

// Function to check scholarship eligibility based on social class, income, and GPA
void checkScholarshipEligibility(SocialClass socialClass, double annualIncome, double gpa) {
    // Using a switch statement with the enum value
    switch (socialClass) {
        case UPPER_MIDDLE_INCOME:
        case UPPER_INCOME:
        case RICH:
            cout << "Not eligible for the scholarship." << endl;
            break;
        default:
            if (annualIncome <= 360000 && gpa >= 3.0) {
                cout << "Eligible for the scholarship." << endl;
            } else {
                cout << "Not eligible for the scholarship." << endl;
            }
            break;
    }
}
