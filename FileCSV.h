/*Libreria objetov de hererar de File*/


class CSV{
  private:
    uint8_t PinSD = 13;
    char charX = ',';
    char charY = '\n';
    File Arc;
  public:
  //Cerrar archivo
    CSV(uint8_t i){
      PinSD = i;
    }

    void Close(){
      Arc.close();
      SD.end();
    }

    uint8_t Start(String Ruta){
      /*Inicia desde 0*/
      if(!SD.begin(PinSD))
      return 1;
      if(!SD.exists(Ruta))
      return 2;
      Arc = SD.open(Ruta);
      return false;
    }

    String readCSV(uint8_t X, uint16_t Y){
      ///posicion
      Arc.seek(0);
      uint16_t P = 0;
      int16_t Ca = 0;
      //movimiento en Y
      while( Y > P){
        Arc.seek(Arc.find(charY)-2);
        //Arc.readStringUntil(charY);
        P++;
      }
      ///Moviendo en X
      P = 0;
      while( X > P){
        Arc.seek(Arc.find(charX)-2);
        //Arc.readStringUntil(charX);
        P++;
      }
      String Cache = "";
      while(1){
        Ca = Arc.read();
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


