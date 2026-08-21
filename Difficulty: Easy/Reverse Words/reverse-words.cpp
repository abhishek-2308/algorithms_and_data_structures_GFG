class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        string str="";
        stack<string> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]>='a' and s[i]<='z'){
                str= str+s[i];
            }
            else{
                if(str.size()>=1){
                st.push(str);
                }
                str="";
                
            }
        }
        if(str.size()>=1)
        st.push(str);
        str="";
        string ans="";
        while(!st.empty()){
            ans= ans+st.top();
            st.pop();
            ans= ans+'.';
            
        }
        ans.pop_back();
        return ans;
    }
};