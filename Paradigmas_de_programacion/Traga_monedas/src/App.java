
public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*Cilindro c = new Cilindro();
		
		System.out.println(c.Girar());
		System.out.println(c.Girar());
		System.out.println(c.Girar());*/
		
		TragaMonedas tg = new TragaMonedas();
		
		int i=0;
		
		while(tg.Tirada() == false)
		{
			i++;
		}
		
		System.out.println(i+1);
		
		
		/*if(tg.Tirada() == true)
			System.out.println("Ganaste");
		else
			System.out.println("perdiste");*/
	}

}
