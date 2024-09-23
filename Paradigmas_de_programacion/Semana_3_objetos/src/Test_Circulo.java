import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Test_Circulo {

	@Test
	void test_1()
	{
		Circulos c = new Circulos(5);
		
		assertEquals(c.getRadio(), 5);
	}
	
	@Test
	void test_2()
	{
		assertThrows(RuntimeException.class, () -> {
			new Circulos(-1);
		});
	}
	
	@Test
	void test_3()
	{
		Circulos c = new Circulos(5);
		Circulos c1 = new Circulos(c);
		
		assertEquals(c.getRadio(), c1.getRadio());
	}
	
	@Test
	void test_4()
	{
		Circulos c = new Circulos(5);
		double n = 31.4159;
		
		assertEquals(c.getPerimetro(), n, 0.0001);
	}
	
	@Test
	void test_5()
	{
		Circulos c = new Circulos(5);
		double n = 78.5398;
		
		assertEquals(c.getArea(), n, 0.0001);
	}
	
	@Test
	void test_6()
	{
		Circulos c = new Circulos(5);
		
		assertEquals(c.getDiametro(), 10);
	}
	
	@Test
	void test_7()
	{
		Circulos c = new Circulos(5);
		
		c.CambiarArea(12);
		
		assertEquals(c.getArea(), 12);
	}
	
	@Test
	void test_8()
	{
		Circulos c = new Circulos(5);
		
		c.CambiarDiametro(21);
		
		assertEquals(c.getDiametro(), 21);
	}
	
	@Test
	void test_9()
	{
		Circulos c = new Circulos(5);
		
		c.CambiarRadio(47);
		
		assertEquals(c.getRadio(), 47);
	}
	
	@Test
	void test_10()
	{
		Circulos c = new Circulos(5);
		
		c.CambiarPerimetro(16);
		
		assertEquals(c.getPerimetro(), 16);
	}

}
