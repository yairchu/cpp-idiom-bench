#include "SpamFilter.h"

using namespace pimpl;

class SpamFilter::Impl
{
public:
    Impl (const std::set<std::string>& forbiddenWords);
    bool isSpam (const std::vector<std::string>& words) const;

private:
    bool isSpam (const std::string& word) const;

    std::set<std::string> m_forbiddenWords;
};

SpamFilter::Impl::Impl (const std::set<std::string>& forbiddenWords) : m_forbiddenWords (forbiddenWords) {}

bool SpamFilter::Impl::isSpam (const std::vector<std::string>& words) const
{
    for (const auto& x : words)
        if (isSpam (x))
            return true;
    return false;
}

bool SpamFilter::Impl::isSpam (const std::string& s) const
{
    return m_forbiddenWords.find (s) != m_forbiddenWords.end();
}

SpamFilter::SpamFilter (const std::set<std::string>& forbiddenWords) : impl (std::make_unique<Impl> (forbiddenWords)) {}

SpamFilter::~SpamFilter() {}

bool SpamFilter::isSpam (const std::vector<std::string>& words) const
{
    return impl->isSpam (words);
}
