package test.solution;

import logic.components.Player;
import logic.components.Status;
import logic.game.GameController;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNull;


public class GameControllerTest {
    @Test
    public void testEndDay() {
        Status status1 = GameController.createNewStatus(4, 3, 2, 1);
        Status status2 = GameController.createNewStatus(5, 3, 2, 0);
        GameController.getInstance().players = new ArrayList<Player>();
        GameController.getInstance().players.add(new Player("player1", status1, 1, 100));
        GameController.getInstance().players.add(new Player("player2", status2, 5, 100));
        GameController.getInstance().endDay();

        assertEquals(GameController.getInstance().players.get(0).getEnergy(), 0);
        assertEquals(GameController.getInstance().players.get(0).getStatus().getHp(), 2);
        assertEquals(GameController.getInstance().players.get(1).getEnergy(), 2);
        assertEquals(GameController.getInstance().players.get(1).getStatus().getHp(), 5);
    }

    @Test
    public void testCreateNewStatus() {
        Status status = GameController.createNewStatus(1, 2, 3, 4);
        assertEquals(status.getHp(), 1);
        assertEquals(status.getDurability(), 2);
        assertEquals(status.getAttack(), 3);
        assertEquals(status.getMagic(), 4);

    }

    @Test
    public void testCreateNewStatusException() {
        Status statusM = GameController.createNewStatus(-1, 5, 2, 1);
        assertNull(statusM);
        statusM = GameController.createNewStatus(2, -4, 4, 2);
        assertNull(statusM);
        statusM = GameController.createNewStatus(7, 3, -5, 5);
        assertNull(statusM);
        statusM = GameController.createNewStatus(3, -3, 1, -3);
        assertNull(statusM);
    }
}
