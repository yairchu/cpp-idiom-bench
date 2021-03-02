#pragma once

#include <set>
#include <string>
#include <vector>

namespace prividiom
{
class SpamFilter
{
public:
    SpamFilter (const std::set<std::string>& forbiddenWords);
    bool isSpam (const std::vector<std::string>& words) const;

private:
    class Priv;

    std::set<std::string> m_forbiddenWords;
};

} // namespace prividiom
