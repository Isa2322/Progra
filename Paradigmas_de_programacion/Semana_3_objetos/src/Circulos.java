import java.util.Objects;

public class Circulos {
	
	private double radio;
	
	public Circulos(double rad)
	{
		if(rad < 0)
			throw new RuntimeException("Radio invalido.");
		
		this.radio = rad; 
	}
	
	public Circulos(Circulos c)
	{
		this.radio = c.radio;
	}
	
	public double getRadio()
	{
		return this.radio;
	}
	
	public double getDiametro()
	{
		return (this.radio * 2);
	}
	
	public double getPerimetro()
	{
		return (2 * Math.PI * this.radio);
	}
	
	public double getArea()
	{
		return (Math.PI * Math.pow(this.radio, 2) );
	}
	
	public void CambiarRadio(double new_radio)
	{
		this.radio = new_radio;
	}
	
	public void CambiarDiametro(double new_diametro)
	{
		this.radio = (new_diametro / 2);
	}
	
	public void CambiarArea(double new_area)
	{		
		new_area = new_area / Math.PI;
		
		new_area = Math.sqrt(new_area);
		
		this.radio = new_area;
	}
	
	public void CambiarPerimetro(double new_perimetro)
	{
		new_perimetro = new_perimetro / 2;
		
		new_perimetro = new_perimetro / Math.PI;
		
		this.radio = new_perimetro;
	}

	@Override
	public int hashCode() {
		return Objects.hash(radio);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Circulos other = (Circulos) obj;
		return Double.doubleToLongBits(radio) == Double.doubleToLongBits(other.radio);
	}

}
