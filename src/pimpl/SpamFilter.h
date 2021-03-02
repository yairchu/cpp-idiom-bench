#pragma once

#include <set>
#include <string>
#include <vector>

namespace pimpl
{
class SpamFilter
{
public:
    SpamFilter (const std::set<std::string>& forbiddenWords);
    ~SpamFilter();

    bool isSpam (const std::vector<std::string>& words) const;

private:
    class Impl;

    std::unique_ptr<Impl> impl;
};

} // namespace pimpl