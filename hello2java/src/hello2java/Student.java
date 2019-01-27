package hello2java;

public class Student {

	private String studentNo;
	private	String name;
	private	int age;
	private String telno;
	
	public String getStudentNo() {
		return studentNo;
	}
	public void setStudentNo(String studentNo) {
		this.studentNo = studentNo;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}

	//010-9999-8888
	
	public String getTelno() {
		if(this.telno = null || telno.length() < 4) {
			return telno;
		}
	}
	
	public void setTelno(String telno) {
		this.telno = telno;
	}
}
