/* math.h permet de faire des calculs au d‚triment de la vitesse */
#include <math.h>
/* string.h permet de manipuler des chaŒnes de caractŠres */
#include <string.h>
/* pic.h permet de configurer automatiquement le PIC en fonction de Configure/Select Device */
#include <pic.h>
/* htc.h contient les d‚finitions des macros dont __CONFIG pour configurer les fusibles */
#include <htc.h>

#define PHH     180
#define PH      30
#define LED1    RB0
#define LED2    RB1
#define LED3    RB2

int TA,TCA,H2O;
unsigned char test,flag,flagc,flagd,k,recfin,cptint;
char rep[]="012345678901234567890123";
char tabrec[5];

__CONFIG(INTIO & WDTDIS & PWRTDIS & MCLRDIS & BORDIS & UNPROTECT);
void initrs232(void);
void initadc(void);
int litadc(unsigned char n);
void pause(long tpus);
void emet(char t[]);

void main(void){
	TRISA=0b01111100;
	TRISB=0;
	TRISC=0b10010000;
	initrs232();
	initadc();
	emet(rep);
	k=0;
	recfin=0;
	cptint=0;
	do{
		TA=litadc(0);
		pause(10000);
		TCA=litadc(1);
		if(TCA>20){
			strcpy(rep,"Surchauffe du condenseur");
			flagc=1;
			LED1=1;	
		}
		if(TCA<=20){
			flagc=0;
			LED1=0;
		}
		if(flagc==1) {
			emet(rep);
			flagc=0;
		}
		pause(5000);
		if(TA>=(TCA-1) && TA<=(TCA+1)) {
			strcpy(rep,"Arrˆt du compresseur");
			flagd=1;
			LED3=1;
		}
		if(TA>(TCA+1) || TA<(TCA-1)){
			flagd=0;
			LED3=0;
		}
		if(flagd==1){
			emet(rep);
			flagd=0;
		}
		pause(10000);
		H2O=litadc(4);
		if(H2O>100){
			strcpy(rep,"Fuite d'eau");
			flag=1;
			LED2=1;
		}
		if(H2O<=100){
			strcpy(rep,"");
			flag=0;
			LED2=0;
		}
		if(flag==1) {
			emet(rep);
			flag=0;
		}
		pause(10000);
		test=0;	
	}while(1==1);
}

void initrs232(void){
	TRISC6=0;
	TRISC7=1;
	SPBRG=25;
	TXSTA=0x86; /*CSRC=1 BRGH=1 TRMT=1*/
	RCSTA=0x90; /*SPEN=1 CREN=1*/
}

void emet(char t[]){
	unsigned char i;
	i=0;
	TXEN=1;
	do{
		TXREG=t[i];
		pause(PH);
		i++;
	}while(i<strlen(t));
    TXREG=0x0D;
	pause(PH);
}

void initadc(void){
	ADCON0=0xC1;
	ADCON1=0x80;
}

int litadc(unsigned char n){
	int res;
	ADCON0=0xC1 | n<<2;  /* lancement de la conversion sur ANn avec FRC, ADON=1 et GODONE=0*/
	GODONE=1;
	while(GODONE==1);
	res=ADRESL+256*ADRESH;
	return res;
}

void pause(long tpus)
  {
      long n;
      for(n=0;n<tpus;n++);
  }

static void interrupt rec232(void)
{
	RCIF=0; //R‚armement de l'interruption
	RCIE=0; //Empˆche une interruption simultan‚e
	tabrec[k]=RCREG; //R‚ception du caractŠre
	if (k==4 || tabrec[k]==0 || tabrec[k]==10)//5e caractŠre ou 0 ou LF
		{
			recfin=1;
			cptint++;
			//permet d'‚liminer CR+LF
			tabrec[k]=0;
			tabrec[k-1]=0;
			k=-1;
		}
	if (k<4) //Passage au caractŠre k+1
		{
			RCIF=0;
			RCIE=1; //Autorisation des interruptions RS232
			k++;
		}
}

void initxbee(void)
	{
		recfin=0;
	    strcpy(rep,"+++");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // Syntaxe des commandes AT : AT+commande+espace+paramŠtre+CR (CR = caractŠre 13 = \13)
        // fixe l'adresse haute du module xbee externe	
        recfin=0;
	    strcpy(rep,"ATDH 00000000\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // fixe l'adresse basse du module xbee externe
	    recfin=0;
	    strcpy(rep,"ATDL 00000002\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // configure le module en coordinateur
	    recfin=0;
	    strcpy(rep,"ATCE 0\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // Autorise la liaison avec tout autre coordinateur sur le r‚seau
	    recfin=0;
	    strcpy(rep,"ATA1 1\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // Interdit le scan pour localiser l'identifiant de r‚seau (ID fixe de r‚seau)
	    recfin=0;
	    strcpy(rep,"ATA2 0\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // Fixe l'adresse r‚seau du module
	    recfin=0;
	    strcpy(rep,"ATMY 0002\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // Actualise les paramŠtres
	    recfin=0;
	    strcpy(rep,"ATAC\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
	    // Sortie du mode commande
	    recfin=0;
	    strcpy(rep,"ATCN\r");
	    emet(rep);
	    while(recfin==0);
	    pause(100000);
    }
