#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>


struct Arr
{
    int len;
    int cnt;
    int *pbase;
};

void init(struct Arr *, int);
void show(struct Arr *);
bool is_empty(struct Arr *);
bool is_full(struct Arr *);
bool append(struct Arr *, int);
bool insert(struct Arr *, int pos, int);
bool delete(struct Arr *, int pos, int *);
void inversion(struct Arr *);
void sort(struct Arr *);


int main()
{
    struct Arr arr;
    int val;

    init(&arr, 6);
    append(&arr, 7);
    append(&arr, 5);
    append(&arr, 3);
    show(&arr);
    insert(&arr, 2, 0);
    show(&arr);
    if (delete(&arr, 1, &val))
    {
        printf("删除成功，删除的元素为：%d\n", val);
    }
    else
    {
        printf("删除失败\n");
    }
    inversion(&arr);
    show(&arr);
    sort(&arr);
    show(&arr);

    return 0;

    return 0;
}

void init(struct Arr *parr, int length)
{
    (*parr).pbase = (int *)malloc(sizeof(int) * length);
    if (NULL == parr->pbase)
    {
        printf("ERROR");
        exit(-1);
    } else {
        parr->len = length;
        parr->cnt = 0;
    }
    return;
}

bool is_empty(struct Arr *parr)
{
    if (0 == parr->cnt)
        return true;
    else
        return false;
}

void  show(struct Arr *parr)
{
    if (is_empty(parr))
    {
        printf("is Empty");
    } else {
        for (int i = 0; i < parr->cnt; ++i)
        {
            printf("%d ", parr->pbase[i]);
        }
        printf("\n");
    }
}

bool is_full(struct Arr *parr)
{
    if (parr->cnt == parr->len)
        return true;
    else
        return false;
}

bool append(struct Arr *parr, int val)
{
    if (is_full(parr))
        return false;
    else
        parr->pbase[parr->cnt] = val;
    parr->cnt++;
    return true;
}

bool insert(struct Arr *parr, int pos, int val)
{
    int i;
    if (is_full(parr))
        return false;

    if (pos < 1 || pos > parr->cnt + 1)
        return false;

    for (i = parr->cnt - 1; i >= pos - 1; --i)
    {
        parr->pbase[i+1] = parr->pbase[i];
    }
    parr->pbase[pos - 1] = val;
    parr->cnt++;
    return true;
}

bool delete(struct Arr *parr, int pos, int *pval)
{
    if (is_empty(parr))
        return false;

    if (pos < 1 || pos > parr->cnt)
        return false;

    *pval = parr->pbase[pos - 1];

    int i;
    for (i = pos; i < parr->cnt; i++)
    {
        parr->pbase[i -1] = parr->pbase[i];
    }
    parr->cnt--;
    return true;
}


void inversion(struct Arr *parr)
{
    int i = 0;
    int j = parr->cnt -1;
    int t;
    while(i < j)
    {
        t = parr->pbase[i];
        parr->pbase[i] = parr->pbase[j];
        parr->pbase[j] = t;
        ++i;
        --j;
    }
    return;
}

void sort(struct Arr * parr)
{
    int i, j, t;
    for(i = 0; i < parr->cnt; ++i)
    {
        for (j = j+1; j < parr->cnt; ++j)
        {
            if (parr->pbase[i] > parr->pbase[j])
            {
                t = parr->pbase[i];
                parr->pbase[i] = parr->pbase[j];
                parr->pbase[j] = t;
            }
        }
    }
    return;
}
