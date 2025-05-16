
#include "./Mat2d.hpp"


class ImgPGM : public Mat2d<int> {
  private:
    int maxVal_;
    
  public:
    ImgPGM() = default; 
    void read(char *fileName);
    void write(char *fileName);
};