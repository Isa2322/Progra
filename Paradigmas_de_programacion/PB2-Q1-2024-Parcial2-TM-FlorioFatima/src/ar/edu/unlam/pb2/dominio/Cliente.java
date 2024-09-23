package ar.edu.unlam.pb2.dominio;

import java.util.Objects;

public class Cliente {
	 private String dni;
	    private String nombre;
	    private String apellido;

	    public Cliente(String dni, String nombre, String apellido) {
	        this.dni = dni;
	        this.nombre = nombre;
	        this.apellido = apellido;
	    }
	    @Override
	    public boolean equals(Object o) {
	        if (this == o) return true;
	        if (o == null || getClass() != o.getClass()) return false;
	        Cliente cliente = (Cliente) o;
	        return Objects.equals(dni, cliente.dni);
	    }

	    @Override
	    public int hashCode() {
	        return Objects.hash(dni);
	    }
	
	    public String getDni() {
	        return dni;
	    }

	    public String getNombre() {
	        return nombre;
	    }

	    public String getApellido() {
	        return apellido;
	    }

	    @Override
	    public String toString() {
	        return "Cliente{" +
	                "dni='" + dni + '\'' +
	                ", nombre='" + nombre + '\'' +
	                ", apellido='" + apellido + '\'' +
	                '}';
	    }
		
	}

