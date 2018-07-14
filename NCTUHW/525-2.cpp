#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int lgN = __lg(MAXN) + 5;
typedef long long LL;
struct SegmentTree {
    struct Node {
        LL L, R; 
        Node *l, *r;
        LL maxV; vector<LL> pos;
        Node(LL _L = 0, LL _R = 0) {
            L = _L, R = _R;
            l = r = NULL;
            pos.clear(); maxV = -1;
        }
    }*rt, *ptr, buf[lgN << 1];
    LL *arr; LL n;
    SegmentTree (LL *_arr, LL _n) {
        arr = _arr, n = _n;
        rt = build(0, n);
    }
    ~SegmentTree() {
        clear(rt);
    }
    void clear(Node *u) {
        if (!u) return ;
        clear(u->l); clear(u->r);
        delete u;
    }
    Node* build(LL L, LL R) {
        Node *u = new Node(L, R);
        if (R - L == 1) {
            u->pos.push_back(L);
            u->maxV = arr[L];
            return u;
        }
        LL M = (R + L) >> 1;
        u->l = build(L, M);
        u->r = build(M, R);
        return pull(u);
    }
    Node* pull(Node *u) {
        return pull(u, u->l, u->r);
    }
    Node* pull(Node *u, Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        if (l->maxV == r->maxV) {
            u->maxV = l->maxV; u->pos.clear();
            for (auto num : l->pos) u->pos.push_back(num);
            for (auto num : r->pos) u->pos.push_back(num);
        } else if (r->maxV < l->maxV) {
            u->maxV = l->maxV; u->pos.clear();
            for (auto num : l->pos) u->pos.push_back(num);
        } else {
            u->maxV = r->maxV; u->pos.clear();
            for (auto num : r->pos) u->pos.push_back(num);
        }
        return u;
    }
    Node* query(LL qL, LL qR) {
        ptr = buf;
        return query(qL, qR, rt);
    }
    Node* query(LL qL, LL qR, Node *u) {
        if (u->R <= qL || qR <= u->L) return (Node*)NULL;
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(LL mPos) {
        return modify(mPos, rt);
    }
    void modify(LL mPos, Node *u) {
        if (u->R <= mPos || mPos + 1 <= u->L) return ;
        if (mPos <= u->L && u->R <= mPos + 1) {
            u->maxV = 0; u->pos.clear();
            return ;
        }
        modify(mPos, u->l);
        modify(mPos, u->r);
        pull(u);
        return ;
    }
    LL solve(LL l, LL r) {
        if (l == r) return 0;
        Node *res = query(l, r);
        LL ans = res->maxV * res->pos.size();
        for (auto num : res->pos) modify(num);
        return ans;
    }
};
int main() { ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<pair<LL, LL> > data;
        for (int i = 0 ; i < n ; i++) {
            LL pos, size; cin >> pos >> size;
            data.push_back(make_pair(pos, size));
        }
        sort(data.begin(), data.end());
        LL pos[MAXN], val[MAXN];
        for (int i = 0 ; i < n ; i++) 
            pos[i] = data[i].first, val[i] = data[i].second;
        SegmentTree *sol = new SegmentTree(val, n);
        LL ans = 0;
        while (m--) {
            LL l, r; cin >> l >> r; //l ^= ans, r ^= ans;
            ans = sol->solve(lower_bound(pos, pos + n, l) - pos, upper_bound(pos, pos + n, r) - pos);
            cout << ans << '\n';
        }
        delete sol;
    }
}
