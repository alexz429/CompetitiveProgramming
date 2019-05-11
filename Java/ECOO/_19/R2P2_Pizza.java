package _19;



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class R2P2_Pizza {
	static class pair{
		int x;
		int y;
		public pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		public String toString() {
			return x+" "+y;
		}
		public double dis() {
			double x=this.x;
			double y=this.y;
			return Math.sqrt(Math.pow(x, 2)+ Math.pow(y, 2));
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
//		BufferedReader br=new BufferedReader(new FileReader("C:\\Users\\alex.zhang\\Desktop\\DATA21.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<10;i++) {
			int max=Integer.parseInt(br.readLine());
			
			pair[] vertices=new pair[max];
			for(int count=0;count<max;count++) {
				String[] next=br.readLine().split(" ");
				int x=Integer.parseInt(next[0]);
				int y=Integer.parseInt(next[1]);
				vertices[count]=new pair(x,y);
			}
			if(max%2==1) {
				System.out.println(0);
				continue;
			}
			int tally=0;
			for(int count=0;count<max/2;count++) {
				
				pair a=vertices[count];
				pair b=vertices[(count+(max/2))%max];
//				System.out.println(a+" "+b+" TEST");
				boolean check=true;
				for(int count2=1;count2<(max/2);count2++) {
					pair compa=vertices[(count2+count+max)%max];
					pair compb=vertices[(-count2+count+max)%max];
//					System.out.println("NEXT PAIR: "+compa+" "+compb);
					pair aa=new pair(Math.abs(compa.x-a.x),Math.abs(compa.y-a.y));
					pair ab=new pair(Math.abs(compb.x-a.x), Math.abs(compb.y-a.y));
					if(aa.dis()!=ab.dis()) {
//						System.out.println("ERROR "+aa+" "+ab);
						check=false;
						break;
					}

					pair ba=new pair(Math.abs(compa.x-b.x),Math.abs(compa.y-b.y));
					pair bb=new pair(Math.abs(compb.x-b.x), Math.abs(compb.y-b.y));
					if(ba.dis()!=bb.dis()) {

//						System.out.println("ERROR "+ba+" "+bb);
						check=false;
						break;
					}
					
				}
				if(check) {
					tally++;
//					System.out.println(a+" "+b);
				}
			}
			System.out.println(tally);

		}
			}

}
