import java.util.Objects;

public class Cerradura {
	
	private int  Clave_apertura, intentos_desbloqueo;
	private boolean abierta;
	private int Aperturas_exitosa, Aperturas_fallidas;
	
	public Cerradura(int Clave, int intentos)
	{
		if(intentos < 1)
			throw new RuntimeException("La cantidad de intentos es invalida");
		
		this.Clave_apertura = Clave;
		this.intentos_desbloqueo = intentos;
		this.abierta = false;
		this.Aperturas_exitosa = 0;
		this.Aperturas_fallidas = 0;
	}
	
	public boolean Abrir(int clave)
	{		
		if(this.intentos_desbloqueo <= this.Aperturas_fallidas)
			return false;
		
		if(this.abierta == true)
			return true;
		
		if(clave == this.Clave_apertura)
		{
			this.abierta = true;
			this.Aperturas_exitosa++;
			return true;
		}
		
		this.Aperturas_fallidas++;
		return false;
	}
	
	public void Cerrar()
	{
		this.abierta = false;
	}
	
	public boolean Esta_abierta()
	{
		return this.abierta;
	}
	
	public boolean Esta_cerrada()
	{
		if(this.abierta == false)
			return true;
		else
			return false;
	}
	
	public boolean Esta_bloqueada()
	{
		if(this.intentos_desbloqueo <= this.Aperturas_fallidas)
			return true;
		else
			return false;
	}
	
	public int Contar_aperturas_exitosas()
	{
		return this.Aperturas_exitosa;
	}
	
	public int Contar_aperturas_fallidas()
	{
		return this.Aperturas_fallidas;
	}

	@Override
	public int hashCode() {
		return Objects.hash(Aperturas_exitosa, Aperturas_fallidas, Clave_apertura, abierta, intentos_desbloqueo);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Cerradura other = (Cerradura) obj;
		return Aperturas_exitosa == other.Aperturas_exitosa && Aperturas_fallidas == other.Aperturas_fallidas
				&& Clave_apertura == other.Clave_apertura && abierta == other.abierta
				&& intentos_desbloqueo == other.intentos_desbloqueo;
	}

}
