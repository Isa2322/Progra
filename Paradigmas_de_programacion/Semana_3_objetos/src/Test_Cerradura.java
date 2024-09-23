import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Test_Cerradura {

	@Test
	void test_1()
	{
		Cerradura c = new Cerradura(1812, 5);
		
		assertEquals(c.Contar_aperturas_exitosas(), 0);
		assertEquals(c.Contar_aperturas_fallidas(), 0);
		
		assertEquals(c.Esta_abierta(), false);
		assertEquals(c.Esta_bloqueada(), false);
		assertEquals(c.Esta_cerrada(), true);
		
		c.Abrir(1810);
		c.Abrir(1811);
		c.Abrir(1812);
		
		assertEquals(c.Contar_aperturas_exitosas(), 1);
		assertEquals(c.Contar_aperturas_fallidas(), 2);
		assertEquals(c.Esta_abierta(), true);
		assertEquals(c.Esta_bloqueada(), false);
		assertEquals(c.Esta_cerrada(), false);
	}
	
	@Test
	void test_2()
	{
		Cerradura c = new Cerradura(1812, 5);
		
		
		for (int i = 0; i < 5; i++)
		{
			c.Abrir(1812);
			c.Cerrar();
		}		
		assertEquals(c.Contar_aperturas_exitosas(), 5);
		assertEquals(c.Contar_aperturas_fallidas(), 0);
	}
	
	@Test
	void test_3()
	{
		assertThrows(RuntimeException.class, () -> {
			new Cerradura(1812, -5);
		});
	}
	
	
	@Test
	void test_4()
	{
		Cerradura c = new Cerradura(1812, 5);
		
		
		for (int i = 0; i < 6; i++)
		{
			c.Abrir(10);
		}		
		
		assertEquals(c.Contar_aperturas_fallidas(), 5);
		assertEquals(c.Esta_abierta(), false);
		assertEquals(c.Esta_bloqueada(), true);
		assertEquals(c.Esta_cerrada(), true);
	}
	

}
