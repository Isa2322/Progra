import java.util.Objects;

public class Circulo {
	
	private double radio;
	
	public Circulo(double rad)
	{
		if(rad <= 0)
		{
			throw new RuntimeException("Radio no valido");
		}
		this.radio = rad;
	}
	
	public double perimetro()
	{
		return this.radio*2*Math.PI;
	}
	
	public double area()
	{
		return Math.PI*this.radio*this.radio;
	}
	
	public Circulo(Circulo original) {
		this.radio = original.radio;
	}
	
	@Override
	public String toString() {
		return "";
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
		Circulo other = (Circulo) obj;
		return Double.valueOf(radio).equals(other.radio);
		//return Double.doubleToLongBits(radio) == Double.doubleToLongBits(other.radio);
	}
	
	
	

}
