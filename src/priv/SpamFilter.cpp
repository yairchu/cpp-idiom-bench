#include "SpamFilter.h"

using namespace prividiom;

struct SpamFilter::Priv
{
    static bool isSpam (const SpamFilter&, const std::string& word);
};

bool SpamFilter::Priv::isSpam (const SpamFilter& self, const std::string& s)
{
    return self.m_forbiddenWords.find (s) != self.m_forbiddenWords.end();
}

SpamFilter::SpamFilter (const std::set<std::string>& forbiddenWords) : m_forbiddenWords (forbiddenWords) {}

bool SpamFilter::isSpam (const std::vector<std::string>& words) const
{
    for (const auto& x : words)
        if (Priv::isSpam (*this, x))
            return true;
    return false;
}
