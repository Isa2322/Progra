import java.util.Objects;

public class Nota {
	
	private int nota;
	
	public Nota(int val)
	{
		if(val < 1 || val > 10)
			throw new RuntimeException("Nota invalida.");
		
		this.nota = val;
	}
	
	public void Recuperar(int NuevaNota)
	{
		if(NuevaNota < 1 || NuevaNota > 10)
			throw new RuntimeException("Nota invalida.");
		
		if(NuevaNota < this.nota)
			throw new RuntimeException("La nueva nota no es superior a la nota actual");
		
		this.nota = NuevaNota; 
	}
	
	public boolean Aprobado()
	{
		if(this.nota >= 4)
			return true;
		else
			return false;
	}
	
	public boolean Desaprobado()
	{
		if(this.nota < 4)
			return true;
		else
			return false;
	}
	
	public int getNota()
	{
		return nota;
	}

	@Override
	public int hashCode() {
		return Objects.hash(nota);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Nota other = (Nota) obj;
		return nota == other.nota;
	}
}
