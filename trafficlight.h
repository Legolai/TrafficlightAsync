class Trafficlight {
  private:
    int RPin = 0;
    int YPin = 0;
    int GPin = 0;
    int *pins[3]={&RPin, &YPin, &GPin};
    int state = 0;

  public:
    Trafficlight(int _pins[]);
    Trafficlight(int _RPin,int _YPin,int _GPin);
    void setPinsMode();
    void turnAllOn();
    void turnAllOff();
    void lightControl();
    void lightSequance();
    void setState(int _state);
    void nextState();
    void checkState();
    ~Trafficlight();
};
