#include <csplitter.h>
#include <splitter.h>

using namespace std;

struct CSplitter* CSplitter_create(void)
{
    struct CSplitter *csplitter = new CSplitter;
    csplitter->splitter = new Splitter();
    csplitter->tokens = NULL;

    return csplitter;
}

void CSplitter_delete(struct CSplitter *csplitter)
{
    if (csplitter == NULL)
        return;

    if (csplitter->splitter == NULL)
    {
        if (csplitter->tokens != NULL)
            delete csplitter->tokens;
        delete csplitter;
        return;
    }

    if (csplitter->tokens != NULL)
    {
        unsigned i = 0;
        while (csplitter->tokens[i] != NULL)
        {
            delete csplitter->tokens[i];
            i++;
        }

        delete csplitter->tokens;
    }

    Splitter *splitter = static_cast<Splitter*>(csplitter->splitter);
    delete splitter;
    delete csplitter;
}

bool CSplitter_insert(struct CSplitter *csplitter, struct CSeparator *cseparator)
{
    if (csplitter == NULL || cseparator == NULL)
        return false;
    if (csplitter->splitter == NULL || cseparator->separator == NULL)
        return false;

    Splitter *splitter = static_cast<Splitter*>(csplitter->splitter);
    Separator *separator = static_cast<Separator*>(cseparator->separator);

    return splitter->Insert(*separator);
}

bool CSplitter_remove(struct CSplitter *csplitter, struct CSeparator *cseparator)
{
    if (csplitter == NULL || cseparator == NULL)
        return false;
    if (csplitter->splitter == NULL || cseparator->separator == NULL)
        return false;

    Splitter *splitter = static_cast<Splitter*>(csplitter->splitter);
    Separator *separator = static_cast<Separator*>(cseparator->separator);

    return splitter->Insert(*separator);
}

void CSplitter_split(struct CSplitter *csplitter, const char *str)
{
    if (csplitter == NULL)
        return;
    if (csplitter->splitter == NULL)
        return;

    Splitter *splitter = static_cast<Splitter*>(csplitter->splitter);
    std::vector<std::string> result = splitter->Split(str);

    if (csplitter->tokens != NULL)
    {
        size_t i = 0;
        while (csplitter->tokens[i] != NULL)
        {
            delete csplitter->tokens[i];
            i++;
        }

        delete csplitter->tokens;
    }

    csplitter->tokens = new char*[result.size() + 1];
    csplitter->tokens[result.size()] = NULL;

    size_t size = result.size();
    for (size_t i = 0; i < size; i++)
    {
        size_t length = result[i].size();
        csplitter->tokens[i] = new char[length + 1];
        csplitter->tokens[i][length] = '\0';

        for (size_t j = 0; j < length; j++)
            csplitter->tokens[i][j] = result[i][j];
    }
}

