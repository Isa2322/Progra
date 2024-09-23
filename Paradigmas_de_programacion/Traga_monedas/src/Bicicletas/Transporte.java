package Bicicletas;

public class Transporte {
	
	float distancia_maxima;
	float peso;
	
	
	public Transporte(float distancia_maxima) 
	{
		this.distancia_maxima = distancia_maxima;
	}

	public boolean PuedeLlevar(Paquete p)
	{
		return false;
	}
	
}
