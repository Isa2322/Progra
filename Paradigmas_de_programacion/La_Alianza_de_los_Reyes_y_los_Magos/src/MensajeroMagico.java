import java.util.LinkedList;

public class MensajeroMagico {

	private LinkedList<String> lista;
	
	public MensajeroMagico()
	{
		lista = new LinkedList<String>();
	}
	
	public void EnviarMensaje(String mensaje)
	{
		lista.addLast(mensaje);
	}
	
	public void EnviarMensajeAltaPrioridad(String mensaje)
	{
		lista.addFirst(mensaje);
	}
	
	public String RecibirMensaje()
	{
		return lista.pop();
	}
}
