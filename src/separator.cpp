#include "separator.h"

using namespace std;

Separator::Separator(const string& separator, unsigned priority, bool status)
{
    _separator = separator;
    _priority  = priority;
    _status    = status;
}

const string& Separator::GetString(void) const
{
    return _separator;
}

const unsigned& Separator::GetPriority(void) const
{
    return _priority;
}

const bool& Separator::GetStatus(void) const
{
    return _status;
}

void Separator::SetPriority(unsigned priority)
{
    _priority = priority;
}

void Separator::SetStatus(bool status)
{
    _status = status;
}

