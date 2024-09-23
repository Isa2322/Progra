package ar.edu.unlam.pb2.dominio;

import static org.junit.Assert.*;

import java.util.List;
import java.util.Map;

import org.junit.Before;
import org.junit.Test;

public class FabricaCopasDelMundoTest {

    private FabricaDeCopasDelMundo fabrica;

    @Before
    public void inicializarFabrica() {
        fabrica = new FabricaDeCopasDelMundo();
    }

    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoSePuedeAgregarUnaCopaDelMundoEstandar() {
        CopaDelMundo copa1 = new CopaDelMundo("C1", "PLASTICO", 100.0);

        assertTrue(fabrica.agregarCopaDelMundo(copa1));
        assertEquals(1, fabrica.getCopasDelMundo().size());
        assertTrue(fabrica.getCopasDelMundo().contains(copa1));
    }

    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoSePuedeAgregarUnaCopaDelMundoPersonalizada() {
        CopaDelMundoPersonalizada copaPersonalizada = new CopaDelMundoPersonalizada("C2", "RESINA", 200.0, "CAOBA");

        assertTrue(fabrica.agregarCopaDelMundo(copaPersonalizada));
        assertEquals(1, fabrica.getCopasDelMundo().size());
        assertTrue(fabrica.getCopasDelMundo().contains(copaPersonalizada));
    }

   
    
    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoAlAgregarUnClienteExistenteNoSeAgrega() {
        Cliente cliente1 = new Cliente("12345678", "Juan", "Perez");
        fabrica.agregarCliente(cliente1);

        Cliente cliente2 = new Cliente("12345678", "María", "López");
        fabrica.agregarCliente(cliente2);

        assertEquals(1, fabrica.getClientes().size());

        assertTrue(fabrica.getClientes().contains(cliente1));

        assertFalse(fabrica.getClientes().contains(cliente2));
    }





    @Test
    public void dadoQueExisteUnaFabricaQuePoseeCopasDelMundoSePuedenObtenerLasCopasDelMundoEstandar() {
        CopaDelMundoEstandar copa1 = new CopaDelMundoEstandar("C1", "PLASTICO", 100.0, 10);
        CopaDelMundoPersonalizada copa2 = new CopaDelMundoPersonalizada("C2", "RESINA", 200.0, "CAOBA");

        fabrica.agregarCopaDelMundo(copa1);
        fabrica.agregarCopaDelMundo(copa2);

        List<CopaDelMundoEstandar> copasEstandar = fabrica.obtenerCopasDelMundoEstandar();

        assertEquals(1, copasEstandar.size());
        assertTrue(copasEstandar.contains(copa1));
    }


    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoConCopasDelMundoPuedoObtenerUnaCopaDelMundoPorSuId() {
        CopaDelMundo copa1 = new CopaDelMundo("C1", "PLASTICO", 100.0);
        CopaDelMundoPersonalizada copa2 = new CopaDelMundoPersonalizada("C2", "RESINA", 200.0, "CAOBA");

        fabrica.agregarCopaDelMundo(copa1);
        fabrica.agregarCopaDelMundo(copa2);

        CopaDelMundo copaObtenida = fabrica.obtenerCopaDelMundoPorId("C2");
        assertNotNull(copaObtenida);
        assertEquals("C2", copaObtenida.getIdentificador());
    }

    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoConCopasDelMundoAlAgregarCincoCopasDelMundoAUnaVentaDeCopasDelMundoEstandarParaUnClienteSeDescuentanCincoUnidadesDelStockDeCopasDelMundoEstandar() {
        CopaDelMundoEstandar copa1 = new CopaDelMundoEstandar("C1", "PLASTICO", 100.0, 10);
        fabrica.agregarCopaDelMundo(copa1);

        Cliente cliente1 = new Cliente("12345678", "Juan", "Perez");
        fabrica.agregarCliente(cliente1);

        fabrica.agregarCopaDelMundoEstandarAVentaDeCliente(cliente1, "C1", 5);

        CopaDelMundo copaEstandar = fabrica.obtenerCopaDelMundoPorId("C1");
        assertNotNull(copaEstandar);
        assertTrue(copaEstandar instanceof CopaDelMundoEstandar);

        int stockDespuesDeVenta = ((CopaDelMundoEstandar) copaEstandar).getStock();
        assertEquals(5, stockDespuesDeVenta); 
    }

   

    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoConCopasDelMundoAlAgregarUnaVentaDeCopasDelMundoPersonalizadaParaUnClienteSeRemueveLaCopaDelMundoPersonalizadaDeLaFabrica() {
        CopaDelMundoPersonalizada copaPersonalizada = new CopaDelMundoPersonalizada("C2", "RESINA", 200.0, "CAOBA");

        fabrica.agregarCopaDelMundo(copaPersonalizada);
        fabrica.agregarCliente(new Cliente("12345678", "Juan", "Perez"));
        fabrica.agregarCopaDelMundoPersonalizadaAVentaDeCliente(new Cliente("12345678", "Juan", "Perez"), "C2");

        assertNull(fabrica.obtenerCopaDelMundoPorId("C2"));
    }

    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoConCopasDelMundoPersonalizadasSePuedeObtenerElPrecioDeUnaCopaDelMundoPersonalizada() {
        CopaDelMundoPersonalizada copaPersonalizada = new CopaDelMundoPersonalizada("C2", "RESINA", 200.0, "CAOBA");

        fabrica.agregarCopaDelMundo(copaPersonalizada);

        Double precio = fabrica.obtenerPrecioDeCopaDelMundoPersonalizada("C2");
        assertNotNull(precio);
        assertEquals(240.0, precio, 0.01); 
    }



    @Test
    public void dadoQueExisteUnaFabricaDeCopasDelMundoConVentasDeCopasDelMundoEstandarYPersonalizadasVendidasAClientesSePuedeObtenerUnMapaConClaveClienteYTotalDeVentasDeCopasEstandarOrdenadoPorCliente() {
       
        CopaDelMundo copaEstandar = new CopaDelMundo("C1", "PLASTICO", 100.0);
        CopaDelMundoPersonalizada copaPersonalizada = new CopaDelMundoPersonalizada("C2", "RESINA", 200.0, "CAOBA");

        fabrica.agregarCopaDelMundo(copaEstandar);
        fabrica.agregarCopaDelMundo(copaPersonalizada);

        Cliente cliente1 = new Cliente("12345678", "Juan", "Perez");
        Cliente cliente2 = new Cliente("87654321", "María", "López");

        fabrica.agregarCliente(cliente1);
        fabrica.agregarCliente(cliente2);

        fabrica.agregarCopaDelMundoEstandarAVentaDeCliente(cliente1, "C1", 2); 
        fabrica.agregarCopaDelMundoPersonalizadaAVentaDeCliente(cliente2, "C2");

        Map<Cliente, Double> totalVentas = fabrica.obtenerTotalDePrecioDeCopasDelMundoEstandarVendidasAClientesOrdenadasPorCliente();

        assertEquals("", 1, totalVentas.size()); 
        assertEquals("", 200.0, totalVentas.get(cliente1), 0.01);
        assertFalse("", totalVentas.containsKey(cliente2)); 
    }


}