#include<bits/stdc++.h>
using namespace std;

int check(int d,vector<int> &a)
{
    int l=0;int h=a.size()-1;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(a[m]==d)
        {
            int r=0;
            while(m+1<a.size() && a[m+1]==a[m]+1) {m++;r++;}
            return r;
        }
        if(a[m]<d)
            l=m+1;
        else if(a[m]>d)
            h=m-1;

    }
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(m,vector<int>(3));
    for(int i=0;i<m;i++)
       cin>>v[i][0]>>v[i][1]>>v[i][2];
    
    vector<vector<int>> r;
    cin>>ws;
    for(int i=0;i<n;i++)
    {
        string s;	
        getline (cin,s);
        vector<int> k;
        for(int j=0;j<s.length();j+=2)
            k.push_back(s[j]-48);
        r.push_back(k);
    }

    
/////////////////////////////////////////////////////////////////////

    

	vector<int> d(m+1);
	d[1]=0;
    int I=9999;
	for(int i=2;i<m+1;i++)
	{
		d[i]=I;		
	}
   
	

	int a=1;
	int k=1;
	while(a<m && k==1)
	{
		k=0;
		for(int i=0;i<m;i++)
		{
			if(d[v[i][1]]>d[v[i][0]]+v[i][2]+check(d[v[i][0]],r[v[i][0]]))
			{
				d[v[i][1]]=d[v[i][0]]+v[i][2];
				k=1;
			}

		}

			a++;	
	}

	
	cout<< d[m];
    
    return 0;

}