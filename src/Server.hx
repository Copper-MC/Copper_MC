/****Copper MC 'RakNet' Protocol****/

package src;
import haxe.io.BytesInput;
import sys.net.Address;
import sys.net.Host;
import sys.net.UdpSocket;
import haxe.io.Bytes;
import haxe.Exception;
using handle.OfflinePingPong;
class Server {
    private var HostName:String;
    private var Ip:String;
    private var Port:Int;
    private var UdpServer:UdpSocket;
    private var IpHost:Host;
    private var AllAdd:Address;
    private var offlineping:OfflinePingPong;


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
        while (true) {
            Sys.sleep(0.05);
            AllAdd = new Address();
            var buffer:Bytes = Bytes.alloc(buffersize);

            try {
                var numBytes:Int = UdpServer.readFrom(buffer, 0, buffersize, AllAdd); // read

            } catch(e:Any) {
                trace(e);
            }
            /*====================================*/
            var bytesinput:BytesInput = new BytesInput(buffer);
            var bytes:Bytes = bytesinput.read(buffersize);
            var packet:Bytes = bytes.sub(0,1);
            var packetsend:String = packet.toHex();
            /*====================================*/


            if(packetsend == "01") { // Unconnected Ping (0x01) & Unconnected Ping Open Connections (0x02)
              offlineping = new OfflinePingPong(bytes,AllAdd,UdpServer);    
              offlineping.Offline_Ping();
            }
            else if(packetsend == "05") { // Open Connection Request 1 -> 0x05

                trace("Open Connection Request 1");
                var packet:Bytes = bytes.sub(0,1);
                trace("Packet Id: " + "0x" + packet.toHex());

                var magicsubs:Bytes = bytes.sub(1,16);
                var RakNetMagic:String = magicsubs.toHex();

                trace("RakNet Magic:" + RakNetMagic);

                var protocol:Bytes = bytes.sub(17,1);
                var timeinput:BytesInput = new BytesInput(protocol);
                timeinput.bigEndian = false;
                var protocolstr:Int = timeinput.readByte();

                trace("Protocol Version:" + protocolstr);
                
                var mtu:Bytes = bytes.sub(18,46);
                trace("Mtu size:" + mtu.length);

            }
           
            
        }

    }

}