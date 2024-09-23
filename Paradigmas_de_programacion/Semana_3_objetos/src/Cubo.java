import java.util.Objects;

public class Cubo {
	
	private double lado;
	
	public Cubo(double lad)
	{
		if(lad <= 0)
			throw new RuntimeException("El valor del lado es incorrecto");
		
		this.lado = lad;
	}
	
	public void Cambiar_lado(double new_lado)
	{
		if(new_lado <= 0)
			throw new RuntimeException("El nuevo valor de lado es incorrecto");
		
		this.lado = new_lado;
	}
	
	public void Cambiar_area_cara(double new_area)
	{
		if(new_area <= 0)
			throw new RuntimeException("El nuevo valor de area es incorrecto");
		
		this.lado = Math.sqrt(new_area);
	}
	
	public void Cambiar_volumen(double new_volumen)
	{
		if(new_volumen <= 0)
			throw new RuntimeException("El nuevo valor de volumen es incorrecto");
		
		this.lado = Math.cbrt(new_volumen);
	}
	
	public double getLado()
	{
		return this.lado;
	}
	
	public double getAreaCara()
	{
		return (Math.pow(this.lado, 2));
	}
	
	public double getVolumen()
	{
		return (Math.pow(this.lado, 3));
	}

	@Override
	public int hashCode() {
		return Objects.hash(lado);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Cubo other = (Cubo) obj;
		return Double.doubleToLongBits(lado) == Double.doubleToLongBits(other.lado);
	}
}
