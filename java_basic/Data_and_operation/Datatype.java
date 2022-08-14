public class Datatype{
	public static void main(String[] args) {
		System.out.println(6); // Number
		System.out.println("six"); // String
		
		System.out.println("6"); // String 6
		
		System.out.println(6+6); // 12
		System.out.println("6"+"6"); // 66
		
		System.out.println(6*6); // 36
		// System.out.println("6"*"6"); -> error 문자열끼리 곱셈연산 불가
		
		System.out.println("1111".length());  // 4 (문자열의 길이 반환)
		// System.out.println(1111.length()); -> error 숫자의 길이를 반환하는 함수는 없다
	}
}

