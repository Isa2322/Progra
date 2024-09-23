
public class Cilindro {
	
	static final String[] simbolos = {"❤️", "♦️", "♠️", "🍀", "😀", "👍"};
	
	public String Girar()
	{
		int n;
		n = (int) (Math.random() * simbolos.length);
		
		return simbolos[n];
	}
	
	
}
