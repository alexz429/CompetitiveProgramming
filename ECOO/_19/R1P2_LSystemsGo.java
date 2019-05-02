package _19;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

public class R1P2_LSystemsGo {
//
//    private static String iter(String s, HashMap<Character, String> axioms){
//        String out = "";
//        for(int i = 0 ; i < s.length() ; i++){
//            if(axioms.containsKey(s.charAt(i))){
//                out+=(axioms.get(s.charAt(i)));
//            }else{
//                out+=(s.charAt(i));
//            }
//        }
//        return out;
//    }
//
//    public static String replace (String s ,  HashMap<Character, String> axioms){
//        String out="";
//
//        for(int i = 0; i < axioms)
//    }
//
//    public static void main(String[] args) throws IOException {
//        HashMap<Character,String> map = new HashMap<>();
//        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\james.ross\\Desktop\\DATA21.txt"));
//        for(int i = 0; i < 10; i++) {
//            String[] input = br.readLine().split(" ");
//            int r = Integer.parseInt(input[0]);
//            int t = Integer.parseInt(input[1]);
//            String initial = input[2];
//            for(int j = 0; j < r; j++) {
//                String s = br.readLine();
//                String[] ln = s.split(" ");
//                Character c = ln[0].charAt(0);
//                String x = ln[1];
//                map.put(c, x);
//            }
//            String newStr = initial;
//            for(int j = 0; j < t; j++) {
//                newStr = iter(newStr, map);
//            }
//            System.out.println(newStr.charAt(0) +""+ newStr.charAt(newStr.length() - 1) + " " + newStr.length());
//        }
//
//    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int something=0;something<10;something++){
            HashMap<String, Long> tally=new HashMap<>();
            String[] first=br.readLine().split(" ");
            int max=Integer.parseInt(first[0]);
            int times=Integer.parseInt(first[1]);
            String left="";
            String right="";
            HashSet<String> exist=new HashSet<>();
            for(int count=0;count<first[2].length();count++){
                String next=first[2].charAt(count)+"";
                if(tally.containsKey(next)){
                    tally.put(next, tally.get(next)+1);
                }
                else{
                    tally.put(next,(long)1);
                }
            }
            left=first[2].charAt(0)+"";
            right=first[2].charAt(first[2].length()-1)+"";
            HashMap<String, String> command=new HashMap<>();
            for(int count=0;count<max;count++){
                String[] next=br.readLine().split(" ");
                command.put(next[0], next[1]);
                exist.add(next[0]);
                if(!tally.containsKey(next[0])){
                    tally.put(next[0], (long)0);
                }
            }
            for(int count=0;count<times;count++){
                HashMap<String, Long> prep=new HashMap<>();
                for(String next:command.keySet()){
                    String nextCom=command.get(next);
                    for(int count2=0;count2<nextCom.length();count2++){
                        String lol=nextCom.charAt(count2)+"";
                        if(prep.containsKey(lol)){
                            prep.put(lol, prep.get(lol)+tally.get(next));
                        }
                        else{
                            prep.put(lol, tally.get(next));
                        }
                    }
                }
                for(String addIn:exist){
                    tally.put(addIn,(long)0);
                }
                for(String addIn:prep.keySet()){
                    tally.put(addIn, prep.get(addIn));
                }
                left=command.get(left).charAt(0)+"";
//                System.out.println(left);
                String rightCom=command.get(right);
                right=rightCom.charAt(rightCom.length()-1)+"";
            }
            long total=0;
            for(long next:tally.values()){
                total+=next;
            }
            System.out.println(left+right+" "+(total));
        }

    }
}