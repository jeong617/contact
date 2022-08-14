
public class Casting {

	public static void main(String[] args) {
		
		double a = 1.1;
		double b = 1; // = (double) 1 -> 자동캐스팅 된 것
		System.out.println(b); // 1.0
		// 1이 실수로 자동 converting 가능
		
		// int c = 1.1;
		// double 형을 int 형으로 바꾸지 못한다. 바꾸게 되면 0.1 을 잃어버리는 현상이 생김
		
		double d = 1.1;
		int e = (int) 1.1;
		
		// 1 to String
		int i = 1;
		String str = Integer.toString(i);
		System.out.println(str.getClass());
		
	}

}
