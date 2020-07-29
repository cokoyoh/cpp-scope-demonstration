#include <iostream>

using namespace std;

void useLocal();
void useStaticLocal();
void useGlobal();

int x{1}; // global variable

int main() {
    cout << "global x in main is "<< x << endl;

    int x{5}; //local variable to the main function

    cout << "local x in main's outer scope is " << x << endl;

    { // block starts a new scope
        int x{7}; // hides both x in outer scope and the global x

        cout << "local x in main's inner scope is " << x << endl;
    }

    cout << "local x in main's outer scope is " << x << endl;

    useLocal(); // has it's own local x
    useStaticLocal(); // has static local x
    useGlobal(); // uses the global x
    useLocal(); // reinitialise it's local x
    useStaticLocal(); // static local x retains its prior value
    useGlobal(); // global x also retains its prior value

    cout << "\nlocal x in main is " << x << endl;
}

void useLocal() {
    int x{25}; // initialised each time useLocal is called

    cout << "\nlocal x is " << x << " on entering useLocal" << endl;
    ++x;
    cout << "local x is " << " on exiting useLocal" << endl;
}

void useStaticLocal() {
    static int x{50}; // retains it's original value after the function was called

    cout << "local static x is " << x << " on entering useStaticLocal" << endl;
    ++x;
    cout << "local static is " << x << " on exiting useStaticLocal" << endl;
}

void useGlobal() {
    cout << "\nglobal x is " << x << " on entering useGlobal" << endl;
    x *= 10;
    cout << "global x is " << x << " on exiting useGlobal" << endl;
}
