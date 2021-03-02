#include "SpamFilter.h"

using namespace interface;

SpamFilter::SpamFilter (const std::set<std::string>& forbiddenWords) : m_forbiddenWords (forbiddenWords) {}

bool SpamFilter::isSpam (const std::vector<std::string>& words) const
{
    for (const auto& x : words)
        if (isSpam (x))
            return true;
    return false;
}

bool SpamFilter::isSpam (const std::string& s) const
{
    return m_forbiddenWords.find (s) != m_forbiddenWords.end();
}
