

void push_down(int p, int s, int t){
    if(lazy[p]) {
        int m = (s + t) >> 1, 
            v = lazy[p];

        lazy[p << 1] += v;
        stree_value[p << 1] += v * (m - s + 1);
        lazy[(p << 1)|1] += v;
        stree_value[p << 1|1] += v * (t - m);
        lazy[p] = 0;
    }
}

void push_up(int p) {
    stree_value[p] = stree_value[p << 1] + stree_value[p << 1|1];
}

void build(int s, int t, int p) {
    if(s == t) { 
        //cout << "s t k " << s << ' ' << t << ' ' << k << endl; 
        stree_value[p] = stree_init[k++]; return; 
    }

    int m = (s + t) >> 1;
    build(s, m, p << 1);
    build(m+1, t, (p << 1) + 1);
    push_up(p);
}

int query(int l, int r, int s, int t, int p){
    if(l <= s && r >= t) return b[p];

    int m = (s + t) >> 1;
    //push_down(p, s, t);
    int ansL = l <= m ? query(l, r, s, m, p << 1): 0;
    int ansR = r > m ? query(l, r, m+1, t, (p << 1) + 1): 0;
    return ansL + ansR;
}

void update(int l, int r, int c, int s, int t, int p) {
    int m = (s + t) >> 1;
    
    if(l <= s && r >= t) {
        b[p] += c; lazy[p] += c; 
        return; 
    }
    
    push_down(p, s, t);
    if(l <= m) update(l, r, c, s, m, p << 1);
    if(r > m) update(l, r, c, m+1, t, p << 1|1);
    push_up(p);
}