    #include <bits/stdc++.h>
    using namespace std;
    double W;
    int N;

    struct Item
    {
        double value, weight, vpw;

        Item(double v, double w) : value(v), weight(w), vpw(v / w)
        {
        }

        bool operator<(const Item &other)
        {
            return this->vpw > other.vpw;
        }
    };

    int main()
    {
        cin >> W;
        cin >> N;

        vector<Item> items;

        vector<double> tmpV(N);

        for (int i = 0; i < N; i++)
            cin >> tmpV[i];

        for (int i = 0; i < N; i++)
        {
            double w;
            cin >> w;
            items.push_back(Item(tmpV[i], w));
        }

        // sort by max value per weight
        sort(items.begin(), items.end());

        // gready choosing
        // chose the most worthy items until cant chosse
        double currWeight = 0;
        double currValue = 0;

        for (Item &item : items)
        {
            if (item.weight + currWeight <= W)
            {
                currWeight += item.weight;
                currValue += item.value;
            }
            else
            {
                double weightLeft = W - currWeight;
                currWeight += weightLeft;
                currValue += item.vpw * weightLeft;
            }
        }
        // assert(currWeight == W) "yee";
        cout << fixed
            << setprecision(4)
            << currValue;
            
        return 0;
    }