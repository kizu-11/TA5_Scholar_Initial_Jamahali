#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Function to validate yes/no input
char getYesNoInput(const string& question) {
    char input;
    while (true) {
        cout << question;
        cin >> input;

        // Check if input is a valid single character for Y/N
        if ((input == 'Y' || input == 'y' || input == 'N' || input == 'n') && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any leftover characters in the buffer
            return input; // Return the single character input
        } else {
            cout << "Invalid input. Please type 'Y' or 'N' only." << endl;
            cin.clear(); // Clear any error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }
}

int main(){
    // Variable declaration and initialization
    float MonthlyIncome = 0.0, AnnualIncome = 0.0, GWA = 0.0, QPA = 0.0, Grade = 0.0;
    char freshman, regularStudent, FilipinoGMRC, FEUCAT, FEUCATavg, pwd, financeEval;
    bool isFreshman = false, isRegularStudent = false, isFilipinoGMRC = false, isFEUCAT = false,
         isFEUCATavg = false, isPWD = false, isFinanceEval = false;

    // Constant declaration for income clusters
    const float Poor_MAX = 12082.0, LowIncome_MIN = 12082.0, LowIncome_MAX = 24164.0, LowMiddle_MIN = 24164.0,
                LowMiddle_MAX = 48328.0, Middle_MIN = 48328.0, Middle_MAX = 84574.0, UpperMiddle_MIN = 84574.0,
                UpperMiddle_MAX = 144984.0, UpperIncome_MIN = 144984.0, UpperIncome_MAX = 241640.0, Rich_MIN = 241640.0;
    
    // Constant declaration for PCI (Per Capita Income) descriptions
    const string Poor_PCI = "Less than the official poverty threshold.",
                 LowIncome_PCI = "Between the poverty line and twice the poverty line.",
                 LowMiddle_PCI = "Between two and four times the poverty line.",
                 Middle_PCI = "Between four and seven times the poverty line.",
                 UpperMiddle_PCI = "Between seven and 12 times the poverty line.",
                 UpperIncome_PCI = "Between 12 and 20 times the poverty line.",
                 Rich_PCI = "At least 20 times the poverty line.";

    // Program title in the middle
    string title = "GrantGuide FEU";
    int consoleWidth = 80;
    int padding = (consoleWidth - title.length()) / 2;
    cout << setw(padding + title.length()) << title << endl;

    // Program description
    cout << "\nAre you looking for a scholarship?"
            "\nGrantGuide FEU is created to help students like you at Far Eastern University"
            "\nfind scholarships that you might be eligible for!\n\n";

    // Prompt for freshman status
    freshman = getYesNoInput("Are you an incoming freshman student? (Type 'Y' or 'N')\t: ");
    isFreshman = (freshman == 'Y' || freshman == 'y');

    // Prompt for regular student status only if not a freshman
    if (!isFreshman) {
        regularStudent = getYesNoInput("Are you a regular FEU student? (Type 'Y' or 'N')\t: ");
        isRegularStudent = (regularStudent == 'Y' || regularStudent == 'y');
    }

    // Check if both freshman and regular student answers are "No"
    if (!isFreshman && !isRegularStudent) {
        cout << "\nOh, no. You must be either an incoming freshman or a regular FEU student to proceed.\n";
        return 0; // Exit program if both conditions are false
    }

    // Prompt for QPA and lowest grade if the user is a regular student
    if (isRegularStudent) {
        while (true) {
            cout << "Please enter your QPA (0.0 - 4.0):\t";
            cin >> QPA;

            // Validate QPA input
            if (!cin.fail() && QPA >= 0.0 && QPA <= 4.0) {
                break;
            } else {
                cout << "Invalid input. Please enter a QPA between 0.0 and 4.0." << endl;
                cin.clear();           // Clear input stream
                cin.ignore(1000, '\n'); // Ignore leftover characters
            }
        }

        while (true) {
            cout << "Enter the lowest subject grade (0.0 - 4.0):\t";
            cin >> Grade;

            // Validate lowest grade input
            if (!cin.fail() && Grade >= 0.0 && Grade <= 4.0) {
                break;
            } else {
                cout << "Invalid input. Please enter a grade between 0.0 and 4.0." << endl;
                cin.clear();           // Clear input stream
                cin.ignore(1000, '\n'); // Ignore leftover characters
            }
        }
    }

    // Prompt for Filipino citizenship and good moral status
    FilipinoGMRC = getYesNoInput("Are you a Filipino citizen with good moral character? (Type 'Y' or 'N')\t: ");
    isFilipinoGMRC = (FilipinoGMRC == 'Y' || FilipinoGMRC == 'y');

    // Prompt for FEUCAT superior rating
    FEUCAT = getYesNoInput("Do you have at least a SUPERIOR rating in FEUCAT? (Type 'Y' or 'N')\t: ");
    isFEUCAT = (FEUCAT == 'Y' || FEUCAT == 'y');

    // Prompt for FEUCAT average rating only if not superior rating
    if (!isFEUCAT) {
        FEUCATavg = getYesNoInput("Do you have at least an average rating in FEUCAT? (Type 'Y' or 'N')\t: ");
        isFEUCATavg = (FEUCATavg == 'Y' || FEUCATavg == 'y');
    }

    // Prompt for PWD status
    pwd = getYesNoInput("Are you a Person With Disability (PWD)? (Type 'Y' or 'N')\t: ");
    isPWD = (pwd == 'Y' || pwd == 'y');

    // Prompt financial evaluation status
    financeEval = getYesNoInput("Did you undergo FEU qualifying financial evaluation? (Type 'Y' or 'N')\t: ");
    isFinanceEval = (financeEval == 'Y' || financeEval == 'y');

    // Prompt for Monthly Income
    cout << "Please enter your family's monthly income:\t";
    while (!(cin >> MonthlyIncome) || MonthlyIncome < 0) {
        cout << "Invalid input. Please enter a valid monthly income:\t";
        cin.clear(); cin.ignore(10000, '\n');
    }

    // Annual income calculation
    AnnualIncome = MonthlyIncome * 12;

    // Prompt for GWA
    cout << "Please enter your High School General Weighted Average (GWA):\t";
    while (!(cin >> GWA) || GWA < 0 || GWA > 100) {
        cout << "Invalid input. Please enter a GWA between 0 and 100:\t";
        cin.clear(); cin.ignore(10000, '\n');
    }

    // Determine income cluster and PCI indication
    string incomeCluster, pciDescription;
    if (MonthlyIncome < Poor_MAX) { incomeCluster = "Poor"; pciDescription = Poor_PCI; }
    else if (MonthlyIncome >= LowIncome_MIN && MonthlyIncome < LowIncome_MAX) { incomeCluster = "Low-income class (but not poor)"; pciDescription = LowIncome_PCI; }
    else if (MonthlyIncome >= LowMiddle_MIN && MonthlyIncome < LowMiddle_MAX) { incomeCluster = "Lower-middle income class"; pciDescription = LowMiddle_PCI; }
    else if (MonthlyIncome >= Middle_MIN && MonthlyIncome < Middle_MAX) { incomeCluster = "Middle-middle income class"; pciDescription = Middle_PCI; }
    else if (MonthlyIncome >= UpperMiddle_MIN && MonthlyIncome < UpperMiddle_MAX) { incomeCluster = "Upper-middle income class"; pciDescription = UpperMiddle_PCI; }
    else if (MonthlyIncome >= UpperIncome_MIN && MonthlyIncome < UpperIncome_MAX) { incomeCluster = "Upper-income class (but not rich)"; pciDescription = UpperIncome_PCI; }
    else { incomeCluster = "Rich"; pciDescription = Rich_PCI; }

    // Display income cluster with PCI indication
    cout << "\nFor a family of 5, your income cluster is: " << incomeCluster << " (" << pciDescription << ")\n";

    // Determine eligible scholarships
    cout << "\nYou are eligible for the following scholarships:\n";
    bool eligible = false;

     if (isFilipinoGMRC && isFreshman && isFEUCAT && GWA >= 88) 
        { cout << "- Entrance Scholarship (Merit-based)\n"; eligible = true; }

    if (isFilipinoGMRC && isFreshman && isFEUCATavg && isFinanceEval && AnnualIncome <= 100000) 
        { cout << "- LEAP (Long Term Educational Assistance Program) (Needs-based)\n"; eligible = true; }

    if (isFilipinoGMRC && isFreshman && isFEUCAT && GWA >= 88) 
        { cout << "- NRSSP (Nicanor Reyes Science Scholarship Program) (Needs-based)\n"; eligible = true; }

    if (isFilipinoGMRC && QPA >= 3.20 && Grade >= 2.5 && isRegularStudent) 
        { cout << "- Academic Scholarship (Merit-based)\n"; eligible = true; }

    if (isPWD) 
        { cout << "- PWD Discount (Needs-based)\n"; eligible = true; }

    if (isFilipinoGMRC && isFreshman && isFEUCAT && GWA >= 88) 
        { cout << "- Teacher's Scholarship Program (Merit-based)\n"; eligible = true; }

        if (!eligible) 
        { cout << "None\n"; }

cout << "\nThank you for using GrantGuide FEU!" <<
    "\nYou may visit https://www.feu.edu.ph/cost-and-aid/scholarship-grants/ for more information.\n" <<
    "\nGoodluck on your journey!";

    return 0;
}
