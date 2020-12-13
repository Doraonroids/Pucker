package tests;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import resources.*;

import static org.junit.jupiter.api.Assertions.assertEquals;


public class Entity_test {

    Entity e;

    @BeforeEach
    void setUp() throws Exception {
        e = new Entity();
    }


    @Test
    void testDefaultConstructor() {
        assertEquals(0, e.getX());
        assertEquals(0, e.getY());
        assertEquals(1, e.getLives());
        assertEquals('%',e.getSymbol());
    }

    @Test
    void testOverrideConstructor(){
        e = new Entity((short) 2,(short) 3,(short)4,'@');
        assertEquals(2, e.getX());
        assertEquals(3, e.getY());
        assertEquals(4, e.getLives());
        assertEquals('@',e.getSymbol());
    }

    @Test
    void testSetters(){
        e.setX((short) 32767);
        assertEquals(32767, e.getX());
        for(short i = -32768; i < 32767 ;i++) {
            e.setX(i);
            e.setY(i);
            e.setLives(i);

            assertEquals(i, e.getX());
            assertEquals(i, e.getY());
            assertEquals(i, e.getLives());
        }

    }

    @Test
    void testSetSymbol(){
        char j = 0;
        e.setSymbol((char)65535);
        assertEquals(65535, e.getSymbol());
        while (j< 65535) {
            e.setSymbol(j);
            assertEquals(j, e.getSymbol());
            j++;
        }
    }

}

