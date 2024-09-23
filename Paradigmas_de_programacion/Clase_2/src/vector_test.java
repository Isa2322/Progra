import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class vector_test {

	@Test
	void test() {
		
		Vector v1 = new Vector(1,2,3);
		Vector v2 = new Vector(3,2);
		
		Vector vr = new Vector(4,4,3);
		
		assertEquals(vr, v1.suma(v2));
		
		//fail("Not yet implemented");
	}

}
