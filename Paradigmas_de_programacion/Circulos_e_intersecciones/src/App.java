
public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Circulo c1 = new Circulo(5, 0, 0);
		Circulo c2 = new Circulo(5, 9, 0);
		
		if(c1.getInterseccion(c2))
			System.out.println("Hay interseccion");
		else
			System.out.println("No hay interseccion");


	}

}
