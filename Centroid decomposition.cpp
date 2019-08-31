const int N = 1e5 + 1;
vector<int> t[N]; //init me
vector<int> T[N]; //centroid decomposition
int siz[N];
bitset<N> added;

int calcSize(int cur, int p) {
    siz[cur] = 1;
    for (int i : t[cur])
        if (!added.test(cur) && i != p)
            siz[cur] += calcSize(i, cur);
    return siz[cur];
}

void make_centroid(int cur = 1, int p = -1) {
    int lim = calcSize(cur, -1) / 2;
    int pr = -1;
    for (bool again = 1; again; ) {
        again = 0;
        for (int i : t[cur]) {
            if (!added.test(i) && i != pr && siz[i] > lim) {
                pr = cur;
                cur = i;
                again = 1;
                break;
            }
        }
    }

	T[cur].pb(cur);
    if (p != -1)
        for (int i : T[p])
            T[cur].pb(i);
    added.set(cur);
    for (int i : t[cur])
        if (!added.test(i))
            make_centroid(i, cur);
}