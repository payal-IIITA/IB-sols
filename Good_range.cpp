int mod=1000000007;
vector<int> Solution::solve(int A, vector<int> &B) {
    map<int,pair<int,int>> s;
    vector<int> ans;
    int n=A;
    s.insert(make_pair(0,make_pair(-1,-1)));
    s.insert(make_pair(n+1,make_pair(-1,-1)));
    int t=0;
    long long count=0;
    while(t<B.size()){
        int a=B[t];
        if(s.find(a)==s.end())
            s.insert(make_pair(a,make_pair(-1,-1)));
        else{
            t++;
            ans.push_back(count);
            continue;
        }
        auto it=s.find(a);
        auto it1=it;
        auto itf=++it1;
        it1=it;
        auto itb=--it1;
        if(itb->first==0 && itf->first==n+1){
            count=(1+n)%mod;
            it->second.first=1;
            it->second.second=n;
        }
        else if(itb->first==0){
            count=(count%mod-itf->second.first%mod)%mod;
            itf->second.first=a+1;
            count=((count)%mod+(a+1)%mod)%mod;
            it->second.second=itf->first-1;
            count=(count%mod+((itf->first)-1)%mod)%mod;
            it->second.first=1;
            count=count%mod+(it->second.first)%mod;
        }
        else if(itf->first==n+1){
            count=(count%mod-itb->second.second)%mod;
            itb->second.second=a-1;
            count=(count%mod+(a-1)%mod)%mod;
            it->second.first=itb->first+1;
            count=(count%mod+(itb->first+1)%mod)%mod;
            it->second.second=n;
            count=(count%mod+it->second.second%mod)%mod;
        }
        else{
            count=(count%mod-itb->second.second)%mod;
            count=(count%mod-itf->second.first)%mod;
            it->second.second=itf->first-1;
            count=(count%mod+it->second.second)%mod;
            it->second.first=itb->first+1;
            count=(count%mod+it->second.first%mod)%mod;
            itb->second.second=a-1;
            count=(count%mod+itb->second.second%mod)%mod;
            itf->second.first=a+1;
            count=(count%mod+itf->second.first%mod)%mod;
        }
        ans.push_back(count%mod);
        t++;
    }
    return ans;
}
