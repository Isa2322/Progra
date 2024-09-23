import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Test_Cubo {

	@Test
	void test_1()
	{
		Cubo c = new Cubo(5);
		
		assertEquals(c.getLado(), 5);
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
		Cubo c = new Cubo(3);
		assertEquals(c.getAreaCara(), 9);
	}
	
	@Test
	void test_$()
	{
		Cubo c = new Cubo(3);
		assertEquals(c.getVolumen(), 27);
	}
	
	@Test
	void test_5()
	{
		Cubo c = new Cubo(3);
		
		c.Cambiar_lado(5);
		
		assertEquals(c.getLado(), 5);
	}
	
	@Test
	void test_6()
	{
		Cubo c = new Cubo(3);
		
		assertThrows(RuntimeException.class, () ->{
			c.Cambiar_lado(-1);
		});
	}
	
	@Test
	void test_7()
	{
		Cubo c = new Cubo(3);
		
		assertThrows(RuntimeException.class, () ->{
			c.Cambiar_area_cara(-1);
		});
	}
	
	@Test
	void test_8()
	{
		Cubo c = new Cubo(3);
		
		assertThrows(RuntimeException.class, () ->{
			c.Cambiar_volumen(-14);
		});
	}
	
	@Test
	void test_9()
	{
		Cubo c = new Cubo(3);
		
		c.Cambiar_area_cara(5);
		
		assertEquals(c.getAreaCara(), 5, 0.0000001);
	}
	
	@Test
	void test_10()
	{
		Cubo c = new Cubo(3);
		
		c.Cambiar_volumen(25);
		
		assertEquals(c.getVolumen(), 25, 0.000001);
	}
}
