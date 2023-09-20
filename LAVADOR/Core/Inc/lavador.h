#ifndef LAVADOR_H
#define LAVADOR_H

// available positions of the selector

typedef enum {
	SELECTOR_OFF , // maquina apagada
	SELECTOR_COTTON_1 , // algodon tipo 1
	SELECTOR_COTTON_2 , // algodon tipo 2
	SELECTOR_SYNTHETIC , // tejidos sinteticos
	SELECTOR_QUICK , // lavado rapido
	SELECTOR_DELICATE , // lavado delicado
	SELECTOR_WOOL , // lavado lanas
	SELECTOR_CARE , // lavado muy delicado
	SELECTOR_DESAGUE , // desague
	SELECTOR_SPIN_1 , // centrifugado nivel 1
	SELECTOR_SPIN_2 , // centrifugado nivel 2
	SELECTOR_ACLARADO , // aclarado + centrifugado nivel 2
	SELECTOR_UNDEFINED // valor no esperado
} TSelectorStatus ;

void selector_Init(void);
TSelectorStatus selector_Read(void);

#endif
