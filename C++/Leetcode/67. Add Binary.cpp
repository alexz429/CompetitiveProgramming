class Solution {
public:
    string addBinary(string a, string b) {
        string build = "";
        if(a.length() < b.length()){
            swap(a,b);
        }
        char carry = '0';
        for(int i = a.length() - 1, i2 = b.length() - 1;i>=0||i2>=0;i--,i2--){
            if(i>=0&&i2>=0){
            if(a[i]=='1'&&b[i2]=='1'){
                build = carry + build;
                carry = '1';
            }
            else if(a[i]=='0'&&b[i2]=='0'){
                build = carry + build;
                carry = '0';
            }
            else if(carry == '0'){
                build = '1' + build;
            }
            else{
                build = '0' + build;
            }
                
            }
            else{
                if((a[i] == '1' && carry == '1') || (a[i] == '0' && carry == '0')){
                    build = '0' + build;
                }
                else{
                    build = '1' + build;
                    carry = '0';
                }
            }
        }
        if(carry == '1') build = '1' + build;
        return build;
    }
};