class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int a[26];
        memset(a, 0, sizeof(int)*26);
        for(char c : A){
            a[c-'A']++;
        }
        
        for(char c : B){
            a[c-'A']--;
            if(a[c-'A']<0){
                return false;
            }
        }
        return true;
    }
};
