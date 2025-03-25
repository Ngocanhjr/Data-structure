

int max_current = 1;

bool Union()
{
    //....
    max_current = max({max_current, sz[u], sz[v]});
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    init();

    int cnt = n;
    for (int i = 0; i < m; i++)
    {
        int x, int y;
        cin >> x >> y;
        if (Union(x, y)) --cnt;
        cout << cnt << ' ' << max_current << endl;
    }
}

/*
5 3
1 2
1 3
4 5
*/