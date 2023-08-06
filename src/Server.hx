package src;
import haxe.io.BytesInput;
import sys.net.Address;
import sys.net.Host;
import sys.net.UdpSocket;
import haxe.io.Bytes;
using handle.OfflinePingPong;
class Server {
    private var HostName:String;
    private var Ip:String;
    private var Port:Int;
    private var UdpServer:UdpSocket;
    private var IpHost:Host;
    private var AllAdd:Address;
    private var offlineping:OfflinePing;


    public function new(hostName:String, ip:String, port:Int) {
        trace("\x1b[31mSocket installing..\x1b[0m");
        HostName = hostName;
        Ip = ip;
        Port = port;
        IpHost = new Host(Ip.toString());
        UdpServer = new UdpSocket();
        
    
    }
    public function Start():Void {
        trace("Socket installed");
        UdpServer.bind(IpHost,Port);
        HandlePackets();
    }

    
    private function HandlePackets():Void {
        var buffersize:Int = 1024;
        var buffer:Bytes = Bytes.alloc(buffersize);
        while (true) {
            AllAdd = new Address();
            var numBytes:Int = UdpServer.readFrom(buffer, 0, buffersize, AllAdd); // read
            var bytesinput:BytesInput = new BytesInput(buffer); // input
            var bytes:Bytes = bytesinput.read(buffersize);

            var packet:Bytes = bytes.sub(0,1);
            if(packet.toHex() == "01") {
              offlineping = new OfflinePingPong(bytes,AllAdd,UdpServer);    
              offlineping.Offline_Ping();
            }
           
            
        }

    }

}