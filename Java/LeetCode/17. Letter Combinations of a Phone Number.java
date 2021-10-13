class Solution {
    public static List<String> out;
    public void recurse(int i, String s, String build){
        if(i == s.length()){
            out.add(build);
            return;
        }
        switch(s.charAt(i)){
            case '2':
                recurse(i+1, s, build+"a");
                recurse(i+1, s, build+"b");
                recurse(i+1, s, build+"c");
                break;
            case '3':
                recurse(i+1, s, build+"d");
                recurse(i+1, s, build+"e");
                recurse(i+1, s, build+"f");
                break;
            case '4':
                recurse(i+1, s, build+"g");
                recurse(i+1, s, build+"h");
                recurse(i+1, s, build+"i");
                break;
            case '5':
                recurse(i+1, s, build+"j");
                recurse(i+1, s, build+"k");
                recurse(i+1, s, build+"l");
                break;
            case '6':
                recurse(i+1, s, build+"m");
                recurse(i+1, s, build+"n");
                recurse(i+1, s, build+"o");
                break;
            case '7':
                recurse(i+1, s, build+"p");
                recurse(i+1, s, build+"q");
                recurse(i+1, s, build+"r");
                recurse(i+1, s, build+"s");
                break;
            case '8':
                recurse(i+1, s, build+"t");
                recurse(i+1, s, build+"u");
                recurse(i+1, s, build+"v");
                break;
            case '9':
                recurse(i+1, s, build+"w");
                recurse(i+1, s, build+"x");
                recurse(i+1, s, build+"y");
                recurse(i+1, s, build+"z");
                break;
                
        }
    }
    public List<String> letterCombinations(String digits) {
        out = new ArrayList<>();
        if(digits.length()==0) return out;
        recurse(0, digits, "");
        return out;
    }
}