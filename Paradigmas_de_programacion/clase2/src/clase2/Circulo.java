package clase2;

import java.util.Objects;

public class Circulo {

	private double radio;

	public Circulo(double r) {
		if (r < 0) {
			throw new RuntimeException("Radio invalido.");
		}
		this.radio = r;
	}

	public Circulo(Circulo c2) {

		this.radio = c2.radio;
	}

	public double getRadio() {
		return radio;
	}

	public double getDiametro() {
		return radio * 2;
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
	}

	@Override
	public String toString() {

		return "r: " + radio;
	}

	public double perimetro() {
		return 2 * (Math.PI) * radio;
	}

	public double area() {
		return (Math.PI) * (radio * radio);
	}

	public static void main(String[] args) {
		Circulo c = new Circulo(3);

	}

}
