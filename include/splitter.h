#ifndef PHILIB_SPLITTER
#define PHILIB_SPLITTER

#include <vector>
#include "separator.h"

class Splitter
{
    public:
        bool Insert(const Separator&);
        bool Remove(const Separator&);
        bool Remove(const std::string&);
        void Split(const std::string&, std::vector<std::string>&) const;
        std::vector<std::string> Split(const std::string&) const;
    private:
        std::vector<Separator> separators;
};

#endif

