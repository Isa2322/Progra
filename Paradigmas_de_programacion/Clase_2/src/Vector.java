import java.util.Arrays;

public class Vector {
	
	private double[] vec;
	
	public Vector(double... valores) {
		vec = new double[valores.length];
		for (int i = 0; i < valores.length; i++) {
			this.vec[i] = valores[i];
		}
	}
	
	public Vector suma(Vector v1)
	{
		/*double[] res = new double[v1.vec.length];

		
		if(this.vec.length > v1.vec.length)
		{
			for (int i = 0; i < vec.length; i++)
			{
				res[i] = this.vec[i] + v1.vec[i];
			}
		}
		else
		{
			for (int i = 0; i < v1.vec.length; i++)
			{
				res[i] = this.vec[i] + v1.vec[i];
			}*/

		if(this.vec.length > v1.vec.length)
		{
			Vector res = new Vector(this.vec);
			
			for (int i = 0; i < v1.vec.length; i++)
			{
				res.vec[i] += v1.vec[i];
			}
			
			return res;
		}
		else
		{
			Vector res = new Vector(v1.vec);
			
			for (int i = 0; i < this.vec.length; i++)
			{
				res.vec[i] += this.vec[i];
			}
			
			return res;
		}
		
	}
	
	public double modulo(Vector v1)
	{
		double aux=0;
		
		for (int i = 0; i < vec.length; i++)
		{
			aux += (Math.pow(v1.vec[i], 2));
		}
		
		aux = Math.sqrt(aux);
		
		return aux;
	}
	
	public void mostar()
	{
		for (int i = 0; i < vec.length; i++)
		{
			System.out.println(this.vec[i] + ", ");
		}
		
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
	
	
	
	
	
	
	
}
