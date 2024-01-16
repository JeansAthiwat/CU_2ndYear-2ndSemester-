#include <bits/stdc++.h>

int main()
{
    // taking inputs
    int n, m, k, w;
    std::cin >> n >> m >> k >> w;
    std::vector<int> p(m);
    std::vector<int> h(m);
    std::vector<int> t(k);
    for (int i = 0; i < m; i++)
        std::cin >> p[i];
    for (int i = 0; i < m; i++)
        std::cin >> h[i];
    for (int i = 0; i < k; i++)
        std::cin >> t[i];

    // summing monster remaining h
    int sum = 0;
    for (int i = 0; i < m; ++i)
        sum += h[i];

    // Print the result
    std::cout << sum << std::endl;

    return 0;
}