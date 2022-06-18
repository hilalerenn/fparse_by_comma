#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int parse_by_comma(char* str, int * result)
{
    int len = strlen(str);
    char str2[256];
    int is2digitFlag=0, is3digitFlag=0, resultIdx=-1;

    strcpy(str2 , str);
    printf("geldim\n %s\n",str);
    
    
    for(int i=0; i < len + 2; i++){
        if(memcmp((char*)&str2[i], ",", 1)){ //virgul degilse
            ++is2digitFlag;
            ++is3digitFlag;
            resultIdx++;

        }
        else if(memcmp((char*)&str2[i], ",", 1) == 0) { //virgul ise islem yapma
            is2digitFlag = 0;
            is3digitFlag = 0;
            continue;
        }        
        result[resultIdx] = atoi(&str2[i]) ;
        
        if(is2digitFlag==2){ //2 basamak icin
            result[resultIdx] = 0;
            is2digitFlag = 0;
            --resultIdx;
        }

        if(is3digitFlag==3){ //3 basamak icin
            printf("is3digitFlag==3\n ");
            result[resultIdx] = 0;
            is3digitFlag = 0;
            --resultIdx;
        }
    }
}


int main()
{
    char* gconfigstr="5,192,64,9,897,71,2,185,6,99";
    int result[256] = {0};
      
    parse_by_comma(gconfigstr,result);

    for(int k=0; result[k]; k++){
        printf("result[%d] %d  \n",k,result[k]);
    }
}
