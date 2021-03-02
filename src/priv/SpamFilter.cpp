#include "SpamFilter.h"

#include "../priv.h"

using namespace prividiom;

class SpamFilter::Priv : public SpamFilter
{
public:
    bool isSpam (const std::string& word) const;
};

bool SpamFilter::Priv::isSpam (const std::string& s) const
{
    return m_forbiddenWords.find (s) != m_forbiddenWords.end();
}

SpamFilter::SpamFilter (const std::set<std::string>& forbiddenWords) : m_forbiddenWords (forbiddenWords) {}

bool SpamFilter::isSpam (const std::vector<std::string>& words) const
{
    for (const auto& x : words)
        if (priv.isSpam (x))
            return true;
    return false;
}
