#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MinMaxStack
{
private:
    vector<T> v;
    vector<T> mins;
    vector<T> maxs;

public:
    bool empty()
    {
        return v.size() == 0;
    }

    void push(T data)
    {
        int currentMin = data;
        int currentMax = data;
        if (mins.size())
        {
            currentMin = min(data, mins[mins.size() - 1]);
            currentMax = max(data, maxs[maxs.size() - 1]);
        }
        mins.push_back(currentMin);
        maxs.push_back(currentMax);
        v.push_back(data);
    }
    void pop()
    {
        if (!empty())
        {
            v.pop_back();
            mins.pop_back();
            maxs.pop_back();
        }
    }
    T top()
    {
        //return the last element
        return v[v.size() - 1];
    }
    T getMin()
    {
        return mins[mins.size() - 1];
    }
    T getMax()
    {
        return maxs[maxs.size() - 1];
    }
};

int main()
{
    MinMaxStack<int> s;
    for (int i = 1; i < 5; i++)
    {
        s.push(i * i);
    }
    cout << s.getMin() << endl;
    cout << s.getMax() << endl;
    return 0;
}