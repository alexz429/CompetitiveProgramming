package CCC._19;
//NOT DONE
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class S5_TriangleDataStructure {
	static class triangle{
		int[][] up;
		int[][] down;
		int[][] prevDown;
		int length=1;
		int height;
		public triangle(int[][] in, int limit) {
			height=in.length;
			up=new int[height][];
			down=new int[height][];
			for(int count=0;count<height;count++) {
				up[count]=new int[in[count].length];
				down[count]=new int[in[count].length];
				for(int count2=0;count2<in[count].length;count2++) {
					up[count][count2]=in[count][count2];
					down[count][count2]=in[count][count2];
				}
			}
			int curSize=2;
			for(int count=Integer.toBinaryString(limit).length()-1;count>0;count--) {
//				System.out.println(count+" "+curSize);
				int[][] next=build(curSize);
				int[][] next2=build2(curSize);
				up=next;
				prevDown=down;
				down=next2;
				curSize<<=1;
				length*=2;
			}
		}
		
		public int[][] build(int size){
			int[][] nextUp=new int[height-size+1][];
			if(size>length*2) {
//				System.out.println("OOF");
				return null;
			}
			for(int count=0;count<=height-size;count++) {
				nextUp[count]=new int[up[count].length];
				for(int count2=0;count2<up[count].length;count2++) {
					nextUp[count][count2]=Math.max(Math.max(up[count][count2], up[count+(size/2)][count2]), Math.max(up[count+(size/2)][count2+(size/2)], down[count+(size/2)-1][count2]));
				}
			}
			return nextUp;
		}
		public int[][] build2(int size){
			int[][] nextDown=new int[height-size+1][];
			
			for(int count=0;count<size-1&&count<(height-size+1);count++) {
				nextDown[count]= new int[1];
				nextDown[count][0]=Integer.MAX_VALUE;
				
			}
			for(int count=size-1;count<=(height-size);count++) {
				nextDown[count]=new int[count+2-size];
				for(int count2=0;count2<(count+2-size);count2++) {
					nextDown[count][count2]=Math.max(Math.max(down[count][count2], down[count][count2+(size/2)]), Math.max(down[count+(size/2)][count2+(size/2)], up[count+(size/2)-1][count2+(size/2)]));
				}
			}
			return nextDown;
		}
		public long sum(int size) {
			long tally=0;
			for(int count=0;count<=height-size;count++) {
				for(int count2=0;count2<up[count].length;count2++) {
					tally+=get(count, count2, size);
				}
				
			}
			return tally;
		}
		public int get(int x, int y, int size) {
			int out=Math.max(Math.max(up[x][y], up[x+size-length][y]), up[x+size-length][y+size-length]);
			for(int count=1;count<size-length;count++) {
				out=Math.max(out, up[x+size-length][y+count]);
			}
			return out;
		}
	}
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		for(int i=1;i<=26;i++) {
			String address=i<10?"0"+i:i+"";
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//			BufferedReader br=new BufferedReader(new FileReader("C:\\Users\\alex.zhang\\Desktop\\s5\\s5.2-"+address+".in"));
			BufferedReader out=new BufferedReader(new FileReader("C:\\Users\\alex.zhang\\Desktop\\s5\\s5.2-"+address+".out"));
			String[] first=br.readLine().split(" ");
			int size=Integer.parseInt(first[0]);
			int target=Integer.parseInt(first[1]);
			int[][] huh=new int[size][];
			for(int count=0;count<size;count++) {
				huh[count]=new int[count+1];
				String[] next=br.readLine().split(" ");
				for(int count2=0;count2<=count;count2++) {
					huh[count][count2]=Integer.parseInt(next[count2]);
				}
			}
			triangle test=new triangle(huh, target);
			String comp=test.sum(target)+"";
			String correct=out.readLine();
			
			System.out.println(comp.equals(correct)?"YES":"NO "+comp+" "+correct);
		}
		
		
		
	}

}