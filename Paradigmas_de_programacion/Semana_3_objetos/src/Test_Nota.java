import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Test_Nota {

	@Test
	void test_1()
	{
		Nota n = new Nota(4);
			
		assertEquals(n.getNota(), 4);
	}
	
	@Test
	void test_2()
	{		
		assertThrows(RuntimeException.class, () -> {
				new Nota(0);
		});
	}
	
	@Test
	void test_3()
	{		
		assertThrows(RuntimeException.class, () -> {
				new Nota(11);
		});
	}
	
	@Test
	void test_4()
	{		
		Nota n = new Nota(5);
		
		n.Recuperar(9);
		
		assertEquals(n.getNota(), 9);
	}
	
	@Test
	void test_5()
	{		
		Nota n = new Nota(5);
		
		assertThrows(RuntimeException.class, () ->{
					n.Recuperar(0);
					}
					);
	}
	
	@Test
	void test_6()
	{		
		Nota n = new Nota(5);
		
		assertThrows(RuntimeException.class, () ->{
					n.Recuperar(11);
					}
					);
	}
	
	@Test
	void test_7()
	{		
		Nota n = new Nota(5);
		
		assertThrows(RuntimeException.class, () ->{
					n.Recuperar(4);
					}
					);
	}
	
	@Test
	void test_8()
	{		
		Nota n = new Nota(5);
		
		assertEquals(n.Aprobado(), true);
	}
	
	@Test
	void test_9()
	{		
		Nota n = new Nota(4);
		
		assertEquals(n.Aprobado(), true);
	}
	
	@Test
	void test_10()
	{		
		Nota n = new Nota(2);
		
		assertEquals(n.Aprobado(), false);
	}
	
	@Test
	void test_11()
	{		
		Nota n = new Nota(2);
		
		assertEquals(n.Desaprobado(), true);
	}
	
	@Test
	void test_12()
	{		
		Nota n = new Nota(8);
		
		assertEquals(n.Desaprobado(), false);
	}
}
