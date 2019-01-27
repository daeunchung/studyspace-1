package hijava.oop;

import java.util.ArrayList;

import hello2java.Man;

public class Main {
	
	public static void main(String[]args) {
		
		eatTest();
	}
	 private static void eatTest() {
		 Man Korean = new Man();
		 Man American = new Man();
	
		eat(Korean);
		eat(American);
	 }
	private static void eat(Man m) {
		if (m instanceof Korean) {
			m.eatRice();
		} else if (m instanceof American) {
			m.eatBread();
	}
		
		
		
		
		
		
		
		
		/*drinkTest();
	}
	 private static void drinkTest() {
		 Mom mom = new Mom();
		 Mom son = new Son();
		
		 
		 drink(mom);
		 drink(son);
	 }
	 private static void drink(Mom m) {
		 if (m instanceof Son) {
		//	 Son s =(Son)m;
		//	 s.drinkMilk();
			
			 ((Son)m).drinkMilk();
			 
			 
		 } else {
			 m.drinkBeer();
		 }
	 }*/
		
		
		
		
		
		
		
		/*ArrayList<Man> people = new ArrayList<Man>(9);
		
		for(int i=0; i<9; i++) {
			Man m = new Man("±è" + (i+1) + "¼ö");
			m.BuyCoffee(1);
			
			people.add(m);
		}
		int size = people.size();
		for(int i=0; i<size; i++) {
			System.out.println(people.get(i));
		}*/
		
	}

}
