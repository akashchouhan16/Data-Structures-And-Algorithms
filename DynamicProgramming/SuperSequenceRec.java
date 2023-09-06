import java.util.*;

public class SuperSequenceRec
{
	static int t[][];

	static void initializeLCS(int n, int m)
	{
		t = new int [n+1][m+1];

		for (int i=0; i<n+1; i++) 
		{
			for (int j=0; j<m+1; j++) 
			{
				t[i][j] = -1;
			}
		}
	}

	static int lcs (String x, String y, int n, int m)
	{
		if(m==0 || n==0)
			return t[n][m] = 0;

		if(t[n][m]!=-1)
			return t[n][m];

		if(x.charAt(n-1) == y.charAt(m-1))
			return t[n][m] = 1+lcs(x,y,n-1,m-1);

		return t[n][m] = Math.max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
	}

	public static void main(String[] args)
	{
		String x,y;
		int res;
		Scanner in = new Scanner(System.in);
		x = in.next();
		y = in.next();
		initializeLCS(x.length(),y.length());
		res = lcs(x,y,x.length(), y.length());
		res = x.length()+y.length()-res;
		System.out.println(res);
	}
}
