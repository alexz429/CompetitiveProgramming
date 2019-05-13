package CCC._05;
import java.util.*;
public class J5_Bananas {
	static int Sswitch=0;
	static int A(int location, String next){
		if(location==next.length()){
			return 1;
		}
		
			//System.out.println("engaged");
			while(next.charAt(location)=='S'){
				
				
				Sswitch--;
				if(Sswitch<0){
					return 0;
				}
				location++;
				if(location==next.length()){
					return 1;
				}
				
			}
			
			
			
		
		if(next.charAt(location)!='N'){
			return 0;
		}
		else{
			location++;
			if(location==next.length()){
				return 0;
			}
			int out=0;
			if(next.charAt(location)=='A'){
				out=A(location+1,next);
			}
			else{
				if(next.charAt(location)=='B'){
					Sswitch++;
					out=B(location+1,next);
				}
				else{
					
				}
			}
			return out;
		}
	}
	static int B(int location, String next){
		
		int out=0;
		if(next.charAt(location)=='A'){
			out=A(location+1,next);
		}
		else{
			if(next.charAt(location)=='B'){
				Sswitch++;
				out=B(location+1,next);
				
			}
			else{
				
			}
		}
		return out;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		String next=sc.next();
		while(!next.equals("X")){
			
			int out=0;
			if(next.charAt(0)=='A'){
				out=A(1, next);
			}
			else{
				if(next.charAt(0)=='B'){
					Sswitch++;
					out=B(1, next);
				}
				else{
					
				}
			}
			if(Sswitch!=0){
				out=0;
				Sswitch=0;
			}
			if(out==0){
				System.out.println("NO");
			}
			else{
				System.out.println("YES");
			}
			next=sc.next();
		}
		sc.close();
	}

}
