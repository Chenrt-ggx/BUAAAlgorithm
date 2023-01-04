#include <cstdio>
#include <cstdlib>

int ans, spl, a[10005], sum[10005];

struct tree
{
    struct tree *ls;
    struct tree *rs;
    int siz, con, data, height;
};

typedef struct tree stu;
typedef struct tree *ptr;

int size(ptr now)
{
    if (now == NULL)
        return 0;
    return now->siz;
}

int h(ptr now)
{
    if (now == NULL)
        return 0;
    return now->height;
}

void pushup(ptr now)
{
    if (now == NULL)
        return;
    now->height = 1;
    now->siz = now->con;
    now->siz += size(now->ls);
    now->siz += size(now->rs);
    if (h(now->ls) > h(now->rs))
        now->height += h(now->ls);
    else
        now->height += h(now->rs);
    return;
}

void left(ptr *now)
{
    ptr tmp = (*now)->rs;
    (*now)->rs = tmp->ls;
    tmp->ls = *now;
    tmp->siz = (*now)->siz;
    pushup(*now), pushup(tmp);
    *now = tmp;
    return;
}

void right(ptr *now)
{
    ptr tmp = (*now)->ls;
    (*now)->ls = tmp->rs;
    tmp->rs = *now;
    tmp->siz = (*now)->siz;
    pushup(*now), pushup(tmp);
    *now = tmp;
    return;
}

void balance(ptr *now)
{
    if (*now == NULL)
        return;
    if (h((*now)->ls) - h((*now)->rs) == 2)
    {
        if (h((*now)->ls->ls) > h((*now)->ls->rs))
            right(now);
        else
            left(&(*now)->ls), right(now);
        return;
    }
    if (h((*now)->rs) - h((*now)->ls) == 2)
    {
        if (h((*now)->rs->rs) > h((*now)->rs->ls))
            left(now);
        else
            right(&(*now)->rs), left(now);
        return;
    }
    return;
}

void ins(ptr *now, int num)
{
    if (*now == NULL)
    {
        *now = (ptr)malloc(sizeof(stu));
        (*now)->siz = (*now)->con = 1;
        (*now)->data = num, (*now)->height = 0;
        (*now)->ls = (*now)->rs = NULL;
        return;
    }
    if ((*now)->data == num)
    {
        (*now)->con++;
        pushup(*now);
        return;
    }
    if ((*now)->data > num)
        ins(&(*now)->ls, num);
    else
        ins(&(*now)->rs, num);
    pushup(*now);
    balance(now);
    return;
}

int rank(ptr now, int num)
{
    if (now == NULL)
        return 0;
    if (now->data == num)
        return size(now->ls);
    if (now->data > num)
        return rank(now->ls, num);
    return size(now->ls) + now->con + rank(now->rs, num);
}

int main()
{
    int n;
    freopen("testcase.txt", "r", stdin);
    scanf("%d %d", &n, &spl);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i), sum[i] = a[i];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];
    ptr root = NULL;
    ins(&root, sum[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        ans += rank(root, sum[i] + spl + 1);
        ins(&root, sum[i]);
    }
    for (int i = 0; i < n; i++)
        ans += sum[i] <= spl;
    printf("%d\n", ans);
    int std;
    scanf("%d", &std);
    printf(ans == std ? "AC\n" : "WA\n");
    return 0;
}