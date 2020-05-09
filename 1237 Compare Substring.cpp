#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)

vector<ll> failure_table(string ptn, ll m)
{
    ll i,k=0;
    vector<ll>prefix(m,0);
    f(i,2,m)
    {
        while(k>0 && ptn[i]!=ptn[k+1])
            k = prefix[k];
        if(ptn[i]==ptn[k+1])
            k++;
        prefix[i] = k;
    }
    return prefix;
}

ll compare(string str, string ptn)
{
    ll i,j,p,mx=LONG_MIN;
    ll len1 = str.length(), len2 = ptn.length();
    f(i,1,len2)
    {
        string temp = "0";
        f(j,i,len2)
        temp += ptn[j];
        vector<ll> prefix = failure_table(temp,temp.length());
        ll k=0;
        f(p,1,len1)
        {
            while(k>0 & str[p]!=temp[k+1])
                k = prefix[k];
            if(str[p]==temp[k+1])
                k++;
            mx = max(mx,k);
            if(k==temp.length()-1)
                k = 0;
        }
    }
    return mx;
}



int main()
{
    string a,b,temp;
    while( getline(cin,a))
    {
        getline(cin,b);
        a.insert(0,"0");
        b.insert(0,"0");
        if(a.length()<b.length())
        {
            temp = a;
            a = b;
            b = temp;
        }
        cout<<compare(a,b)<<endl;
    }
}
