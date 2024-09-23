package edu.unlam.paradigmas.basicas;

import java.util.Objects;

public class Rango implements Comparable<Rango>{

	private double inicio, fin;
	private boolean max, min;
	private static double minimo_total, maximo_total;
	private static boolean primero = true;
	
	public Rango(double inic, double fin, boolean min, boolean max)
	{
		if(fin < inic)
			throw new RuntimeException("Rango invalido");
		
		this.inicio = inic;
		this.fin = fin;
		this.min = min;
		this.max = max;
		
		if(primero == true)
		{
			minimo_total = this.inicio;
			maximo_total = this.fin;
			return;
		}
		
		if(this.inicio < minimo_total)
			minimo_total = this.inicio;
		
		if(this.fin > maximo_total)
			maximo_total = this.fin;
	}
	
	public static Rango Rango_abierto_abierto(double inicio, double fin)
	{
		return new Rango(inicio, fin, true, true);
	}
	
	public static Rango Rango_abierto_cerrado(double inicio, double fin)
	{
		return new Rango(inicio, fin, true, false);
	}
	
	public static Rango Rango_cerrado_abierto(double inicio, double fin)
	{
		return new Rango(inicio, fin, false, true);
	}
	
	public static Rango Rango_cerrado_cerrado(double inicio, double fin)
	{
		return new Rango(inicio, fin, false, false);
	}
	
	public boolean Num_esta_en_el_rango(double num)
	{
		if(this.inicio <= num && num <= this.fin)
		{
			if(this.min == false && this.inicio == num)
				return false;
			
			if(this.max == false && num == this.fin)
				return true;
			
			return true;
		}
		else
			return false;
	}
	
	public boolean Rango_esta_dentro_de_rango(Rango sub_r)
	{
		if(this.inicio <= sub_r.inicio && sub_r.fin <= this.fin)
		{
			if(this.inicio == sub_r.inicio)
				if(this.min == false && sub_r.min == true)
					return false;
			
			if(this.fin == sub_r.fin)
				if(this.max == false && sub_r.max == true)
					return false;
			
			return true;
		}
		
		return false;
	}
	
	public boolean Hay_interseccion(Rango subr)
	{
		if(this.inicio <= subr.fin && subr.inicio <= this.inicio)
			return true;
		
		if(subr.inicio <= this.fin && this.fin <= subr.fin)
			return true;
			
		return false;
	}
	
	public boolean Son_iguales(Rango subr)
	{
		if(this.inicio == subr.inicio && this.min == subr.min)
			if(this.fin == subr.fin && this.max == subr.max)
				return true;
		
		return false;
	}
	
	public String toString()
	{
		if(this.min == true)
			if(this.max == true)
				return "[" + this.inicio + " , " + this.fin + "]";
			else
				return "[" + this.inicio + " , " + this.fin + ")";
		
		if(this.max == true)
			return "(" + this.inicio + " , " + this.fin + "]";
		else
			return "(" + this.inicio + " , " + this.fin + ")";
	}
	
	public static Rango Rango_de_rangos()
	{
		Rango r = new Rango(minimo_total, maximo_total, true, true);
		
		return r;
	}
	
	public Rango Suma_rangos(Rango r)
	{
		Rango res = new Rango(this.inicio, r.fin, this.min, r.max);
		
		return res;
	}
	
	public Rango Interseccion(Rango subr)
	{
		Rango res = new Rango(0, 0, false, false);
		
		if(this.inicio <= subr.fin && subr.inicio <= this.inicio)
		{
			res.inicio = this.inicio;
			res.min = this.min;
			
			if(this.fin <= subr.fin)
			{
				res.fin = this.fin;
				res.max = this.max;
			}
			else
			{
				res.fin = subr.fin;
				res.max = subr.max;
			}
		}
		
		if(subr.inicio <= this.fin && this.fin <= subr.fin)
		{
			res.inicio = subr.inicio;
			res.min = subr.min;
			
			if(this.fin <= subr.fin)
			{
				res.fin = this.fin;
				res.max = this.max;
			}
			else
			{
				res.fin = subr.fin;
				res.max = subr.max;
			}
		}
		
		return res;
	}
	
	
	public void Desplazar_rango_escalar(int escalar)
	{
		this.inicio += escalar;
		this.fin += escalar;
	}
	

	@Override
	public int hashCode() {
		return Objects.hash(fin, inicio, max, min);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Rango other = (Rango) obj;
		return Double.doubleToLongBits(fin) == Double.doubleToLongBits(other.fin)
				&& Double.doubleToLongBits(inicio) == Double.doubleToLongBits(other.inicio) && max == other.max
				&& min == other.min;
	}

	@Override
	public int compareTo(Rango o) {
		int cmp;
		
		cmp = Double.compare(this.inicio, o.inicio);
		
		if(cmp != 0)
			return cmp;
		
		cmp = Double.compare(this.fin, o.fin);
		
		if(cmp != 0)
			return cmp;
		
		cmp = Boolean.compare(this.min, o.min);
		
		if(cmp != 0)
			return cmp;
		
		return Boolean.compare(this.max, max);
	}
}
