#include <string>
#include <sstream>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static int passed = 0;
static int failed = 0;

static std::string strip_newline(const std::string& s)
{
    std::string out = s;

    while (!out.empty())
    {
        char c = out[out.size() - 1];
        if (c == '\n' || c == '\r')
            out.erase(out.size() - 1);
        else
            break;
    }
    return out;
}

static void check(const std::string& label, bool ok)
{
    if (ok)
    {
        std::cout << "[PASS] " << label << std::endl;
        ++passed;
    }
    else
    {
        std::cout << "[FAIL] " << label << std::endl;
        ++failed;
    }
}

static std::string identify_ptr_output(Base* p)
{
    std::ostringstream oss;
    std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

    Base::identify(p);
    std::cout.rdbuf(old);
    return strip_newline(oss.str());
}

static std::string identify_ref_output(Base& p)
{
    std::ostringstream oss;
    std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

    Base::identify(p);
    std::cout.rdbuf(old);
    return strip_newline(oss.str());
}

int main()
{
    // 1. identify(Base*) on stack objects
    A a;
    B b;
    C c;

    check("identify(Base*) A", identify_ptr_output(&a) == "A");
    check("identify(Base*) B", identify_ptr_output(&b) == "B");
    check("identify(Base*) C", identify_ptr_output(&c) == "C");

    // 2. identify(Base&) on stack objects
    check("identify(Base&) A", identify_ref_output(a) == "A");
    check("identify(Base&) B", identify_ref_output(b) == "B");
    check("identify(Base&) C", identify_ref_output(c) == "C");

    // 3. identify(Base*) on heap objects
    Base* pa = new A();
    Base* pb = new B();
    Base* pc = new C();

    check("identify(Base*) heap A", identify_ptr_output(pa) == "A");
    check("identify(Base*) heap B", identify_ptr_output(pb) == "B");
    check("identify(Base*) heap C", identify_ptr_output(pc) == "C");

    // 4. identify(Base&) on heap objects via dereference
    check("identify(Base&) heap A", identify_ref_output(*pa) == "A");
    check("identify(Base&) heap B", identify_ref_output(*pb) == "B");
    check("identify(Base&) heap C", identify_ref_output(*pc) == "C");

    delete pa;
    delete pb;
    delete pc;

    // 5. identify(Base*) with NULL should not crash
    identify_ptr_output(0);
    check("identify(NULL) survived", true);

    // 6. generate: many runs, check non-null, all types, and pointer/reference agreement
    bool all_non_null = true;
    bool seen_a = false;
    bool seen_b = false;
    bool seen_c = false;
    bool ptr_ref_agree = true;

    int i = 0;
    while (i < 300)
    {
        Base* p = Base::generate();

        if (p == 0)
        {
            all_non_null = false;
        }
        else
        {
            std::string by_ptr = identify_ptr_output(p);
            std::string by_ref = identify_ref_output(*p);

            if (by_ptr != by_ref)
                ptr_ref_agree = false;

            if (by_ptr == "A")
                seen_a = true;
            else if (by_ptr == "B")
                seen_b = true;
            else if (by_ptr == "C")
                seen_c = true;
            else
                all_non_null = false;

            delete p;
        }
        ++i;
    }

    check("generate returns non-null", all_non_null);
    check("generate produces A", seen_a);
    check("generate produces B", seen_b);
    check("generate produces C", seen_c);
    check("identify pointer and reference agree", ptr_ref_agree);

    // 7. repeated identify on the same object stays stable
    check("repeated identify stable",
          identify_ptr_output(&a) == identify_ptr_output(&a));

    std::cout << std::endl
              << passed << " passed, " << failed << " failed" << std::endl;

    if (failed == 0)
        return 0;
    return 1;
}
