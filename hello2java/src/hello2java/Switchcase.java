package hello2java;

public class Switchcase {

	public static void main(String[]args) {
		
        long ctm = System.currentTimeMillis() % 10;
        System.out.println("ctm=" + ctm);
        
        long sct = ctm % 3;
        
        switch( (int)sct ) {
        case 1:
            System.out.println("One");
            break;
        case 2:
            System.out.println("Two");
            break;
        default:
            System.out.println("Zero");
        }
	}
}
