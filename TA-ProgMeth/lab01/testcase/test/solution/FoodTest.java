package test.solution;

import static org.junit.jupiter.api.Assertions.*;
import logic.components.Food;
import org.junit.jupiter.api.Test;
public class FoodTest{
    @Test
    void testConstructor(){
        Food food1 = new Food("Food1",12,16);
        Food food2 = new Food("Food2",5,3);
        Food food3 = new Food("Food3",-10,-11);
        assertEquals("Food1",food1.getName());
        assertEquals(12,food1.getPrice());
        assertEquals(16,food1.getEnergy());
        assertEquals("Food2",food2.getName());
        assertEquals(5,food2.getPrice());
        assertEquals(3,food2.getEnergy());
        assertEquals("Food3",food3.getName());
        assertEquals(1,food3.getPrice());
        assertEquals(1,food3.getEnergy());
    }

    @Test
    void testSetName(){
        Food food1 = new Food("Testfood1",10,20);
        food1.setName("PadThai");
        assertEquals("PadThai",food1.getName());
    }

    @Test
    void testSetPrice(){
        Food food1 = new Food("Testfood1",10,20);
        food1.setPrice(19);
        assertEquals(19,food1.getPrice());
        food1.setPrice(0);
        assertEquals(1,food1.getPrice());
        food1.setPrice(4);
        assertEquals(4,food1.getPrice());
    }

    @Test
    void testSetEnergy(){
        Food food1 = new Food("Testfood1",10,12);
        food1.setEnergy(13);
        assertEquals(13,food1.getEnergy());
        food1.setEnergy(0);
        assertEquals(1,food1.getEnergy());
        food1.setEnergy(12);
        assertEquals(12,food1.getEnergy());
    }


}
