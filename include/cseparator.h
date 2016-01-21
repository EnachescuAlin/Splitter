#ifndef PHILIB_CSPLITTER_CSEPARATOR
#define PHILIB_CSPLITTER_CSEPARATOR

struct CSeparator
{
    void *separator;
};

#ifdef __cplusplus
extern "C"
{
#endif

struct CSeparator* CSeparator_create(const char*, unsigned, bool);
void CSeparator_delete(struct CSeparator*);
const char* CSeparator_getString(const struct CSeparator*);
unsigned CSeparator_getPriority(const struct CSeparator*);
bool CSeparator_getStatus(const struct CSeparator*);
void CSeparator_setPriority(struct CSeparator*, unsigned);
void CSeparator_setStatus(struct CSeparator*, bool);
bool CSeparator_equal(const struct CSeparator*, const struct CSeparator*);

#ifdef __cplusplus
}
#endif

#endif

