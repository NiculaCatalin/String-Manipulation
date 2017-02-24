#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long dist(char *s1, char *s2)
{
	//calculez distanta dintre 2 stringuri scazand valorile lor ASCII
	int i=0, s=0;
	while(s1[i]!=0 && s2[i]!=0)
	{
		s = s +abs(s1[i] - s2[i]);
		i++;
	}
	if (strlen(s1) > strlen(s2))
		while(s1[i] != 0)
		{
			s=s + s1[i];
			i++;
		}
		else
	while(s2[i] != 0)
	{
		s = s+s2[i];
		i++;
	}
	return s;
}
int main()
{
	char **lista1, **lista2, *p, *aux;
	//imi declar 2 vectori de pointeri in care voi pastra listele de cuvinte
	//declar 2 vectori integer in care voi pastra in paralel cu listele numarul de aparitii al cuvintelor
	int *aparitii1, *aparitii2, nr_cuv1=0, nr_cuv2=0;
	int i, j, n, m, ok, swap;
	long NR, suma=0;
	char *linie = malloc(12000 *sizeof(char));
	scanf("%i", &n);
	fflush(stdin);
	//aloc putina memorie listei si vectorului deoarece 
	//de fiecare data cand gasesc un cuvant am sa le realoc memoria 
	lista1 = malloc(sizeof(char *));
	aparitii1 = malloc(sizeof(int));
	
	for(i=0; i<=n; i++)
	{
		fgets(linie, 12000, stdin);
		
		if(linie[strlen(linie) - 1] == '\n')
				linie[strlen(linie)- 1] = '\0';
		//despart textul in cuvinte cu strtok
		//si verific daca se afla sau nu in lista
		//daca se afla cresc nr de aparitii corespunzatoare cuvantului
		//daca nu realoc memoria vectorului si a listei si il introduc in acestea
		p = strtok(linie, "\"' ,!?");
		while(p != 0)
		{
			ok=1;
			for(j=0; j<nr_cuv1; j++)
				if(strcmp(p, lista1[j])==0)
				{
					ok=0;
					aparitii1[j]++;
				}
			//daca cuvantul se gaseste in linie => ok=0 altfel ok=1
			if(ok==1)
			{
				nr_cuv1++;

				lista1 = realloc(lista1, nr_cuv1 *sizeof(char *));

				aparitii1 = realloc(aparitii1, nr_cuv1 *sizeof(int));
				
				lista1[nr_cuv1-1] = malloc(3000 *sizeof(char));
				
				strcpy(lista1[nr_cuv1 - 1], p);
				aparitii1[nr_cuv1 - 1] = 1;
			}
			p=strtok(NULL, "\"' ,!?");
		}
	}
	//fac acelasi lucru ca mai sus pentru a doua lista
	scanf("%i", &m);
	fflush(stdin);
	lista2 = malloc(sizeof(char *));
	aparitii2 = malloc(sizeof(int));
	
	for(i=0; i<=m; i++)
	{
		fgets(linie, 12000, stdin);
		if(linie[strlen(linie) - 1]=='\n')
				linie[strlen(linie) - 1]='\0';

		p=strtok(linie, "\"' ,!?");
		
		while(p)
		{
			ok=1;
			for(j=0; j<nr_cuv2; j++)
				if(strcmp(p, lista2[j]) == 0)
				{
					ok=0;
					aparitii2[j]++;
				}

			if(ok==1)
			{
				nr_cuv2++;

				lista2 = realloc(lista2, nr_cuv2 *sizeof(char *));
				aparitii2 = realloc(aparitii2, nr_cuv2 *sizeof(int));
				lista2[nr_cuv2-1] = malloc(3000 *sizeof(char));				
				strcpy(lista2[nr_cuv2-1], p);
				aparitii2[nr_cuv2 - 1]=1;
			}
			p=strtok(NULL, "\"' ,!?");
		}
	}	
	//acum ca am listele de cuvinte le ordonez cu un bubble-sort
	//mai intai in functie de aparitii si mai apoi alfabetic
	for(i=0; i<nr_cuv1-1; i++)
		for(j=i+1; j<nr_cuv1; j++)
		{	
			if(aparitii1[i] < aparitii1[j])
			{
				aux=malloc( (strlen(lista1[i]) + 1) *sizeof(char));
				//interschimb atat valoarea cuvantului cat si numarul de apariti din vector
				strcpy(aux, lista1[i]);
				strcpy(lista1[i], lista1[j]);
				strcpy(lista1[j], aux);
				
				swap=aparitii1[i];
				aparitii1[i]=aparitii1[j];
				aparitii1[j]=swap;
				
				free(aux);
			}
			
				if(aparitii1[i] == aparitii1[j])
					if(strcmp(lista1[i], lista1[j])>0)
					{
						aux=malloc((strlen(lista1[i]) + 1) *sizeof(char));
						//interschimb doar cuvantul deoarece nr de aparitii e acelasi
						strcpy(aux,lista1[i]);
						strcpy(lista1[i],lista1[j]);
						strcpy(lista1[j],aux);
						
						free(aux);
					}
		}
	//fac aceeasi ordonare si pentru lista2
	for(i=0; i<nr_cuv2-1; i++)
		for(j=i+1; j<nr_cuv2; j++)
		{
			if(aparitii2[i] < aparitii2[j])
			{
				aux = malloc((strlen(lista2[i]) + 1) *sizeof(char));
				
				strcpy(aux, lista2[i]);
				strcpy(lista2[i], lista2[j]);
				strcpy(lista2[j], aux);
				
				swap=aparitii2[i];
				aparitii2[i]=aparitii2[j];
				aparitii2[j]=swap;
				
				free(aux);
			}
			else
				if(aparitii2[i] == aparitii2[j])
					if(strcmp(lista2[i], lista2[j]) > 0)
				{
					aux=malloc((strlen(lista2[i]) + 1) *sizeof(char));
					
					strcpy(aux, lista2[i]);
					strcpy(lista2[i], lista2[j]);
					strcpy(lista2[j], aux);
					
					free(aux);
				}
		}
	//stabilesc min(nr_cuv1,nr_cuv2)
	if(nr_cuv1 > nr_cuv2)
		NR=nr_cuv2;
	else
		NR=nr_cuv1;
	for(i=0; i < NR; i++)
		suma = suma + (aparitii1[i] + aparitii2[i]) *dist(lista1[i], lista2[i]);
	//calculez formula ceruta si o afisez
	printf("%li", 100 *abs(nr_cuv1 - nr_cuv2) + suma);	
	free(linie);
	return 0;
}
