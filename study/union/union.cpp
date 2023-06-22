#include <iostream>
using namespace std;


union U {
    std::string s;
    std::vector<int> v;

    U (int t) {
        if (t == 0) {
            new (&s) std::string;
        } else if (t==1) {
            new (&v) std::venctor<int>;
        } else {
            assert(false);
        }
    }

    ~U() {}
}

int main() {
    U au(1);
    au.v.~vector;

    return 0;
}
