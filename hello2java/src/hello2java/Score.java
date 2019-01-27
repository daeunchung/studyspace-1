package hello2java;

public class Score {

	private String subfect;
	private int score;
	
	public Score(String subfect, int score) {
		this.subject = subject;
		this.score = score;
		
	}

	public String getSubfect() {
		return subfect;
	}

	public void setSubfect(String subfect) {
		this.subfect = subfect;
	}

	public int getScore() {
		return score;
	}

	public void setScore(int score) {
		this.score = score;
	}

	@Override
	public String toString() {
		return "Score [subfect=" + subfect + ", score=" + score + "]";
	}

}
