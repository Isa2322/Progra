
public class CuentaCorriente extends Cuenta {

	protected double descubierto_tope, descubierto;

	public CuentaCorriente(double desc) {
		super();

		if (desc <= 0)
			throw new RuntimeException("Monto de descubierto invalido");

		this.descubierto_tope = desc;
		this.descubierto = desc;
	}

	public void Retiro(double monto) {
		if (monto <= 0)
			throw new RuntimeException("Saldo a retirar invalido");

		if (monto > this.saldo)
			if (monto > (this.descubierto + this.saldo))
				throw new RuntimeException("No hay saldo suficiente");
			else {
				monto -= this.saldo;
				this.saldo = 0;
				this.descubierto -= monto;
			}

		this.saldo -= monto;
		this.historial.add(new Registro("Reserva", monto));
	}

	public void Ingreso(double monto) {
		double deuda = this.descubierto_tope - this.descubierto;

		this.IngresoSaldo(monto);

		if (this.saldo >= deuda) {
			this.descubierto = this.descubierto_tope;
			this.saldo -= deuda;
			this.historial.add(new Registro("Saldo dedua", monto));
		} else {
			this.descubierto += this.saldo;
			this.historial.add(new Registro("Saldo deuda parcial", monto));
			this.saldo = 0;
		}
	}

	public double getDescubierto() {
		return this.descubierto;
	}

}
