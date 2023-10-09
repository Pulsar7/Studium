import java.net.Socket;
import java.net.InetSocketAddress;
import java.io.IOException;
import java.util.ArrayList;


public class PortScanner {

	public static void main(String[] args) {
		Logger log = new Logger();
		long started = System.currentTimeMillis();
		log.info("Started.");
		String target_host = "localhost";
		int target_port = 0, timeout = 5000;
		//
		Socket socket = new Socket();
		InetSocketAddress serverAddr = new InetSocketAddress(target_host,target_port);
		ArrayList<Integer> open_ports = new ArrayList<>();
		//
		while (target_port <= 9999) {
			try {
	            socket.connect(serverAddr, timeout);
	            open_ports.add(target_port);
	            socket.close();
			} catch (IOException e) {
				// log.warning("Found closed port at "+target_port+" ("+e.getMessage()+")");
			}
			target_port++;
			socket = new Socket();
            serverAddr = new InetSocketAddress(target_host,target_port);
		}
		log.show_open_ports(open_ports);
		log.info("Closed. (Runtime="+((System.currentTimeMillis()-started)/1000)+" Seconds)");
	}

}
