import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Test_Punto {

	@Test
	void test_1() {
		Punto p = new Punto(2,1);
		
		assertEquals(p.Obtener_X(), 2);
		assertEquals(p.Obtener_y(), 1);
	}
	
	@Test
	void test_2() {
		Punto p = new Punto(2,0);
		
		assertEquals(p.Esta_sobre_eje_x(), true);
	}
	
	@Test
	void test_3() {
		Punto p = new Punto(2,1);
		
		assertEquals(p.Esta_sobre_eje_x(), false);
	}
	
	@Test
	void test_4() {
		Punto p = new Punto(0,1);
		
		assertEquals(p.Esta_sobre_eje_y(), true);
	}
	
	@Test
	void test_5() {
		Punto p = new Punto(2,1);
		
		assertEquals(p.Esta_sobre_eje_y(), false);
	}
	
	@Test
	void test_6() {
		Punto p = new Punto(2,1);
		
		p.Cambiar_x(89);
		
		assertEquals(p.Obtener_X(), 89);
	}
	
	@Test
	void test_7() {
		Punto p = new Punto(2,1);
		
		p.Cambiar_Y(21);
		
		assertEquals(p.Obtener_y(), 21);
	}
	
	@Test
	void test_8() {
		Punto p = new Punto(2,1);
		
		assertEquals(p.Es_el_origen(), false);
	}
	
	@Test
	void test_9() {
		Punto p = new Punto(0,0);
		
		assertEquals(p.Es_el_origen(), true);
	}
	
	@Test
	void test_10() {
		Punto p = new Punto(1,2);
		
		assertEquals(p.Distancia_al_origen(), 2.236, 0.0001);
	}
	
	@Test
	void test_11() {
		Punto p = new Punto(1,2);
		Punto p1 = new Punto(2,4);
		
		assertEquals(p.Distancia_entre_puntos(p1), 2.236, 0.0001);
	}

}
