#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define inf 1'000'000'000

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    //这里如果改成 while(l + 1 != r) 以及 l = mid,会有样例无法通过
    ll l = 0, r = (ll)inf * n, ret = 0;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        ll cnt = 0;

        for (const auto &x : arr)
        {
            cnt += min((ll)x, mid);
        }

        if (cnt / k >= mid)
        {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ret << '\n';

    return 0;
}
