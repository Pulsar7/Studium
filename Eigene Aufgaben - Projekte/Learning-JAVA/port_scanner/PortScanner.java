package port_scanner;
import java.io.*;
import java.net.*;


public class PortScanner extends Logger {
    public static void main(String[] args) {
        if (args.length < 1) {
            error("Too few arguments! You have to enter the host-IP!");
            return;
        }
        String host_ip = args[0], service_name = "";
        int host_port = 0, open_ports = 0;
        info("Started scan");
        while (host_port < 65535) {
            host_port++;
            try {
                Socket socket = new Socket(host_ip, host_port);
                open_ports++;
                service_name = socket.getInetAddress().getHostName();
                info("Open Port at "+host_port+" => "+service_name);
                socket.close();
            } catch (IOException e) {
                // error("An exception occured: "+e.getMessage());
                // break;
            }
        }
        info("Found "+open_ports+" open ports at "+host_ip);
        info("Scan finished.");
    }
}
