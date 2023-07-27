package TicTacToe;


class Player {
    String name;
    char symbol;

    public char select_symbol() {
        char symbol = 'x';
        double randomNumber = Math.random();
        if (randomNumber < 5.0) {
            symbol = 'O';
        } else {
            symbol = 'X';
        }
        return symbol;
    }
}

class Game {
    public void play(Player person, Player computer) {
        System.out.println("Symbol of '"+computer.name+"' -> '"+computer.symbol+"'");
    }
}

public class tic_tac_toe {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Not enough arguments! Please enter your name.");
            return;
        }
        if (args[0] == "" || args[0] == " ") {
            System.out.println("Invalid name!");
            return;
        }
        System.out.println(args[0]);
        // Person
        Player person = new Player();
        person.name = args[0];
        person.symbol = person.select_symbol();
        
        // Computer
        Player computer = new Player();
        computer.name = "Computer";
        computer.symbol = person.symbol == 'X' ? 'O' : 'X';

        // Game
        Game game = new Game();
        game.play(person,computer);
        
    }
}
