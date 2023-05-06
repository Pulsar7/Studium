#include <iostream>
using namespace std;


class CALCULATOR {
    public: 
        int a, b;

        int get_rek_ggt(void) {
            if (a != 0 && b != 0 && a != b && b != a) {
                if (a > b) {
                    a = a-b;
                } else {
                    b = b-a;
                }
                return get_rek_ggt();
            } else {
                if (a == 0) {
                    return b;
                } else {
                    return a;
                }
            }
        }

        int get_iter_ggt(void) {
            while (a != 0 && b != 0 && a != b && b != a) {
                if (a > b) {
                    a = a-b;
                } else {
                    b = b-a;
                }
            }
            if (a == 0) {
                return b;
            } else {
                return a;
            }
        }
};


int main(int argc, char *argv[]) {
    CALCULATOR calc;
    calc.a = 1000;
    calc.b = 512;
    cout << calc.get_iter_ggt() << "\n";
    cout << calc.get_rek_ggt() << "\n";
    return 0;
}