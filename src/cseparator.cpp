#include <cseparator.h>
#include <separator.h>

struct CSeparator* CSeparator_create(const char *str, unsigned priority, bool status)
{
    if (str == NULL)
        return NULL;

    struct CSeparator *cseparator = new CSeparator;
    cseparator->separator = new Separator(str, priority, status);

    return cseparator;
}

void CSeparator_delete(struct CSeparator *cseparator)
{
    if (cseparator == NULL)
        return;
    if (cseparator->separator == NULL)
    {
        delete cseparator;
        return;
    }

    Separator *separator = static_cast<Separator*>(cseparator->separator);
    delete separator;
    delete cseparator;
}

const char* CSeparator_getString(const struct CSeparator *cseparator)
{
    if (cseparator == NULL)
        return NULL;
    if (cseparator->separator == NULL)
        return NULL;

    Separator *separator = static_cast<Separator*>(cseparator->separator);
    return separator->GetString().c_str();
}

unsigned CSeparator_getPriority(const struct CSeparator *cseparator)
{
    if (cseparator == NULL)
        return 0;
    if (cseparator->separator == NULL)
        return 0;

    Separator *separator = static_cast<Separator*>(cseparator->separator);
    return separator->GetPriority();
}

bool CSeparator_getStatus(const struct CSeparator *cseparator)
{
    if (cseparator == NULL)
        return false;
    if (cseparator->separator == NULL)
        return false;

    Separator *separator = static_cast<Separator*>(cseparator->separator);
    return separator->GetStatus();
}

void CSeparator_setPriority(struct CSeparator *cseparator, unsigned priority)
{
    if (cseparator == NULL)
        return;
    if (cseparator->separator == NULL)
        return;

    Separator *separator = static_cast<Separator*>(cseparator->separator);
    separator->SetPriority(priority);
}

void CSeparator_setStatus(struct CSeparator *cseparator, bool status)
{
    if (cseparator == NULL)
        return;
    if (cseparator->separator == NULL)
        return;

    Separator *separator = static_cast<Separator*>(cseparator->separator);
    separator->SetStatus(status);
}

bool CSeparator_equal(const struct CSeparator *a, const struct CSeparator *b)
{
    if (a == NULL || b == NULL)
        return false;
    if (a->separator == NULL || b->separator == NULL)
        return false;

    Separator *x = static_cast<Separator*>(a->separator);
    Separator *y = static_cast<Separator*>(b->separator);

    return *x == *y;
}

