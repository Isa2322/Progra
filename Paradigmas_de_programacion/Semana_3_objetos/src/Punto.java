import java.util.Objects;

public class Punto {
	
	private double x, y;
	
	public Punto(double new_x, double new_y)
	{
		this.x = new_x;
		this.y = new_y;
	}
	
	public double Obtener_X()
	{
		return this.x;
	}
	
	public double Obtener_y()
	{
		return this.y;
	}
	
	public void Cambiar_x(double new_x)
	{
		this.x = new_x;
	}
	
	public void Cambiar_Y(double new_y)
	{
		this.y = new_y; 
	}
	
	public boolean Esta_sobre_eje_x()
	{
		if(this.y == 0)
			return true;
		else
			return false;
	}
	
	public boolean Esta_sobre_eje_y()
	{
		if(this.x == 0)
			return true;
		else
			return false;
	}
	
	public boolean Es_el_origen()
	{
		if(this.x == 0 && this.y == 0)
			return true;
		else
			return false;
	}
	
	public double Distancia_al_origen()
	{
		double dist;
		
		dist = Math.pow(this.x, 2) + Math.pow(this.y, 2);
		dist = Math.sqrt(dist);
		
		return dist;
	}

	public double Distancia_entre_puntos(Punto p1)
	{
		double dx, dy, dist;
		
		if(this.x * p1.x < 0)
			dx = this.x + p1.x;
		else
			dx = this.x - p1.x;
		

		if(this.y * p1.y < 0)
			dy = this.y + p1.y;
		else
			dy = this.y - p1.y;
			
			
		dist = Math.pow(dx, 2) + Math.pow(dy, 2);
		dist = Math.sqrt(dist);
		
		return dist;
	}

	@Override
	public int hashCode() {
		return Objects.hash(x, y);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Punto other = (Punto) obj;
		return Double.doubleToLongBits(x) == Double.doubleToLongBits(other.x)
				&& Double.doubleToLongBits(y) == Double.doubleToLongBits(other.y);
	}
	
	
}
