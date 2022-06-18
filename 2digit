#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int parse_by_comma(char* str, int * result)
{
    int len = strlen(str);
    char str2[256];
    int is2digitFlag=0, resultIdx=-1;

    strcpy(str2 , str);
    printf("geldim\n %s\n",str);
    
    
    for(int i=0; i < len + 2; i++){
        if(memcmp((char*)&str2[i], ",", 1)){ //virgul degilse
            //printf("str2[%d] %c\n",i,str2[i]);
            ++is2digitFlag;
            resultIdx++;

        }
        else if(memcmp((char*)&str2[i], ",", 1) == 0) {
            is2digitFlag = 0;
            continue;
        }

        
        result[resultIdx] = atoi(&str2[i]) ;
        
        if(is2digitFlag==2){
            result[resultIdx] = 0;
            is2digitFlag = 0;
            --resultIdx;
        }
    }  
}


int main()
{
    char* gconfigstr="5,19,64,9,87,71,2,18,6";
    int result[256] = {0};
      
    parse_by_comma(gconfigstr,result);

    for(int k=0; result[k]; k++){
        printf("result[%d] %d  \n",k,result[k]);
    }
}
