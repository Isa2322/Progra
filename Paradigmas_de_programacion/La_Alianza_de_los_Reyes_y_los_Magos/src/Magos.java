import java.util.HashMap;
import java.util.HashSet;

public class Magos {
	
	private HashSet<String> hechizos;
	static HashSet<Magos> magosQueVotaron;
	static HashMap<String, Integer> votosLider;
		
	public Magos(String[] listaHechizos)
	{
		this.hechizos = new HashSet<String>();
		
		for (String string : listaHechizos) {	
			this.hechizos.add(string);
		}
	}
	
	public HashSet<String> CompararHechizos(Magos mago2)
	{
		HashSet<String> lista = new HashSet<String>();
		
		for (String string : this.hechizos) {
			for (String string2 : mago2.hechizos) {
				
				if(string == string2)
					lista.add(string);
			}
		}
		return lista;
	}
	
	public void VotarLider(String lider)
	{
		if(magosQueVotaron.contains(this))
			throw new RuntimeException("El mago ya voto");
		
		if(votosLider.containsKey(lider))
		{
			int votos;
			votos = votosLider.get(lider);
			votos ++;
			votosLider.put(lider, votos);
			magosQueVotaron.add(this);
		}
	}

}
