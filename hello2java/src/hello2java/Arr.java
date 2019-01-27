package hello2java;

/*public class Arr {
	
	public static void main(String[]args) {
		
		ex1();
		ex2();
	}

	private static void ex2() {
		Man[] people + new Man[9];
		int len = people.length;
		for(int i = 0; i < len; i++) {
			Man m = new Man
		}
	}

	private static void ex1() {
		int[] nums = new int[100];
		
		for(int i=0; i< nums.length; i++) {
			nums[i] = i + 1;
		}
	}

} */

public class Arr {

	public static void main(String[] args) {
//		ex1();
//		ex2();
//		ex3();
//		ex4();
		ex5();
	}

	private static void ex5() {
		int[] arr1 = {10, 20, 30, 40, 50};
		int[] arr2 = { 1, 2, 3, 4, 5 };
		System.arraycopy(arr1, 0, arr2, 2, 3);
		
		for (int i : arr2) {
			System.out.println(i);
		}
	}
}
