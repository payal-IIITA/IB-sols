vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> v;
    for(int i=0;i<A.size();i++){
        v.push_back(make_pair(A[i],0));
    }
    for(int i=0;i<B.size();i++){
        v.push_back(make_pair(B[i],1));
    }
    sort(v.begin(),v.end());
    long long maxA=3*A.size(),maxB=3*B.size();
    if(maxA-maxB<0){
        maxA=2*A.size(),maxB=2*B.size();
    }
    vector<int> ans;
    int x=0,y=0;
    long long sumA,sumB;
    int i=v.size()-1;
    while(i){
        if(v[i].second==0){
            x++;
        }
        else{
            y++;
        }
        sumA=3*x+2*(A.size()-x);
        sumB=3*y+2*(B.size()-y);
        if(sumA-sumB>maxA-maxB){
            maxA=sumA;
            maxB=sumB;
        }
        else if(sumA-sumB==maxA-maxB && sumA>maxA){
            maxA=sumA;
            maxB=sumB;
        }
        i--;
    }
    
    ans.push_back(maxA);
    ans.push_back(maxB);
    return ans;
}
