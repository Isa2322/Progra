package ar.edu.unlam.pb2.dominio;

public class CopaDelMundoEstandar extends CopaDelMundo {
	private int stock;

    public CopaDelMundoEstandar(String identificador, String material, double precio, int stock) {
        super(identificador, material, precio);
        this.stock = stock;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }
    private double getPrecioBase() {
        return super.getPrecio(); 
    }

    public double obtenerPrecio() {
        return getPrecioBase() * 1.2;
    }
   
    public double getPrecio() {
		return precio;
	}

	@Override
    public String toString() {
        return "CopaDelMundoEstandar{" +
                "identificador='" + getIdentificador() + '\'' +
                ", material='" + getMaterial() + '\'' +
                ", precio=" + super.obtenerPrecio() +
                ", stock=" + stock +
                '}';
    }
}