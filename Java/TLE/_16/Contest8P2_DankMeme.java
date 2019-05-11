package _16;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Contest8P2_DankMeme {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		for(int count=Integer.parseInt((new BufferedReader(new InputStreamReader(System.in))).readLine());count>0;count--) System.out.println(Integer.toBinaryString(Integer.parseInt((new BufferedReader(new InputStreamReader(System.in))).readLine())).replaceAll("1", " dank").replaceAll("0", " meme").substring(1));
	}

}
