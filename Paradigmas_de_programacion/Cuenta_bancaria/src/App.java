
public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		CuentaDeAhorros c1 = new CuentaDeAhorros();
		CuentaDeAhorros c2 = new CuentaDeAhorros();

		
		c1.Ingreso(-21_000);
		
		c1.Ingreso(21_000);
		
		c1.Reserva(5_000);
				
		c1.Reintegro(2_000);
				
		c1.Reintegro();
		
		c1.Retiro(1_000);
		
		c1.Transferir(c2, 15_000, "prueba");
		
		System.out.println(c1.getHistorial());
		System.out.println("\n\n\n");
		System.out.println(c2.getHistorial());

	}

}
