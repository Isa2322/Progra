package ar.edu.unlam.pb2.dominio;

public class CopaDelMundoPersonalizada extends CopaDelMundo {
    private String colorAtril;

    public CopaDelMundoPersonalizada(String identificador, String material, double precio, String colorAtril) {
        super(identificador, material, precio);
        this.colorAtril = colorAtril;
    }

    public String getColorAtril() {
        return colorAtril;
    }

    public void setColorAtril(String colorAtril) {
        this.colorAtril = colorAtril;
    }

    @Override
    public double obtenerPrecio() {
        double precioFinal = super.obtenerPrecio();

        switch (colorAtril) {
            case "CAOBA":
                precioFinal *= 1.2; 
                break;
            case "CEDRO":
                precioFinal *= 1.1;
                break;
            case "ROBLE_OSCURO":
                precioFinal *= 1.15; 
                break;
            default:
               
                precioFinal *= 1.0;
                break;
        }

        return precioFinal;
    }

    @Override
    public String toString() {
        return "CopaDelMundoPersonalizada{" +
                "identificador='" + getIdentificador() + '\'' +
                ", material='" + getMaterial() + '\'' +
                ", precio=" + obtenerPrecio() +
                ", colorAtril='" + colorAtril + '\'' +
                '}';
    }
}
