// Test 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<map>
#include<vector>
#include<string>
#include<utility>
struct cmp
{
    bool operator()(std::pair<std::string, int> a, std::pair<std::string, int> b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};
bool verif(char c, std::string x)
{
    for (auto i : x)
        if (c == i)
            return true;
    return false;
}

int main()
{

    std::string s="am ama fost dost fost la la mare mare mare ama ama jer jer.";
   // std::cin >> s;
    std::vector<std::string> v;
    std::string sep = " !.,";
    std::transform(s.begin(), s.end(), s.begin(), tolower); //oke l

    std::map<std::string, int>m;
    std::priority_queue<int>q;

    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        if (verif(c, sep))
        {
            std::string sub = s.substr(n, i - n); /// Problem?
            n = i + 1;
            if (sub.length() > 0)
                v.push_back(sub);
        }
    }
    //Hai sa punem in map si sa am fiecare cuv in parte
    std::vector<std::string> w;
    for (auto i : v)
    {
        if (m[i] == 0)
            w.push_back(i);//unicitatea cuv ;
        m[i]++;//nr de aparitii in map
    }
    //As vrea ca  fiecare el sa aiba asociat nr de aparitii.
    std::vector<std::pair<std::string, int> > p;
    for (auto i : w)
        p.push_back(std::make_pair(i, m[i]));
    //Acum sortez cu priority que;
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, cmp> Q;
    for (auto i : p)
        Q.push(i);
    //Afisez in ordine
    while (!Q.empty())
    {
        std::cout << Q.top().first << ' ' << " = >" << ' ' << Q.top().second << '\n';
        Q.pop();
    }

}
