package hello2java;

public class School {

	public static void main(String[] args) {
		Score korean = new Score();
		korean.setSubject("국어");
		korean.setScore(90);
		
		Score math = new Score("수학",80);
		
		String k = korean.toString();
		
		System.out.println(korean);
		System.out.println(korean);
	}

}
