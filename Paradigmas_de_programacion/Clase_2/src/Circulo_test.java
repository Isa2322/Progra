import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Circulo_test {

	@Test
	void test1() {
		Circulo c1 = new Circulo(5);

		double perimetro = 31.41;

		assertEquals(c1.perimetro(), perimetro, 0.01);
	}

	@Test
	void test2() {
		Circulo c1 = new Circulo(5);

		double area = 78.53;

		assertEquals(area, c1.area(), 0.01);
	}

	@Test
	void test3() 
		{	
			assertThrows(Exception.class, () -> {
				
			new Circulo(-1);
		});
	}

	@Test
	void test4() {
		Circulo c1 = new Circulo(5);
		Circulo c2 = new Circulo(c1);

		assertEquals(c1, c2);
	}
}