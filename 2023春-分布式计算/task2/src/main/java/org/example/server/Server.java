package org.example.server;

import org.example.LibController;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.sql.SQLException;

public class Server {
    public static void main(String[] args) throws SQLException, RemoteException {
        System.out.println("[Server] starting...");
        // 实例化:
        LibController lib = new LibControllerImpl();
        // 将此服务转换为远程服务接口:
        LibController skeleton = (LibController) UnicastRemoteObject.exportObject(lib, 0);
        // 将RMI服务注册到1099端口:
        Registry registry = LocateRegistry.createRegistry(1099);
        // 注册此服务，服务名为"LibController":
        registry.rebind("LibController", skeleton);
        System.out.println("[server] ready.");
    }
}
