#include <string>
#include <iostream>
#include "Serialization.hpp"

static int passed = 0;
static int failed = 0;

void check(const std::string& label, bool ok)
{
    if (ok) {
        std::cout << "[PASS] " << label << std::endl;
        ++passed;
    } else {
        std::cout << "[FAIL] " << label << std::endl;
        ++failed;
    }
}

int main()
{
    // 1. heap object round-trip
    Serialization::Data* a = new Serialization::Data();
    a->x = 42;
    a->y = -7;
    a->str = "hello";

    uintptr_t raw = Serialization::serialize(a);
    Serialization::Data* b = Serialization::deserialize(raw);

    check("heap pointer round-trip", a == b);
    check("heap x value preserved", b->x == 42);
    check("heap y value preserved", b->y == -7);
    check("heap string value preserved", b->str == "hello");

    b->x = 99;
    check("modification through deserialized pointer is visible", a->x == 99);

    delete a;

    // 2. null pointer
    Serialization::Data* n = 0;
    uintptr_t raw0 = Serialization::serialize(n);
    Serialization::Data* dn = Serialization::deserialize(raw0);
    check("null pointer round-trip", dn == 0);

    // 3. multiple distinct objects
    Serialization::Data* c = new Serialization::Data();
    c->x = 1;
    c->str = "first";
    Serialization::Data* d = new Serialization::Data();
    d->x = 2;
    d->str = "second";

    uintptr_t rc = Serialization::serialize(c);
    uintptr_t rd = Serialization::serialize(d);

    check("distinct objects stay distinct",
          Serialization::deserialize(rc) != Serialization::deserialize(rd));
    check("first object value preserved",
          Serialization::deserialize(rc)->x == 1);
    check("second object value preserved",
          Serialization::deserialize(rd)->x == 2);

    delete c;
    delete d;

    // 4. stack object
    Serialization::Data s;
    s.x = 100;
    s.y = 200;
    s.str = "stack";

    Serialization::Data* ps = Serialization::deserialize(Serialization::serialize(&s));
    check("stack pointer round-trip", ps == &s);
    check("stack string value preserved", ps->str == "stack");

    // 5. empty string
    Serialization::Data* e = new Serialization::Data();
    e->x = 0;
    e->y = 0;
    e->str = "";

    uintptr_t re = Serialization::serialize(e);
    check("empty string preserved", Serialization::deserialize(re)->str == "");

    delete e;

    std::cout << std::endl
              << passed << " passed, " << failed << " failed" << std::endl;

    if (failed == 0)
        return 0;
    return 1;
}
