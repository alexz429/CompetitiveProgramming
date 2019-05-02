package _01;
import java.util.Arrays;
import java.util.Scanner;
public class S2_Spirals {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int from=sc.nextInt();
		int to=sc.nextInt();
		int num=to-from;
		//System.out.println(num);
		
		int count=0;
		for(count=1;num>0;count++){
			num-=count*2;
		}
	int[][] out=new int[count][count];
		
		num=to-from;
		
		for(int i=0;i<count;i++){
		Arrays.fill(out[i], -1);	
		}
		
		int start;
		if(count%2!=0){
			start=count/2;
		}
		else{
			start=count/2-1;
		}
		out[start][start]=from;
		int dir=0;
		int x=start;
		int y=start;
		int length=1;
		int lol=0;
		int lul=0;
		for(count=1;count<num+1;count++){
			if(dir%4==0){
				x++;
			}
			else{
				if(dir%4==1){
					y++;
				}
				else{
					if(dir%4==2){
						x--;
					}
					else{
						y--;
					}
				}
			}
			out[x][y]=from+count;
			//System.out.println(from+count);
			lol++;
			if(lol==length){
				lul++;
				if(lul==2){
					length++;
					lul=0;
				}
				lol=0;
				dir++;
			}
			
		}
		int no=0;
		for( count=0;count<out.length;count++){
			if(out[count][0]!=-1){
				no=1;
				break;
			}
		}
		int add=0;
		if(no==0){
			add=1;
		}
		for(count=0;count<out.length;count++){
			for(int count2=0+add;count2<out.length;count2++){
				System.out.print(" ");
				if(out[count][count2]!=-1){
					System.out.print(out[count][count2]);
					if(out[count][count2]<10){
						System.out.print(" ");
					}
				}
				else{
					
					System.out.print("  ");
					
					
				}
				
			}
			System.out.println();
		}
		sc.close();
	}

}
