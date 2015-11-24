#include <iostream>
#include <vector>
using namespace std;


std::vector<std::vector<char> > func(std::vector<char>& abcdefg)
{
    if(abcdefg.size() == 2)
    {
        std::vector<std::vector<char> > a;
        std::vector<char> aaa;
        aaa.push_back(abcdefg[0]);
        std::vector<char> bbb;
        bbb.push_back(abcdefg[1]);
        a.push_back(aaa);
        a.push_back(bbb);
        a.push_back(abcdefg);
        return a;
    }
    else
    {
        char a = abcdefg[abcdefg.size() - 1];
        //cout << "xxx "<<a << endl;
        abcdefg.pop_back();
        std::vector<std::vector<char> > result = func(abcdefg);
        std::vector<std::vector<char> > rr;
        std::vector<char> A;
        A.push_back(a);
        rr.push_back(A);
        for(auto i : result)
        {
            //rr.push_back(i);
            std::vector<char> j = i;
            j.push_back(a);
            rr.push_back(j);
        }

        for(auto ii : rr)
        {
            result.push_back(ii);
        }
        return result;
    }
}


int main()
{
    std::vector<char> abcefg = {'a', 'b', 'c', 'd', 'e', 'f' ,'g'}; //
    std::vector<std::vector<char> > r = func(abcefg);
    cout << "sum " << r.size() << endl;
    for(auto i: r)
    {
        cout << endl;
        for(auto ii: i)
        {
            cout << ii << " ";
        }
    }
    cout << endl;
    return 0;
}
