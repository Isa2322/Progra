package clase2;

import java.util.Arrays;

public class Vector {
	private double[] vec;

	public Vector(double... valores) {
		this.vec = new double[valores.length];
		for (int i = 0; i < valores.length; i++)
			vec[i] = valores[i];
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + Arrays.hashCode(vec);
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Vector other = (Vector) obj;
		return Arrays.equals(vec, other.vec);
	}

	public Vector suma(Vector vec1) {
		Vector masChico, masGrande;
		if (this.vec.length < vec1.vec.length) {
			masChico = this;
			masGrande = vec1;
		} else {
			masChico = vec1;
			masGrande = this;
		}
		Vector suma = new Vector(masGrande.vec);
		for (int i = 0; i < masChico.vec.length; i++) {
			suma.vec[i] += masChico.vec[i];
		}
		return suma;
//		int menor;
//		if()
//		Vector suma = new Vector(this.vec.length > vec1.vec.length ? this.vec:vec1.vec);
//		double[] vecNuevo = new double[menor];
//		for (int i = 0; i < menor; i++) {
//			suma.vec[i] = this.vec[i] + vec1.vec[i];
//		}
//		suma = new Vector(vecNuevo);
//		return suma;
	}

	public double Modulo() {
		double aux = 0;
		for (int i = 0; i < this.vec.length; i++) {
			aux += (Math.pow(this.vec[i], 2));
		}
		aux = Math.sqrt(aux);
		return aux;
	}

	public String MostrarVector() {
		return Arrays.toString(this.vec);
	}

	public static void main(String[] args) {

		double numero;
		double[] vec = { 4, 3 };
		double[] vec1 = { 3, 7 };
		Vector v1 = new Vector(vec);
		Vector v2 = new Vector(vec1);
		Vector suma = v1.suma(v2);
		System.out.println(v1.MostrarVector());
		System.out.println(suma.MostrarVector());
		numero = v1.Modulo();
		System.out.println(numero);
	}

}
