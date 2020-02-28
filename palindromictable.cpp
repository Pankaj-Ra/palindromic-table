#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n ,m;
typedef vector<int> inner_vec;
typedef vector<inner_vec> outer_vec;
bool canFormPalindrome(outer_vec &a, int k, int l)
{    
        for(int r = 0; r < n-k; r++){
            for(int c = 0; c < m-l; c++){
                int count[10] = {0};
                for (int i = r; i <= k+r;  i++){
                    for(int j = c; j <= l+c; j++){
                        count[a[i][j]]++;
                    }
                }
                int odd = 0;
                int  nonzero = 0;
                for (int i = 0; i < 10; i++){
                    if (count[i] & 1)
                        odd++;
                    if(i && count[i])
                        nonzero += count[i];
                }
                int result = ((odd <= 1)&&nonzero>1)
                    ?1:0;
                if(result){
                    cout << (k+1)*(l+1)<<endl;
                    cout << r << " "<< c<< " "<< k+r<< " "<< l+c<<endl;                    
                    return result;
                }                
            }
        }
    return 0;
}

int matrix(outer_vec &a, outer_vec &v,
           vector<vector<int> > &area){
    int out = 0;    
    for(int i = n*m-1; i > 0; i--){
        if(area[i].size()){
            for(int j = 0;j < area[i].size();j+=2){
                if(v[area[i][j]][area[i][1+j]]){                    
                    continue;
                }
                out = canFormPalindrome(a,
                          area[i][j], area[i][1+j]);
                if(out){
                    return 1;
                }
                v[area[i][j]][area[i][1+j]] = 1;
                if(area[i][j]<m && area[i][1+j]<n &&
                   area[i][j]!=area[i][1+j]){
                    out =
     canFormPalindrome(a,area[i][1+j], area[i][j]);
                    if(out){
                        return 1;
                    }
                    v[area[i][1+j]][area[i][j]] = 1;
                }                
            }
        }
    }
    return 0;
}



int main() {

    cin >> n >> m;
    outer_vec a(n,inner_vec(m));
    outer_vec visit(n,inner_vec(m));
    vector<vector<int> > area(n*m);
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            sum += a[i][j];
            area[((i+1)*(j+1))-1].push_back(i);
            area[((i+1)*(j+1))-1].push_back(j);
        }
    }
    if(sum && sum != 1){
        int out = 0;   
        out = matrix(a,visit, area);
        if(out){
            return 0;
        }
    }    
    cout << 1 << endl;
    cout << 0 << " "<< 0 <<" "<< 0<< " "<< 0;
    return 0;
}


