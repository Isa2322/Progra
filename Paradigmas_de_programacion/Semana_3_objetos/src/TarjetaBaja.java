import java.util.Objects;

public class TarjetaBaja {
	
	private double saldo;
	private int ViajesC, ViajesS;
	
	
	public TarjetaBaja(double Saldo_inicial)
	{
		if(Saldo_inicial < 0)
			throw new RuntimeException("No puede iniciar con saldo negativo");
		
		this.saldo = Saldo_inicial;
		this.ViajesC = 0;
		this.ViajesS = 0;
	}
	
	public void Cargar_saldo(double new_saldo)
	{
		if(new_saldo <= 0)
			throw new RuntimeException("Cantidad a cargar invalida");
		
		this.saldo += new_saldo;
	}
	
	public void Pagar_viaje_colectivo()
	{
		if(this.saldo < 39.59)
			throw new RuntimeException("Saldo insuficiente");
		
		this.saldo -= 39.59;
		this.ViajesC++;
	}
	
	public void Pagar_viaje_subte()
	{
		if(this.saldo < 34.50)
			throw new RuntimeException("Saldo insuficiente");
		
		this.saldo -= 34.50;
		this.ViajesS++;
	}
	
	public double Ver_saldo()
	{
		return this.saldo;
	}
	
	public double Contar_viajes_colectivo()
	{
		return this.ViajesC;
	}
	
	public double Contar_viajes_subte()
	{
		return this.ViajesS;
	}
	
	public double Contar_viajes()
	{
		return (this.ViajesC + this.ViajesS);
	}

	@Override
	public int hashCode() {
		return Objects.hash(ViajesC, ViajesS, saldo);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		TarjetaBaja other = (TarjetaBaja) obj;
		return ViajesC == other.ViajesC && ViajesS == other.ViajesS
				&& Double.doubleToLongBits(saldo) == Double.doubleToLongBits(other.saldo);
	}
	
	
}
