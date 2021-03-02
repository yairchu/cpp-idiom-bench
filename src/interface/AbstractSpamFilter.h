#pragma once

#include <set>
#include <string>
#include <vector>

namespace interface
{
class AbstractSpamFilter
{
public:
    virtual ~AbstractSpamFilter() {};

    virtual bool isSpam (const std::vector<std::string>& words) const = 0;
};

} // namespace interface