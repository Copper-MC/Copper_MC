using src.Server;
class Main {
  static public function main() {
    var myServer:Server = new Server("Copper MC", "192.168.1.55", 19132);
    myServer.Start();
  }

}
