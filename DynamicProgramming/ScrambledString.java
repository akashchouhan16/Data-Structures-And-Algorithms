import java.util.*;

public class ScrambledString
{
	static HashMap <String, Boolean> t = new HashMap<>();

	static boolean isScrambled(String a, String b)
	{
		if(a.compareTo(b) == 0)
			return true;

		if(a.length() <= 1)
			return false;

		int n = a.length();

		String key = a+" "+b;

		if(t.containsKey(key))
		{
			return t.get(key);
		}

		boolean flag = false;
		for (int i=1; i<=n-1; i++)
		{
			if((isScrambled(a.substring(0,i), b.substring(n-i,n)) &&
				isScrambled(a.substring(i,n), b.substring(0,n-i)))
				||
				(isScrambled(a.substring(0,i), b.substring(0,i)) &&
				 isScrambled(a.substring(i,n), b.substring(i,n)))
				)
			{
				flag = true;
				break;
			}
		}
		t.put(key,flag);
		return flag;
	}

	public static void main(String[] args) 
	{
		String a,b;
		Scanner in = new Scanner(System.in);
		a = in.next();
		b = in.next();

		if(a.length() != b.length())
			System.out.print(false);

		if(a.length() == 0)
			System.out.print(false);

		System.out.print(isScrambled(a,b));
	}
}
