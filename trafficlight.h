class Trafficlight {
  private:
    int RPin = 0;
    int YPin = 0;
    int GPin = 0;
    int *pins[3]={&RPin, &YPin, &GPin};
    unsigned long *curruntTime;
    unsigned long prevTime;
    int state = 0;
    Trafficlight *otherLight;
    void checkState();

  public:
    Trafficlight(int _RPin,int _YPin,int _GPin, unsigned long &_time);
    void setPinsMode();
    void turnAllOn();
    void turnAllOff();
    void lightControl();
    void lightSequance();
    void setOtherLight(Trafficlight &_otherLight);
    
    void setState(int _state);
    int getState();
    void nextState();
   
    ~Trafficlight();
};
