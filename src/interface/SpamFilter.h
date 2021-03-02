#pragma once

#include "AbstractSpamFilter.h"

namespace interface
{
class SpamFilter : public AbstractSpamFilter
{
public:
    SpamFilter (const std::set<std::string>& forbiddenWords);
    bool isSpam (const std::vector<std::string>& words) const override;

private:
    bool isSpam (const std::string& word) const;

    std::set<std::string> m_forbiddenWords;
};

} // namespace interface
