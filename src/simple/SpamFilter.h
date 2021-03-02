#pragma once

#include <set>
#include <string>
#include <vector>

namespace simple
{
class SpamFilter
{
public:
    SpamFilter (const std::set<std::string>& forbiddenWords);
    bool isSpam (const std::vector<std::string>& words) const;

private:
    bool isSpam (const std::string& word) const;

    std::set<std::string> m_forbiddenWords;
};

} // namespace simple