package Clase_1;

public class Complejo
{ 
	private double real;
	private double imaginario;
	public Complejo(double real, double imaginario) 
	{ 
		this.real = real; this.imaginario = imaginario;
	}
	
	public Complejo suma(Complejo n1)
	{
		Complejo suma = new Complejo(0,0);
		suma.real = this.real + n1.real; 
		suma.imaginario = this.imaginario +n1.imaginario;
		return suma;
	}
	
	public Complejo Resta(Complejo n1)
	{ 
		Complejo resta = new Complejo(0,0);
		resta.real = this.real - n1.real;
		resta.imaginario = this.imaginario - n1.imaginario;
		return resta;
	}   
	
	public double Modulo(Complejo n1)
	{ 
		double modulo;
	}   
	
	public void Mostrar()
	{
		if(this.imaginario >= 0) System.out.println(this.real + " + " +this.imaginario+"i");
		else System.out.println(this.real + "  " +this.imaginario+"i");
	}
	
	//numero1.suma() 
	
	public static void main(String[] args)
	{
		Complejo c1 = new Complejo(5,3);
		Complejo c2 = new Complejo(3,4);
		Complejo resultado = new Complejo(0,0);
		resultado = c1.suma(c2); resultado.Mostrar();
		resultado = c1.Resta(c2); resultado.Mostrar(); 
	}
	  
}
