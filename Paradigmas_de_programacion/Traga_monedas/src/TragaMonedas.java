
public class TragaMonedas {
	
	private Cilindro c1 = new Cilindro();
	private Cilindro c2 = new Cilindro();
	private Cilindro c3 = new Cilindro();

	public Boolean Tirada()
	{
		String s1 = c1.Girar();
		String s2 = c2.Girar();
		String s3 = c3.Girar();
		
		/*if(c2.Girar() == s)
			if(c3.Girar() == s)
				return true;
				*/
		System.out.println(s1 + " " + s2 + " " + s3);
		if(s1 == s2)
			if(s3 == s2)
				return true;
		
		return false;
	}
}
