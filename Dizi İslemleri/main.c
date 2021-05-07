#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

 int dizi[10];
 int secim,i,y,k,sayi,j,x;
 float toplam=0.0;
 float stoplam=0.0;
 char c;
 float standartSapma,ortalama;
 int diziMax,diziMin;
 
 void diziYazdir(){
  	printf("Olusturulan Dizi: ");
 	for(i=0;i<9;i++){
 		printf("%d,",dizi[i]);
	 }
 	printf("%d\n",dizi[9]);
 }
 void diziTerstenYazdir(){
 	for(i=9;i>0;i--){
 		printf("%d,",dizi[i]);
	 }
 	printf("%d",dizi[0]);
 }
 void maxMinYazdir(char c){
 	if(c=='B'){
 		for(i=0;i<10;i++){
 			if(dizi[i]>diziMax) diziMax=dizi[i];
		 }
		 printf("En buyuk eleman: %d",diziMax);		 

	 }
	else if(c=='K'){
 		for(i=0;i<10;i++){
 			if(dizi[i]<diziMin) diziMin=dizi[i];
		 }
		 printf("En kucuk eleman: %d",diziMin);		 		
		
	}
 	
 }
 void sirala(char c){
 	if(c=='B'){
 		for(i=0;i<10;i++){
 			for(y=0;y<10;y++){
 				if(dizi[y]<=dizi[i]){
 					k=dizi[i];
 					dizi[i]=dizi[y];
 					dizi[y]=k;
				 }
			 }
		 }
		 for(i=0;i<9;i++){
		 	printf("%d,",dizi[i]);
		 }
		 printf("%d",dizi[9]);
	 }
	else if(c=='K'){
 		for(i=0;i<10;i++){
 			for(y=0;y<10;y++){
 				if(dizi[i]<dizi[y]){
 					k=dizi[i];
 					dizi[i]=dizi[y];
 					dizi[y]=k;
				 }
			 }
		 }
		 for(i=0;i<9;i++){
		 	printf("%d,",dizi[i]);
		 }
		 printf("%d",dizi[9]);
	}
 	
 	
 }
 void istatistikGoster(){
 	for(i=0;i<10;i++){
 		toplam+=dizi[i];
	 }
	 ortalama=toplam/10;
	 printf("Ortalama:%f\n",ortalama);
	 
	 for(y=0;y<10;y++){
	 	stoplam+=pow((dizi[y]-ortalama),2);
	 }
	 float k=stoplam/9;
	 standartSapma=sqrt(k);
	 printf("Standart sapma: %f",standartSapma);
 }
 
 
 main() {

 	 srand(time(NULL)); 
     dizi[0]=rand()%50+1;

    for(x=1;x<10;x++){
    	sayi=rand()%50+1;
    	for(y=0;y<x;y++){
    		if(sayi==dizi[y]){
    			x--;
    			break;
			}
			else if(sayi!=dizi[y]){
 	            dizi[x]=sayi;
			}
		}  	
    }
     diziMax=dizi[0];
     diziMin=dizi[0];

 printf("1-Yazdir\n2-Tersten Yazdir\n3-MAX-MIN Yazdir\n4-Sirala\n5-Istatistik Goster\n");
 printf("\nSECIMINIZ:");
 scanf("%d",&secim);
 
 if(secim==1){
 	diziYazdir();
 }
 else if(secim==2){
 	diziYazdir();
 	diziTerstenYazdir();
 }
  else if(secim==3){
  	diziYazdir();
  	printf("Seciminiz:Kucuk/Buyuk(K veya B olarak giriniz.):");
  	scanf(" %c",&c);
  	maxMinYazdir(c);
 }
  else if(secim==4){
  	diziYazdir();
  	printf("Seciminiz:Kucuk/Buyuk(K veya B olarak giriniz.):");
  	scanf(" %c",&c);
  	sirala(c);
 }
  else if(secim==5){
  	diziYazdir();
  	istatistikGoster();
 }
 else {
 	printf("Hatali giris yaptiniz..");
 }

} 
