import java.util.ArrayList;

public class Logger {
	// ANSI escape codes for text color
    public static final String RESET = "\u001B[0m";
    public static final String RED = "\u001B[31m";
    public static final String GREEN = "\u001B[32m";
    public static final String YELLOW = "\u001B[33m";
    
    // ANSI escape codes for background color
    public static final String BG_WHITE = "\u001B[47m";
    public static final String BG_BLACK = "\u001B[40m";
    
    
    public void info(Object message) {
    	System.out.println(RESET+"["+YELLOW+"INFO"+RESET+"] "+message);
    }
    
    public void info_prog(Object message) {
    	System.out.print(RESET+"["+YELLOW+"INFO"+RESET+"] "+message+"...");
    }
    
    public void warning(Object message) {
    	System.out.println(RESET+"["+YELLOW+"WARNING"+RESET+"] "+YELLOW+message+RESET);
    }
    
    public void error(Object message) {
    	System.out.println(RESET+"["+RED+"ERROR"+RESET+"] "+RED+message+RESET);
    }
    
    public void show_open_ports(ArrayList<Integer> all_ports) {
    	for (int port : all_ports) {
    		System.out.println(RESET+"["+GREEN+"+"+RESET+"] Found open port at "+YELLOW+port);
    	}
    	System.out.println(RESET+"["+GREEN+"+"+RESET+"] Found "+all_ports.size()+" open ports.");
    }
    
}
