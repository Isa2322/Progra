package ar.edu.unlam.pb2.dominio;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FabricaDeCopasDelMundo {
    private List<Cliente> clientes;
    private List<Venta> ventas;
    private List<CopaDelMundo> copasDelMundo = new ArrayList<>();

    

public CopaDelMundo obtenerCopaDelMundoPorId(String identificador) {
    for (CopaDelMundo copa : copasDelMundo) {
        if (copa.getIdentificador().equals(identificador)) {
            return copa;
        }
    }
    return null;
}

    public FabricaDeCopasDelMundo() {
        copasDelMundo = new ArrayList<>();
        clientes = new ArrayList<>();
        ventas = new ArrayList<>();
    }
    
    public class FabricaCopasDelMundo {
        private List<Cliente> clientes = new ArrayList<>();

        public void agregarCliente(Cliente cliente) {
            if (!clientes.contains(cliente)) {
                clientes.add(cliente);
            }
        }

        public List<Cliente> getClientes() {
            return clientes;
        }
    }

    public void agregarCopaDelMundoEstandarAVentaDeCliente(Cliente clienteDeVenta, String identificador, int cantidadAVender) {
        CopaDelMundo copa = obtenerCopaDelMundoPorId(identificador);
        if (copa != null && copa instanceof CopaDelMundoEstandar) {
            CopaDelMundoEstandar copaEstandar = (CopaDelMundoEstandar) copa;
            Venta venta = obtenerVentaPorCliente(clienteDeVenta);
            if (venta == null) {
                venta = new Venta(clienteDeVenta);
                ventas.add(venta);
            }
            for (int i = 0; i < cantidadAVender && copaEstandar.getStock() > 0; i++) {
                venta.agregarCopa(copaEstandar);
                copaEstandar.setStock(copaEstandar.getStock() - 1);
            }
        }
    }

    public void agregarCopaDelMundoPersonalizadaAVentaDeCliente(Cliente clienteDeVenta, String identificador) {
        CopaDelMundo copa = obtenerCopaDelMundoPorId(identificador);
        if (copa != null && copa instanceof CopaDelMundoPersonalizada) {
            Venta venta = obtenerVentaPorCliente(clienteDeVenta);
            if (venta == null) {
                venta = new Venta(clienteDeVenta);
                ventas.add(venta);
            }
            venta.agregarCopa(copa);
            copasDelMundo.remove(copa);
        }
    }

    private Venta obtenerVentaPorCliente(Cliente clienteDeVenta) {
        for (Venta venta : ventas) {
            if (venta.getCliente().equals(clienteDeVenta)) {
                return venta;
            }
        }
        return null;
    }

    public Double obtenerPrecioDeCopaDelMundoPersonalizada(String identificador) {
        CopaDelMundo copa = obtenerCopaDelMundoPorId(identificador);
        if (copa instanceof CopaDelMundoPersonalizada) {
            return copa.obtenerPrecio();
        }
        return null;
    }

    public boolean agregarCopaDelMundo(CopaDelMundo copa) {
        return copasDelMundo.add(copa);
    }

    	public void agregarCliente(Cliente cliente) {
    	    if (!clientes.contains(cliente)) {
    	        clientes.add(cliente);
    	    }
    	}

    
    public List<CopaDelMundoEstandar> obtenerCopasDelMundoEstandar() {
        List<CopaDelMundoEstandar> copasEstandar = new ArrayList<>();
        for (CopaDelMundo copa : copasDelMundo) {
            if (copa instanceof CopaDelMundoEstandar) {
                copasEstandar.add((CopaDelMundoEstandar) copa);
            }
        }
        return copasEstandar;
    }


    public Map<Cliente, Double> obtenerTotalDePrecioDeCopasDelMundoEstandarVendidasAClientesOrdenadasPorCliente() {
	    Map<Cliente, Double> totalPorCliente = new HashMap<>();

	    for (Venta venta : ventas) {
	        Cliente cliente = venta.getCliente();
	        double totalVenta = venta.calcularTotalCopasEstandar();

	        if (totalPorCliente.containsKey(cliente)) {
	            totalVenta += totalPorCliente.get(cliente);
	        }
	        totalPorCliente.put(cliente, totalVenta);
	    }

	    return totalPorCliente;
	}



   

	public List<CopaDelMundo> getCopasDelMundo() {
		    return copasDelMundo;
		}

	public List<Cliente> getClientes() {
	    return clientes;
	}
	
	}

