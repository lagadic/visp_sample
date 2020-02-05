#include "vpRequestImage.h"

vpRequestImage::vpRequestImage(){
  request_id = "image";
}

vpRequestImage::vpRequestImage(vpImage<unsigned char> *Im){
  request_id = "image";
  I = Im;
}

vpRequestImage::~vpRequestImage(){}

void vpRequestImage::encode(){
  clear(); 
  
  unsigned int h = I->getHeight();
  unsigned int w = I->getWidth();     

  addParameterObject(&h);
  addParameterObject(&w);
  addParameterObject(I->bitmap,h*w*sizeof(unsigned char));
}
  
void vpRequestImage::decode(){
  if(listOfParams.size() == 3){
    unsigned int w, h;
    memcpy((void*)&h, (void*)listOfParams[0].c_str(), sizeof(unsigned int));
    memcpy((void*)&w, (void*)listOfParams[1].c_str(), sizeof(unsigned int));
    
    I->resize(h,w);
    memcpy((void*)I->bitmap,(void*)listOfParams[2].c_str(),w*h*sizeof(unsigned char));
  }
}