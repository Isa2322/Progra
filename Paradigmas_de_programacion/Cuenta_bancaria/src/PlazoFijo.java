import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class PlazoFijo extends Cuenta{
	
	private double interes_anual = 36;
	private int meses;
	private LocalDate fecha_ingreso;
	private double monto;
	
	public PlazoFijo(double monto, int meses)
	{
		try
		{
			this.RetiroSaldo(monto);
		}
		catch(RuntimeException a)
		{
			this.historial.add(new Registro("ERROR Ingresar Plazo fijo", monto));
		}
		
		fecha_ingreso = LocalDate.now();
		this.monto = monto;
		this.meses = meses;
	}
	
	public void RetirarPlazoFijo()
	{	
		if(VerificarMeses(fecha_ingreso, meses) == false)
		{
			throw new RuntimeException("No han pasado los meses indicados (" + this.meses +")");
		}
		
		this.Ingreso(monto * (interes_anual / 12) * meses);
		this.historial.add(new Registro("Retiro de plazo fijo", (monto * (interes_anual / 12) * meses)));

	}
	
	private boolean VerificarMeses(LocalDate fecha, int meses)
	{
		LocalDate hoy = LocalDate.now();
		long cant_meses;
		
        cant_meses = ChronoUnit.MONTHS.between(fecha, hoy);
        
        if(cant_meses < meses)
        	return false;
        else
        	return true;
	}

}
