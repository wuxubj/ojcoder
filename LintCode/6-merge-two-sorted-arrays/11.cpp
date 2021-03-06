class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int mx_sz = A.size()>=B.size()?A.size():B.size();
        int mi_sz = A.size()<B.size()?A.size():B.size();
        vector<int> &MX = A.size()>=B.size()?A:B;
        vector<int> &MI = A.size()<B.size()?A:B;
        vector<int> res(mx_sz + mi_sz);
        int i = mx_sz-1, j = mi_sz -1, k = mx_sz + mi_sz - 1;
        copy(MX.begin(), MX.end(), res.begin());
        while(i>=0 && j>=0){
            if(res[i]>MI[j]){
                res[k] = res[i];
                i--;
                k--;
            }else{
                res[k] = MI[j];
                j--;
                k--;
            }
        }
        
        while(j>=0){
            res[k] = MI[j];
            j--;
            k--;
        }
        
        return res;
    }
};
