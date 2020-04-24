/*
 ugly numbers are the numbers only multiple of 2,3,5
 it mean 
 2,4,8,16,32.... only have multiple 2
 3,9,27,81...... only have multiple 3
 5,25,125,625 ..... only have multiple 5
 now for every 2 multiple we can also multiply with 3 or 5,
 now for every 3 multiple we can also multiply with 2 or 5,
 and so on ...
 //problem of DP

*/


class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0]=1;
        int it2=0,it3=0,it5=0;
        int multiple_2 = ugly[it2]*2;
        int multiple_3 = ugly[it3]*3;
        int multiple_5 = ugly[it5]*5;
    
        for(int i=1; i<n; i++){
            int next_ugly = min(multiple_2,min(multiple_3,multiple_5));
            ugly[i]=next_ugly;
            if(next_ugly == multiple_2){
                it2++; 
                multiple_2=ugly[it2]*2;
            }
            if (next_ugly == multiple_3){
                it3++;
                multiple_3=ugly[it3]*3;
            }
            if (next_ugly == multiple_5){
                it5++;
                multiple_5=ugly[it5]*5;
            } 
        }
        //for(int i=0; i<n; i++) cout << ugly[i] <<" "; 
        return ugly[n-1]; 
    }
};
