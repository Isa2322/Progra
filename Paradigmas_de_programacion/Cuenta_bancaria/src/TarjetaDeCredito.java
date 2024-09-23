
public class TarjetaDeCredito extends Cuenta{
	
	private double credito;
	private final double comision = 1.03;
	
	public TarjetaDeCredito()
	{
		super();
		this.credito = 0;
	}
	
	protected void CompraConCredito(double monto)
	{
		this.credito += monto;
		this.historial.add(new Registro("Compra con credito", credito));
	}
	
	protected void SaldarCredito()
	{
		try
		{
			this.RetiroSaldo(credito * comision);
		}
		catch(RuntimeException a)
		
		{
			this.historial.add(new Registro("ERROR Saldar Credito", credito * comision));
		}
		
		this.historial.add(new Registro("Saldar Credito", credito * comision));

	}

}
