import java.util.*;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Set <Integer> lista = new HashSet <Integer>();
		
		int[] bolsa = {1,2,9,2,4,2,8,1,8,6,1,9,4,8,1,3,4,8,46,2};
		int k = 10;
		int contador = 0;
		
		//sin repetidos
		/*
		for (int gema : bolsa) {
			
			if(lista.contains(k-gema))
			{
				contador++;
			}
			
			lista.add(gema);
			
		}
		
		System.out.println(contador);
		*/
		
		//Con repetidos
		
		for (int i = 0; i < bolsa.length; i++) {		
			for (int j = i+1; j < bolsa.length; j++) {		
				if((bolsa[i] + bolsa[j]) == k)
					contador++;
			}			
		}
		System.out.println(contador);
		

	}

}
