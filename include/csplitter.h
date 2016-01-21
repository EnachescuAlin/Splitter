#ifndef PHILIB_CSPLITTER
#define PHILIB_CSPLITTER

#include <cseparator.h>

struct CSplitter
{
    void *splitter;
    char **tokens;
};

#ifdef __cplusplus
extern "C"
{
#endif

struct CSplitter* CSplitter_create(void);
void CSplitter_delete(struct CSplitter*);
bool CSplitter_insert(struct CSplitter*, struct CSeparator*);
bool CSplitter_remove(struct CSplitter*, struct CSeparator*);
void CSplitter_split(struct CSplitter*, const char*);

#ifdef __cplusplus
}
#endif

#endif

