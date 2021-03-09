#include "SpamFilter.h"

using namespace heaponly;

class SpamFilter::Impl : public SpamFilter
{
public:
    Impl (std::set<std::string>&);
    bool isSpamImpl (const std::vector<std::string>&) const;

private:
    bool isSpam (const std::string& word) const;

    std::set<std::string> m_forbiddenWords;
};

SpamFilter::Impl::Impl (std::set<std::string>& forbiddenWords) : m_forbiddenWords (forbiddenWords) {}

bool SpamFilter::Impl::isSpamImpl (const std::vector<std::string>& words) const
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

bool SpamFilter::isSpam (const std::vector<std::string>& words) const
{
    return static_cast<const Impl*> (this)->isSpamImpl (words);
}

std::unique_ptr<SpamFilter, SpamFilter::Deleter> SpamFilter::make (std::set<std::string> forbiddenWords)
{
    return std::unique_ptr<SpamFilter, SpamFilter::Deleter> {new Impl (forbiddenWords)};
}

void SpamFilter::Deleter::operator() (SpamFilter* self) const
{
    delete static_cast<const Impl*> (self);
}
