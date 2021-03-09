#include <cmath>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

namespace heaponly
{
class SpamFilter
{
    struct Deleter
    {
        void operator() (SpamFilter*) const;
    };

public:
    bool isSpam (const std::vector<std::string>& words) const;

    static std::unique_ptr<SpamFilter, Deleter> make (std::set<std::string> forbiddenWords);

protected:
    ~SpamFilter() = default; // Note: protected destructor is not virtual
    SpamFilter() = default;
    SpamFilter (const SpamFilter&) = delete;
    SpamFilter& operator= (const SpamFilter&) = delete;
    class Impl;
};

} // namespace heaponly