#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ld;

void solve() {
    ld X; // Tax amount
    if (!(cin >> X)) return;

    ld income = 0.0;
    
    // Thresholds for Cumulative Tax
    const ld T_0 = 0.0;          // Income <= 12,500
    const ld T_BASIC_MAX = 7500.0;   // Income = 50,000 (Standard tax)
    const ld T_HIGHER_MID = 27500.0; // Income = 100,000 (Standard tax)
    const ld T_HIGHER_MAX = 47500.0; // Income = 150,000 (Standard tax)

    // Tax includes the Tax on Reduced PA (TRP)
    // T(I) = TRP(I) + T_Standard(I)

    // Case 1: Tax <= 7,500. Income in (12,500, 50,000]. No PA reduction.
    // T = 0.20 * (I - 12,500)
    if (X <= T_BASIC_MAX) {
        // Handle X=0 case explicitly, any income up to 12,500 is valid.
        if (X < 1e-9) { 
            income = 12500.0;
        } else {
            // I = 12,500 + X / 0.20 = 12,500 + 5 * X
            income = 12500.0 + X / 0.20;
        }
    } 
    // Case 2: Tax > 7,500 and Standard Tax <= 27,500. Income in (50,000, 100,000]. No PA reduction.
    // T = 7,500 + 0.40 * (I - 50,000)
    else if (X <= T_HIGHER_MID) {
        // I = 50,000 + (X - 7,500) / 0.40
        income = 50000.0 + (X - T_BASIC_MAX) / 0.40;
    }
    // Case 3: Standard Tax > 27,500. Income > 100,000. PA is reduced.
    else {
        // Calculate the actual tax thresholds including PA reduction tax
        // I_100k = 100,000. T(100k) = 27,500 (No PA reduction effect just at 100k)
        
        // I_125k = 125,000. PA is fully phased out. 
        // TRP = (125,000 - 100,000) / 2 * 0.40 = 12,500 * 0.40 = 5,000.
        // T_Standard(125k) = 27,500 + (125,000 - 100,000) * 0.40 = 27,500 + 10,000 = 37,500.
        // T(125k) = 5,000 + 37,500 = 42,500.
        const ld T_PA_PHASE_OUT = 42500.0; 

        // I_150k = 150,000. PA is fully phased out.
        // TRP = 5,000.
        // T_Standard(150k) = 47,500.
        // T(150k) = 5,000 + 47,500 = 52,500.
        const ld T_MAX_HIGHER_RATE = 52500.0;


        // Subcase 3a: T_HIGHER_MID < X <= T_PA_PHASE_OUT. Income in (100,000, 125,000].
        // I = 100,000 + Y, where Y = I - 100,000
        // T = 27,500 + 0.40 * Y + 0.20 * Y = 27,500 + 0.60 * Y
        if (X <= T_PA_PHASE_OUT) {
            // Y = (X - 27,500) / 0.60
            income = 100000.0 + (X - T_HIGHER_MID) / 0.60;
        } 
        // Subcase 3b: T_PA_PHASE_OUT < X <= T_MAX_HIGHER_RATE. Income in (125,000, 150,000].
        // TRP is fixed at 5,000. Standard Tax starts from 37,500 at 125,000.
        // T = 42,500 + 0.40 * (I - 125,000)
        else if (X <= T_MAX_HIGHER_RATE) {
            // I = 125,000 + (X - 42,500) / 0.40
            income = 125000.0 + (X - T_PA_PHASE_OUT) / 0.40;
        } 
        // Subcase 3c: X > T_MAX_HIGHER_RATE. Income > 150,000.
        // TRP is fixed at 5,000. Standard Tax starts from 47,500 at 150,000.
        // T = 52,500 + 0.45 * (I - 150,000)
        else {
            // I = 150,000 + (X - 52,500) / 0.45
            income = 150000.0 + (X - T_MAX_HIGHER_RATE) / 0.45;
        }
    }

    // Output with high precision for the special judge
    cout << fixed << setprecision(4) << income << "\n";
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}