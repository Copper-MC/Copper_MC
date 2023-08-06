package handle;
import src.Server;
import sys.net.UdpSocket;
import haxe.io.BytesInput;
import haxe.io.Bytes;
import haxe.io.BytesOutput;
import sys.net.Address;
class OfflinePing {
    private var buf:Bytes;
    private var add:Address;
    private var socket:UdpSocket;
    public function new(buf:Bytes,add:Address,socket:UdpSocket) {
        this.buf = buf;
        this.add = add;
        this.socket = socket;

    }
    public function Offline_Ping():Void {



        var packet:Bytes = buf.sub(0,1);

        trace("Packet Id: " + "0x" + packet.toHex());
        /// time 
        var timesubs:Bytes = buf.sub(5,8);
        var timesubss:Bytes = buf.sub(1,8);
        var timeinput:BytesInput = new BytesInput(timesubs);
        timeinput.bigEndian = true;
        var time:Int = timeinput.readInt32();
        trace("Time: " + time);
        
        // RakNet Magic
        var magicsubs:Bytes = buf.sub(9,16);
        var RakNetMagic:String = magicsubs.toHex();
        trace("RakNet Magic: " + RakNetMagic);
        // Client guid
        var guidsubs:Bytes = buf.sub(25,8);
        var ClientGuid:String = guidsubs.toHex();
        trace("Client guid: " + ClientGuid);

        var data:Bytes = Bytes.alloc(1024);
        var output:BytesOutput = new BytesOutput();
        var ServerMOTD = 'MCPE;CopperMC Server;589;1.20.0;2;20;13253860892328930865;Powered by CopperMC;Survival;1;19132;19133;';
        // // packet id
        output.bigEndian = false;
        output.writeByte(0x1c);
        // // client time
        output.bigEndian = true;
        output.writeBytes(timesubss,0,timesubss.length);
        // // // server guid
        output.bigEndian = true;
        output.writeBytes(guidsubs,0,guidsubs.length);
        // // // magic
        output.bigEndian = false;
         output.writeBytes(magicsubs,0,magicsubs.length);
        //server string
        output.bigEndian = true;
        var motd:Int = ServerMOTD.length;
        output.writeUInt16(motd);
        var motdd:Bytes = Bytes.ofString(ServerMOTD,UTF8);
        output.writeBytes(motdd,0,motdd.length);
        data = output.getBytes();        
        trace(data.toHex());

        socket.sendTo(data,0,data.length,add);

    }
    
}