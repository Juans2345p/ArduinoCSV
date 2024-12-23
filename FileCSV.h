/*Libreria objetov de hererar de File*/


class FileCSV : public File{
  private:
    //uint8_t PinSD = 13;
    char charX = ',';
    char charY = '\n';
  public:
///You use when you CSV don't use , or space
FileCSV(char DivX = ',', char DivY = '\n'){
    charX = DivX;
    charY = DivY;
  }
  FileCSV();
  //Cerrar archivo
    /*FileCSV(uint8_t i){
      PinSD = i;
    }
    //this isn't need because you're doing out of class
    void Close(){
      close();
      SD.end();
    }
    uint8_t Start(String Ruta){
      Inicia desde 0
      if(!SD.begin(PinSD))
      return 1;
      if(!SD.exists(Ruta))
      return 2;
      Arc = SD.open(Ruta);
      return false;
    }*/
////You use this fun when 
    String readCSV(uint8_t X, uint16_t Y){
      ///posicion
      seek(0);
      uint16_t P = 0;
      int16_t Ca = 0;
      //movimiento en Y
      while( Y > P){
        seek(find(charY)-2);
        P++;
      }
      ///Moviendo en X
      P = 0;
      while( X > P){
        seek(find(charX)-2);
        P++;
      }
      String Cache = "";
      while(1){
        Ca = read();
        if(Ca == -1)
        return Cache;
        else if(Ca == charX)
        return Cache;
        else if(Ca == charY)
        return Cache;
        else
        Cache += char(Ca);
      }
    }
};
