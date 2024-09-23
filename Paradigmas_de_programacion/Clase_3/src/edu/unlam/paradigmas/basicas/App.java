package edu.unlam.paradigmas.basicas;

public class App {

	public static void main(String[] args) 
	{
		Rango r = Rango.Rango_cerrado_cerrado(2,8);
		
		r.Desplazar_rango_escalar(-10);
		
		System.out.println("Rango 1:" + r);

	}
}