#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, height, width;
    cin >> t;
    while (t--)
    {
        cin >> width >> height;
        cin >> n;
        if (n == 0)
        {
            cout << width * height << endl;
            break;
        }
        int w[40010], h[40010];
        for (int i = 0; i < n; i++)
        {
            cin >> w[i] >> h[i];
        }
        //sort
        sort(w, w + n);
        sort(h, h + n);
        int max_width = w[0] - 1;
        int max_height = h[0] - 1;
        for (int i = 1; i < n; i++)
        {
            max_height = max(max_height, h[i] - h[i - 1] - 1);
            max_width = max(max_width, w[i] - w[i - 1] - 1);
        }
        //corner case of the grid end
        max_height = max(max_height, height - h[n - 1]);
        max_width = max(max_width, width - w[n - 1]);
        cout << max_height * max_width << endl;
    }
    return 0;
}