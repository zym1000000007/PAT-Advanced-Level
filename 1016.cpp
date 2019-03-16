#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _bill {
	char name[25];
	char date[12];
	char line[10];
	int type;
} BILL;

BILL bill[1010];
int TYPE,NUM,n,_type[1010],toll[24];

void namesort();
void datesort(int a,int b);
int _money(char*d[2]);
int _time(char*d[2]);

int main(void) {
	int i,Total,cnt,j,k,time[1010],amount[1010];
	char na[25],*DT[2],*begin[1010],*end[1010],month[3];
//	char a[20];

//	printf("%d",strcmp("ab","abc"));
//	scanf("%s",a);
//	printf("%d",strlen(a));
	for (i=0; i<24; i++) {
		scanf("%d",&toll[i]);
	}
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%s%s%s",bill[i].name,bill[i].date,bill[i].line);
	}
	month[0]=bill[0].date[0];
	month[1]=bill[0].date[1];
	month[2]='\0';
	//米¯車?℅?℅?米???D辰o‘那y
	namesort();
	//??D辰o車～∩???3D辰??type?3?米㏒????角辰?????℅?type++㏒?℅?o車??3?℅邦TPYE
	strcpy(na,bill[0].name);
	TYPE=0;
	_type[0]=0;
	for (i=0; i<n; i++) {
		if (strcmp(na,bill[i].name) == 0) {
		} else {
			TYPE++;
			_type[TYPE]=i;
			strcpy(na,bill[i].name);
		}
		bill[i].type=TYPE;
	}
	TYPE++;
	_type[TYPE]=n;
//	printf("TYPE=%d\n",TYPE);
	//豕?3?type?角赤???﹞??迆辰???℅谷角?㏒?????3?那y芍?NUMo赤??㊣那????㏒?米¯車?那㊣????D辰o‘那y
	for (i=0; i<TYPE; i++) {
		Total=0;
		cnt=0;
		datesort(_type[i],_type[i+1]);
		for (j=_type[i]+1; j<_type[i+1]; j++) {
			if ((strcmp(bill[j-1].line,"on-line") == 0) && (strcmp(bill[j].line,"off-line") == 0)) {
				begin[cnt]=bill[j-1].date+3;
				end[cnt]=bill[j].date+3;
				DT[0]=bill[j-1].date;
				DT[1]=bill[j].date;
				time[cnt]=_time(DT);
				amount[cnt]=_money(DT);
				Total += amount[cnt];
				cnt++;
			}
		}
		if (cnt>0) {
			printf("%s %s\n",bill[j-1].name,month);
			for (k=0; k<cnt; k++) {
				printf("%s %s %d $%.2f\n",begin[k],end[k],time[k],amount[k]/100.0);
			}
			printf("Total amount: $%.2f",Total/100.0);
			if (i<TYPE-1) {
				printf("\n");
			}
		}
	}
	//?迄?Yonline,offline????
	//????﹞?車?
//	for (i=0;i<n;i++){
//		printf("%s %s %s %d\n",bill[i].name,bill[i].date,bill[i].line,bill[i].type);
//	}
	return 0;
}

//??℅?℅?米???D辰o‘那y
void namesort() {
	int i,j;
	BILL na;

	for (i=0; i<n; i++) {
		for (j=i+1; j<n; j++) {
			if (strcmp(bill[i].name,bill[j].name) > 0) {
				na=bill[i];
				bill[i]=bill[j];
				bill[j]=na;
			}
		}
	}
}
//那㊣????D辰o‘那y

void datesort(int a,int b) {
	int i,j;
	BILL na;

	for (i=a; i<b; i++) {
		for (j=i+1; j<b; j++) {
			if (strcmp(bill[i].date,bill[j].date) > 0) {
				na=bill[i];
				bill[i]=bill[j];
				bill[j]=na;
			}
		}
	}
}
//????㏒?????﹞?車?o‘那y

int _time(char *d[2]) {
	int time,t[2],i;

	for (i=0; i<2; i++) {
		t[i]=(d[i][3]-'0')*24*60*10+(d[i][4]-'0')*24*60+(d[i][6]-'0')*10*60+(d[i][7]-'0')*60+(d[i][9]-'0')*10+(d[i][10]-'0');
	}
	time=t[1]-t[0];

	return time;
}

int _money(char *d[2]) {
	int money,i,t[2],ti,hour,ret;

//	printf("d0=%s\nd1=%s\n",d[0],d[1]);
	for (i=0; i<2; i++) {
		t[i]=(d[i][3]-'0')*24*60*10+(d[i][4]-'0')*24*60+(d[i][6]-'0')*10*60+(d[i][7]-'0')*60+(d[i][9]-'0')*10+(d[i][10]-'0');
	}
	ti=t[0];
	hour=(ti%1440)/60;
	ret=ti%60;
	if ((t[1]-t[0])<=(60-ret)) {
		money=(t[1]-t[0])*toll[hour];
//		printf("ti=%d hour=%d ret=%d money=%d\n",ti,hour,ret,money);
	} else {
		money=(60-ret)*toll[hour];
		ti+=60-ret;
		while (ti<(t[1]-60)) {
			hour=(ti%1440)/60;
			money+=60*toll[hour];
			ti+=60;
		}
		hour=(ti%1440)/60;
		money+=(t[1]-ti)*toll[hour];
	}

	return money;
}
