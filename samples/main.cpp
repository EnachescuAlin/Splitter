#include <splitter.h>
#include <iostream>

using namespace std;

int main(void)
{
    Splitter s;
    vector<string> v;
    s.Insert(Separator("+=", 2));
    s.Insert(Separator(" ", 1, false));
    s.Insert(Separator("+", 1));
    s.Insert(Separator("*", 1));
    s.Insert(Separator("/", 1));
    s.Insert(Separator("(", 1));
    s.Insert(Separator(")", 1));

    s.Split("a += ((2 * (3 + 1) + 1) / 3)", v);
    for (auto i : v)
        cout << i << "\n";

    return 0;
}

