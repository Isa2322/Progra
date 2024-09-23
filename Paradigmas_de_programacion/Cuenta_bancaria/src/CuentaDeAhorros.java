
public class CuentaDeAhorros extends Cuenta {

	protected double Reserva;

	public CuentaDeAhorros() {
		super();
		this.Reserva = 0;
	}

	public void Reserva(double monto) {
		if (monto <= 0)
			throw new RuntimeException("Saldo a reservar invalido");

		if (monto > this.saldo)
			throw new RuntimeException("No hay saldo suficiente");

		this.saldo -= monto;

		this.Reserva = monto;

		this.historial.add(new Registro("Reserva", monto));
	}

	public void Reintegro(double monto) {
		if (monto <= 0)
			throw new RuntimeException("Saldo a reintegrar invalido");

		if (monto > this.Reserva)
			throw new RuntimeException("No hay saldo suficiente");

		this.Reserva -= monto;
		this.saldo += monto;

		this.historial.add(new Registro("Reintegro", monto));
	}

	public void Reintegro() {
		this.saldo += this.Reserva;
		this.Reserva = 0;

		this.historial.add(new Registro("Reserva", this.Reserva));
	}

	public double getReserva() {
		return this.Reserva;
	}

}
