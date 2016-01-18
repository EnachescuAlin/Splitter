#include <splitter.h>

using namespace std;

bool Splitter::Insert(const Separator& separator)
{
    for (auto i : separators)
        if (i == separator)
            return false;

    for (auto i = separators.begin(); i != separators.end(); i++)
        if (i->GetPriority() < separator.GetPriority())
        {
            separators.insert(i, separator);
            return true;
        }

    separators.push_back(separator);

    return true;
}

bool Splitter::Remove(const Separator& separator)
{
    for (auto i = separators.begin(); i != separators.end(); i++)
        if (*i == separator)
        {
            separators.erase(i);
            return true;
        }

    return false;
}

bool Splitter::Remove(const string& separator)
{
    return Remove(Separator(separator, 0));
}

void Splitter::Split(const string& str, vector<string>& result) const
{
    bool foundSeparator = false;
    for (auto i : separators)
    {
        if (str == i.GetString() && i.GetStatus())
        {
            result.push_back(str);
            return;
        }

        auto found = str.find(i.GetString());
        if (found != string::npos)
        {
            if (found != 0)
                Split(string(str, 0, found), result);
            if (i.GetStatus())
                result.push_back(i.GetString());
            if (found + i.GetString().size() != str.size())
                Split(string(str, found + i.GetString().size()), result);
            return;
        }
    }

    if (!foundSeparator)
        result.push_back(str);
}

