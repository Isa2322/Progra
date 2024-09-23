package ar.edu.unlam.pb2.dominio;

public class CopaDelMundo {
    private String identificador;
    private String material;
    protected double precio;

    public CopaDelMundo(String identificador, String material, double precio) {
        this.identificador = identificador;
        this.material = material;
        this.precio = precio;
    }

    public String getIdentificador() {
        return identificador;
    }

    public String getMaterial() {
        return material;
    }

    public double obtenerPrecio() {
        return precio;
    }

	public double getPrecio() {
		// TODO Auto-generated method stub
		return precio;
	}

}
