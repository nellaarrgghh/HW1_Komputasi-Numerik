#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main () {
    double trueVal = 6.737947e-3; // e^-5
    double x = 5.0;
    double a = 0.0, b = 0.0; // b di sini itu yg pecahan, nanti hasil akhirnya 1/b
    double prev_A = 0.0, prev_B = 0.0;
    double factorial = 1.0;
    
    cout<<fixed<<setprecision(8);
    cout<< "| n | Approx A |  et (a) % | ea (a) %|  Approx B | et (b) % | ea (b) % |" << endl;
    cout<< "-------------------------------------------------------------" << endl;
    for (int n = 0; n < 20; ++n) {
        if (n > 0) factorial *= n; 
        double term = pow(x, n) / factorial;

        // Rumus A
        a += pow(-1, n) * term;
        double etA = abs((trueVal - a) / trueVal) * 100.0;
        double eaA = (n == 0) ? 0.0 : abs((a - prev_A)/ a) * 100.0; 

        // Rumus B
        b += term;
        double approx_b = 1.0 / b;
        double etB = abs((trueVal - approx_b) / trueVal) * 100.0;
        double eaB = (n == 0) ? 0.0 : abs((approx_b - prev_B) / approx_b) * 100.0;

        // Output
        cout << "| " << setw(2) << n + 1 
             << " | " << setw(11) << a << " | " << setw(10) << etA 
             << " | " << setw(10) << eaA << " | " << setw(11) << b 
             << " | " << setw(10) << etB << " | " << setw(10) << eaB << " |" << endl;

        // Update
        prev_A = a;
        prev_B = b;

        if (etA < 0.01 && etB < 0.01) break;
    }
    return 0;
}
