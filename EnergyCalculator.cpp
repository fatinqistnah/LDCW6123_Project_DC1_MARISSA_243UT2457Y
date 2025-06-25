#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// Function to get AI energy-saving tip
string getAITip(double hoursPerDay, const string& applianceName) {
    if (hoursPerDay > 4) { // if else, if hours > 4 then the AI Tip suggested is to use during off-peak hours to save energy
        return "Try using your " + applianceName + " during off-peak hours to save energy.";
    } else if (hoursPerDay < 2) { // else if hours < 2 AI Tip suggested is they are managing their energy well
        return "Great usage! You're already managing your energy well.";
    } else {
        return "Consider using energy-saving settings for better efficiency.";
    }
}
int main() {
    char proceed; // for continuity 
    do{
    string applianceName; //declare variable
    double powerWatts = 0.0, hoursPerDay = 0.0;

    const double RATE_PER_KWH = 0.50;        // RM per kWh
    const double CO2_PER_KWH = 0.276;        // kg CO2 per kWh
    
    
    cout << "=== Smart Living Energy Calculator ===\n\n";

    cout << "Enter Appliance Name: "; //device name
    getline (cin, applianceName);

    cout << "Enter Power Rating (Watts): "; //device power
    cin >> powerWatts;

    cout << "Enter Hours Used Per Day: "; //how long the device is used per day
    cin >> hoursPerDay;

    // Calculations
    double dailyEnergyKWh = (powerWatts * hoursPerDay) / 1000.0; //Daily Energy (kWh)
    double monthlyCost = dailyEnergyKWh * 30 * RATE_PER_KWH; //Monthly Cost (RM)
    double monthlyCO2 = dailyEnergyKWh * 30 * CO2_PER_KWH; //Monthly CO2 (kg)
    string tip = getAITip(hoursPerDay, applianceName);

    // Output calculation results 
    cout << fixed << setprecision(2);
    cout << "\n--- Calculation Results ---\n";
    cout << "Appliance: " << applianceName << endl;
    cout << "Daily Energy Usage: " << dailyEnergyKWh << " kWh" << endl;
    cout << "Estimated Monthly Cost: RM " << monthlyCost << endl;
    cout << "Estimated Monthly CO2 Emissions: " << monthlyCO2 << " kg" << endl;

    cout << "\nAI Energy Tip:\n" << tip << endl;
    // General energy tips
    cout << "\n--- General Energy Saving Tips ---\n";
    cout << "- Peak Hours: Avoid using high-power appliances from 7-10 PM.\n";
    cout << "- Smart Scheduling: Use timers or smart plugs to control usage.\n";
    cout << "- Energy Efficiency: Choose ENERGY STAR certified appliances.\n";
    
        do {
            cout << "Would you like to calculate for another appliance? (Y/N): ";
            cin >> proceed;
            // Check for any invalid input 
            if (proceed != 'Y' && proceed != 'y' && proceed != 'N' && proceed != 'n') {
                cout << "Invalid input. Please enter Y or N." << endl;
            }
            } while (proceed != 'Y' && proceed != 'y' && proceed != 'N' && proceed != 'n');
            
            if (proceed =='Y' || proceed == 'y'){
                system("cls");// clear screen
                cin.ignore();// clear input buffer

            }
    }while(proceed == 'Y' || proceed == 'y'); // loop if user enter Y or y
    return 0;
}