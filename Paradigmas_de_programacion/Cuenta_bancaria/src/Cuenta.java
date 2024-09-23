import java.util.Objects;
import java.util.ArrayList;
import java.util.List;

public class Cuenta {

	protected double saldo;
	protected List<Registro> historial;

	public Cuenta() {
		this.saldo = 0;
		this.historial = new ArrayList<>();
	}

	public void Ingreso(double monto) {
		try {
			IngresoSaldo(monto);
		} catch (RuntimeException a) {
			this.historial.add(new Registro("ERROR Ingreso", monto));
			System.out.println(a);
			throw a;
		}

		this.historial.add(new Registro("Ingreso", monto));
	}

	protected void IngresoSaldo(double monto) {
		if (monto <= 0)
			throw new RuntimeException("Saldo a ingresar invalido");

		this.saldo += monto;
	}

	public void Retiro(double monto) {
		try {
			RetiroSaldo(monto);
		} catch (RuntimeException a) {
			this.historial.add(new Registro("ERROR Retiro", monto));
			System.out.println(a);
			throw a;
		}
		this.historial.add(new Registro("Retiro", monto));
	}

	protected void RetiroSaldo(double monto) {
		if (monto <= 0)
			throw new RuntimeException("Saldo a retirar invalido");

		if (monto > this.saldo)
			throw new RuntimeException("No hay saldo suficiente");

		this.saldo -= monto;
	}

	public void Transferir(Cuenta destino, double monto, String motivo) {
		try {
			this.RetiroSaldo(monto);
		} catch (RuntimeException a) {
			System.out.println(a);
			this.historial.add(new Registro("ERROR Transferencia", monto));
			throw a;
		}

		destino.IngresoSaldo(monto);

		this.historial.add(new Registro("Transferencia", monto, motivo));
	}

	public double getSaldo() {
		return this.saldo;
	}

	public List<Registro> getHistorial() {
		return this.historial;
	}

	@Override
	public int hashCode() {
		return Objects.hash(historial, saldo);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Cuenta other = (Cuenta) obj;
		return Objects.equals(historial, other.historial)
				&& Double.doubleToLongBits(saldo) == Double.doubleToLongBits(other.saldo);
	}

}
