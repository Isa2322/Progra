
public class Complejo
{
	private int real, imaginario;
	
	public Complejo(int real, int imaginario)
	{
		this.real = real;
		this.imaginario = imaginario;
	}
	
	public void suma(Complejo n1, Complejo n2)
	{
		Complejo sum = new Complejo(0,0);
		
		sum.real = n1.real + n2.real;
		sum.imaginario = n1.imaginario + n2.imaginario;
		
		this.imaginario = sum.imaginario;
		this.real = sum.real;
	}
	
	public void resta(Complejo n1, Complejo n2)
	{
		Complejo res = new Complejo(0,0);
		
		res.real = n1.real - n2.real;
		res.imaginario = n1.imaginario - n2.imaginario;
		
		this.imaginario = res.imaginario;
		this.real = res.real;	
	}
	
	public void producto(Complejo n1, Complejo n2)
	{
		Complejo res = new Complejo(0,0);
		
		res.real = (n1.real * n2.real) - (n1.imaginario * n2.imaginario);
		res.imaginario = (n1.real * n2.imaginario) + (n1.imaginario * n2.real);
		
		this.real = res.real;
		this.imaginario = res.imaginario;
	}
	
	public void division(Complejo n1, Complejo n2)
	{
		Complejo res = new Complejo(0,0);
		
		//res.real = ((n1.real*n2.real)+(n1.imaginario*n2.imaginario))/((n2.real*n2.real)+(n2.imaginario*n2.imaginario));
		
		res.real = ((n1.real * n2.real) + (n1.imaginario * n2.imaginario));
		res.real = res.real / ((n2.real * n2.real) + (n2.imaginario * n2.imaginario));
		
		//res.imaginario = ((n1.imaginario * n2.real) - (n1.real * n2.imaginario)) /  ((n2.real * n2.real) + (n2.imaginario * n2.imaginario));
		
		res.imaginario = ((n1.imaginario * n2.real) - (n1.real * n2.imaginario));
		res.imaginario = res.imaginario / ((n2.real * n2.real) + (n2.imaginario * n2.imaginario));
		
		this.real = res.real;
		this.imaginario = res.imaginario;
	}
	
	public double modulo(Complejo n1)
	{
		double res=0;
		
		res = Math.pow(n1.real, 2) + Math.pow(n1.imaginario, 2);
		
		res = Math.sqrt(res);
		
		return res;
	}
	
	
	public void mostrar()
	{
		if(this.imaginario < 0)
		{
			System.out.println(this.real + " " + this.imaginario + "i");
		}
		else
		{
			System.out.println(this.real + " + " + this.imaginario + "i");
		}
	}
}
