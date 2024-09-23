package clase2;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class circuloTests {

	@Test
	void test() {
		Circulo c1 = new Circulo(2);
		double perimetro = 12.56;

		assertEquals(perimetro, c1.perimetro(), 0.01);

	}

	@Test
	void test2() {
		Circulo c1 = new Circulo(2);
		double area = 12.56;

		assertEquals(area, c1.area(), 0.01);
	}

	@Test
	void testRnegativo() {
		assertThrows(Exception.class, () -> {
			new Circulo(-1);
		});
	}

	@Test
	void test3() {
		Circulo c1 = new Circulo(33);
		Circulo c2 = new Circulo(c1);

		assertEquals(c1, c2);
	}
}
