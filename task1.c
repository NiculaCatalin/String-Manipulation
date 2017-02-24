#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void operatia1(char *text[], int nr_lnii)
{
	char *cuvant, *aux, *p;
	int i, nr=0;
	//aloc o memorie de 100 variabilei cuvant pentru a nu risipi memorie
	cuvant = malloc(100 *sizeof(char));
	fgets(cuvant, 100, stdin);
	cuvant[strlen (cuvant) - 1]='\0';
	//citesc cuvantul si ma asigur ca ultimul caracter nu este \n
	for(i=0; i < nr_lnii; i++)
	{
		//tin vaoarea liniilor in aux(pentru a nu o pierde) pe care o prelucrez
		//pt a salva memorie aloc strictul necesar de memorie lui aux pe care mai apoi o eliberez
		aux = malloc(strlen (text[i]) *sizeof(char)+1);
		aux[strlen (text[i]) - 1]='\0';
		strcpy(aux, text[i]);
		p = strtok(aux, "\"' ,!?");
		//despart liniile in cuvinte pe care le compar cu cuvantul cautat
		//daca cele doua sunt egale cresc valoarea lui nr cu unu
		while(p != NULL)
		{
			if(strcmp(p, cuvant) == 0)
				nr++;
			p=strtok(NULL, "\"' ,!?");
		}
		//eliberez memoria lui aux pentru a nu
		free(aux);
	}
	printf("%d\n", nr);

}
void operatia2(char *text[], int nr_lnii)
{
	char *cuvant, *cuvant_nou, *aux,*p;
	int i, nr=0;
	//aloc memorie dinamica si citesc cele doua cuvinte
	cuvant=malloc(1200 *sizeof(char));
	cuvant_nou=malloc(1200 *sizeof(char));
	scanf("%s",cuvant);
	scanf("%s",cuvant_nou);
	
	for(i=0;i<nr_lnii;i++)
	{	
		//copiez linia in aux 
		//iau un alt pointer decat "text"(pentru a nu pierde originalul)
		//merg cu acesta in paralel cu strstr
		char *pointer=text[i];
		aux=malloc((strlen(text[i])+1) *sizeof(char));
		while(strstr(pointer,cuvant) )
		{
			p=strstr(pointer,cuvant);
			//cand gasesc secventa cautata in linia text[i] aflu mai intai daca 
			//secventa este un cuvant sau doar parte dintr-unul, verificand caracterele vecine
			if(strchr("\"' ,!?",pointer[p-pointer-1])!=0&& strchr("\"' ,!?",pointer[p-pointer + strlen(cuvant)])!=0 )
			{	
				//daca este cuvant, copiez totul de la sfarsitul cuvantului pana la sfarsitul liniei in aux
				//peste cuvantul vechi il copiez pe cel nou la care ii concatenez restul liniei(din aux)
				strcpy(aux, p + strlen(cuvant));
				strcpy(p, strdup(cuvant_nou));
				strcat(pointer, strdup(aux));
				pointer=p + strlen(cuvant_nou);
				//mut pointerul la sfarstul cuvantului nou
			}
			else 
				pointer=p + strlen(cuvant);

		}
		free(aux);
		printf("%s\n", text[i]);
	}
}
void operatia3(char *text[], int nr_lnii)
{
	int permutari, i, j, k;
	char *aux, *cuvant, litera;
	cuvant = malloc(sizeof(char));
	scanf("%i", &permutari);
	
	for(i=0; i < nr_lnii; i++)
	{
		//copiez linia in aux pe care il divid cu strtok pentru a izola cuvintele
		aux=malloc((strlen(text[i]) +1) *sizeof(char)+1);
		char *pointer = text[i];
		//iau un pointer la linie pentru a lucra mai usor cu adrese
		strcpy(aux, text[i]);
		cuvant = strtok(aux, "\"' ,!?");

		while(cuvant)
		{
			//iau cuvantul din aux cu strtok si il caut in pointerul la linia originala
			//mut adresa pointerului la inceputul cuvantului
			pointer=strstr(pointer, cuvant);
			for(k=0; k < permutari % strlen(cuvant); k++)
			{
				//deoarece dupa un numar=strlen(cuvant) permutarile se repeta
				//pot eficientiza permutand doar de nr_permutari % strlen(cuvant)
				litera=pointer[strlen(cuvant)-1];
				for(j=strlen(cuvant)-1;j>0;j--)
				{
					pointer[j]=pointer[j-1];
				}
				pointer[j]=litera;
				//permut cuvantul in linia originala pastrand ultima litera a cuvantului si 
				//le mut pe celelate cu o pozitie inainte lipind la inceputul cuv ultima litera
			}
			pointer=pointer+strlen(cuvant);
			//mut pointerul la sf cuv pt a nu il citi iarasi
			cuvant=strtok(NULL, "\"' ,!?");
		}

		free(aux);
		printf("%s\n", text[i]);
	}
}
int main()
{
	int nr_lnii, i, nr_operatii, k;
	char **text, *p;
	//declar un vector de pointeri, fiecare pointer aratand spre o linie de text
	scanf("%d\n", &nr_lnii);
	text = malloc(nr_lnii*sizeof(char *));
	for(i=0; i<nr_lnii; i++)
		{
			text[i]=malloc(15000*sizeof(char));
			fgets(text[i], 15000, stdin);
			if(text[i][strlen(text[i])-1]=='\n')
				text[i][strlen(text[i])-1]='\0';

		}
	scanf("%d\n", &nr_operatii);
	//in functie de numarul introdus apelez una din cele 3 operatii
	for(i=0; i < nr_operatii; i++)
		{
			scanf("%i\n", &k);
			if(k==1)
				operatia1(text, nr_lnii);
			else
				if(k==2)
					operatia2(text, nr_lnii);
				else
					operatia3(text, nr_lnii);
		}
		return 0;
}