#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
using namespace std;

ifstream fin("text.txt");
struct Compare
{
    bool operator()(const std::pair<std::string,int>& a, const std::pair<std::string,int>& b) const
    {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};
int main()
{
    std::string a;
    std::map<std::string,int> m;
    std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string,int>> , Compare> p;
    getline(fin,a);
    cout<<a<<'\n';
    int i=0,j=0;
    for(i;i<a.size();i++)
    {
        if(a[i] == ' ' || a[i] == ',' || a[i] == '?' || a[i] == '!' || a[i] == '.')
        {
            std::string b = a.substr(j,i-j);
            if(!b.empty())
            {
                for(int q = 0;q<b.size();q++)
                if(b[q] >= 'A' && b[q] <='Z')
                    b[q] = b[q] + 32;
                m[b] ++;
            }
            while(i < a.size() && (a[i] == ' ' || a[i] == ',' || a[i] == '?' || a[i] == '!' || a[i] == '.'))
                i++;
            j=i;
            i--;
        }
    }
    if(!a.empty() && !(a[a.size() - 1] == ' ' || a[a.size() - 1] == ',' || a[a.size() - 1] == '?' || a[a.size() - 1] == '!' || a[a.size() - 1] == '.'))
    {
        std::string b = a.substr(j,a.size()-j);
            for(int q = 0;q<b.size();q++)
                if(b[q] >= 'A' && b[q] <='Z')
                    b[q] = b[q] + 32;
        m[b] ++;
    }
    for(auto it : m)
        {
            std::pair<std::string,int> q = make_pair(it.first,it.second);
            p.push(q);
        }
    while(!p.empty())
    {
        cout<<p.top().first<<' '<<p.top().second<<'\n';
        p.pop();
    }

}
