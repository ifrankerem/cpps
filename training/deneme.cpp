#include <iostream>

class naber {
public:
    int x;

    naber& operator=(const naber& rhs) {
        std::cout << "copy assignment called\n";
        if (this != &rhs)
            this->x = rhs.x;
        return *this;
    }
};

int main() {
    naber *a = new naber;
    naber *b = new naber;

    a->x = 5;

    b = a;   // <-- burada senin operator= çalışır (nesne kopyası)
    b->x = 3;

    std::cout << a->x << "\n"; // 5
    std::cout << b->x << "\n"; // 3

    delete a;
    //delete b;
}
