import java.util.*;

public class PalindromicPartition
{
	static int t[][];

	static void initializeDP(int n)
	{
		t = new int [n][n];

		for (int i=0; i<n; i++) 
		{
			for (int j=0; j<n; j++) 
			{
				t[i][j] = -1;
			}
		}
	}

	static boolean isPalindrome(String s, int i, int j)
	{
		while (i<j)
		{
			if(s.charAt(i) != s.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}

	static int partition(String s, int i, int j)
	{
		if(i>=j || isPalindrome(s,i,j))
			return 0;

		if(t[i][j] != -1)
			return t[i][j];

		int min=Integer.MAX_VALUE, left, right;

		for (int k=i; k<=j-1; k++)
		{
			if(t[i][k] != -1)
				left = t[i][k];
			else
				left = t[i][k] = partition(s,i,k);

			if(t[k+1][j] != -1)
				right = t[k+1][j];
			else
				right = t[k+1][j] = partition(s,k+1,j);

			int temp = 1 + left + right;

			if(temp<min)
				min = temp;
		}
		return t[i][j] = min;
	}

	public static void main(String[] args) 
	{
		String s;
		Scanner in = new Scanner(System.in);
		s = in.next();
		initializeDP(s.length());
		System.out.println(partition(s,0,s.length()-1));
	}
}
