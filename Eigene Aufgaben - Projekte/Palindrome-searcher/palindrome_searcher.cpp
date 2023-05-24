#include <iostream>
#include <string>
using namespace std;


class SEARCHER {
    public:
        bool pal_state = true;

        void check_if_palindrome(string text) {
            for (int i = text.length()-1; i >= 0; i--) {
                if (text[i] != text[(text.length()-1)-i]) {
                    pal_state = false;
                    break;
                }
            }
        }
};


int main(int argc, char *argv[]) {
    SEARCHER searcher;
    string text;
    cout << "Enter a text: ";
    // cin >> text; // only reads the first word if there is any space
    getline(cin,text); // suggestion from `ChatGPT-openai` (using GPT3)
    searcher.check_if_palindrome(text);
    if (searcher.pal_state == true) {
        cout << "\nThe text '"+text+"' is a palindrome!" << endl;
    } else {
        cout << "\nThe text '"+text+"' isn't a palindrome" << endl;
    }
    return 0;
}