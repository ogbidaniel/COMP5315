#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = {"The quick brown fox folded when he saw the lazy dog."};
    string t = {"folded"};
    int sizeS = s.size();
    int sizeT = t.size();

    for (int i = 0; i <= sizeS - sizeT; i++) { // Corrected loop condition
        bool matched = true;
        for (int j = 0; j < sizeT; j++) {
            if (s[i + j] != t[j]) { // Corrected comparison
                matched = false;
                break; // Exit inner loop if mismatch
            }
        }
        if (matched) {
            cout << "\nMatch Found at index " << i << endl; // Indicate match and index
            return 0; // Exit after first match (optional)
        }
    }

    cout << "\nNo match found" << endl;
    return 0;
}