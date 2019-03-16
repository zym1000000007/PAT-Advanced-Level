#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const float fd=0.000001;

typedef struct _station {
	float price;
	int dis;
} Station;

bool yes2;

void sort(Station* station,int n) {
	int i,j;
	Station p;
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if (station[i].dis > station[j].dis) {
				p=station[i];
				station[i]=station[j];
				station[j]=p;
			}
		}
	}
}

int find(int i,Station *station,int DISTANCE,int n) {
	int j,k=-1;
	float min;
	yes2=false;

	j = i+1;
	min = 1+station[j].price;
	while (DISTANCE >= (station[j].dis-station[i].dis)) {
//		printf("j=%d station[j].gas=%.2f station[i].gas=%.2f\n",j,station[j].gas,station[i].gas);
//		yes = true;
		if (fd < station[i].price - station[j].price) {
			yes2=true;
			k = j;
			break;
		}
		if (fd < min - station[j].price) {
			min = station[j].price;
			k = j;
		}
		j++;
	}
	return k;
}

int main(void) {
	int i,j,k,n,tank,distance,run,dis,DIS,rest=0,DISTANCE;
	float ALL=0,z;
	bool yes3=true;

	scanf("%d%d%d%d",&tank,&distance,&run,&n);
	DISTANCE = tank * run;
	Station station[n+1];

	for (i=0; i<n; i++) {
		scanf("%f%d",&(station[i].price),&station[i].dis);
		station[i].price /= run;
	}
	station[n].dis = distance;
	station[n].price = -1;

	sort(station,n);

	if (station[0].dis > 0) {
		printf("The maximum travel distance = 0.00");
	} else {
		for (i=0; i<n;) {
			z=ALL;
//		printf("i=%d\n",i);
			k=find(i,station,DISTANCE,n);
//		printf("k=%d\n",k);
			if (k == -1) {
				DIS = station[i].dis + DISTANCE;
				printf("The maximum travel distance = %.2f",(float)DIS);
				yes3=false;
				break;
			} else if (yes2) {
				ALL += (station[k].dis - station[i].dis - rest) * station[i].price;
				rest = 0;
				i=k;
			} else {
				ALL += (DISTANCE- rest) * station[i].price;
				rest = DISTANCE - (station[k].dis - station[i].dis);
				i=k;
			}
//			printf("ALL=%f rest=%f\n",ALL,rest);
			if (z - ALL > fd) {
				j=0;
				while(1) {
					j++;
				}
			}
		}
		if (yes3)
			printf("%.2f",ALL);
	}

	return 0;
}
