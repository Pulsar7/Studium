import java.util.Random;
import java.util.Scanner;
import java.util.HashMap;
import java.io.IOException;


public class Roulette {
	 private Player player = new Player();
	 private enum Color { BLACK, RED };
	 HashMap<Integer, Color> fields;

	public static void main(String[] args) throws IOException {
		Roulette roulette = new Roulette();
        roulette.play();
	}
	
	public void play() throws IOException {
		Scanner scanner = new Scanner(System.in);
		fields = initializeFields();
		int[] red_numbers = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
        for (int number : red_numbers) {
        	fields.put(number, Color.RED);
        }
        int[] black_numbers = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
        for (int number : black_numbers) {
        	fields.put(number, Color.BLACK);
        }
        // fields.put(0, Color.GREEN);
        String player_choice;
        int player_bet;
        int winning_number;
        Boolean continue_status = true;
		while (continue_status) {
			System.out.println("Your capital: "+player.capital+"€");
			player_choice = get_choice(scanner);
			player_bet = get_bet(scanner);
			winning_number = select_winning_number();
			System.out.println("The winning-number is: "+winning_number);
			continue_status = handle_result(player_choice, player_bet, winning_number);
			player.bets_counter++;
		}
		scanner.close();
	}
	
	private HashMap<Integer, Color> initializeFields() {
        HashMap<Integer, Color> fields = new HashMap<>();
        int[] red_numbers = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
        int[] black_numbers = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

        for (int number : red_numbers) {
            fields.put(number, Color.RED);
        }
        
        for (int number : black_numbers) {
            fields.put(number, Color.BLACK);
        }
        
        return fields;
    }
	
	private Boolean handle_result(String player_choice, int player_bet, int winning_number) {
		int player_number;
		try {
			// Number
			player_number = Integer.parseInt(player_choice);
			if (winning_number == player_number) {
				// WON
				won(true,player_bet);
			} else {
				return lost(player_bet);
			}
		} catch (NumberFormatException e) {
			// Color
			if (player_choice.contains("black") && fields.get(winning_number) == Color.BLACK) {
				// WON
				won(false,player_bet);
			} else if (player_choice.contains("red") && fields.get(winning_number) == Color.RED) {
				// WON
				won(false,player_bet);
			} else {
				// LOST
				return lost(player_bet);
			}
		}
		return true;
	}
	
	private Boolean lost(int player_bet) {
		if ((player.capital-player_bet) <= 0) {
			return false;
		}
		player.capital -= player_bet;
		System.out.println("You lost "+player_bet);
		return true;
	}
	
	private void won(Boolean best_case, int player_bet) {
		if (best_case) { // Selected the correct number
			player.capital += player_bet*35;
			System.out.println("> You won "+(player_bet*35)+"!");
		} else { // Selected the correct color
			player.capital += player_bet*2;
			System.out.println("> You won "+(player_bet*2)+"!");
		}
	}
	
	private String get_choice(Scanner scanner) throws IOException {
		String choice = "";
		while (true) {
			try {
				if (player.bets_counter > 0) {
					// scanner.nextLine();
				}
				System.out.print("Select your choice (Color / Number)> ");
				choice = scanner.nextLine().toLowerCase();
				if (Integer.parseInt(choice) >= 0 && Integer.parseInt(choice) <= 36) {
					break;
				} else {
					invalid_choice();
				}
			} catch (NumberFormatException e) {
				if (choice.contains("black") || choice.contains("red")) { // || choice.contains("green")) {
					break;
				} else {
					invalid_choice();
				}
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
		return choice;
	}
	
	public int get_bet(Scanner scanner) {
		int bet;
		while (true) {
			System.out.print("Place your bet> ");
			try {
				bet = scanner.nextInt();
			} catch (Exception e) {
				System.out.println("An error occured: "+e.getMessage());
				if (e.getMessage() == null) {
					scanner.next();
				}
				continue;
			}
			if (bet <= player.capital) {
				if (bet == player.capital) {
					System.out.println("All in.");
				}
				break;
			} else {
				System.out.println("You cannot bet more than you have");
			}
		}
		return bet;
	}
	
	public static int select_winning_number() {
		Random random = new Random();
		return random.nextInt(36 - 1) + 0;
	}

	private void invalid_choice() {
		System.out.println("You selected an invalid option!");
	}
	
}
