/*
 * Attention, ici les tailles sont compt�es en bits alors que partout
 * ailleurs c'est en octets. Il faudra peut �tre revoir �a. A titre
 * pr�ventif, cela apparait dans les noms des variables, et des macros
 * permettent d'envisager une modificiation sans cons�quences sur le
 * reste.
 */

#ifndef __DEF_DVBS2_LL
#define __DEF_DVBS2_LL

#include <pdu.h>
#include <dvb-s2-ll.h>

#define NB_MODCOD_MAX 4

struct t_modcod;
struct DVBS2ll_t;

/*
 * Cr�ation d'une entit� DVB-S2 couche 2. Attention, elle ne contient
 * aucun MODCOD par d�faut, il faut en ajouter
 */
struct DVBS2ll_t * DVBS2ll_create(void * destination,
				  processPDU_t destProcessPDU,
				  unsigned long  symbolPerSecond,
				  unsigned int FECFrameBitLength);

#define FEC_FRAME_BITSIZE_LARGE 64800

/*
 *Constantes permettant le param�trage des MODCODs
 */
#define  C14SIZE  16008
#define  C13SIZE  21408
#define  C25SIZE  25728
#define  C12SIZE  32208
#define  C35SIZE  38688
#define  C23SIZE  43040
#define  C34SIZE  48408
#define  C45SIZE  51648
#define  C56SIZE  53840
#define  C89SIZE  57472
#define  C910SIZE 58192

#define   MQPSK    2
#define   M8PSK    3
#define   M16APSK  4
#define   M32APSK  5


/*
 * Ajout d'un MODCOD. Le codage est param�tr� par le nombre de bits
 * par BBFRAME et la modulation par le nombre de bits par symbole.
 * La valeur retourn�e est l'indice de ce nouveau MODCOD.
 */
int DVBS2ll_addModcod(struct DVBS2ll_t * dvbs2ll,
		      unsigned int bbframeBitLength,
		      unsigned int bitsPerSymbol);

/*
 * Modification des propri�t�s du MODCOD n
 */
void DVBS2ll_setModcod(struct DVBS2ll_t * dvbs2ll,
                       int n,
		       unsigned int bbframeBitLength,
		       unsigned int bitsPerSymbol);
/************************************************************************/
/*    Le modele in/out                                                  */
/************************************************************************/
/*
 * Attribution d'une source. Attention c'est obligatoire ici car c'est
 * l'entit� DVBS2ll qui va solliciter la source lorsque le support
 * sera libre
 */
void DVBS2ll_setSource(struct DVBS2ll_t * dvbs2ll, void * source, getPDU_t getPDU);

/*
 * Une fonction permettant la conformit� au mod�le d'�change
 */
void DVBS2ll_processPDU(struct DVBS2ll_t * dvbs2ll,
                        getPDU_t getPDU,
                        void * source);

/*
 * Emission d'une PDU au travers d'un MODCOD s�lectionn�. La PDU doit
 * �tre d'une taille inf�rieure ou �gale � la taille de charge utile du
 * MODCOD choisi.
 */
void DVBS2ll_sendPDU(struct DVBS2ll_t * dvbs2ll, struct PDU_t * pdu);

/************************************************************************/
/*    Les sondes                                                        */
/************************************************************************/
/*
 * Ajout d'une sonde sur la taille de la charge utile des trames �mises
 * sur un MODCOD donn�
 */
void DVBS2ll_setActualPayloadBitSizeProbe(struct DVBS2ll_t * dvbs2ll, int mc, struct probe_t * pr);

/*
 * Ajout de la probe sur les DUMMY. Elle n'�chantillonne aucune
 * valeur, juste les dates d'�mission de DUMMY frames.
 */
void DVBS2ll_setDummyFecFrameProbe(struct DVBS2ll_t * dvbs2ll, struct probe_t * pr);

/************************************************************************/
/*
 * Nombre de MODCODs
 */
int DVBS2ll_nbModcod(struct DVBS2ll_t * dvbs2ll);

/*
 * Capacit� d'une BBFRAME associ�e au MODCOD d'indice fourni
 */ 
unsigned int DVBS2ll_bbframePayloadBitSize(struct DVBS2ll_t * dvbs2ll, int mcIdx);

/*
 * Nombre de bits par symbole d'un modcod
 */
unsigned int DVBS2ll_bitsPerSymbol(struct DVBS2ll_t * dvbs2ll, int mcIdx);

/*
 * Temps d'�mission d'une BBFRAME associ�e au MODCOD d'indice fourni
 */ 
double DVBS2ll_bbframeTransmissionTime(struct DVBS2ll_t * dvbs2ll, int mcIdx);

/*
 * Le support est-il disponible ?
 */
int DVBS2ll_available(struct DVBS2ll_t * dvbs2ll);



#endif
