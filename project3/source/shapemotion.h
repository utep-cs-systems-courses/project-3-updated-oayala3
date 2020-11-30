#ifndef led_included
#define  led_included
#include <msp430.h>

typedef struct MovLayer_s MovLayer;
extern int redrawScreen;
extern Layer layer4, layer3, fieldLayer, layer1, layer0; 


void movLayerDraw(MovLayer *movLayers, Layer *layers);
void mlAdvance(MovLayer *ml, Region *fence);


#endif
