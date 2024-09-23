package ar.edu.unlam.pb2.dominio;

import java.util.ArrayList;
import java.util.List;

public class Venta {
    private Cliente cliente;
    private List<CopaDelMundo> copasVendidas;

    public Venta(Cliente cliente) {
        this.cliente = cliente;
        this.copasVendidas = new ArrayList<>();
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void agregarCopa(CopaDelMundo copa) {
        copasVendidas.add(copa);
    }

    public double getTotal() {
        double total = 0;
        for (CopaDelMundo copa : copasVendidas) {
            total += copa.obtenerPrecio();
        }
        return total;
    }

    @Override
    public String toString() {
        return "Venta{" +
                "cliente=" + cliente +
                ", copasVendidas=" + copasVendidas +
                '}';
    }

	
	   private List<CopaDelMundoEstandar> copasEstandar;
	    public double calcularTotalCopasEstandar() {
	        double total = 0;
			for (CopaDelMundoEstandar copa : copasEstandar) {
	            total += copa.getPrecio();
	        }
	        return total;
	    }
	}


