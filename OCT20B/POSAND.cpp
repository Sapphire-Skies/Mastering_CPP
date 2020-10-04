#include <iostream>
#include <vector>
using namespace std;
vector<long int> T={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int main() {
	long long int t;
	cin>>t;
	long int n;
	while(t--){
	    
	    cin>>n;
	    vector<long int>::iterator it=lower_bound(T.begin(),T.end(),n);
	    if(n==1)cout<<"1\n";
	    else if(n==3)cout<<"2 3 1\n";
        else if(it!=T.end() && *it==n)cout<<"-1\n";
        else if(n==5)cout<<"2 3 1 5 4\n";
	    else
	    {
	        cout<<"2 3 1 5 4 ";
	        long int i=6;
	        while(i<=n){
	            it=lower_bound(T.begin(),T.end(),i);
	            if(it!=T.end() && *it==i){
	                cout<<i+1<<" "<<i<<" ";
	                i+=2;
	            }
	            else {
	                cout<<i<<" ";
	                i++;
	            }
	        }cout<<"\n";
	    }
	}
	return 0;
}
