import java.time.LocalDateTime;

public class Registro {

	private String tipo;
	private double monto;
	private LocalDateTime fecha;
	private String motivo;
	
	
	public Registro(String tipo, double monto)
	{
		this.tipo = tipo;
		this.monto = monto;
		this.fecha = LocalDateTime.now();
		this.motivo = "N/A";
	}
	
	public Registro(String tipo, double monto, String motivo)
	{
		this.tipo = tipo;
		this.monto = monto;
		this.fecha = LocalDateTime.now();
		this.motivo = motivo;
	}
	
	
	public String toString()
	{
		return "Transaccion [tipo = " + this.tipo + ", Motivo = " + this.motivo +", monto = " + this.monto + ", fecha = " + this.fecha + "]\n";

	}
}