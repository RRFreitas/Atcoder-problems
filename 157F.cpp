#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long double ld;
ld eps = 1e-6;

struct point{
    ld x,y,c;
    point(ld x=0, ld y=0) : x(x), y(y){}
    point operator - () const{ return point(-x, -y);}
    point& operator += (const point& o){ x += o.x; y += o.y; return *this;}
    point operator + (const point& o) const{ return point(x, y) += o;}
    point& operator -= (const point& o){ x -= o.x; y -= o.y; return *this;}
    point operator - (const point& o) const{ return point(x, y) -= o;}
    point& operator /= (const ld k){ x /= k; y /= k; return *this;}
    point operator / (const ld k){ return point(x, y) /= k;}
    point r90cw(){ return point(y, -x);}
    point r90ccw(){ return point(-y, x);}
    ld dist(point o){ return sqrt((o.x - x)*(o.x - x) + (o.y - y)*(o.y - y));}
};

point operator * (const ld k, const point& p){ return point(p.x*k, p.y*k);}
point operator * (const point& p, const ld k){ return point(p.x*k, p.y*k);}

struct circle{
    point center; ld r;
    circle (point c = point(0, 0), ld rr = 0) : center(c), r(rr) {}
    bool intersect(circle o){
        return center.dist(o.center) <= r + o.r && center.dist(o.center) >= fabs(r - o.r);
    }
    vector<point> intersection(circle o){
        vector<point> ans;
        ld d = center.dist(o.center), R = o.r;
        if (d > r + R || d < fabs(r - R)) return ans;
        ld x = (d*d - R*R + r*r)/(2*d*r);
        ld y = r*sqrt(1 - x*x);
        point middle = center + (o.center - center)*( (r*x) / d);
        point vdif = (o.center - center).r90cw()*(y / d);
        ans.push_back(middle + vdif); ans.push_back(middle - vdif);
        return ans;
    }
};

int n,k;
int const N = 61;
point pts[N];

bool check(ld T){
    circle a[N];
    for (int i=0; i<n; i++){
        a[i] = circle(pts[i], T / pts[i].c);
    }

    vector<point> temp;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j == i) temp.push_back(a[i].center);
            else{
                vector<point> inter = a[i].intersection(a[j]);
                for (int k=0; k<inter.size(); k++) temp.push_back(inter[k]);
            }
        }
    }
    for (int p=0; p<temp.size(); p++){
        int cont = 0;
        for (int i=0; i<n; i++){
            if (a[i].center.dist(temp[p]) <= a[i].r + 1e-7) cont++;
            if (cont >= k) return true;
        }
    }
    return false;
}

ld bb(){
    ld l = 0, r = 300000;
    while( (r - l)/r > eps && r - l > eps){
        ld m = (l + r) * 0.5;
        if (check(m)) r = m;
        else l = m;
    }
    return (l + r) * 0.5;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> pts[i].x >> pts[i].y >> pts[i].c;
    }
    if (k == 1) cout << "0.0\n";
    else cout << fixed << setprecision(9) << bb() << endl;
}
