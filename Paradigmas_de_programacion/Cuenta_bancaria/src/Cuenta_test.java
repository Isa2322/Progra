import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Cuenta_test {

	@Test
	void test() {
		Cuenta c = new Cuenta();

		assertEquals(c.getSaldo(), 0);
	}

	@Test
	void test_1() {
		Cuenta c = new Cuenta();

		assertThrows(RuntimeException.class, () -> {
			c.Retiro(500);
		});
	}

	@Test
	void test_2() {
		Cuenta c = new Cuenta();

		c.Ingreso(500);

		assertEquals(c.getSaldo(), 500);
	}

	@Test
	void test_3() {
		Cuenta c = new Cuenta();

		c.Ingreso(500);
		c.Retiro(200);

		assertEquals(c.getSaldo(), 500 - 200);
	}

	@Test
	void test_4() {
		Cuenta c = new Cuenta();

		assertThrows(RuntimeException.class, () -> {
			c.Ingreso(-1);
		});
	}

	@Test
	void test_5() {
		Cuenta c = new Cuenta();

		c.Ingreso(1000);

		assertThrows(RuntimeException.class, () -> {
			c.Retiro(-1);
		});
	}

	@Test
	void test_6() {
		Cuenta c1 = new Cuenta();
		Cuenta c2 = new Cuenta();

		c1.Ingreso(1000);

		assertThrows(RuntimeException.class, () -> {
			c1.Transferir(c2, 1001, "Prueba");
		});
	}

	@Test
	void test_7() {
		Cuenta c1 = new Cuenta();
		Cuenta c2 = new Cuenta();

		double saldo = 260611;

		c1.Ingreso(1_000_000);

		c1.Transferir(c2, saldo, "Test");

		assertEquals(c2.getSaldo(), saldo);
		assertEquals(c1.getSaldo(), 1_000_000 - saldo);
	}

	@Test
	void test_8() {
		CuentaDeAhorros c = new CuentaDeAhorros();

		assertEquals(c.getSaldo(), 0);
		assertEquals(c.getReserva(), 0);
	}

	@Test
	void test_9() {
		CuentaDeAhorros c = new CuentaDeAhorros();

		c.Ingreso(1_000);

		c.Reserva(500);

		assertEquals(c.getSaldo(), 500);
		assertEquals(c.getReserva(), 500);
	}

	@Test
	void test_10() {
		CuentaDeAhorros c = new CuentaDeAhorros();

		c.Ingreso(1_000);
		c.Reserva(500);

		assertEquals(c.getSaldo(), 500);
		assertEquals(c.getReserva(), 500);

		c.Reintegro(250);

		assertEquals(c.getSaldo(), 750);
		assertEquals(c.getReserva(), 250);

		c.Reintegro();

		assertEquals(c.getSaldo(), 1000);
		assertEquals(c.getReserva(), 0);
	}

	@Test
	void test_11() {
		CuentaCorriente c = new CuentaCorriente(200);

		c.Retiro(100);

		c.Ingreso(50);

		assertEquals(c.getSaldo(), 0);
		assertEquals(c.getDescubierto(), 50);
	}

}
