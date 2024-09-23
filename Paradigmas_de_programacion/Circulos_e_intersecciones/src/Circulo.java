import java.util.Objects;

public class Circulo {

	private double radio;
	private Punto centro;

	public Circulo(double rad, double x, double y) {
		if (rad < 0)
			throw new RuntimeException("Radio invalido.");
		
		centro = new Punto(x,y);

		this.radio = rad;
	}

	public Circulo(Circulo c) {
		this.radio = c.radio;
	}

	public double getRadio() {
		return this.radio;
	}

	public double getDiametro() {
		return (this.radio * 2);
	}

	public double getPerimetro() {
		return (2 * Math.PI * this.radio);
	}

	public double getArea() {
		return (Math.PI * Math.pow(this.radio, 2));
	}

	public void CambiarRadio(double new_radio) {
		this.radio = new_radio;
	}

	public void CambiarDiametro(double new_diametro) {
		this.radio = (new_diametro / 2);
	}

	public void CambiarArea(double new_area) {
		new_area = new_area / Math.PI;

		new_area = Math.sqrt(new_area);

		this.radio = new_area;
	}

	public void CambiarPerimetro(double new_perimetro) {
		new_perimetro = new_perimetro / 2;

		new_perimetro = new_perimetro / Math.PI;

		this.radio = new_perimetro;
	}


	public boolean getInterseccion(Circulo circ)
	{
		double dist_entre_centros;
		
		dist_entre_centros = this.centro.Distancia_entre_puntos(circ.centro);
		
		if(dist_entre_centros <= (this.getRadio() + circ.getRadio()))
			return true;
		else
			return false;
	}

	@Override
	public int hashCode() {
		return Objects.hash(centro, radio);
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
		return Objects.equals(centro, other.centro)
				&& Double.doubleToLongBits(radio) == Double.doubleToLongBits(other.radio);
	}
	
	

}
