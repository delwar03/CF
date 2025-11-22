#include<bits/stdc++.h>
using namespace std;

int main() {
    
    string sub[] = {"TOC", "Eco", "Numerical", "DS", "DS Lab",
                        "Project", "Numerical Lab", "DLD",
                        "DLD Lab", "Laplace", "CP"};
    double credit[] = {3, 3, 2, 2, 1.5, 1, 1.5, 3, 1.5, 3, 1.5};
    int n = 11;

    double totalCredits = 0, totalPoints = 0;

    for (int i = 0; i < n; i++) {
        double gpa;
        cout << "Enter GPA for " << sub[i] << " (0.0 - 4.0): ";
        cin >> gpa;

        // Weighted GPA = GPA * credit hours
        totalPoints += gpa * credit[i];
        totalCredits += credit[i];
        cout << "\n";
    }

    double GPA = totalPoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Your Overall GPA: " << GPA << " / 4.00" << endl;
}