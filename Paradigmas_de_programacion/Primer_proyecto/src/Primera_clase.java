 
public class Primera_clase {

	public static void main(String[] args) 
	{
		Complejo c1 = new Complejo(5,2);
		Complejo c2 = new Complejo(3,9);
		Complejo c3 = new Complejo(0,0);
		double nn;
		
		c3.suma(c1, c2);
		
		nn = c3.modulo(c3);
		
		System.out.println("La suma de: ");
		c1.mostrar();
		System.out.println("y");
		c2.mostrar();
		System.out.println("es: ");
		c3.mostrar();
		
		System.out.println("\n\nEl modulo de: ");
		c3.mostrar();
		System.out.println("es: " + nn);
	}

}