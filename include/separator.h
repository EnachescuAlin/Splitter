#ifndef PHILIB_SPLITTER_SEPARATOR
#define PHILIB_SPLITTER_SEPARATOR

#include <string>

class Separator
{
    public:
        Separator(const std::string&, unsigned, bool = true);
        const std::string& GetString(void) const;
        const unsigned& GetPriority(void) const;
        const bool& GetStatus(void) const;
        void SetPriority(unsigned);
        void SetStatus(bool);
    private:
        std::string _separator;
        unsigned _priority;
        bool _status;
};

inline bool operator==(const Separator& a, const Separator& b)
{
    return a.GetString() == b.GetString();
}

#endif

