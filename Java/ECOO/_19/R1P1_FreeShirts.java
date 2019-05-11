package _19;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class R1P1_FreeShirts {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int count3=0;count3<10;count3++){
            String[] first=br.readLine().split(" ");
            int n=Integer.parseInt(first[0]);
            int m=Integer.parseInt(first[1]);
            int d= Integer.parseInt(first[2]);
            int shirts[] =new int[d];
            String[] second=br.readLine().split(" ");
            for(int count=0;count<m;count++){
                shirts[Integer.parseInt(second[count])-1]++;
            }
            int laundry=0;
            int clean=n;
            for(int count=0;count<d;count++){
                if(clean==0){
//            System.out.println(count);
                    clean=n;
                    laundry++;
                }
                clean--;

                n+=shirts[count];
                clean+=shirts[count];
            }
            System.out.println(laundry);
        }

    }
}