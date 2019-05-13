package ECOO._19;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class R1P3_SideScrollingSimulator {
    public static void main(String[] args)throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        for(int AHAH=0;AHAH<10;AHAH++){
            String[] first=br.readLine().split(" ");
            int J=Integer.parseInt(first[0]);
            int w=Integer.parseInt(first[1]);
            int h=Integer.parseInt(first[2]);
            char[][] grid=new char[h][w];
            for(int count=0;count<h;count++){
                String next=br.readLine();
                for(int count2=0;count2<w;count2++){
                    grid[h-1-count][count2]=next.charAt(count2);
                }
            }
            int index=0;
            boolean survive=true;
            for(;grid[1][index]!='L';index++);
            for(;grid[1][index]!='G';index++){
                if(grid[1][index]=='@'){
                    int lowest=Integer.MAX_VALUE;
                    for(int j=1;j<=J&&j+1<h;j++){
                        if(grid[1+j][index]=='.'){
                            lowest=j;
                            break;
                        }
                    }
                    if(lowest==Integer.MAX_VALUE){
                        survive=false;
                        break;
                    }
//                    System.out.print(" "+lowest);
                    for(int count=1;count<=1+lowest;count++){
                        if(grid[count][index-1]=='@'||grid[count][index+1]=='@'){
                            survive=false;
                            break;
                        }
                    }
                    if(!survive){
                        break;
                    }

                }

            }
            if(!survive){
                System.out.println(index+1);
            }
            else{
                System.out.println("CLEAR");
            }
        }


    }
}
