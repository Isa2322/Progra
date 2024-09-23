package clase2;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class vectorTests {

	@Test
	void test() {
		Vector v1 = new Vector(1, 2, 3);
		Vector v2 = new Vector(3, 2, 1);

		Vector resultadoEsperado = new Vector(4, 4, 4);

		assertEquals(resultadoEsperado, v1.suma(v2));
	}

}
