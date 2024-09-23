package Bicicletas;

public class Bicicleta extends Transporte {
	
	public Bicicleta()
	{
		super(2);
	}
	
	public boolean PuedeLlevar(Paquete p)
	{
		return p.peso <= 10 && Comprobar_distancia(p);
	}

	private boolean Comprobar_distancia(Paquete p) {
		return p.distancia <= distancia_maxima;
	}
}
