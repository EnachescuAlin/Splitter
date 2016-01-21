#include <stdbool.h>
#include <cseparator.h>
#include <csplitter.h>
#include <stdio.h>

int main(void)
{
    struct CSplitter *s = CSplitter_create();
    struct CSeparator *a = CSeparator_create("+=", 2, true);
    struct CSeparator *b = CSeparator_create(" ", 1, false);
    struct CSeparator *c = CSeparator_create("+", 1, true);
    struct CSeparator *d = CSeparator_create("*", 1, true);
    struct CSeparator *e = CSeparator_create("/", 1, true);
    struct CSeparator *f = CSeparator_create("(", 1, true);
    struct CSeparator *g = CSeparator_create(")", 1, true);

    CSplitter_insert(s, a);
    CSplitter_insert(s, b);
    CSplitter_insert(s, c);
    CSplitter_insert(s, d);
    CSplitter_insert(s, e);
    CSplitter_insert(s, f);
    CSplitter_insert(s, g);

    CSplitter_split(s, "a += ((2 * (3 + 1) + 1) / 3)");

    size_t i = 0;
    while (s->tokens[i])
    {
        printf("%s\n", s->tokens[i]);
        i++;
    }

    CSplitter_delete(s);
    CSeparator_delete(a);
    CSeparator_delete(b);
    CSeparator_delete(c);
    CSeparator_delete(d);
    CSeparator_delete(e);
    CSeparator_delete(f);
    CSeparator_delete(g);

    return 0;
}

