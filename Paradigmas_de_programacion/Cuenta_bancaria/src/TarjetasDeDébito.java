
public class TarjetasDeDébito extends Cuenta{
	
	public TarjetasDeDébito()
	{
		super();
	}
	
	public void CompraConDebito(double monto)
	{
		try
		{
			this.RetiroSaldo(monto);
		}
		catch(RuntimeException a)
		{
			this.historial.add(new Registro("ERROR Compra con debito", monto));
		}
		
		this.historial.add(new Registro("Compra con debito", monto));
	}

}
