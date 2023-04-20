#include <stdio.h>
#include <stdlib.h>

int main()
{
    // x();
    y();

    return 0;
}

int x()
{
    const char *s[] = {"man", "woman", "girl", "boy", "sister"};
    const char **q;
    int k;
    for (k = 0; k < 5; k++)
    {
        q = &s[k];
        printf("%s ", *q);
        printf("%p\n", q);
    }

    return 0;
}

struct man
{
    char name[20];
    int age;
} person[3] = {"liql", 28, "wang", 23, "sun", 21};

int y()
{
    struct man *q, *p;
    int i, m = 0;
    p = person;

    for (i = 0; i < 3; i++)
    {
        if (m < p->age)
        {
            m = p->age;
            q = p;
        }
        p++;
    }
    printf("%s %d\n", q->name, q->age);
    return 0;
}