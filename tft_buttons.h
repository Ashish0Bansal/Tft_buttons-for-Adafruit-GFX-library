class tft_buttons{
    uint16_t x_pos;
    uint16_t y_pos;

    uint16_t width;
    uint16_t height;

    uint16_t color;
    char shape; //'R' - rectangle, 'C' -- circular, 'r'-- Rounded Rectangle
    void (*function)();

  public:

    tft_buttons(uint16_t x, uint16_t y,uint16_t w, uint16_t h, uint16_t col, void (*fun)(), char shp){
      x_pos = x;
      y_pos = y;
      
      width  = w;
      height = h;
      
      color = col;
      shape = shp;

      function = fun;
    }

    void display_button(Adafruit_TFTLCD &t, uint16_t ro=0){
      switch(shape){
        case 'R' : 
        default  : t.fillRect(x_pos, y_pos, width, height, color); break;
        case 'C' : t.fillCircle(x_pos, y_pos, width, color); break;
        case 'r' : t.fillRoundRect(x_pos, y_pos, width, height, ro, color); break;
      }
      
    }

    void call_function(int x, int y){
      
      switch(shape){
        case 'R':
        case 'r':
        default : if((x>=x_pos && x<=(x_pos+width)) && (y>=y_pos && y<=(y_pos+width))){
                    (*function)();
                  } 
                  break;
        case 'C': int result = (x>x_pos?(x-x_pos):(x_pos-x))*(x>x_pos?(x-x_pos):(x_pos-x))+ (y>y_pos?(y-y_pos):(y_pos-y))*(y>y_pos?(y-y_pos):(y_pos-y));
                  if(result<=(width*width)){
                    (*function)(); 
                  }
      }
      
      
    }
};
