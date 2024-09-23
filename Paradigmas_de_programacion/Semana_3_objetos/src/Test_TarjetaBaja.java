import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Test_TarjetaBaja {

	@Test
	void test_1()
	{
		TarjetaBaja t = new TarjetaBaja(1000);
				
		assertEquals(t.Ver_saldo(), 1000);
	}
	
	@Test
	void test_2()
	{
		assertThrows(RuntimeException.class, () -> {
			new TarjetaBaja(-1);
		});
	}
	
	@Test
	void test_3()
	{
		TarjetaBaja t = new TarjetaBaja(1000);
		
		t.Cargar_saldo(500);
				
		assertEquals(t.Ver_saldo(), 1500);
	}
	
	@Test
	void test_4()
	{
		TarjetaBaja t = new TarjetaBaja(1000);
		
		assertThrows(RuntimeException.class, () -> {
			t.Cargar_saldo(-1);
		});
	}
	
	@Test
	void test_5()
	{
		TarjetaBaja t = new TarjetaBaja(1000);
		
		t.Pagar_viaje_colectivo();
				
		assertEquals(t.Ver_saldo(), (1000-39.59));
	}
	
	@Test
	void test_6()
	{
		TarjetaBaja t = new TarjetaBaja(1000);
		
		t.Pagar_viaje_subte();
				
		assertEquals(t.Ver_saldo(), (1000-34.5));
	}
	
	@Test
	void test_7()
	{
		TarjetaBaja t = new TarjetaBaja(10);
		
		assertThrows(RuntimeException.class, () -> {
			t.Pagar_viaje_colectivo();
		});
	}
	
	@Test
	void test_8()
	{
		TarjetaBaja t = new TarjetaBaja(10);
		
		assertThrows(RuntimeException.class, () -> {
			t.Pagar_viaje_subte();
		});
	}
	
	@Test
	void test_9()
	{
		TarjetaBaja t = new TarjetaBaja(1000);
		int i, j; 
		
		for (i = 0; i < 7; i++)
		{
			t.Pagar_viaje_colectivo();
		}
		
		for (j = 0; j < 9; j++)
		{
			t.Pagar_viaje_subte();
		}
				
		assertEquals(t.Contar_viajes_colectivo(), i);
		assertEquals(t.Contar_viajes_subte(), j);
		assertEquals(t.Contar_viajes(), i+j);
	}

}
