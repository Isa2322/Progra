package Bicicletas;

public class Moto extends Transporte{
	
	private float dist = 15;
	private float peso = 50;
	private	int cant = 3;
		
	
	
	public boolean PuedeLlevar(Paquete p)
	{
		if(ComprobarPeso(p))
			if(ComprobarDistancia(p))
				if(cant < 0)
				{
					return true;
				}
		
		return false;
	}

	private boolean ComprobarPeso(Paquete p) {
		return p.peso <= this.peso;
	}

	private boolean ComprobarDistancia(Paquete p) {
		return p.distancia <= this.dist;
	}
	
	public void Llevar(Paquete p)
	{
		this.peso -= p.peso;
		this.cant--;
	}

	public Moto(float distancia_maxima) {
		super(distancia_maxima);
		// TODO Auto-generated constructor stub
	}
	
	
	
}
