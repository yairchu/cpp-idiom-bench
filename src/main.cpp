#include "heaponly/SpamFilter.h"
#include "interface/SpamFilter.h"
#include "pimpl/SpamFilter.h"
#include "priv/SpamFilter.h"
#include "simple/SpamFilter.h"

#include <stdio.h>
#include <string>

template <typename Interface>
bool benchCheck (const Interface& filter)
{
    return filter.isSpam ({"commercial", "for", "popcorn"});
}

template <typename Concrete, typename Interface>
int benchIter (const std::set<std::string>& badWords)
{
    const Concrete filter (badWords);
    return benchCheck<Interface> (filter) ? 1 : 0;
}

template <>
int benchIter<std::unique_ptr<heaponly::SpamFilter>, heaponly::SpamFilter> (const std::set<std::string>& badWords)
{
    auto filter = heaponly::SpamFilter::make (badWords);
    return benchCheck<heaponly::SpamFilter> (*filter) ? 1 : 0;
}

template <typename Concrete, typename Interface>
void bench()
{
    std::set<std::string> badWords;
    badWords.insert ("popcorn");
    badWords.insert ("cookies");
    int r = 0;
    for (int i = 0; i < 1000000; ++i)
        r += benchIter<Concrete, Interface> (badWords);
    if (r < 1)
        printf ("Bug!\n");
}

int main (int argc, const char** argv)
{
    if (argc != 2)
    {
        printf ("Usage: cpp-idiom-bench <MODE>\n");
        return 1;
    }

    const char* mode = argv[1];
    if (0 == strcmp (mode, "heaponly"))
        bench<std::unique_ptr<heaponly::SpamFilter>, heaponly::SpamFilter>();
    else if (0 == strcmp (mode, "simple"))
        bench<simple::SpamFilter, simple::SpamFilter>();
    else if (0 == strcmp (mode, "interface"))
        bench<interface::SpamFilter, interface::AbstractSpamFilter>();
    else if (0 == strcmp (mode, "pimpl"))
        bench<pimpl::SpamFilter, pimpl::SpamFilter>();
    else if (0 == strcmp (mode, "priv"))
        bench<prividiom::SpamFilter, prividiom::SpamFilter>();
    else
    {
        printf ("Unknown mode: %s\n", mode);
        return 1;
    }

    printf ("Done\n");
    return 0;
}
